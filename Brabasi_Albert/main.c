#include "includes/barabasi_Albert.h"


int main(int ac, char **av)
{
  t_graph_matrix *g;
  int n;

  if (ac < 2)
  {
    printf("use ./barabasi_Albert <node>");
    return 1;
  }

  srand((unsigned int)time(NULL)); //random generative

  if (ac == 2)
  {
    n = ft_atoi(av[1]); 

    if (n <= 0)
    {
      printf("Error: Invalid parameters\n");
      return 1;
    }

    printf("\nBarabasi-Albert graph\n");
    g = gm_create(n);
    if (!g)
    {
      printf("Error: Failed to create graph\n");
      return 1;
    }


    gm_add_edge(g, 0,1);
    gm_add_edge(g, 1,3);
    gm_add_edge(g, 1,2);
    gm_add_edge(g, 2,3);

    print_adj(g);
    int *node_deg;
    node_deg = malloc(sizeof(int) * n);
    if (!node_deg)
    {
      gm_destroy(g);
      return -1;
    }
    for (int i = 0; i < n; i++)
      printf("the degre of node %d: %d\n", i,  gm_degree(g,i));
    degree_distribution(g);
    gm_destroy(g);
  }
  
  return 0;
}
