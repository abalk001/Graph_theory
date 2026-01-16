#include "../includes/barabasi_Albert.h"

// Build cumulative degree array for preferential attachment
static int *get_cum_deg(t_graph_matrix *g, int max_index)
{
  int *cum_degr;
  int i;
  int deg;

  if (max_index < 0)
    return NULL;
  cum_degr = malloc(sizeof(int) * (max_index + 1));
  if (!cum_degr)
    return NULL;
  i = 0;
  cum_degr[0] = gm_degree(g, 0);
  if (cum_degr[0] == 0)
    cum_degr[0] = 1;
  while (++i <= max_index)
  {
    deg = gm_degree(g, i);
    cum_degr[i] = cum_degr[i - 1] + ((deg > 0) ? deg : 1);
  }
  return (cum_degr);
}

// Pick node with probability proportional to degree
static int pick_weighted_node(t_graph_matrix *g, int max_index)
{
  int *cum_degr;
  int total;
  int r;
  int i;

  if (max_index < 0)
    return -1;
  cum_degr = get_cum_deg(g, max_index);
  if (!cum_degr)
    return -1;
  total = cum_degr[max_index];
  if (total == 0)
  {
    free(cum_degr);
    return rand_int(0, max_index);
  }
  r = rand_int(1, total);
  i = -1;
  while (++i <= max_index)
  {
    if (cum_degr[i] >= r)
    {
      free(cum_degr);
      return i;
    }
  }
  free(cum_degr);
  return max_index;
}

// Create initial complete graph with m0 nodes
static int init_complete_graph(t_graph_matrix *g, int m0)
{
  int i;
  int j;

  if (!g || m0 < 2)
    return -1;
  i = -1;
  while (++i < m0)
  {
    j = i;
    while (++j < m0)
    {
      if (gm_add_edge(g, i, j) == -1)
        return -1;
    }
  }
  return 1;
}

// Add m edges from new_node to existing nodes
static int attach_new_node(t_graph_matrix *g, int new_node, int m)
{
  int target;
  int attempts;
  int j;

  if (!g || new_node >= g->n || new_node < m)
    return -1;
  j = -1;
  while (++j < m)
  {
    attempts = 0;
    target = pick_weighted_node(g, new_node - 1);
    while ((target == new_node || gm_has_edge(g, new_node, target) == 1)
           && attempts < 100)
    {
      target = pick_weighted_node(g, new_node - 1);
      attempts++;
    }
    if (attempts >= 100)
      return -1;
    if (gm_add_edge(g, new_node, target) == -1)
      return -1;
  }
  return 1;
}

// Barabasi-Albert algorithm: m0 initial nodes, m edges per new node
int ba_graph(t_graph_matrix *g, int m0, int m)
{
  int new_node;

  if (!g || m0 < 2 || m < 1 || m > m0 || g->n < m0)
    return -1;
  if (init_complete_graph(g, m0) == -1)
    return -1;
  new_node = m0 - 1;
  while (++new_node < g->n)
  {
    if (attach_new_node(g, new_node, m) == -1)
      return -1;
  }
  return 1;
}
