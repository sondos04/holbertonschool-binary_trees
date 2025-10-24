#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
#endif
