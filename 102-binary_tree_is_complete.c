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
			if (seen_null)
				return (0);
			if (!q_push(&h, &t, cur->left))
				return (0);
		}
		else
			seen_null = 1;

		if (cur->right)
		{
			/* if we already saw a null left, can't have right child */
			if (seen_null)
				return (0);
			if (!q_push(&h, &t, cur->right))
				return (0);
		}
		else
			seen_null = 1;
	}

	return (1);
}

