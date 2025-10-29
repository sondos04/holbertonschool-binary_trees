#include "binary_trees.h"

/* Helper: height in number of nodes on the longest path */
static size_t height(const binary_tree_t *tree)
{
    size_t hl, hr;

    if (tree == NULL)
        return 0;

    hl = height(tree->left);
    hr = height(tree->right);
    return (hl >= hr ? hl : hr) + 1;
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor (left height - right height),
 *         or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return (int)height(tree->left) - (int)height(tree->right);
}
