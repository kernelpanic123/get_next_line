/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:51 by abtouait          #+#    #+#             */
/*   Updated: 2025/01/24 23:21:34 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
char	*copy_word(char *s1)
{
	int 	i;
	char	*mot;

	i = 0;
	mot = malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (s1[i] != '\0')
	{
		mot[i] = s1[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mot;

	i = 0;
	j = 0;
	mot = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!mot)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		mot[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mot[i + j] = s2[j];
		j++;
	}
	return (mot);
}
