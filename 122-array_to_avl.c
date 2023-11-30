#include "binary_trees.h"
/**
 * array_to_avl - vuild an avl from an array
 * @array: pointer to array
 * @size: number of elements
 * Return: pointer to root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array || size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			avl_delete_tree(root);
			return (NULL);
		}
	}
	return (root);
}
