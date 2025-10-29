#include "binary_trees.h"

/**
 * height_edges - Return height of a tree in edges (local helper).
 * @t: Pointer to node.
 *
 * Return: Height in edges (0 for a single node), 0 for NULL.
 */
static size_t height_edges(const binary_tree_t *t)
{
	size_t lh = 0, rh = 0;

	if (!t)
		return (0);

	if (t->left)
		lh = 1 + height_edges(t->left);
	if (t->right)
		rh = 1 + height_edges(t->right);

	return (lh > rh ? lh : rh);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: left-height - right-height. If @tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((int)height_edges(tree->left) - (int)height_edges(tree->right));
}

