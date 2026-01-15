#include "../includes/barabasi_Albert.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int rand_int(int min, int max)
{
  int value;
  value = min + rand() % (max - min + 1);
  return value;
}
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
