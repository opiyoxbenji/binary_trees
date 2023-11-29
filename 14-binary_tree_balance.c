#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to root node
 * Return: balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
/**
 * binary_tree_height - checks the height of a binary tree
 * @tree: pointer to root
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((left_height > right_height) ? left_height : right_height);
}
