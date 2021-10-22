/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:19:48 by mframbou          #+#    #+#             */
/*   Updated: 2021/10/22 15:43:41 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Copy the content of the buffer (if any)
// Loop until newline
// Get only the result before \n
// Shift the buffer to remove the first line
// Return the result
char	*get_next_line(int fd)
{
	char		*result;
	static char	buffer[255][BUFFER_SIZE];
	int			head_pos;
	int			i;

	head_pos = 1;
	if (fd < 0 || fd > 254)
		return (NULL);
	result = ft_strdup(buffer[fd]);
	while (head_pos > 0 && !has_newline(result))
	{
		head_pos = read(fd, buffer[fd], BUFFER_SIZE);
		i = head_pos;
		while (i < BUFFER_SIZE)
			buffer[fd][i++] = '\0';
		result = ft_strcatdup(result, buffer[fd], head_pos);
	}
	result = get_first_line_in_string_free(result);
	if (*result == '\0' || head_pos == -1)
	{
		free(result);
		return (NULL);
	}
	shift_buffer(buffer[fd]);
	return (result);
}
