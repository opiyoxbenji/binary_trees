#include "binary_trees.h"
/**
 * bst_search -  searches for a value in a Binary Search Tree
 * @tree: pointer to root
 * @value: val to search
 * Return: pointer to node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
	{
		return (tree);
	}
	if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}
	else
	{
		return (bst_search(tree->right, value));
	}
}
