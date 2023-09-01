#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle node, NULL if node is NULL or has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	uncle = node->parent->parent->left == node->parent ?
		node->parent->parent->right : node->parent->parent->left;
	return (uncle);
}
