#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
* @parent: Pointer to the parent node
* @value: Value to put in the new node
*
* Return: Pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *newnode, *tmp;

if (parent == NULL)
return (NULL);

newnode = malloc(sizeof(binary_tree_t));

if (newnode == NULL)
return (NULL);

newnode->n = value;
newnode->parent = parent;
newnode->left = NULL;
newnode->right = NULL;

if (parent->right == NULL)
{
parent->right = newnode;
}
else
{
tmp = parent->right;
parent->right = newnode;
newnode->right = tmp;
tmp->parent = newnode;
}
return (newnode);
}
