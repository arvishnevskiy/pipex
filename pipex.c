/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:04:57 by kelisabe          #+#    #+#             */
/*   Updated: 2022/03/19 11:56:26 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd(t_pipex pipex, char *cmd_name)
{
	int	i;

	i = 0;
	while (pipex.paths[i] != NULL)
	{
		pipex.paths[i] = ft_strjoin(pipex.paths[i], "/");
		pipex.paths[i] = ft_strjoin(pipex.paths[i], cmd_name);
		if (access(pipex.paths[i], 0) == 0)
			return (pipex.paths[i]);
		i++;
	}
	exit(1);
}

void	child_process(t_pipex pipex, char **envp, int i)
{
	char	**cmd;

	if (i == 0)
	{
		dup2(pipex.in_file, 0);
		dup2(pipex.fds[1], 1);
		close(pipex.fds[0]);
		close(pipex.fds[1]);
		cmd = ft_split(pipex.cmd1, ' ');
		execve(find_cmd(pipex, cmd[0]), cmd, envp);
	}
	else if (i == 1)
	{
		dup2(pipex.fds[0], 0);
		dup2(pipex.out_file, 1);
		close(pipex.fds[0]);
		close(pipex.fds[1]);
		cmd = ft_split(pipex.cmd2, ' ');
		execve(find_cmd(pipex, cmd[0]), cmd, envp);
	}
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	parsing_pipex(argc, argv, &pipex);
	if (pipe(pipex.fds) == -1)
	{
		perror("Error");
		return (1);
	}
	pipex.paths = ft_split(finder_path(envp) + 5, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		child_process(pipex, envp, 0);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_process(pipex, envp, 1);
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
