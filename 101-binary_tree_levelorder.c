#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Tree to go through
 * Return: The height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}
/**
 * binary_tree_depth - Depth of specified node from root
 * @tree: Node to check the depth
 * Return: 0 if root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - Function that makes a linked list from depth level and node
 * @head: Pointer to the head of linked list
 * @tree: Node to store
 * @level: Depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *auxi;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		auxi = *head;
		while (auxi->next != NULL)
		{
			auxi = auxi->next;
		}
		new->next = NULL;
		auxi->next = new;
	}
}
/**
 * recursion - Goes through the complete tree and stores each node
 * in linked_node function
 * @head: Pointer to head of linked list
 * @tree: Node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - Print the nodes element in a lever-order
 * @tree: Root node
 * @func: Function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *auxi;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			auxi = head;
			while (auxi != NULL)
			{
				if (count == auxi->n)
				{
					func(auxi->node->n);
				}
				auxi = auxi->next;
			}
			count++;
		}
		while (head != NULL)
		{
			auxi = head;
			head = head->next;
			free(auxi);
		}
	}
}
