/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:30:39 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/04 09:30:39 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	get_read(t_nl *nl, int fd, char **buf)
{
	ft_bzero_gnl(nl->buf, BUFFER_SIZE + 1);
	nl->rd = read(fd, nl->buf, BUFFER_SIZE);
	if (nl->rd <= 0)
		return ;
	buf[fd] = ft_strjoin_gnl(buf[fd], nl->buf);
	if (!buf[fd])
		buf[fd] = ft_str_free_gnl(buf[fd]);
}

static void	buffs_set(t_nl *nl, char **buf, int fd)
{
	nl->buf = ft_str_free_gnl(nl->buf);
	nl->next_line = get_new_line(buf[fd], &nl->nl_pos);
	nl->buf = buf[fd];
	buf[fd] = ft_strjoin_gnl(NULL, buf[fd] + nl->nl_pos);
	if (!buf[fd])
		buf[fd] = ft_str_free_gnl(buf[fd]);
}

char	*get_new_line(char *str, int *position)
{
	size_t	i;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	*position = i;
	if (i == 0)
		return (NULL);
	res = ft_calloc_gnl(i + 1, sizeof(char));
	if (!res)
		return (res = ft_str_free_gnl(res), NULL);
	while (i--)
		res[i] = str[i];
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf[4000];
	t_nl		nl;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4000 || read(fd, &nl.buf, 0) < 0)
		return (buf[fd] = ft_str_free_gnl(buf[fd]), NULL);
	if (!buf[fd])
		buf[fd] = ft_calloc_gnl(1, sizeof(char));
	if (!buf[fd])
		return (buf[fd] = ft_str_free_gnl(buf[fd]), NULL);
	nl.buf = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	while (!nl.buf)
		nl.buf = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	nl.nl_pos = 0;
	while (find_nl(buf[fd]) == 0)
	{
		get_read(&nl, fd, buf);
		if (nl.rd <= 0 || !buf[fd])
			break ;
	}
	if (!buf[fd])
		return (buf[fd] = ft_str_free_gnl(buf[fd]), NULL);
	buffs_set(&nl, buf, fd);
	if (nl.rd == 0)
		buf[fd] = ft_str_free_gnl(buf[fd]);
	return (nl.buf = ft_str_free_gnl(nl.buf), nl.next_line);
}
