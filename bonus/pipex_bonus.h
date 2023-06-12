/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:37:36 by jonchoi           #+#    #+#             */
/*   Updated: 2023/03/18 13:47:48 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# define BUFFER_SIZE 42

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
	int				*fd;
	pid_t			pid;
	int				status_code;
	t_cmd			*head;
	t_cmd			*tail;
	int				cnt_cmd;
	int				is_here_doc;
	char			**cmd_here_doc;
}					t_pipex;

/*GNL*/
typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}					t_list;

/*utils*/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_error(char *s);

/*gnl*/
char	*get_next_line(int fd);
size_t	ft_strlen2(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr2(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*init*/
void	init_info(t_pipex *info, int argc, char **argv, char **envp);

/*parse*/
void	parse_cmd(t_pipex *info, char **argv);

/*here_doc*/
void	here_doc(char *limiter);

/*pipex*/
void	child_process(t_pipex info);
void	close_fd(t_pipex info);

/*free*/
void	free_array(char **arr);
void	free_nodes(t_pipex *info);

#endif
