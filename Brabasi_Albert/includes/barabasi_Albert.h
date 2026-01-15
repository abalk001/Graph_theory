#ifndef BARABASI_ALBERT_H
#define BARABASI_ALBERT_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>


typedef struct s_graph_matrix
{
  int n;
  int *data;
} t_graph_matrix;

int             er_graph(t_graph_matrix *g, int nbr_nodes, double prb);
t_graph_matrix  *gm_create(int n);
int             gm_degree(t_graph_matrix *g, int v);
void            gm_destroy(t_graph_matrix *g);
int             gm_add_edge(t_graph_matrix *g, int v, int u);
int	            ft_atoi(const char *str);
int             gm_has_edge(t_graph_matrix *g, int u, int v);
void            print_adj(t_graph_matrix *g);
int             rand_int(int min, int max);

#endif
