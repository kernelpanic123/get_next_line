/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:58 by abtouait          #+#    #+#             */
/*   Updated: 2025/01/26 19:31:42 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static	char	*str;
	int				byte_read;

	if (!str)
		str = ft_strdup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buff);
			return (NULL);
		}
		if (byte_read == 0)
			break ;
		buff[byte_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	line = extract_line(str);
	str = update_static_str(str);
	return (line);
}

char	*update_static_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc((ft_strlen(str) - i) * sizeof(char));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*extract_line(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str || !*str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	new_str = malloc((i + (str[i] == '\n') + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\n';
	new_str[j + 1] = '\0';
	return (new_str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
