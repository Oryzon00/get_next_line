/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:26:57 by ajung             #+#    #+#             */
/*   Updated: 2021/12/02 18:33:06 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			read_output;
	static char	*reste = NULL;
	char		*buffer;
	char 		*output;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!reste)
		reste = ft_strdup_gnl("", 1);
	buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_output = read(fd, buffer, BUFFER_SIZE);
	while (read_output != 0)
	{
		buffer[read_output] = '\0';
		buffer = ft_strjoin_gnl(reste, buffer);
		i = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			output = ft_strdup_gnl(buffer, i + 1); //+1 pour chopper \n
			reste = ft_strdup_gnl(&buffer[i + 1], ft_strlen(&buffer[i + 1]));
			free(buffer);
			return (output);
		}
		// else if (buffer[i] == '\0')
		// {
		// 	output = ft_strdup_gnl(buffer, i);
		// 	free(buffer);
		// 	return (output);
		// }
		else
		{
			reste = ft_strjoin_gnl(reste, buffer);
			free(buffer);
		}
	}
	return (NULL);
}
