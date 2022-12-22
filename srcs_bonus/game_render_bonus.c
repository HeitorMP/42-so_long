/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:07:35 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:07:38 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_tile(t_root *root, char tile, size_t y, size_t x)
{
	if (tile == 'P')
		put_sprite(root, root->hero, y, x);
	else if (tile == '1')
	{
		root->wall.y = y;
		root->wall.x = x;
		wall_animation(root);
		put_sprite(root, root->wall, y, x);
	}
	else if (tile == 'C')
		put_sprite(root, root->collect, y, x);
	else if (tile == 'E' || tile == 'O')
		put_sprite(root, root->exit, y, x);
	else if (tile == '0')
		put_sprite(root, root->floor, y, x);
	else if (tile == 'M')
		put_sprite(root, root->patrol, y, x);
}

void	render_text(t_root *root)
{
	root->score = ft_itoa(root->counters.count_move);
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, \
		(root->playfield.lin * 32) + 16, 16711680, "Moves: ");
	mlx_string_put(root->mlx.mlx, root->mlx.win, 100, \
		(root->playfield.lin * 32) + 16, 16711680, root->score);
	free(root->score);
}

void	render_map(t_root *root)
{
	size_t	lines;
	size_t	cols;

	lines = 0;
	cols = 0;
	render_text(root);
	while (lines < root->playfield.lin)
	{
		while (cols < root->playfield.col)
		{
			render_tile(root, root->playfield.playfield[lines][cols], \
				lines, cols);
			cols++;
		}
		cols = 0;
		lines++;
	}
}
