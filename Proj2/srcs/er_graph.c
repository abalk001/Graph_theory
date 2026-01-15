#include "../includes/graph.h"
// ER random graph generator

void add_edge_p(t_graph_matrix *g, double p, int u, int v)
{
  if (!g || p <= 0 || p > 1)
    return;
  double rand_num = (double)rand() / (double)RAND_MAX;
  if (rand_num < p)
    gm_add_edge(g, u, v);
}

int main(int ac, char **av)
{
  if (ac > 2 )
    return 0;
  int n = atoi(av[1]);
  t_graph_matrix *g;
  g = gm_create(n);
  int u = 0;
  int v;
  srand(time(NULL));
  while (u < g->n - 1)
  {
    printf("u,\n")
    v = u+1;
    while( v < g->n - 1)
    {
      add_edge_p(g, 0.99, u , v);
      v++;
    }
    u++;
  }
  printf("the adg matrix\n");
  print_adj(g);
  gm_destroy(g);
  return 0;
}
