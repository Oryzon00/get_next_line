/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:08:22 by ajung             #+#    #+#             */
/*   Updated: 2021/12/03 20:24:26 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			read_output;
	static char buffer[BUFFER_SIZE + 1];
	char		*output;
	char		*stock;
	
	i = 0;

	//CHECK PARAMS VALABLE
	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	
	// METTRE RESTE DANS STOCK
	if (buffer[0])
		stock = ft_strndup_gnl(buffer, ft_strlen(buffer));
	else
		stock = ft_strndup_gnl("", 1);
	
	// LECTURE POUR TROUVER \N
	read_output = 1;
	while (read_output && !(ft_strchr(stock, '\n')))
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		buffer[read_output] = '\0';
		stock = ft_strjoin_free_s1(stock, buffer);
	}
	
	// TROUVER EMPLACEMENT \N
	while (stock[i] && stock[i] != '\n')
		i++;
	
	//FAIRE LA LIGNE 
	output = ft_strndup_gnl(stock, i + 1); //+1 pour chopper \n
	
	//RECUPERER LE RESTE APRES \N DANS BUFFER STATIC ET LE NULL TERMINATED
	// j = 0;
	while (stock[i])
	{
		buffer[i] = stock[i]; //buffer[j]
		i++;
		//j++; 
	}
	buffer[i] = '\0';
	free(stock);
	return (output);
}
