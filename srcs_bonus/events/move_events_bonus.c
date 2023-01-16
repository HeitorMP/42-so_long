/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:09 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:09:11 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_move_wall(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == '1')
			return (0);
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == '1')
			return (0);
	}
	return (1);
}

int	check_move_exit(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == 'E')
			return (0);
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == 'E')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == 'E')
			return (0);
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == 'E')
			return (0);
	}
	return (1);
}

void	check_move_sprite(t_root *root, int direction)
{
	if (check_move_wall(root, direction))
	{
		if (check_move_exit(root, direction))
		{
			root->counters.count_move++;
			move_sprite(root, &root->hero, &root->floor, direction);
		}
	}
}
