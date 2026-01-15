#include "../includes/header.h"

static void print_adj(t_graph_matrix *g)
{
  int i;
  int j;

  if(!g || !g->data)
    return;
  i = -1;
  printf("  ");
  while (++i < g->n)
  {
    printf("%i,", i);
  }
  printf("\n");
  i = -1;
  while(++i < g->n)
  {
    j = -1;
    printf("%i,", i);
    while (++j < g->n)
    {
      printf("%d,",g->data[i * g->n + j]);
    }
    printf("\n");
  }
}


int main(void)
{
  t_graph_matrix *g;

  g = gm_create(3);
  if(!g)
    return 1;

  gm_add_edge(g, 0,1);
  gm_add_edge(g, 0,2);
  printf("the adjacent matrix\n");
  print_adj(g);
  gm_destroy(g);
  return 0;
}
