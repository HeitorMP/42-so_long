/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:03 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:09:05 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_door_open(t_root *root)
{
	if (root->counters.count_collect <= 0)
	{
		root->flags.is_door_open = 1;
		root->playfield.playfield[root->exit.y][root->exit.x] = 'O';
	}
}

void	game_events(t_root *root)
{
	check_door_open(root);
	if (root->counters.count_patrol_animation == 899)
		check_move_patrol(root);
}
