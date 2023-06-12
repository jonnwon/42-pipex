/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:39:50 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:28:29 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmd {
	char			**cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pipex {
	int				idx;
	int				i_fd;
	int				o_fd;
	char			**envp;
	char			**path;
	int				fd[2];
	pid_t			pid;
	int				status_code;
	t_cmd			*head;
	t_cmd			*tail;
}					t_pipex;

/*utils*/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_error(char *s);

/*init*/
void	init_info(t_pipex *info, int argc, char **argv, char **envp);

/*parse*/
void	parse_cmd(t_pipex *info, int argc, char **argv);

/*free*/
void	free_nodes(t_pipex *info);
void	free_array(char **arr);

/*pipex*/
void	child_process(t_pipex info);

#endif
