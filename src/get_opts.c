/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:59:13 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 12:31:47 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	get_opts(char *a, t_directory *d)
{
	(ft_strchr(a, 'l')) ? (d->opt[0] = 1) : 0;
	(ft_strchr(a, 'R')) ? (d->opt[1] = 1) : 0;
	(ft_strchr(a, 'a')) ? (d->opt[2] = 1) : 0;
	(ft_strchr(a, 'r')) ? (d->opt[3] = 1) : 0;
	(ft_strchr(a, 't')) ? (d->opt[4] = 1) : 0;
}

void	print_link(t_directory *d)
{
	char	link_read[255];
	ssize_t bytes_read;

	lstat(d->path, &d->infos);
	if (S_ISLNK(d->infos.st_mode))
	{
		ft_putstr(d->path);
		ft_putstr(" ");
		bytes_read = readlink(d->path, link_read, 254);
		link_read[bytes_read] = '\0';
		ft_putstr("-> ");
		ft_putstr(link_read);
		ft_putchar('\n');
	}
}

void	ft_print_e(t_directory *d, char *temp, char *current, char *name)
{
	if (d->first_result == 1)
	{
		ft_putstr("\n");
		ft_path_creation(d->path, current, name);
		ft_putstr(d->path);
		ft_putstr(":\n");
		if (d->permerror == 1)
			ft_print_permerror(d);
		else
		{
			if (d->permerror == 1)
				ft_print_permerror(d);
		}
		perror(temp);
	}
}
