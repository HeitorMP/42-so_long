/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:55:56 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/18 22:56:00 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	call_flood_fill(t_root *root, int y, int x)
{
	if (root->playfield.playfield_mask[y][x] != '1')
	{
		root->playfield.playfield_mask[y][x] = '1';
		call_flood_fill(root, y, x + 1);
		call_flood_fill(root, y, x - 1);
		call_flood_fill(root, y + 1, x);
		call_flood_fill(root, y - 1, x);
	}
}

void	check_flood_fill(t_root *root)
{
	size_t	lin;
	size_t	col;

	lin = 0;
	col = 0;
	while (lin < root->playfield.lin)
	{
		while (col < root->playfield.col)
		{
			if (root->playfield.playfield_mask[lin][col] == 'C' || \
				root->playfield.playfield_mask[lin][col] == 'E')
			{
				root->flags.is_not_way_out = 1;
				root->flags.has_init_error = 1;
			}
			col++;
		}
		col = 0;
		lin++;
	}
}

void	flood_fill(t_root *root)
{
	int	x;
	int	y;

	x = root->hero.x;
	y = root->hero.y;
	call_flood_fill(root, y, x);
	check_flood_fill(root);
}
