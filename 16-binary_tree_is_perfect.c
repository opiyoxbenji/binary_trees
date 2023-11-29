#include "binary_trees.h"
int perfect_recursion(const binary_tree_t *tree, int depth, int level);
int depth(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: pointer to root
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (perfect_recursion(tree, depth(tree), 0));
}
/**
 * perfect_recursion - helper function to check if perfect
 * @tree: pointer to root
 * @depth: depth of tree
 * @level: level to check
 * Return: 1 if perfect
 */
int perfect_recursion(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (depth == level + 1);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (perfect_recursion(tree->left, depth, level + 1) &&
			perfect_recursion(tree->right, depth, level + 1));
}
/**
 * depth - checks depth of binary tree
 * @tree: pointer to root
 * Return: depth
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}
