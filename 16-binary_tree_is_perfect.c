#include "binary_trees.h"

/**
 * height_edges - measures the height of a binary tree in edges
 * @tree: pointer to the root node
 * Return: height in edges, -1 if tree is NULL
 */
static int height_edges(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (-1);

	left_h = height_edges(tree->left);
	right_h = height_edges(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	/* If leaf node, it's perfect */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If one child missing -> not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	left_h = height_edges(tree->left);
	right_h = height_edges(tree->right);

	/* Both subtrees must be perfect and have equal height */
	if (left_h == right_h)
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));

	return (0);
}
