#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (size);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, 0 if tree is NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 0;
	size_t depth = 0, size = 0, perfectDepth = 1;

	if (!tree)
		return (0);

	depth = tree->left ? 1 + binary_tree_depth(tree->left) : 0;
	size = tree->left ? binary_tree_size(tree->left) : 0;
	perfect = tree->right ? binary_tree_is_perfect(tree->right) : perfect;
	if (perfect == 0)
		perfect = 1;
	if (size != 0 && size == perfectDepth << depth)
		perfect = 1;
	return (perfect);
}
