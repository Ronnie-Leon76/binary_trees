#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: Pointer to the sibling node, NULL if node is NULL or has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (!node || !node->parent)
		return (NULL);

	sibling = node->parent->left == node ?
		node->parent->right : node->parent->left;
	return (sibling);
}
