/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:29:52 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 12:29:55 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_patrol_allow(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->patrol.y - 1][root->patrol.x] == '0'\
		|| root->playfield.playfield[root->patrol.y - 1][root->patrol.x] == 'P')
			return (1);
	}
	else if (direction == DOWN)
	{
		if (root->playfield.playfield[root->patrol.y + 1][root->patrol.x] == '0'\
		|| root->playfield.playfield[root->patrol.y + 1][root->patrol.x] == 'P')
			return (1);
	}
	else if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->patrol.y][root->patrol.x + 1] == '0'\
		|| root->playfield.playfield[root->patrol.y][root->patrol.x + 1] == 'P')
			return (1);
	}
	else if (direction == LEFT)
	{
		if (root->playfield.playfield[root->patrol.y][root->patrol.x - 1] == '0'\
		|| root->playfield.playfield[root->patrol.y][root->patrol.x - 1] == 'P')
			return (1);
	}
	return (0);
}

void	check_move_patrol(t_root *root, int direction)
{
	int	new_direction;

	new_direction = direction;
	if (root->counters.count_collect_animation == 20)
		new_direction = UP;
	else if (root->counters.count_collect_animation == 40)
		new_direction = DOWN;
	else if (root->counters.count_collect_animation == 65)
		new_direction = LEFT;
	else
		new_direction = RIGHT;
	if (check_patrol_allow(root, new_direction))
		move_sprite(root, &root->patrol, '0', new_direction);
}
