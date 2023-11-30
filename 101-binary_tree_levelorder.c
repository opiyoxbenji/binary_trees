#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree);
void print_level(const binary_tree_t *tree, void (*func)(int), int level);
/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 * @tree: pointer to root
 * @func: function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, level;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	height = binary_tree_height(tree);
	for (level = 1; level <= height; level++)
	{
		print_level(tree, func, level);
	}
}
/**
 * binary_tree_height - measures height of binary tree
 * @tree: pointer to root
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}
/**
 * print_level - prints the level of binary t ree
 * @tree: pointer to root
 * @func: function to call
 * @level: level of tree
 */
void print_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
	{
		return;
	}
	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}
