#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_cnt, right_cnt, self;

	if (tree == NULL)
		return (0);

	/* this node counts if it has at least one child */
	self = (tree->left != NULL || tree->right != NULL) ? 1 : 0;

	left_cnt = binary_tree_nodes(tree->left);
	right_cnt = binary_tree_nodes(tree->right);

	return (self + left_cnt + right_cnt);
}
