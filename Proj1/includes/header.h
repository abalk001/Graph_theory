#ifndef HEADER_H 
#define HEADER_H 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_graph_matrix
{
  int n;
  int *data;
} t_graph_matrix;

typedef struct s_node 
{
  int v;
  struct s_node *next;
} t_node;

typedef struct s_graoh_list
{
  int n;
  t_node **adj;
} t_graph_list;

t_graph_matrix *gm_create(int n);
void    gm_add_edge(t_graph_matrix *g, int u, int v);
int     gm_has_edge(t_graph_matrix *g, int u, int v);
int     gm_degree(t_graph_matrix *g, int v);
void    gm_destroy(t_graph_matrix *g);

t_graph_list *gl_create(int n);
void gl_add_edge(t_graph_list *g, int u, int v);
int gl_has_edge(t_graph_list *g, int u, int v);
int gl_degree(t_graph_list *g, int v);
void gl_destroy(t_graph_list *g);

t_graph_list *matrix_to_listt(t_graph_matrix *gm);
t_graph_matrix *list_to_matrix(t_graph_list *gl);

#endif 
