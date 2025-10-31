#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_s - singly linked queue node for level-order traversal
 * @node: pointer to a tree node
 * @next: next queue element
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * q_push - push a tree node pointer at queue tail
 * @head: address of queue head
 * @tail: address of queue tail
 * @n:    tree node to push
 *
 * Return: 1 on success, 0 on malloc failure
 */
static int q_push(queue_t **head, queue_t **tail, const binary_tree_t *n)
{
	queue_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);

	new->node = n;
	new->next = NULL;

	if (*tail)
		(*tail)->next = new;
	else
		*head = new;

	*tail = new;
	return (1);
}

/**
 * q_pop - pop a tree node pointer from queue head
 * @head: address of queue head
 * @tail: address of queue tail (may change if queue becomes empty)
 *
 * Return: pointer to tree node, or NULL
 */
static const binary_tree_t *q_pop(queue_t **head, queue_t **tail)
{
	queue_t *old;
	const binary_tree_t *n;

	if (!head || !*head)
		return (NULL);

	old = *head;
	n = old->node;
	*head = old->next;
	if (!*head)
		*tail = NULL;
	free(old);
	return (n);
}

/**
 * binary_tree_levelorder - traverse a binary tree using level-order
 * @tree: pointer to the root node
 * @func: function to call for each node (given node->n)
 *
 * If @tree or @func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *h = NULL, *t = NULL;
	const binary_tree_t *cur;

	if (!tree || !func)
		return;

	if (!q_push(&h, &t, tree))
		return;

	while ((cur = q_pop(&h, &t)) != NULL)
	{
		func(cur->n);
		if (cur->left && !q_push(&h, &t, cur->left))
			break;
		if (cur->right && !q_push(&h, &t, cur->right))
			break;
	}

	/* drain queue if we broke early due to malloc failure */
	while ((cur = q_pop(&h, &t)) != NULL)
		;
}
