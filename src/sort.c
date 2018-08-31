/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:38:16 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 12:19:37 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_dir_tree	*mall(t_dir_tree *node, char *param)
{
	node = ft_memalloc(sizeof(t_dir_tree));
	node->left = NULL;
	node->right = NULL;
	node->name = ft_strdup(param);
	return (node);
}

t_dir_tree	*ft_make_node(t_directory *d, char *param)
{
	t_dir_tree			*node;

	node = mall(node, param);
	if (S_ISDIR(d->infos.st_mode) &&
		!ft_strequ(node->name, ".") && !ft_strequ(node->name, ".."))
		node->isdir = 'd';
	else
		node->isdir = '0';
	(d->opt[0] == 1) ? node->long_list = ft_list_all(d, param) : 0;
	if (d->opt[4] == 1)
	{
		node->time = d->infos.st_mtime;
		node->nanosec = d->infos.st_mtimespec.tv_nsec;
	}
	if (S_ISREG(d->infos.st_mode || S_ISLNK(d->infos.st_mode)))
		node->print = ft_strdup(node->name);
	if (!d->infos.st_mode)
	{
		node->print = ft_strnew(ft_strlen(param) + 60);
		ft_strcpy(node->print, "ls: ");
		ft_strcpy(&node->print[ft_strlen(node->print)], param);
		ft_strcpy(&node->print[ft_strlen(node->print)],
				": No such file or directory\n");
	}
	return (node);
}

void		ft_sort_by_name(t_dir_tree **root, t_directory *d, char *name)
{
	if (*root == NULL)
	{
		*root = ft_make_node(d, name);
		return ;
	}
	if (ft_strcmp(name, (*root)->name) < 0)
		ft_sort_by_name(&(*root)->left, d, name);
	else
		ft_sort_by_name(&(*root)->right, d, name);
}

void		ft_sort_by_date(t_dir_tree **root, t_directory *d, char *name)
{
	if (*root == NULL)
	{
		*root = ft_make_node(d, name);
		return ;
	}
	if (d->infos.st_mtime > (*root)->time)
		ft_sort_by_date(&(*root)->left, d, name);
	else if (d->infos.st_mtime < (*root)->time)
		ft_sort_by_date(&(*root)->right, d, name);
	else
	{
		if (d->infos.st_mtimespec.tv_nsec > (*root)->nanosec)
			ft_sort_by_date(&(*root)->left, d, name);
		else if (d->infos.st_mtimespec.tv_nsec < (*root)->nanosec)
			ft_sort_by_date(&(*root)->right, d, name);
		else
		{
			if (ft_strcmp(name, (*root)->name) <= 0)
				ft_sort_by_date(&(*root)->left, d, name);
			else
				ft_sort_by_date(&(*root)->right, d, name);
		}
	}
}

int			ft_create_tree(t_directory *d, char *current)
{
	if (!(d->dir = opendir(current)))
		return (-1);
	while ((d->file = readdir(d->dir)) != NULL)
	{
		ft_path_creation(d->path, current, d->file->d_name);
		(lstat(d->path, &d->infos) == 0) ? stat(d->path, &d->infos) : 0;
		if (ft_strstr(d->path, "permerror") && ft_strequ(d->file->d_name, "."))
		{
			if (!(d->dir2 = opendir(d->path)))
			{
				d->permerror = 1;
				return (-1);
			}
			if (closedir(d->dir2) == -1)
				return (-1);
		}
		if (ft_strequ(d->file->d_name, ".") || ft_strequ(d->file->d_name, "..")
				|| d->file->d_name[0] != '.' ||
				(d->file->d_name[0] == '.' && d->opt[2] == 1))
			d->opt[4] == 1 ? ft_sort_by_date(&d->node, d, d->file->d_name) :
				ft_sort_by_name(&d->node, d, d->file->d_name);
	}
	if (closedir(d->dir) == -1 || !d->node)
		return (-1);
	return (0);
}
