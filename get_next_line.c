/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:58 by abtouait          #+#    #+#             */
/*   Updated: 2025/01/30 03:17:55 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*str = NULL;
	int				byte_read;

	if (mandatory(fd, &buff) == 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(buff);
			if (byte_read == 0)
				break ;
			return (NULL);
		}
		buff[byte_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	if (ft_strchr(str, '\n') != NULL)
		free(buff);
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
	{
		free(str);
		return (NULL);
	}
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
	while (str[i] && str[i] != '\n')
		i++;
	new_str = malloc((i + (str[i] == '\n') + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	if (str[i] == '\n')
	{
		new_str[j] = '\n';
		j++;
	}
	new_str[j] = '\0';
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
	close(fd);
	return (0);
}
