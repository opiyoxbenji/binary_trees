#include "binary_trees.h"
/**
 * check_bst - check if tree is a valid BST
 * @tree: pointer to root
 * @prev: pointer to prev node
 * Return: 1 if BST, otherwise 0
 */
int check_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (!check_bst(tree->left, prev))
	{
		return (0);
	}
	if (tree->n <= *prev)
	{
		return (0);
	}
	*prev = tree->n;
	return (check_bst(tree->right, prev));
}
/**
 * binary_tree_is_bst - checks if a valid BST
 * @tree: pointer to root
 * Return: 1 if bst otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (tree == NULL)
	{
		return (0);
	}
	return (check_bst(tree, &prev));
}
