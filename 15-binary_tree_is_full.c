#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 if tree is NULL or not full
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (!tree)
		return (0);

	full = tree->left ? binary_tree_is_full(tree->left) : full;
	full += tree->right ? binary_tree_is_full(tree->right) : full;
	if (full == 0)
		full = 1;
	return (full);
}
