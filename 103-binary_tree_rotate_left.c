#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the tree
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pvot = tree->right;
	tree->right = pvot->left;
	if (pvot->left != NULL)
	{
		pvot->left->parent = tree;
	}
	pvot->left = tree;
	pvot->parent = tree->parent;
	tree->parent = pvot;
	return (pvot);
}
