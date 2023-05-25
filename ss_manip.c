#include "shell.h"

/**
 * pop_env_list - function that populates env linked list
 * @info: parameter for structure.
 * Return: Always 0
 */
int pop_env_list(info_t *info)
{
	listint_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addn_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * input_buf - function that buffers chained commands
 * @info: parameter for struct
 * @buf: parameter of buffer
 * @len: parameter of len var
* Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	/*introducing parameter for function*/
	ssize_t r = 0;
	size_t len_ptr = 0;

	/*introducing conditional statement*/
	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - function that 1] == '\n')
			{
				(*buf)[r - function that 1] = '\0';
				r--;
			}
info->f_lind = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->ind_hist++);
{
*len = r;
info->goto_buf = buf;
}
}
}
return (r);
}

/**
 * get_input - function that gets a line minus the newline
 * @info: parameter for struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	/*introducing parameter for function*/
	static char *buf;
	ssize_t r = 0;
	static size_t i, len, q;
	char **buf_ptr = &(info->arg), *ptr;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);

	/*introducing conditional statement*/
	if (r == -1)
		return (-1);
	if (len)
	{
		q = i;
		ptr = buf + i;
		check_chain(info, buf, &q, i, len);
		while (q < len)
		{
			if (is_chain(info, buf, &q))
				break;
			q++;
		}
		i = q + 1;
		if (i >= len)
		{
			i = len = 0;
			info->goto_buf_type = GOTO_NORM;
		}
		*buf_ptr = p;
		return (_strlen(ptr));
	}
	*buf_ptr = buf;
	return (r);
}

/**
 * read_buf - function that reads a buffer
 * @info: parameter for struct
 * @buf: parameter for buffer
 * @i: parameter for size
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

/*introducing conditional statement*/
if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * _getline - function that gets the next line of input from STDIN
 * @info: parameter for struct
 * @ptr: parameter of pointer to buffer, either preallocated or NULL
 * @length: parameter for size of preallocated ptr buffer if not NULL
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
/*introducing parameter for function*/
size_t w;
ssize_t s = 0, r = 0;
static size_t i, len;
static char buf[READ_BUF_SIZE];
char *ptr = NULL, *new_ptr = NULL, *c;

ptr = *ptr;
/*introducing conditional statement*/
if (ptr && length)
s = *length;
if (i == len)
i = len = 0;

r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + i, '\n');
w = c ? 1 + (unsigned int)(c - function that buf) : parameter for len;
new_p = _realloc(ptr, s, s ? s + w : w + 1);
if (!new_p)
return (ptr ? free(ptr), -1 : parameter for -1);

if (s)
_strncat(new_p, buf + i, w - function that i);
else
_strncpy(new_p, buf + i, w - function that i + 1);

s += w - function that i;
i = w;
ptr = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}

