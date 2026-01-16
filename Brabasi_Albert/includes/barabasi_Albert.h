#ifndef BARABASI_ALBERT_H
#define BARABASI_ALBERT_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <math.h>


typedef struct s_graph_matrix
{
  int n;
  int *data;
} t_graph_matrix;

// Graph creation and manipulation
int             er_graph(t_graph_matrix *g, int nbr_nodes, double prb);
int             ba_graph(t_graph_matrix *g, int m0, int m);
t_graph_matrix  *gm_create(int n);
int             gm_degree(t_graph_matrix *g, int v);
void            gm_destroy(t_graph_matrix *g);
int             gm_add_edge(t_graph_matrix *g, int v, int u);
int             gm_has_edge(t_graph_matrix *g, int u, int v);

// Utility functions
int	            ft_atoi(const char *str);
void            print_adj(t_graph_matrix *g);
int             rand_int(int min, int max);

// Degree distribution analysis
double          degree_k(int *degree, int n, int k);
int             degree_distribution(t_graph_matrix *g);
#endif
