/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:23:39 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/15 04:23:54 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_nodes(t_pipex *info)
{
	t_cmd	*cur;
	t_cmd	*temp;

	cur = info->head;
	while (cur)
	{
		temp = cur->next;
		free_array(cur->cmd);
		free(cur);
		cur = temp;
	}
	info->head = NULL;
	info->tail = NULL;
}
