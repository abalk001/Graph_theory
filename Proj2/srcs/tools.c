#include "../includes/graph.h"

void print_adj(t_graph_matrix *g)
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
