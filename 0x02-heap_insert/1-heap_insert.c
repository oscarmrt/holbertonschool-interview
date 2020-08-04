#include "binary_trees.h"

/**
 * binary_tree_length - function that return the size of a tree
 * @tree: tree to check its size
 * Return: size of tree or 0 if NULL
 */
size_t binary_tree_length(const binary_tree_t *tree)
{
	size_t size = 0;
	size_t rt = 0;
	size_t lt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		lt = binary_tree_length(tree->left);
		rt = binary_tree_length(tree->right);
		size = rt + lt + 1;
	}
	return (size);
}

/**
 * node_insert_order - Inserts node level ordered
 * @tree: pointer of the parent node
 * @value: value inserted into node
 * @idx: index of the node
 * @nLeaf: node array position (parent formula: idx / 2)
 * Return: Node inserted or NULL if tree is NULL
 */
heap_t *node_insert_order(binary_tree_t *tree, int value, int idx, int nLeaf)
{
	heap_t *new_node;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (idx + 1 == nLeaf / 2)
	{
		if (nLeaf & 1)
		{
			tree->right = binary_tree_node(tree, value);
			return (tree->right);
		}
		else
		{
			tree->left = binary_tree_node(tree, value);
			return (tree->left);
		}
	}
	new_node = node_insert_order(tree->left, value, 2 * idx + 1, nLeaf);
	if (new_node != 0)
	{
		return (new_node);
	}
	else
	{
		return (node_insert_order(tree->right, value, 2 * idx + 2, nLeaf));
	}
}

/**
 * heap_insert - entry point
 * @root: double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 *
 * Description: Function that inserts a value into a Max Binary Heap
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = node_insert_order(*root, value, 0, binary_tree_length(*root) + 1);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}
