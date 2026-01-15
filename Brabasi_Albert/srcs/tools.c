#include "../includes/barabasi_Albert.h"

static int *get_cum_deg(t_graph_matrix *g)
{
  int *cum_degr;
  int i;

  cum_degr = malloc(sizeof(int) * g->n);
  if (!cum_degr)
    return NULL;
  i = 0;
  cum_degr[0] = gm_degree(g, 0);
  while (++i < g->n)
    cum_degr[i] = gm_degree(g, i) + cum_degr[i - 1];
  return (cum_degr);
}

int pick_weighted_node(t_graph_matrix *g, int max_index)
{
  int *cum_degr;
  int total;
  int r;
  int i;

  cum_degr = get_cum_deg(g);
  if (!cum_degr)
    return -1;
  total = cum_degr[g->n - 1];
  if (total == 0)
  {
    free(cum_degr);
    return rand_int(0, max_index);
  }
  r = rand_int(1, total);
  i = -1;
  while (++i <= max_index)
  {
    if(cum_degr[i] >= r)
    {
      free(cum_degr);
      return i;
    }
  }
  free(cum_degr);
  return -1;
}

static int core_code(t_graph_matrix *g, int m, int edges_per_node)
{
  int new_node;
  int existing_node;
  int i;
  int j;

  i = -1;
  new_node = 0;
  while (++i < m)
  {
    j = -1;
    while (++j < edges_per_node)
    {
      existing_node = pick_weighted_node(g, new_node - 1);
      while (g->data[new_node * g->n + existing_node] == 1)
        existing_node = pick_weighted_node(g, new_node - 1);
      if (gm_add_edge(g, new_node, existing_node) == -1)
        return -1;
    }
  }
  return 1;
}

t_graph_matrix *add_m_node_to_graph(t_graph_matrix *g, int m,
                                    int edges_per_node)
{
  int new_n;
  t_graph_matrix *new_g;
  int i;
  int j;

  if (!g)
    return NULL;
  new_n = g->n + m;
  new_g = gm_create(new_n);
  if (!new_g)
    return NULL;
  i = -1;
  while (++i < g->n)
  {
    j = -1;
    while(++j < g->n)
    {
      if(g->data[i * g->n + j])
        gm_add_edge(new_g, i,j);
    }
  }
  core_code(new_g, m, edges_per_node);
  gm_destroy(g);

  return (new_g);
}
