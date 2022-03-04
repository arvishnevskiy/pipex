/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:40:23 by kelisabe          #+#    #+#             */
/*   Updated: 2022/03/04 19:21:32 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_pipex(int argc, char **argv, t_pipex *pipex)
{
	pipex->rights = S_IRUSR | S_IWUSR | S_IXUSR;
	pipex->in_file = open(argv[1], O_RDONLY);
	if (pipex->in_file == -1)
	{
		perror("Error");
		exit(1);
	}
	pipex->out_file = open(argv[argc - 1], \
			O_RDWR | O_CREAT | O_TRUNC, pipex->rights);
	if (pipex->out_file == -1)
	{
		perror("Error");
		exit(1);
	}
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
}
