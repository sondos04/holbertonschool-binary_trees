#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
		return (NULL);

	a = first;
	while (a)
	{
		b = second;
		while (b)
		{
			if (a == b)
				return ((binary_tree_t *)a);
			b = b->parent;
		}
		a = a->parent;
	}
	return (NULL);
}

