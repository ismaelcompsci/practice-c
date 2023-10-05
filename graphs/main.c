#include "./graphs.h"

int main(void)
{
  int d_vertices = 9;
  int un_vertices = 9;
  int iter_verticies = 9;

  UndirectedGraph *g = un_graph_create(un_vertices);

  un_graph_add_edge(g, 0, 1);
  un_graph_add_edge(g, 1, 2);
  un_graph_add_edge(g, 1, 7);
  un_graph_add_edge(g, 2, 3);
  un_graph_add_edge(g, 3, 4);
  un_graph_add_edge(g, 3, 5);
  un_graph_add_edge(g, 3, 7);
  un_graph_add_edge(g, 4, 5);
  un_graph_add_edge(g, 5, 6);
  un_graph_add_edge(g, 6, 7);
  un_graph_add_edge(g, 6, 8);
  un_graph_add_edge(g, 7, 8);

  un_dfs(g);

  printf("\n\nDirected graph with %d vertices:\n", d_vertices);

  DirectedGraph *dg = graph_create(d_vertices);

  graph_add_edge(dg, 0, 1);
  graph_add_edge(dg, 0, 5);
  graph_add_edge(dg, 1, 2);
  graph_add_edge(dg, 2, 4);
  graph_add_edge(dg, 2, 6);
  graph_add_edge(dg, 3, 2);
  graph_add_edge(dg, 6, 5);
  graph_add_edge(dg, 5, 8);
  graph_add_edge(dg, 7, 5);

  dfs(dg);

  printf("\n\nIterative Graph with %d vertices:\n", iter_verticies);

  graph *ig = malloc(sizeof(graph));
  initialize_graph(ig, false);

  insert_edge(ig, 0, 1, false);
  insert_edge(ig, 0, 5, false);
  insert_edge(ig, 1, 2, false);
  insert_edge(ig, 2, 4, false);
  insert_edge(ig, 2, 6, false);
  insert_edge(ig, 3, 2, false);
  insert_edge(ig, 6, 5, false);
  insert_edge(ig, 5, 8, false);
  insert_edge(ig, 7, 5, false);

  iterative_bfs(ig, 5);
}
