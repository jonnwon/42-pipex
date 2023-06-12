/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:13:47 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:33:53 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_env_path(char **envp)
{
	char	**path;
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	env_path = envp[i] + 5;
	path = ft_split(env_path, ':');
	return (path);
}

static void	open_file(int argc, char **argv, t_pipex *info)
{
	if (info->is_here_doc)
	{
		here_doc(argv[2]);
		info->i_fd = open(".here_doc", O_RDONLY);
		if (info->i_fd == -1)
			print_error(".here_doc");
		info->o_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	else
	{
		info->i_fd = open(argv[1], O_RDONLY);
		if (info->i_fd == -1)
			perror("Infile");
		info->o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	if (info->o_fd == -1)
		print_error("Outfile");
}

void	init_info(t_pipex *info, int argc, char **argv, char **envp)
{
	int	i;

	open_file(argc, argv, info);
	info->cnt_cmd = argc - 3 - info->is_here_doc;
	info->envp = envp;
	info->path = get_env_path(envp);
	info->fd = (int *)malloc(sizeof(int) * 2 * (info->cnt_cmd - 1));
	if (!info->fd)
		print_error("fd malloc");
	i = 0;
	while (i < info->cnt_cmd - 1)
	{
		if (pipe(info->fd + 2 * i) < 0)
		{
			free(info->fd);
			print_error("PIPE");
		}
		i++;
	}
}
