#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	int array[2048];
	int x = 0;
	int y = 0;
	int med;

	if (head == NULL || (temp != NULL && temp->next == NULL))
		return (1);
	while (temp != NULL)
	{
		array[x] = temp->n;
		temp = temp->next;
		x++;
	}
	x--, med = x / 2;
	while (x >= med && y <= med)
	{
		if (array[y] != array[x])
			return (0);
		x--, y++;
	}
	return (1);
}
