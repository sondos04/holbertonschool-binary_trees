#include "binary_trees.h"

/* ------- minimal internal queue (linked list of nodes) ------- */

typedef struct qnode_s
{
	const binary_tree_t *node;
	struct qnode_s *next;
} qnode_t;

static int q_push(qnode_t **head, qnode_t **tail, const binary_tree_t *n)
{
	qnode_t *q = malloc(sizeof(*q));

	if (!q)
		return (0);
	q->node = n;
	q->next = NULL;

	if (*tail)
		(*tail)->next = q;
	else
		*head = q;
	*tail = q;
	return (1);
}

static const binary_tree_t *q_pop(qnode_t **head, qnode_t **tail)
{
	qnode_t *q;
	const binary_tree_t *n;

	if (!head || !*head)
		return (NULL);

	q = *head;
	n = q->node;
	*head = q->next;
	if (!*head)
		*tail = NULL;
	free(q);
	return (n);
}

/* ------- required function ------- */

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	qnode_t *h = NULL, *t = NULL;
	const binary_tree_t *cur;
	int seen_null = 0;

	if (!tree)
		return (0);

	if (!q_push(&h, &t, tree))
		return (0);

	while ((cur = q_pop(&h, &t)))
	{
		/* LEFT child handling */
		if (cur->left)
		{
			if (seen_null)               /* NULL was seen earlier -> not complete */
				return (0);
			if (!q_push(&h, &t, cur->left))
				return (0);
		}
		else
		{
			seen_null = 1;
		}

		/* RIGHT child handling */
		if (cur->right)
		{
			/* If we already saw a missing child before, right child now is illegal */
			if (seen_null)
				return (0);
			if (!q_push(&h, &t, cur->right))
				return (0);
		}
		else
		{
			seen_null = 1;
		}
	}

	/* queue already freed by pops */
	return (1);
}

