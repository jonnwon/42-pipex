/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:37:24 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:08:22 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	info;

	if (argc != 5)
		print_error("Not 5 ARG");
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc, argv);
	while (info.idx < 2)
	{
		child_process(info);
		info.idx++;
	}
	close(info.fd[0]);
	close(info.fd[1]);
	close(info.i_fd);
	close(info.o_fd);
	wait(NULL);
	free_nodes(&info);
	free_array(info.path);
	return (info.status_code);
}
