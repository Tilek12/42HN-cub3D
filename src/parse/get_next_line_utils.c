/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:33:39 by ryusupov          #+#    #+#             */
/*   Updated: 2024/10/16 18:15:39 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_strjoin_new(char *s1, char *s2)
{
	size_t	size;
	char	*result;
	size_t	temp1;
	size_t	temp2;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	temp1 = -1;
	temp2 = -1;
	while (s1[++temp1])
		result[temp1] = s1[temp1];
	while (s2[++temp2])
		result[temp1 + temp2] = s2[temp2];
	result[temp1 + temp2] = '\0';
	free(s1);
	return (result);
}

char	*ft_strndup(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while ((i + start) < end)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	new_line(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_struct	*get_t_struct(int new_fd)
{
	t_struct	*i;

	i = (t_struct *)malloc(sizeof(t_struct));
	if (!i)
	{
		return (NULL);
	}
	i->fd = new_fd;
	return (i);
}

size_t	ft_strlen_gnl(const char *s)
{
	int	i;
	int	counter;

	if (!s)
	{
		return (0);
	}
	i = 0;
	counter = 0;
	while (s[i])
	{
		i++;
		counter++;
	}
	return (counter);
}
