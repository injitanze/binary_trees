#include "binary_trees.h"
/**
 * bst_insert - Insert nodes in order to create a BST tree
 * @tree: Tree to create the BST
 * @value: Value of node to insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temprary;
	binary_tree_t *auxi;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		auxi = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)auxi;
		*tree = new;
	}
	else
	{
		temprary = *tree;
		if (value < temprary->n)
		{
			if (temprary->left)
				new = bst_insert(&temprary->left, value);
			else
			{
				auxi = binary_tree_node((binary_tree_t *)temprary, value);
				new = temprary->left = (bst_t *)auxi;
			}
		}
		else if (value > temprary->n)
		{
			if (temprary->right)
				new = bst_insert(&temprary->right, value);
			else
			{
				auxi = binary_tree_node((binary_tree_t *)temprary, value);
				new = temprary->right = auxi;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
