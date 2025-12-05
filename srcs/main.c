/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:35:09 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/25 11:37:25 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_w(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	close_w_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int	x;
	int	y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "So-long");
	
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
	x = 0;
	y = 0;
	while (x < 100)
		my_mlx_pixel_put(&img, x++, y, 0x00FFFF00);
	while (y < 100)
		my_mlx_pixel_put(&img, x, y++, 0x00FFFFFF);
	while (x > 0)
		my_mlx_pixel_put(&img, x--, y, 0x00FFFF00);
	while (y > 0)
		my_mlx_pixel_put(&img, x, y--, 0x00FFFF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_w, &vars);
	mlx_hook(vars.win, 17, 0, close_w_cross, &vars);
	mlx_loop(vars.mlx);
}

