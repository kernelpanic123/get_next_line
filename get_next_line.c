/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:58 by abtouait          #+#    #+#             */
/*   Updated: 2025/01/24 20:51:34 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char	*str = NULL;
	int		byte_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (ft_strchr(line, '\n') == NULL)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buff[byte_read] = '\0';
		line = ft_strjoin(line, buff);
	}

	return (line);
}

int	main(void)
{
	int		fd;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
}
