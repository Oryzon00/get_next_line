/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_qui_pue.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:26:57 by ajung             #+#    #+#             */
/*   Updated: 2021/12/03 19:25:28 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line_qui_pue(int fd)
{
	int			i;
	int			read_output;
	static char	*reste = NULL; //[BUFFER_SIZE]
	char		*buffer;
	char 		*output;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	if (!reste)
		reste = ft_strdup_gnl("", 1);
	read_output = 1;
	while(read_output)
	{
		buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		if (!(ft_strchr(reste, '\n')))
		{
			read_output = read(fd, buffer, BUFFER_SIZE);
			buffer[read_output] = '\0';
		}
		buffer = ft_strjoin_frees2(reste, buffer);
		i = 0;
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			output = ft_strdup_gnl(buffer, i + 1); //+1 pour chopper \n
			reste = ft_strdup_gnl(&buffer[i + 1], ft_strlen(&buffer[i + 1]));
			//reste = ft_strjoin_gnl(reste, &(buffer[i + 1]));
			free(buffer);
			return (output);
		}
		else
		{
			//reste = ft_strjoin_gnl(reste, buffer);
			reste = ft_strdup_gnl(buffer, ft_strlen(buffer));
			free(buffer);
		}
	}
	return (reste);
}
