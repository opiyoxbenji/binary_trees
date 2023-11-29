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

	if (!first || !second)
	{
		return (NULL);
	}
	temp1 = first;
	temp2 = second;
	while (temp1 != temp2)
	{
		temp1 = temp1->parent ? temp1->parent : second;
		temp2 = temp2->parent ? temp2->parent : first;
	}
	return ((binary_tree_t *)temp1);
}
