#include "./graphs.h"

int main(void)
{
  int d_vertices = 9;
  int un_vertices = 9;
  int iter_verticies = 9;

  printf("\n\nDFS with adjacency list (recursive) UnDirected Graph with %d vertices:\n", d_vertices);

  UndirectedGraph *g = un_graph_create(un_vertices);

  un_graph_add_edge(g, 0, 1); //
  un_graph_add_edge(g, 1, 2); //
  un_graph_add_edge(g, 1, 7); //
  un_graph_add_edge(g, 2, 3); //
  un_graph_add_edge(g, 3, 4); //
  un_graph_add_edge(g, 3, 5); //
  un_graph_add_edge(g, 3, 7); //
  un_graph_add_edge(g, 4, 5); //
  un_graph_add_edge(g, 5, 6); //
  un_graph_add_edge(g, 6, 7); //
  un_graph_add_edge(g, 6, 8); //
  un_graph_add_edge(g, 7, 8); //

  un_dfs(g);

  printf("\n\nDFS with adjacency list (recursive) Directed Graph with %d vertices:\n", d_vertices);

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

  printf("\n\nDFS with adjacency list (iterative with stack) with %d vertices:\n", iter_verticies);

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

  iterative_dfs(ig, 5);

  printf("\n\nDFS with adjacency matrix (recursive) with %d vertices:\n", iter_verticies);

  struct MatrixGraph *mg = matrix_graph_create(7, 7);

  matrix_insert_edge(0, 1, mg);
  matrix_insert_edge(0, 2, mg);
  matrix_insert_edge(1, 3, mg);
  matrix_insert_edge(1, 4, mg);
  matrix_insert_edge(1, 5, mg);
  matrix_insert_edge(1, 6, mg);
  matrix_insert_edge(6, 2, mg);

  matrix_dfs(0, mg);

  printf("\n\nDFS with adjacency matrix (iterative) with %d vertices:\n", iter_verticies);

  struct MatrixGraph *img = matrix_graph_create(7, 7);

  matrix_insert_edge(0, 1, img);
  matrix_insert_edge(0, 2, img);
  matrix_insert_edge(1, 3, img);
  matrix_insert_edge(1, 4, img);
  matrix_insert_edge(1, 5, img);
  matrix_insert_edge(1, 6, img);
  matrix_insert_edge(6, 2, img);

  iterative_matrix_dfs(0, img);

  printf("\n\nBFS with adjacency list\n");

  graph *bfsg = malloc(sizeof(graph));
  initialize_graph(bfsg, true);

  insert_edge(bfsg, 0, 1, true);
  insert_edge(bfsg, 1, 2, true);
  insert_edge(bfsg, 1, 7, true);
  insert_edge(bfsg, 2, 3, true);
  insert_edge(bfsg, 3, 4, true);
  insert_edge(bfsg, 3, 5, true);
  insert_edge(bfsg, 3, 7, true);
  insert_edge(bfsg, 4, 5, true);
  insert_edge(bfsg, 5, 6, true);
  insert_edge(bfsg, 6, 7, true);
  insert_edge(bfsg, 6, 8, true);
  insert_edge(bfsg, 7, 8, true);

  bfs(bfsg);

  printf("\n\nBFS with adjacency matrix\n");
  // todo
}
