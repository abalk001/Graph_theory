#include "includes/barabasi_Albert.h"

int main(int ac, char **av)
{
  int node;

  node = ft_atoi(av[1]);
  if (ac != 2 && (node <= 0))
    return (perror("Put an interger sup to 0\n"), -1);
  t_graph_matrix *g;

  g = gm_create(node);
  if (!g)
    return -1;

  srand((unsigned int)time(NULL));
  if (er_graph(g, node, 0.6) != 1)
  {
    gm_destroy(g);
    return 1;
  }
  print_adj(g);
  gm_destroy(g);
  return 0;
}
