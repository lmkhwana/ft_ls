/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:37:31 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 09:37:34 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				ft_print_dir_tree(t_dir_tree *tree, t_directory *d)
{
	if (tree->left)
		ft_print_dir_tree(tree->left, d);
	if (d->opt[2] == 1 || (d->opt[2] == 0 && tree->name[0] != '.'))
	{
		if (d->opt[0] == 1)
		{
			tree->line_list = ft_strnew(1024);
			ft_padding(tree->line_list, tree->long_list, d->max_len);
			ft_putendl(tree->line_list);
			free(tree->line_list);
		}
		else
			ft_putendl(tree->name);
	}
	if (tree->right)
		ft_print_dir_tree(tree->right, d);
}

void				ft_print_dir_tree_rev(t_dir_tree *tree, t_directory *d)
{
	if (tree->right)
		ft_print_dir_tree_rev(tree->right, d);
	if (d->opt[2] == 1 || (d->opt[2] == 0 && tree->name[0] != '.'))
	{
		if (d->opt[0] == 1)
		{
			tree->line_list = ft_strnew(1024);
			ft_padding(tree->line_list, tree->long_list, d->max_len);
			ft_putendl(tree->line_list);
			free(tree->line_list);
		}
		else
			ft_putendl(tree->name);
	}
	if (tree->left)
		ft_print_dir_tree_rev(tree->left, d);
}

void				ft_print_error(t_directory *d, char *current, char *name)
{
	char			*tmp;

	tmp = ft_strnew(ft_strlen(name) + 5);
	ft_strcpy(tmp, "ls: ");
	ft_strcpy(&tmp[ft_strlen(tmp)], name);
	if (errno == 2)
		perror(tmp);
	if (errno == 13)
	{
		ft_print_e(d, tmp, current, name);
	}
	if (d->permerror != 0)
	{
		if (d->first_result == 1)
		{
			ft_putstr("\n");
			ft_path_creation(d->path, current, name);
			ft_putstr(d->path);
			ft_putstr(":\n");
		}
	}
	free(tmp);
}

void				ft_print(t_directory *d, char *current)
{
	int				i;

	i = 0;
	if (d->first_result == 1 || (d->opt[1] == 1 && d->first_result == 1))
	{
		if (!ft_strequ(current, d->very_first))
			ft_putstr("\n");
		ft_putstr(current);
		ft_putstr(":\n");
	}
	d->first_result = 1;
	d->very_first[0] = '\0';
	if (d->opt[0] == 1)
	{
		ft_putstr("total ");
		ft_putnbr(d->blocksize);
		ft_putstr("\n");
	}
	if (d->opt[3] == 0)
		ft_print_dir_tree(d->node, d);
	else
		ft_print_dir_tree_rev(d->node, d);
}
