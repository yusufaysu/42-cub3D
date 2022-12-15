/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:37:01 by yaysu             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:51 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 3 || check_arg(argv[1]))
		return (print_error("Something wrong with arguments.\n"));
	if (before_start_game(fd, &data))
		return (ft_free_map(&data));
	if (start_game(&data))
		return (ft_free_map(&data));
	return (0);
}
