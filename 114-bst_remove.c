#include "binary_trees.h"
/**
 * min_value - fin d node with minimum value
 * @node: root of bst
 * Return: node with min value
 */
bst_t *min_value(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
	{
		current = current->left;
	}
	return (current);
}
/**
 * bst_remove - remove a node from bst
 * @root: pointer to root
 * @value: value to remove
 * Return: pointer to new node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
	{
		return (NULL);
	}
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
