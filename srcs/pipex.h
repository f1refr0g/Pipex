/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:44 by abeaudet          #+#    #+#             */
/*   Updated: 2023/02/18 12:55:42 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../includes/libft/libft.h"

# define WRITE_END 1
# define READ_END 0

void	exit_error(const char *a);
char	*get_command_path(char *argv, char **envp);
void	get_command(char **argv, char **envp, int argval);
void	parent(char **argv, char **envp, int *fd);
void	child(char **argv, char **envp, int *fd);
void	**ft_free_array(char **array);
void	*ft_free(void *ptr);

#endif