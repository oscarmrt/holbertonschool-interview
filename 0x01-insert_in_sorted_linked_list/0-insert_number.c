#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: Given number to insert in the list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
		listint_t *prov;
		listint_t *hcp;

		hcp = *head;

		prov = malloc(sizeof(listint_t));
		if (prov == NULL)
			return (NULL);

		prov->n = number;
		prov->next = NULL;

		if (*head == NULL)
			*head = prov;
		else
		{
			while (hcp->next != NULL)
			{
				if (hcp->next->n >= prov->n)
					break;
				hcp = hcp->next;
			}
			if (hcp->n > prov->n)
			{
				prov->next = hcp;
				*head = prov;
				return (prov);
			}
			prov->next = hcp->next;
			hcp->next = prov;
		}
		return (prov);
}
