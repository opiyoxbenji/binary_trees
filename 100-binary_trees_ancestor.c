#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp1, *temp2;
	size_t depth1, depth2;

	if (!first || !second)
	{
		return (NULL);
	}
	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);
	temp1 = first;
	temp2 = second;
	while (depth1 > depth2)
	{
		temp1 = temp1->parent;
		depth1--;
	}
	while (depth2 > depth1)
	{
		temp2 = temp2->parent;
		depth2--;
	}
	while (temp1 && temp2)
	{
		if (temp1 == temp2)
		{
			return ((binary_tree_t *)temp1);
		}
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}
	return (NULL);
}
/**
 * binary_tree_depth - measures depth of node
 * @tree: pointer to root
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
