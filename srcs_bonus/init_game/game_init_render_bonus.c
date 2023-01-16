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

#include "../../includes/so_long_bonus.h"

void	render_collect_tile(t_root *root, size_t y, size_t x)
{
	root->collect[root->quant.quant_collect - 1].path = \
	root->path.collect[0];
	root->collect[root->quant.quant_collect - 1].control = 'C';
	put_sprite(root, &root->collect[root->quant.quant_collect - 1], y, x);
	root->quant.quant_collect--;
}

void	render_patrol_tile(t_root *root, size_t y, size_t x)
{
	root->patrol[root->quant.quant_patrol - 1].path = root->path.patrol1;
	root->patrol[root->quant.quant_patrol - 1].control = 'M';
	put_sprite(root, &root->patrol[root->quant.quant_patrol - 1], y, x);
	root->quant.quant_patrol--;
}

void	render_tile(t_root *root, char tile, size_t y, size_t x)
{
	if (tile == 'P')
		put_sprite(root, &root->hero, y, x);
	else if (tile == '1')
	{
		root->wall.y = y;
		root->wall.x = x;
		wall_animation(root);
		put_sprite(root, &root->wall, y, x);
	}
	else if (tile == 'C')
		render_collect_tile(root, y, x);
	else if (tile == 'E')
		put_sprite(root, &root->exit, y, x);
	else if (tile == '0')
		put_sprite(root, &root->floor, y, x);
	else if (tile == 'M')
		render_patrol_tile(root, y, x);
}

void	render_map(t_root *root)
{
	size_t	lines;
	size_t	cols;

	lines = 0;
	cols = 0;
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
	root->quant.quant_collect = root->counters.count_collect;
	root->quant.quant_patrol = MONSTERS;
}
