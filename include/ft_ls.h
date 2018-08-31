/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:36:40 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/08/31 12:31:07 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>

typedef struct			s_dir_tree
{
	struct s_dir_tree	*left;
	struct s_dir_tree	*right;

	char				**long_list;
	char				*line_list;
	unsigned int		time;
	long				nanosec;
	char				*name;
	char				*link;
	char				*print;
	char				isdir;

}						t_dir_tree;

typedef struct			s_directory
{
	char				**name_dir;
	char				**wrong_dir;
	char				**no_dir;
	int					*opt;
	int					*max_len;

	char				*path;
	char				*directory_path;
	void				*dir;
	void				*dir2;
	int					permerror;
	struct dirent		*file;
	struct stat			infos;
	struct stat			tmp_infos;
	struct passwd		*user;
	struct group		*group;
	time_t				*tloc;
	blkcnt_t			blocksize;

	int					first_result;
	t_dir_tree			*node;
	t_dir_tree			*bad_param;
	t_dir_tree			*file_param;
	t_dir_tree			*param;
	char				*very_first;

}						t_directory;

void					ft_free_stuff(t_dir_tree *node);
void					ft_path_creation(char *path, char *first, char *second);
void					ft_initialize(t_directory *d);
void					ft_final_free(t_directory *d);
void					ft_print_permerror(t_directory *d);

char					*ft_format(char *line_l, char **long_l, int *max);
void					ft_padding(char *line_l, char **long_l, int *max);

void					ft_illegal_option(t_directory *d, char *option);
void					ft_sort_param(t_directory *d, char **av, int i);
void					ft_print_param(t_directory *d, t_dir_tree *tree);
void					ft_check_args(t_directory *d, int ac, char **av);

void					ft_recurs(t_dir_tree *tree, t_directory *d,
		char *current);
void					ft_recurs_rev(t_dir_tree *tree, t_directory *d,
		char *current);
int						ft_list(t_directory *d, char *current);
void					ft_display_dir(t_dir_tree *tree, t_directory *d);
int						main(int ac, char **av);

char					*ft_permissions(t_directory *d);
char					*ft_time(t_directory *d);
char					*ft_devices(t_directory *d);
void					ft_count_len(t_directory *d, char **long_l);
char					**ft_list_all(t_directory *d, char *param);
void					get_opts(char *a, t_directory *d);
void					ft_print_dir_tree(t_dir_tree *tree, t_directory *d);
void					ft_print_dir_tree_rev(t_dir_tree *tree,
		t_directory *d);
void					print_link(t_directory *d);
void					ft_print_error(t_directory *d, char *current,
		char *name);
void					ft_print(t_directory *d, char *current);
void					ft_print_e(t_directory *d, char *temp,
		char *current, char *name);

t_dir_tree				*ft_make_node(t_directory *d,
		char *param);
void					ft_sort_by_name(t_dir_tree **root, t_directory *d,
		char *name);
void					ft_sort_by_date(t_dir_tree **root, t_directory *d,
		char *name);
int						ft_create_tree(t_directory *d, char *current);

#endif
