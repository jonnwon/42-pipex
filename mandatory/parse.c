/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:42:05 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/14 03:08:34 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_cmd(t_pipex *info, char *cmd)
{
	char	*abs_path;
	char	*tmp;
	int		i;
	char	**path;

	if (!access(cmd, X_OK) || cmd[0] == '/')
		return (cmd);
	tmp = ft_strjoin("/", cmd);
	i = 0;
	path = info->path;
	while (path[i])
	{
		abs_path = ft_strjoin(path[i], tmp);
		if (!access(abs_path, X_OK))
		{
			free(cmd);
			free(tmp);
			return (abs_path);
		}
		i++;
		free(abs_path);
	}
	free(tmp);
	info->status_code = 127;
	return (cmd);
}

static t_cmd	*create_node(char **cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	return (new);
}

static void	add_cmd(t_pipex *info, char **cmd)
{
	t_cmd	*new;

	new = create_node(cmd);
	if (!info->head)
	{
		info->head = new;
		info->tail = new;
	}
	else
	{
		info->tail->next = new;
		info->tail = new;
	}
}

void	parse_cmd(t_pipex *info, int argc, char **argv)
{
	char	**cmd;
	int		i;

	i = 0;
	while (i + 2 < argc - 1)
	{
		cmd = ft_split(argv[i + 2], ' ');
		cmd[0] = check_cmd(info, cmd[0]);
		add_cmd(info, cmd);
		i++;
	}
}
