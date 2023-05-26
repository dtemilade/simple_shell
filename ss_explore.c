#include "shell.h"

/**
 * get_history_file - function that gets the history file
 * @info: parameter for struct
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	/*introducing parameter for function*/
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	/*introducing conditional statement*/
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * ((_strlen(dir)) + ((_strlen(HIST_FILE)) + 2)));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * create_history - function that creates a file, or appends to a file
 * @info: parameter for the parameter struct
 * Return: 1 on success, else -1
 */
int create_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
	return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * view_history - function that reads history from file
 * @info: parameter for the parameter struct
 * Return: ind_hist on success, 0 otherwise
 */
int view_history(info_t *info)
{
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);
	int i, var_c, last;
	ssize_t fd, var_s = 0, var_len;

	var_c = 0;
	last = 0;
	if (!filename)
	return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		var_s = st.st_size;
	if (var_s < 2)
		return (0);
	buf = malloc(sizeof(char) * (var_s + 1));
	if (!buf)
		return (0);
	var_len = read(fd, buf, var_s);
	buf[var_s] = 0;
	if (var_len <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < var_s; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, var_c++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, var_c++);
	free(buf);
	info->ind_hist = var_c;
	while (info->ind_hist-- >= HIST_MAX)
		deleten_at_index(&(info->history), 0);
	hist_num(info);
	return (info->ind_hist);
}
/**
 * build_history_list - function that adds entry to a history linked list
 * @info: parameter for structure.
 * @buf: parameter for buffer
 * @var_c: parameter for the history var_c, ind_hist
* Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int var_c)
{
	list_t *node = NULL;

	if (info->history)
	node = info->history;
	addn_end(&node, buf, var_c);

	if (!info->history)
	info->history = node;
	return (0);
}

/**
 * hist_num - function that renumbers the history linked list after changes
 * @info: parameter for structure.
 * Return: the new ind_hist
 */
int hist_num(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->ind_hist = i);
}
