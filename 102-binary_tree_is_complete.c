#include "binary_trees.h"
int complete_recursion(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - checks if tree is complete
 * @tree: pointer to root
 * Return: 1 if complete otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (complete_recursion(tree, 0, binary_tree_size(tree)));
}
/**
 * complete_recursion - check if tree is complete
 * @tree: pointer to root
 * @index: index of node
 * @size: size of tree
 * Return: 1 if complete
 */
int complete_recursion(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= size)
	{
		return (0);
	}
	return (complete_recursion(tree->left, 2 * index + 1, size) &&
			complete_recursion(tree->right, 2 * index + 2, size));
}
/**
 * binary_tree_size - checks size of tree
 * @tree: pointer to root
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
