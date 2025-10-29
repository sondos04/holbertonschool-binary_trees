#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling of
 *
 * Return: pointer to the sibling node, or NULL if:
 *         - node is NULL
 *         - node has no parent
 *         - node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* if node is left child, sibling is right child; otherwise left */
	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
