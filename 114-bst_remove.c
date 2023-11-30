#include "binary_trees.h"
/**
 * min_value - fin d node with minimum value
 * @root: root of bst
 * Return: node with min value
 */
bst_t *min_value(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}
/**
 * bst_remove - remove a node from bst
 * @root: pointer to root
 * @value: value to remove
 * Return: pointer to new node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor, *node = root, *parent = NULL;

	if (root == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->n == value)
		{	break;
		}
		parent = node;
		if (node->n > value)
			node = node->left;
		else
			node = node->right;
	}
	if (node == NULL)
		return (root);
	if (node->left == NULL)
	{
		if (parent != NULL)
		{
			if (parent->left == node)
				parent->left = node->right;
			else
				parent->right = node->right; }
		else
			root = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node); }
	else if (node->right == NULL)
	{
		if (parent != NULL)
		{
			if (parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
		} else
			root = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
	} else
	{	successor = min_value(node->right);
		node->n = successor->n;
		node->right = bst_remove(node->right, successor->n);
	} return (root);
}
