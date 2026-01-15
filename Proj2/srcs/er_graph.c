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

int *get_cum(t_graph_matrix *g)
{
  int *cum_deg;
  cum_deg = malloc(sizeof(int) * g->n);
  if (cum_deg == NULL)
    return NULL;
  int i = 0;
  cum_deg[0] = gm_degree(g, 0);
  while (i < g->n)
  {
    cum_deg[i] = gm_degree(g,i) + cum_deg[i - 1];
    i++;
  }
  return cum_deg;
}

int pick_weighted_node(t_graph_matrix *g, int max_index)
{
  int *cum_deg;
  int r;
  int total;
  int i;

  cum_deg = get_cum(g);
  if (!cum_deg)
    return -1;

  total = cum_deg[g->n - 1];
  if (total == 0)
  {
    free(cum_deg);
    return rand_int(0, max_index);
  }
  r = rand_int(1, total);
  i = -1;
  while (++i <= max_index)
  {
    if (cum_deg[i] >= r)
    {
      free(cum_deg);
      return i;
    }
  }
  free(cum_deg);
  return -1;
}

t_graph_matrix *add_m_node_to_graph(t_graph_matrix *g, int m, int edges_per_node)
{
  int old_n = g->n;
  int new_n = g->n + m;

  t_graph_matrix *new_g = gm_create(new_n);
  if (!new_g)
    return NULL;
  int i = 0;
  int j = 0;
  while (i < old_n)
  {
    j = 0;
    while (j < old_n)
    {
      if(g->data[i * old_n +j])
        gm_add_edge(new_g,i,j);
      j++;
    }
    i++;
  }
  gm_destroy(g);
  i = 0;
  int new_node = 0;
  int exisiting_node;
  while (i < m)
  {
    new_node = old_n + i;
    j = 0;
    while (j < edges_per_node)
    {
      exisiting_node = pick_weighted_node(new_g, new_node - 1);
      while (new_g->data[new_node * new_g->n + exisiting_node] == 1)
        exisiting_node = pick_weighted_node(new_g, new_node -1);
      gm_add_edge(new_g, new_node, exisiting_node);
      j++;
    }
    i++;
  }
  return new_g;
}
int main(int ac, char **av)
{
  if (ac > 2 || ac == 1)
    return 0;
  int n = atoi(av[1]);
  t_graph_matrix *g;
  g = gm_create(n);
  int u = 0;
  int v;
  srand(time(NULL));
  while (u < g->n - 1)
  {
    v = u+1;
    while( v < g->n)
    {
      add_edge_p(g, 0.6, u , v);
      v++;
    }
    u++;
  }
  u = -1;
  while (++u < g->n)
  {
    printf("the node %d, have %d deg\n", u, gm_degree(g,u));
  }
  printf("the adg matrix\n");
  print_adj(g);
  int m = 5;
  int edges_per_node = 2;
  g = add_m_node_to_graph(g,m,edges_per_node);

  u = -1;
  while (++u < g->n)
  {
    printf("the node %d, have %d deg\n", u, gm_degree(g,u));
  }
  printf("the adg matrix\n");
  print_adj(g);

  gm_destroy(g);
  return 0;
}
