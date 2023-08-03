#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the tree
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pvot = tree->left;
	tree->left = pvot->right;
	if (pvot->right != NULL)
	{
		pvot->right->parent = tree;
	}
	pvot->right = tree;
	pvot->parent = tree->parent;
	tree->parent = pvot;
	return (pvot);
}
