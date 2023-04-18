/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:15:08 by abeaudet          #+#    #+#             */
/*   Updated: 2023/02/18 12:55:39 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(const char *a)
{
	perror(a);
	exit(EXIT_FAILURE);
}

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	**ft_free_array(char **array)
{
	int		i;

	if (!array)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (array[i])
			array[i] = ft_free(array[i]);
	}
	array = ft_free(array);
	return (NULL);
}
