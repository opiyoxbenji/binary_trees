#include "binary_trees.h"
/**
 * array_to_avl - vuild an avl from an array
 * @array: pointer to array
 * @size: number of elements
 * Return: pointer to root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL, *temp;
	size_t i;

	if (!array || size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			while (root != NULL)
			{
				temp = root;
				root = root->parent;
				free(temp);
			}
			return (NULL);
		}
	}
	return (root);
}
