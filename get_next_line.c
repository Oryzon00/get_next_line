/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:08:22 by ajung             #+#    #+#             */
/*   Updated: 2021/12/06 15:11:46 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			read_output;
	static char buffer[BUFFER_SIZE + 1];
	char		*output;
	char		*stock;

	//CHECK PARAMS VALABLE
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	
	// METTRE RESTE DANS STOCK
	if (buffer[0] != '\0')
		stock = ft_strndup_gnl(buffer, ft_strlen(buffer));
	else
		stock = ft_strndup_gnl("", 1);
	
	// LECTURE POUR TROUVER \N
	read_output = 1;
	while (read_output && !(ft_strchr(stock, '\n')))
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		buffer[read_output] = '\0';
		if (read_output == 0)
			break ;
		if (read_output < 0)
		{
			free(stock);
			return (NULL);
		}
		stock = ft_strjoin_free_s1(stock, buffer);
	}
	//
	if (stock[0] == 0 && read_output == 0)
		return (free(stock), NULL);
	
	// TROUVER EMPLACEMENT \N
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	
	//FAIRE LA LIGNE
	if (stock[i] == '\0')
	{
		output = ft_strndup_gnl(stock, i);
		//free(stock);
		//return (output);
	}
	else
		output = ft_strndup_gnl(stock, i + 1); //+1 pour chopper \n
	
	
	//RECUPERER LE RESTE APRES \N DANS BUFFER STATIC ET LE NULL TERMINATED
	j = 0;
	if (stock[i])
		i++;
	while (stock[i])
	{
		buffer[j] = stock[i]; //buffer[j]
		i++;
		j++; 
	}
	buffer[j] = '\0';
	free(stock);
	return (output);
}
