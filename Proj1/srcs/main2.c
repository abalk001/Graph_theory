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
  t_graph_matrix *gm;
  int i;

  gm = gm_create(3); 
  gm_add_edge(gm, 0,1);
  gm_add_edge(gm, 0,2);
  gm_add_edge(gm, 1,2);

  printf("adjacent matrix\n");
  print_adj(gm);

  printf("\n Node degree (matrix);\n");
  i = -1;
  while (++i < gm-> n)
    printf("Node %d; %d\n", i, gm_degree(gm,i));

  gm_destroy(gm);
  return 0;
}
