#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_is_leaf - Check if the function is leaf or not
* @node:  pointer to the node to chec
*
* Return: 1 if it is leaf, or 0 otherwise
**/
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->left == NULL && node->right == NULL)
return (1);
else
return (0);
}
