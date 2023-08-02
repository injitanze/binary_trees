#include "binary_trees.h"
/**
 * binary_tree_postorder - Print elements of tree using post-order traversal
 * @tree: Tree to go through
 * @func: Function to use
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
