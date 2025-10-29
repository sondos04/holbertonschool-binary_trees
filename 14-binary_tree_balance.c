#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor (left height - right height).
 *         If @tree is NULL, return (0).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		lh = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		rh = 1 + binary_tree_height(tree->right);

	return ((int)(lh - rh));
}

