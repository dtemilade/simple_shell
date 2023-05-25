#include "shell.h"

/**
 * add_node - function that adds a node to the start of the list
 * @head: parameter of pointer to head node
 * @str: parameter for str field of node
 * @num: parameter for node index used by history
 *
 * Return: size of list
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new;

	/*introducing conditional statement*/
	if (!head)
	return (NULL);
	new = malloc(sizeof(list_t));
	if (!new)
	return (NULL);
	_memset((void *)new, 0, sizeof(list_t));
	new->num = num;
	if (str)
	{
		new->str = _strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * addn_end - function that adds a node to the end of the list
 * @head: parameter of pointer to head node
 * @str: parameter for str field of node
 * @num: parameter for node index used by history
* Return: size of list
 */
list_t *addn_end(list_t **head, const char *str, int num)
{
	list_t *new, *node;

	if (!head)
	return (NULL);

	node = *head;
	new = malloc(sizeof(list_t));
	if (!new)
	return (NULL);
	_memset((void *)new, 0, sizeof(list_t));
	new->num = num;
	if (str)
	{
		new->str = _strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*head = new;
	return (new);
}

/**
 * print_list_str - function that prints only the str element of a list_t linked
 * @h: parameter for pointer to first node
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	i++;
}
return (i);
}

/**
 * deleten_at_index - function that deletes node at given index
 * @head: parameter of pointer to first node
 * @index: parameter for index of node to delete
* Return: 1 on success, 0 on failure
 */
int deleten_at_index(list_t **head, unsigned int index)
{
	/*introducing parameter for function*/
	list_t *prev_node, *node;
	unsigned int i = 0;

	/*introducing conditional statement*/
	if (!*head || !head)
	return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - function that frees all nodes of a list
 * @head_ptr: parameter of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	/*introducing parameter for function*/
	list_t *node, *n, *head;

	/*introducing conditional statement*/
	if (!*head_ptr || !head_ptr)
	return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		n = node->next;
		free(node->str);
		free(node);
		node = n;
	}
	*head_ptr = NULL;
}
