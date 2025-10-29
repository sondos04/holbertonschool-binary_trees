#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree (in edges).
 * @tree: Pointer to the node to measure from.
 *
 * Return: Height (0 for NULL or leaf); uses edges as the unit.
 */
static size_t height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		lh = 1 + height(tree->left);
	if (tree->right != NULL)
		rh = 1 + height(tree->right);

	return (lh > rh ? lh : rh);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The balance factor (left height - right height).
 *         If @tree is NULL, return (0).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)height(tree->left) - (int)height(tree->right));
}
}

