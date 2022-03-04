/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:04:49 by kelisabe          #+#    #+#             */
/*   Updated: 2022/03/04 17:19:26 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	int		in_file;
	int		out_file;
	char	*cmd1;
	char	*cmd2;
	int		fds[2];
	char	**paths;
	pid_t	pid1;
	pid_t	pid2;
	int		rights;
}	t_pipex;

void	parsing_pipex(int argc, char **argv, t_pipex *pipex);
char	*finder_path(char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif