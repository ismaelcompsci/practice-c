#include "../stack/stack.h"
#include "../queue/queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef PROJECT_GRAPHS_H
#define PROJECT_GRAPHS_H

/* ------------------------------------- Recursive Undirected Graph ---------------------------------- */
typedef struct
{
  int v;
  int e;

  struct neighbors
  {
    int length;
    int capacity;
    int list[];
  } *adjacencylist[];

} UndirectedGraph;

UndirectedGraph *un_graph_create(int v);

void un_graph_add_edge(UndirectedGraph *g, int src, int dst);

void _append_edge(UndirectedGraph *g, int src, int dst);

void un_dfs(UndirectedGraph *g);

void un_dfs_util(UndirectedGraph *g, int visited[], int vertex);

/* ------------------------------------- Recursive Directed Graph ---------------------------------- */

typedef struct
{
  int v;
  int e;

  struct targets
  {
    int length;
    int capacity;
    int list[];
  } *adjacencylist[];

} DirectedGraph;

DirectedGraph *graph_create(int v);

void graph_add_edge(DirectedGraph *g, int src, int dst);

void dfs_util(DirectedGraph *g, int visited[], int vertex);

void dfs(DirectedGraph *g);

/* ------------------------------------- Iterative Un/Directed Graph ---------------------------------- */

#define MAXV 1000

typedef struct edgenode
{
  int y;                 /* Adjacency info */
  int weight;            /* edge weigth, if any */
  struct edgenode *next; /* next edge in list */
} edgenode;

typedef struct
{
  edgenode *edges[MAXV + 1]; /* adjacency info REQUIRED */
  int degree[MAXV + 1];      /* outdegree of each vertext */
  int nvertices;             /* number of vertices in the graph */
  int nedges;                /* number of edges in the graph REQUIRED  */
  int directed;              /* is the graph directed */
} graph;

void initialize_graph(graph *g, bool directed);
void initialize_dfs(graph *g);
void insert_edge(graph *g, int x, int y, bool directed);
void iterative_dfs(graph *g, int start);

void process_vertex_early(int v);
void process_edge(int v, int y);
void process_vertex_late(int v);

struct MatrixGraph
{
  int v;
  int e;
  int **adj;
};

struct MatrixGraph *matrix_graph_create(int v, int e);

void matrix_insert_edge(int x, int y, struct MatrixGraph *g);
void matrix_dfs(int start, struct MatrixGraph *g);
void matrix_dfs_util(int start, struct MatrixGraph *g);

void iterative_matrix_dfs(int start, struct MatrixGraph *g);

void bfs(graph *g);
void bfs_util(graph *g, int start);

#endif
