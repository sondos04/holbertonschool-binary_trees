#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *root;
root = malloc(sizeof(binary_tree_t));
if (root == NULL)
return (NULL);
root->n = value;
root->parent = parent;
root->left = NULL;
root->right = NULL;
return (root);
}
