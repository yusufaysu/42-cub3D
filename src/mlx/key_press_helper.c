/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/12/13 15:30:04 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_data_rc(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH -1;
	data->raydir_x = data->dir_x + data->plane_x * camera_x;
	data->raydir_y = data->dir_y + data->plane_y * camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1 / data->raydir_x);
	data->delta_dist_y = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	key_press_helper3(t_data *data, int key)
{
	if (key == RIGHT)
	{
		if (data->map3[(int)data->pos_x][(int)(data->pos_y \
			- (data->dir_x * data->move_speed))] != 1)
			data->pos_y -= data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x + (data->dir_y \
			* data->move_speed))][(int)data->pos_y] != 1)
			data->pos_x += data->dir_y * data->move_speed;
	}
	if (key == LEFT)
	{
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			+ (data->dir_x * data->move_speed))] != 1)
			data->pos_y += data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x - (data->dir_y \
			* data->move_speed))][(int)(data->pos_y)] != 1)
			data->pos_x -= data->dir_y * data->move_speed;
	}
}

void	key_press_helper2(t_data *data, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == UP)
	{
		if (data->map3[(int)(data->pos_x + data->dir_x \
			* data->move_speed)][(int)(data->pos_y)] != 1)
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			+ data->dir_y * data->move_speed)] != 1)
			data->pos_y += data->dir_y * data->move_speed;
	}
	if (key == CAMERA_RIGHT)
	{
		olddir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot_speed) \
			- data->dir_y * sin(-data->rot_speed);
		data->dir_y = olddir_x * sin(-data->rot_speed) \
			+ data->dir_y * cos(-data->rot_speed);
		oldplane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot_speed) \
			- data->plane_y * sin(-data->rot_speed);
		data->plane_y = oldplane_x * sin(-data->rot_speed) \
			+ data->plane_y * cos(-data->rot_speed);
	}
}

void	key_press_helper(t_data *data, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == BACK)
	{
		if (data->map3[(int)(data->pos_x - data->dir_x \
			* data->move_speed)][(int)(data->pos_y)] != 1)
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map3[(int)(data->pos_x)][(int)(data->pos_y \
			- data->dir_y * data->move_speed)] != 1)
			data->pos_y -= data->dir_y * data->move_speed;
	}
	if (key == CAMERA_LEFT)
	{
		olddir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed) \
			- data->dir_y * sin(data->rot_speed);
		data->dir_y = olddir_x * sin(data->rot_speed) \
			+ data->dir_y * cos(data->rot_speed);
		oldplane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed) \
			- data->plane_y * sin(data->rot_speed);
		data->plane_y = oldplane_x * sin(data->rot_speed) \
			+ data->plane_y * cos(data->rot_speed);
	}
}
