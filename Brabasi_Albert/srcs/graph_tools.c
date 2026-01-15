#include "../includes/barabasi_Albert.h"

t_graph_matrix *gm_create(int n)
{
  int i = -1;

  if (n <= 0)
    return NULL;
  t_graph_matrix *graph;
  graph = malloc(sizeof(t_graph_matrix));
  if (graph == NULL)
    return NULL;
  // A[i][j] = data[i * n + j]
  graph->data = malloc(sizeof(int) * n*n);
  if (graph->data == NULL)
  {
    free(graph);
    return NULL;
  }
  while (++i < n*n) // initialise the graph data to zero;
    graph->data[i] = 0;
  graph->n = n;
  return graph;
}

int gm_add_edge(t_graph_matrix *g, int u, int v)
{
  if(!g || u < 0 || v < 0
      || u >= g->n || v >= g->n)
    return -1;
  g->data[u * g->n + v] = 1;
  g->data[v * g->n + u] = 1;
  return 1;
}

void gm_destroy(t_graph_matrix *g)
{
  free(g->data);
  g->n = 0;
  free(g);
}

int gm_has_edge(t_graph_matrix *g, int u, int v)
{
  if(!g || u < 0 || v < 0
      || u >= g->n || v >= g->n)
    return -1;
  if (g->data[u * g->n + v] == 1)
    return 1;
  else 
    return 0;
}

int gm_degree(t_graph_matrix *g, int v) // nbr of edge connected to v
{
  if(!g  || v < 0 || v >= g->n)
    return -1;
  int deg = 0;
  int i = -1;
  while (++i < g->n)
  {
    if (g->data[v * g->n + i] != 0)
      deg++;
  }
  return deg;
}
