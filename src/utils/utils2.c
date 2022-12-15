/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:10:29 by yaysu             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:19 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_helper(t_data *data)
{
	free(data->f_rgb);
	free(data->c_rgb);
	free_int_array(data->map3, data->map_size);
}

int	rbg_to_int(int r, int g, int b)
{
	return (((r & 0x0ff) << 16) | ((g & 0x0ff) << 8) | (b & 0x0ff));
}

void	ft_exit(t_data *data)
{
	ft_free_helper(data);
	ft_free_map(data);
	exit(EXIT_SUCCESS);
}
