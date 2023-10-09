#include "./graphs.h"

/* ------------------------------------- Recursive Undirected Graph ---------------------------------- */
UndirectedGraph *un_graph_create(int v)
{
  UndirectedGraph *g =
      malloc(sizeof(UndirectedGraph) + sizeof(struct neighbors *) * v);

  assert(g);

  g->v = v;
  g->e = 0;

  for (int i = 0; i < v; i++)
  {
    g->adjacencylist[i] = malloc(sizeof(struct neighbors));

    assert(g->adjacencylist[i]);

    g->adjacencylist[i]->length = 0;
    g->adjacencylist[i]->capacity = 0;
  }

  return g;
}

void un_graph_add_edge(UndirectedGraph *g, int src, int dst)
{
  assert(src != dst);
  assert(src >= 0);
  assert(src >= 0);
  assert(dst < g->v);
  assert(src < g->v);

  _append_edge(g, src, dst);
  _append_edge(g, dst, src);
}

void _append_edge(UndirectedGraph *g, int src, int dst)
{
  if (g->adjacencylist[src]->length == g->adjacencylist[src]->capacity)
  {
    g->adjacencylist[src]->capacity = g->adjacencylist[src]->capacity * 2 + 1;

    g->adjacencylist[src] =
        realloc(g->adjacencylist[src],
                sizeof(struct neighbors) +
                    sizeof(int) * g->adjacencylist[src]->capacity);
  }

  g->adjacencylist[src]->list[g->adjacencylist[src]->length++] = dst;

  g->e++;
}

void un_dfs(UndirectedGraph *g)
{
  int visited[g->v];

  memset(visited, 0, sizeof(visited));

  un_dfs_util(g, visited, 0);
  printf("END\n");
}

void un_dfs_util(UndirectedGraph *g, int visited[], int vertex)
{
  visited[vertex] = 1;

  printf("%d -> ", vertex);

  for (int e = 0; e < g->adjacencylist[vertex]->length; ++e)
  {
    int u = g->adjacencylist[vertex]->list[e];

    if (visited[u] == 0)
    {
      un_dfs_util(g, visited, u);
    }
  }
}

/* ------------------------------------- Recursive Directed Graph ---------------------------------- */
DirectedGraph *graph_create(int v)
{
  DirectedGraph *g =
      malloc(sizeof(DirectedGraph) + sizeof(struct targets *) * v);

  g->v = v;
  g->e = 0;

  for (int i = 0; i < v; i++)
  {
    g->adjacencylist[i] = malloc(sizeof(struct targets));

    g->adjacencylist[i]->length = 0;
    g->adjacencylist[i]->capacity = 0;
  }

  return g;
}

void graph_add_edge(DirectedGraph *g, int src, int dst)
{
  if (g->adjacencylist[src]->length == g->adjacencylist[src]->capacity)
  {
    g->adjacencylist[src]->capacity = g->adjacencylist[src]->capacity * 2 + 1;

    g->adjacencylist[src] = realloc(
        g->adjacencylist[src],
        sizeof(struct targets) + sizeof(int) * g->adjacencylist[src]->capacity);
  }

  g->adjacencylist[src]->list[g->adjacencylist[src]->length++] = dst;
  g->e++;
}

void dfs(DirectedGraph *g)
{
  int visited[g->v];

  memset(visited, 0, sizeof(visited));

  for (int v = 0; v < g->v; v++)
  {
    dfs_util(g, visited, v);
  }
}

void dfs_util(DirectedGraph *g, int visited[], int vertex)
{
  visited[vertex] = 1;

  printf("\n%d: ", vertex);

  for (int e = 0; e < g->adjacencylist[vertex]->length; e++)
  {
    int adj_vertex = g->adjacencylist[vertex]->list[e];
    printf("\t%d -> %d, ", vertex, adj_vertex);
    if (visited[adj_vertex] == 0)
    {
      dfs_util(g, visited, adj_vertex);
    }
  }
}

/* ------------------------------------- Iterative Un/Directed Graph ---------------------------------- */
bool processed[MAXV + 1]; /* which verticies have been processed */
bool discoverd[MAXV + 1]; /* which verticies have been found */
int parent[MAXV + 1];     /* discovery realtion */
int time;

void initialize_graph(graph *g, bool directed)
{
  printf("[INITIALIZIE_GRAPH] ...\n");
  int i;

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++)
    g->degree[i] = 0;

  for (i = 1; i <= MAXV; i++)
    g->edges[i] = NULL;

  printf("[INITIALIZIE_GRAPH] DONE\n");
}

void insert_edge(graph *g, int x, int y, bool directed)
{
  edgenode *p;

  p = malloc(sizeof(edgenode));

  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;

  g->degree[x]++;

  if (!directed)
  {
    insert_edge(g, y, x, true);
  }
  else
  {
    g->nedges++;
  }

  printf("[INSERT_EDGE] %i, %i\n", x, y);
}

void initialize_dfs(graph *g)
{
  printf("[INITIALIZE_DFS]\n");

  int i;
  time = 0;

  for (i = 0; i <= MAXV; i++)
  {
    processed[i] = false;
    discoverd[i] = false;
    parent[i] = -1;
  }
}

void iterative_dfs(graph *g, int start)
{
  initialize_dfs(g);
  printf("[ITERATIVE_DFS]\n");

  struct Stack *s = create_stack(MAXV);
  int v;       /* current vertex */
  int y;       /* successor vertex */
  edgenode *p; /* tmp pointer */

  push(s, start);

  discoverd[start] = true;

  while (!is_empty(s))
  {
    v = pop(s);
    process_vertex_early(v);
    processed[v] = true;

    p = g->edges[v];

    while (p != NULL)
    {
      y = p->y;
      if (!processed[y] || g->directed)
      {
        process_edge(v, y);
      }
      if (!discoverd[y])
      {
        push(s, y);
        discoverd[y] = true;
        parent[y] = v;
      }

      p = p->next;
    }
    process_vertex_late(v);
  }
}

void process_vertex_early(int v) {}

void process_edge(int v, int y)
{
  printf("(%i, %i)", v, y);
}

void process_vertex_late(int v) {}

/* ------------------------------------- Recursive Graph Matrix ---------------------------------- */

struct MatrixGraph *matrix_graph_create(int v, int e)
{
  struct MatrixGraph *g = malloc(sizeof(struct MatrixGraph));
  if (!g)
  {
    exit(EXIT_FAILURE);
  }

  g->v = v;
  g->e = e;

  g->adj = malloc((g->v) * sizeof(int *));
  for (int k = 0; k < g->v; k++)
    g->adj[k] = malloc(sizeof(int) * (g->v));

  for (int u = 0; u < g->v; u++)
    for (int v = 0; v < g->v; v++)
      g->adj[u][v] = 0;

  return g;
}

void matrix_insert_edge(int x, int y, struct MatrixGraph *g)
{
  g->adj[x][y] = 1;
  g->adj[y][x] = 1;
}

bool visited[100];

void matrix_dfs(int start, struct MatrixGraph *g)
{
  memset(visited, 0, sizeof(visited));

  for (int i = 0; i < g->v; i++)
    if (!visited[i])
      matrix_dfs_util(i, g);
}

void matrix_dfs_util(int start, struct MatrixGraph *g)
{
  visited[start] = true;
  printf("%d ", start);
  for (int i = 0; i < g->v; i++)
  {
    if (!visited[i] && g->adj[start][i])
    {
      // printf(" (%d, %d) ", start, i);

      matrix_dfs_util(i, g);
    }
  }
}

/* ------------------------------------- Iterative Graph Matrix ---------------------------------- */

void iterative_matrix_dfs(int start, struct MatrixGraph *g)
{
  bool nodes[100];

  for (int i = 0; i < 100; i++)
    nodes[i] = false;

  struct Stack *stack = create_stack(MAXV);
  int a = 0;

  push(stack, start);

  while (!is_empty(stack))
  {
    start = pop(stack);

    if (nodes[start])
      continue;

    nodes[start] = true;
    printf("%d ", start);

    for (int i = 0; i < g->v; i++)
    {
      if (g->adj[start][i] && !nodes[i])
        push(stack, i);
    }
  }
}

/* ------------------------------------- BFS Graph Adjaceny List  ---------------------------------- */
bool bfs_processed[MAXV + 1]; /* which verticies have been processed */
bool bfs_discoverd[MAXV + 1]; /* which verticies have been found */
int bfs_parent[MAXV + 1];     /* discovery realtion */
int bfs_time;

void bfs(graph *g)
{
  int i;

  time = 0;

  for (i = 0; i < g->nvertices; i++)
  {
    bfs_processed[i] = false;
    bfs_discoverd[i] = false;
    bfs_parent[i] = -1;
  }

  bfs_util(g, 0);
}

void bfs_util(graph *graph, int start)
{
  queue_t *q = create_queue(sizeof(int));
  int y;
  edgenode *p;
  int *ip = &start;
  // int *vp;

  enqueue(q, ip);

  bfs_discoverd[start] = true;

  while (!empty(q))
  {
    int *vp = (int *)dequeue(q);
    int v = *vp;

    process_vertex_early(v);
    bfs_processed[v] = true;

    p = graph->edges[v];

    while (p != NULL)
    {
      y = p->y;

      if ((!bfs_processed[y]) || graph->directed)
      {
        process_edge(v, y);
      }

      if (!bfs_discoverd[y])
      {
        vp = &y;
        enqueue(q, vp);
        bfs_discoverd[y] = true;
        parent[y] = v;
      }

      p = p->next;
    }
    process_vertex_late(v);
  }
}