/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:38:31 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/14 03:02:04 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	init_info(t_pipex *info, int argc, char **argv, char **envp)
{
	ft_memset(info, 0, sizeof(t_pipex));
	info->i_fd = open(argv[1], O_RDONLY);
	if (info->i_fd == -1)
		perror("Infile");
	info->o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->o_fd == -1)
		print_error("Outfile");
	if (pipe(info->fd) == -1)
		print_error("Pipe");
	info->envp = envp;
	info->path = get_env_path(envp);
}
