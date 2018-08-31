/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:37:40 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 09:37:42 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_path_creation(char *path, char *first, char *second)
{
	ft_strcpy(path, first);
	if (!ft_strequ(first, "/"))
		ft_strcpy(&path[ft_strlen(path)], "/");
	ft_strcpy(&path[ft_strlen(path)], second);
}

void				ft_free_stuff(t_dir_tree *node)
{
	if (!node)
		return ;
	if (node->left)
		ft_free_stuff(node->left);
	if (node->right)
		ft_free_stuff(node->right);
	free(node->name);
	node->name = NULL;
	free(node);
	node = NULL;
}

void				ft_initialize(t_directory *d)
{
	d->max_len = ft_memalloc(sizeof(int) * 8);
	d->opt = ft_memalloc(sizeof(int) * 5);
	d->path = ft_strnew(PATH_MAX);
	d->directory_path = ft_strnew(PATH_MAX);
	d->permerror = 0;
	d->first_result = 0;
	d->bad_param = NULL;
	d->file_param = NULL;
	d->param = NULL;
}

void				ft_final_free(t_directory *d)
{
	free(d->very_first);
	free(d->name_dir);
	free(d->wrong_dir);
	free(d->no_dir);
	free(d->path);
	free(d->directory_path);
	free(d->file);
	free(d->max_len);
	free(d->opt);
	free(d);
}

void				ft_print_permerror(t_directory *d)
{
	if (d->opt[2] == 1)
		ft_putstr_fd(
				"ls: .: Permission denied\nls: ..: Permission denied\n", 2);
	ft_putstr_fd("ls: : Permission denied\n", 2);
	d->permerror = 0;
}
