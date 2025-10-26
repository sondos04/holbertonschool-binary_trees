#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height -  function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left, right;

if (tree == NULL || (tree->left == NULL && tree->right == NULL))
return (0);

left = binary_tree_height(tree->left);
right = binary_tree_height(tree->right);
return ((left>right? left : right) + 1);
}
