#include "../includes/barabasi_Albert.h"

// Compute degree distribution 
double degree_k(int *degree, int n, int k)
{
  int count = 0;

  if (!degree || n<= 0 || k < 0)
    return -1;
  for (int i = 0; i < n; i++)
  {
    if (degree[i] == k)
      count++;
  }
  return  ((double)count / (double)n);
}

int degree_distribution(t_graph_matrix *g)
{
  int *node_degree = malloc(sizeof(int) * g->n);
  
  if (node_degree == NULL)
    return -1;

  for (int i = 0; i < g->n; i++)
    node_degree[i] = gm_degree(g,i);
  for (int i = 0; i < g->n; i++)
    printf("p(k_%i) : %.2f\n", i, degree_k(node_degree, g->n, i));

  free(node_degree);
  return 0;
}


