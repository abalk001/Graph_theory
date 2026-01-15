#include "../includes/barabasi_Albert.h"


static int add_edge_p(t_graph_matrix *g, double p, int u, int v)
{
  if (!g || p <= 0.0 || p > 1.0)
    return -1;
  double rand_num = (double)rand() / (double)RAND_MAX;
  if (rand_num < p)
  {
      gm_add_edge(g, u, v);
  }
  return 1;
}

int er_graph(t_graph_matrix *g, int nbr_nodes, double prb)
{
  if (!g || nbr_nodes <= 0 || prb <= 0.0 || prb > 1.)
    return -1;
  int u;
  int v;

  u = 0;
  while (u < g->n - 1)
  {
    v = u + 1;
    while (v < g->n)
    {
      if(add_edge_p(g, prb, u, v) == -1)
        return -1;
      v++;
    }
    u++;
  }
  return 1;
}
