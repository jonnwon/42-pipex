/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:30:50 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:47:52 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	setup_child_fd(t_pipex info)
{
	if (info.idx == 0)
	{
		dup2(info.i_fd, STDIN_FILENO);
		dup2(info.fd[1], STDOUT_FILENO);
	}
	else if (info.idx == info.cnt_cmd - 1)
	{
		dup2(info.fd[2 * info.idx - 2], STDIN_FILENO);
		dup2(info.o_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(info.fd[2 * info.idx - 2], STDIN_FILENO);
		dup2(info.fd[2 * info.idx + 1], STDOUT_FILENO);
	}
}

void	close_fd(t_pipex info)
{
	int	i;

	i = 0;
	while (i < (info.cnt_cmd - 1) * 2)
	{
		close(info.fd[i]);
		i++;
	}
	close(info.i_fd);
	close(info.o_fd);
}

static char	**find_cmd(t_pipex info)
{
	t_cmd	*tmp;

	tmp = info.head;
	while (info.idx)
	{
		tmp = tmp->next;
		info.idx--;
	}
	return (tmp->cmd);
}

static void	exec_child(t_pipex info, char **cmd)
{
	if (execve(cmd[0], cmd, info.envp) < 0)
	{
		print_error("Command not found");
		info.status_code = 127;
		exit(info.status_code);
	}
}

void	child_process(t_pipex info)
{
	char	**cmd;

	info.pid = fork();
	if (!info.pid)
	{
		setup_child_fd(info);
		close_fd(info);
		cmd = find_cmd(info);
		exec_child(info, cmd);
	}
}
