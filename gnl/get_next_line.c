/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:03:55 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/21 09:49:26 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

static char	*get_line(char *line)
{
	size_t	start;
	char	*next_line;

	start = 0;
	while (line[start] != '\n' && line[start])
		start++;
	next_line = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (!*next_line)
	{
		free(next_line);
		return (NULL);
	}
	line[start + 1] = '\0';
	return (next_line);
}

static char	*read_line(int fd, char *next_line, char *buffer)
{
	int		byte;
	char	*temp;

	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (NULL);
		else if (byte == 0)
			return (next_line);
		buffer[byte] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		temp = next_line;
		next_line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			return (next_line);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	line = read_line(fd, next_line, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	next_line = get_line(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*ret;

// 	fd = open("42file", O_RDONLY | O_CREAT, S_IRUSR, S_IWUSR);
// 	if (fd == -1)
// 	{
// 		printf("File Error\n");
// 		return (1);
// 	}
// 	while (ret = get_next_line(fd))
// 	{
// 		printf("%s", ret);
// 		free(ret);
// 	}
// 	printf("\n");
// 	if (close(fd) == -1)
// 	{
// 		printf("File Close Error\n");
// 		return (1);
// 	}
// 	return (0);
// }