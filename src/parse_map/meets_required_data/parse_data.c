/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:47:20 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 06:52:55 ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_empty_line(char *line)
{
	return (*line == '\0' || *line == '\n');

}

bool	store_2d_map(t_mapdata *mapdata, char *line)
{
	int			old_size;
	int			new_size;
	int			new_alloc_rows;
	char		**new_map2d;
	static int	alloc_rows;

	if (mapdata->rows >= alloc_rows)
	{
		if (alloc_rows == 0)
			new_alloc_rows = 1;
		else
			new_alloc_rows = alloc_rows * 2;
		old_size = alloc_rows * sizeof(char *);
		new_size = new_alloc_rows * sizeof(char *);
		new_map2d = ft_realloc(mapdata->map2d, old_size, new_size);
		if (!new_map2d)
			return (return_with_error("ft_realloc failed."));
		mapdata->map2d = new_map2d;
		alloc_rows = new_alloc_rows;
	}
	mapdata->map2d[mapdata->rows] = ft_strtrim(line, "\n");
	mapdata->rows++;
	return (PASS);
}

bool	parse_data(t_main *main, int fd)
{
	char	*line;
	bool	started;

	started = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_empty_line(line) && (started == false))
		{
			free(line);
			continue ;
		}
		if (is_empty_line(line) && (started == true))
			return (free(line), return_with_error("has empty line in map."));
		started = true;
		if (store_2d_map(&main->mapdata, line) == FAIL)
			return (free(line), return_with_error("can't stop map as 2d form."));
		free(line);
	}
	return (free(line), pad_2d_map(&main->mapdata));
}
