#include "binary_trees.h"
/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: ointer to root
 * Return: point to new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;
	if (temp != NULL)
	{
		temp->parent = tree;
	}
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (new_root->parent != NULL)
	{
		if (new_root->parent->left == tree)
		{
			new_root->parent->left = new_root;
		}
		else
		{
			new_root->parent->right = new_root;
		}
	}
	return (new_root);
}
