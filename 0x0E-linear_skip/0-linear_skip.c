#include "search.h"


/**
 * linear_skip - function that searches for a value in a
 * sorted skip list of integer
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *slw = NULL, *fst = NULL;

	if (!list)
		return (NULL);
	slw = list;
	fst = list->express;
	while (fst)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       fst->index, fst->n);
		if (fst->n >= value)
			break;
		slw = fst;
		if (fst->express == NULL)
		{
			while (fst->next)
				fst = fst->next;
			break;
		}
		fst = fst->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       slw->index, fst->index);
	while (slw && slw->index <= fst->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       slw->index, slw->n);
		if (slw->n == value)
			return (slw);
		slw = slw->next;
	}
	return (NULL);
}
