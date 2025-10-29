#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 *         If @tree is NULL, return 0
 *
 * A full binary tree is a tree where every node has either
 * 0 children or 2 children (no node with only one child).
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Leaf node is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If exactly one child is missing -> not full */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Both children exist -> both subtrees must be full */
	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}
