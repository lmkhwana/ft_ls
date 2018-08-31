/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:37:23 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 11:48:35 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		ft_recurs(t_dir_tree *tree, t_directory *d, char *current)
{
	char	*tmp;

	tmp = ft_strdup(current);
	if (tree->left)
		ft_recurs(tree->left, d, tmp);
	if (tree->isdir == 'd')
	{
		ft_path_creation(d->directory_path, tmp, tree->name);
		if (ft_list(d, d->directory_path) == -1)
			ft_print_error(d, tmp, tree->name);
	}
	if (tree->right)
		ft_recurs(tree->right, d, tmp);
	free(tmp);
	free(tree->name);
	free(tree);
}

void		ft_recurs_rev(t_dir_tree *tree, t_directory *d, char *current)
{
	char	*tmp;

	tmp = ft_strdup(current);
	if (tree->right)
		ft_recurs_rev(tree->right, d, tmp);
	if (tree->isdir == 'd')
	{
		ft_path_creation(d->directory_path, tmp, tree->name);
		if (ft_list(d, d->directory_path) == -1)
			ft_print_error(d, tmp, tree->name);
	}
	if (tree->left)
		ft_recurs_rev(tree->left, d, tmp);
	free(tmp);
	free(tree->name);
	free(tree);
}

int			ft_list(t_directory *d, char *current)
{
	short int	i;

	i = 0;
	while (i < 8)
		d->max_len[i++] = 0;
	d->blocksize = 0;
	d->node = NULL;
	if (ft_create_tree(d, current) == -1)
		return (-1);
	ft_print(d, current);
	if (d->opt[1] == 0)
		ft_free_stuff(d->node);
	else
	{
		if (d->opt[3] == 1)
			ft_recurs_rev(d->node, d, current);
		else
			ft_recurs(d->node, d, current);
	}
	return (0);
}

void		ft_display_dir(t_dir_tree *tree, t_directory *d)
{
	if (tree->left)
		ft_display_dir(tree->left, d);
	if (ft_list(d, tree->name) == -1)
		ft_print_error(d, tree->name, tree->name);
	if (tree->right)
		ft_display_dir(tree->right, d);
}

int			main(int ac, char **av)
{
	t_directory			*d;

	d = NULL;
	d = ft_memalloc(sizeof(t_directory));
	ft_initialize(d);
	ft_check_args(d, ac, av);
	if (d->param)
		ft_display_dir(d->param, d);
	ft_final_free(d);
	return (0);
}
