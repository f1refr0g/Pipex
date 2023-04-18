/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:03:36 by abeaudet          #+#    #+#             */
/*   Updated: 2023/02/18 15:15:06 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FIX FREE VERIFIER OUTFILE FAIRE FONCTION LIBFT
#include "pipex.h"

void	child(char **argv, char **envp, int *fd)
{
	int		file;

	file = open(argv[0], O_RDONLY, 0644);
	if (file == -1)
		exit_error("child infile invalid");
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(file, 0);
	get_command(argv, envp, 1);
	close(file);
	exit(1);
}

void	parent(char **argv, char **envp, int *fd)
{
	int		file;

	file = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		exit_error("parent outfile invalid");
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(file, 1);
	get_command(argv, envp, 2);
	close(file);
}

void	get_command(char **argv, char **envp, int argval)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = ft_split(argv[argval], 32);
	cmd_path = get_command_path(cmd[0], envp);
	if (!cmd_path)
	{
		while (cmd[i++])
			free(cmd[i]);
		exit_error("path error");
	}
	if (!cmd_path)
	{
		ft_free(cmd_path);
		ft_free_array(cmd);
		exit_error("Commmand or Command path not found");
	}
	i = execve(cmd_path, cmd, envp);
	if (i == -1)
		exit_error("execve error.");
}

char	*get_command_path(char *argv, char **envp)
{
	char	**path_list;
	char	*splitted_path;
	char	*pat;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_list = ft_split(envp[i], ':');
	i = 0;
	while (path_list[i])
	{
		splitted_path = ft_strjoin(path_list[i++], "/");
		pat = ft_strjoin(splitted_path, argv);
		ft_free(splitted_path);
		if (access(pat, F_OK) == 0)
			return (pat);
		ft_free(pat);
	}
	ft_free_array(path_list);
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	process;

	++argv;
	if (argc == 5)
	{
		pipe(fd);
		process = fork();
		if (process < 0)
			exit_error("Pipe error.");
		if (process < 0)
			exit_error("Fork error.");
		if (process == 0)
			child(argv, envp, fd);
		waitpid(process, NULL, 0);
		parent(argv, envp, fd);
	}
	else
		exit_error("Bad arguments");
	return (0);
}
