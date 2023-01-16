/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:08:13 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:08:16 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_sprite(t_root *root, t_sprite *sprite, size_t y, size_t x)
{
	int	w;
	int	h;

	sprite->y = y;
	sprite->x = x;
	sprite->img = mlx_xpm_file_to_image(root->mlx.mlx, \
		sprite->path, &w, &h);
	if (sprite->img == NULL)
	{
		ft_printf("put sprite error");
		exit_ingame_error_(root);
	}
	sprite->addr = mlx_get_data_addr(sprite->img, \
		&sprite->bits_per_pixel, &sprite->line_length, \
		&sprite->endian);
	mlx_put_image_to_window(root->mlx.mlx, root->mlx.win, \
		sprite->img, sprite->x * 32, sprite->y * 32);
	mlx_destroy_image(root->mlx.mlx, sprite->img);
}
