/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:04:26 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:47:50 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	number_of_argc(char *arg, t_pipex *info)
{
	if (arg && !ft_strncmp("here_doc", arg, 8))
	{
		info->is_here_doc = 1;
		return (6);
	}
	else
		return (5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	info;

	ft_memset(&info, 0, sizeof(t_pipex));
	if (argc < number_of_argc(argv[1], &info))
		print_error("ARG ERROR");
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argv);
	while (info.idx < info.cnt_cmd)
	{
		child_process(info);
		info.idx++;
	}
	close_fd(info);
	wait(NULL);
	free_nodes(&info);
	free_array(info.path);
	return (info.status_code);
}
