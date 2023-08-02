#include "binary_trees.h"
/**
 * binary_tree_preorder - Print elements of tree using pre-order traversal
 * @tree: Tree to go through
 * @func: Function to use
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
