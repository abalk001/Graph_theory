#ifndef GRAPH_H
#define GRAPH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct s_graph_matrix
{
  int n;
  int *data;
} t_graph_matrix;


t_graph_matrix *gm_create(int n);
void    gm_add_edge(t_graph_matrix *g, int u, int v);
int     gm_has_edge(t_graph_matrix *g, int u, int v);
int     gm_degree(t_graph_matrix *g, int v);
void    gm_destroy(t_graph_matrix *g);


void print_adj(t_graph_matrix *g);
int rand_int(int min, int max);
#endif

