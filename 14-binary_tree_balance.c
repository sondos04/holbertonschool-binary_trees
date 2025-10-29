#include "binary_trees.h"

/**
 * height_edges - computes the height of a subtree measured in edges
 * @tree: pointer to the root of the subtree
 *
 * Return: height in edges; -1 if tree is NULL (so a leaf has height 0)
 */
static int height_edges(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (-1);

	lh = height_edges(tree->left);
	rh = height_edges(tree->right);

	return ((lh > rh ? lh : rh) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: balance factor (left height - right height). If tree is NULL, 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	lh = height_edges(tree->left);
	rh = height_edges(tree->right);

	return (lh - rh);
}

