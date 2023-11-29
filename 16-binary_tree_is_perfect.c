#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: pointer to root
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_depth, right_depth;

	if (tree == NULL)
	{
		return (0);
	}
	left_depth = binary_tree_height(tree->left);
	right_depth = binary_tree_height(tree->right);
	if (binary_tree_is_full(tree) && left_depth == right_depth)
	{
		return (1);
	}
	return (0);
}
/**
 * binary_tree_height - checks height of binary tree
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
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return ((left_height > right_height) ? left_height : right_height);
}
/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to root
 * Return: if empty 0 otherwise 1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	if (tree->left != NULL && tree->right != NULL)
	{
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}
	return (0);
}
