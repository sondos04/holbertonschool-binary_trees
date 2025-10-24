#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a node as the left-child of another node
* @parent: Pointer to the parent node
* @value: Value to put in the new node
*
* Return: Pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

if (parent->left == NULL)
{
parent->left = newnode;
}
else
{
tmp = parent->left;
parent->left = newnode;
newnode->left = tmp;
tmp->parent = newnode;
}
return (newnode);
}
