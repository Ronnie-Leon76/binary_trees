#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 * Return: Number of leaves in the tree, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	leaves = tree->left ? binary_tree_leaves(tree->left) : leaves;
	leaves += tree->right ? binary_tree_leaves(tree->right) : leaves;
	return (leaves ? leaves : 1);
}
