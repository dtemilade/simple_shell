#inlcude "shell.h"

/**
 * list_len - function that determines length of linked list
 * @h: parameter for pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	/*introducing parameter for function*/
	size_t i = 0;

	/*introducing condtional function*/
	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - function that returns an array of strings of the list->str
 * @head: parameter for pointer to first node
* Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	/*introducing parameter for function*/
	char *str;
	list_t *node = head;
	char **strs;
	size_t i = list_len(head), q;

	/*introducing conditional statement*/
	if (!i || !head)
	return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
	return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (q = 0; q < i; q++)
				free(strs[q]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - function that prints all elements of a list_t linked list
 * @h: parameter for pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(': parameter for');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - function that returns node whose string starts with prefix
 * @node: parameter for pointer to list head
 * @prefix: parameter for string to match
 * @c: parameter for the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *ptrrefix, char c)
{
	char *ptr = NULL;

	/*introducing conditional statement*/
	while (node)
	{
		ptr = starts_with(node->str, prefix);
		if (ptr && ((c == -1) || (*ptr == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getn_index - function that gets the index of a node
 * @head: parameter for pointer to list head
 * @node: parameter for pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t getn_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
