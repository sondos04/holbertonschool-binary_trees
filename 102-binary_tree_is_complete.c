#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_s - Simple queue for level-order traversal
 * @node: Pointer to the binary tree node
 * @next: Next element in the queue
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * q_push - add a node pointer to the queue
 * @head: pointer to queue head
 * @tail: pointer to queue tail
 * @node: node to push
 * Return: 1 on success, 0 on failure
 */
static int q_push(queue_t **head, queue_t **tail, const binary_tree_t *node)
{
	queue_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->node = node;
	new->next = NULL;

	if (*tail)
		(*tail)->next = new;
	else
		*head = new;
	*tail = new;
	return (1);
}

/**
 * q_pop - remove and return node pointer from queue head
 * @head: pointer to queue head
 * @tail: pointer to queue tail
 * Return: node pointer or NULL
 */
static const binary_tree_t *q_pop(queue_t **head, queue_t **tail)
{
	queue_t *tmp;
	const binary_tree_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	node = tmp->node;
	*head = tmp->next;
	if (!*head)
		*tail = NULL;
	free(tmp);
	return (node);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *h = NULL, *t = NULL;
	const binary_tree_t *cur;
	int seen_null = 0;

	if (!tree)
		return (0);

	if (!q_push(&h, &t, tree))
		return (0);

	while ((cur = q_pop(&h, &t)))
	{
		if (cur->left)
		{
			if (seen_null || !q_push(&h, &t, cur->left))
				return (0);
		}
		else
			seen_null = 1;

		if (cur->right)
		{
			if (seen_null || !q_push(&h, &t, cur->right))
				return (0);
		}
		else
			seen_null = 1;
	}
	return (1);
}
