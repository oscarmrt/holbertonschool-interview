#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *header = NULL;

	if (array == NULL)
		return (NULL);

	if (binary_nodes(array, 0, (int)size - 1, &header) == NULL)
		return (NULL);
	return (header);
}
/**
 * binary_nodes - create binary tree
 * @array: pointer to the first element of the array to be converted
 * @p1: initial position
 * @p2: final position
 * @header: pointer to head
 * Return: pointer
 */
avl_t *binary_nodes(int *array, int p1, int p2, avl_t **header)
{
	avl_t *new_node = NULL, *left = NULL, *right = NULL;
	int middle;

	if (p1 > p2)
		return (NULL);

	middle = (p2 + p1) / 2;

	binary_nodes(array, p1, middle - 1, &left);
	binary_nodes(array, middle + 1, p2, &right);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[middle];
	new_node->parent = NULL;
	new_node->left = left;
	new_node->right = right;

	if (left != NULL)
		left->parent = new_node;

	if (right != NULL)
		right->parent = new_node;

	*header = new_node;
	return (new_node);
}
