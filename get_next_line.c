/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:26:57 by ajung             #+#    #+#             */
/*   Updated: 2021/12/01 23:33:11 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	*output;
	
	static char	buffer[BUFFER_SIZE + 1]; //char **?
	//static int start_line = 0; //trouver comment read a partir d'un index?
	
	while (1)
	{
		i = 0;
		read(fd, buffer, BUFFER_SIZE); // ssize_t read(int fd, void *buf, size_t nbyte);
		buffer[BUFFER_SIZE] = '\0';
		while (buffer[i] != '\0' || buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			output = ft_strjoin_gnl(output, buffer, i + 1); // +1 pour chooper le /n
			return (output);
		}
		else if (buffer[i] == '\0')
		{
			output = ft_strjoin_gnl(output, buffer, i);
			return (output);
		}
		else
		{
			output = ft_strjoin_gnl(output, buffer, BUFFER_SIZE);
		}
	}
}
