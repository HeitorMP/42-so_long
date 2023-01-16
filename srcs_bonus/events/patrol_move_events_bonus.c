/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move_events_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:29:52 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/01/03 18:09:42 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_patrol_allow(t_root *root, t_sprite element, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[element.y - 1][element.x] == '0'\
		|| root->playfield.playfield[element.y - 1][element.x] == 'P')
			return (1);
	}
	else if (direction == DOWN)
	{
		if (root->playfield.playfield[element.y + 1][element.x] == '0'\
		|| root->playfield.playfield[element.y + 1][element.x] == 'P')
			return (1);
	}
	else if (direction == RIGHT)
	{
		if (root->playfield.playfield[element.y][element.x + 1] == '0'\
		|| root->playfield.playfield[element.y][element.x + 1] == 'P')
			return (1);
	}
	else if (direction == LEFT)
	{
		if (root->playfield.playfield[element.y][element.x - 1] == '0'\
		|| root->playfield.playfield[element.y][element.x - 1] == 'P')
			return (1);
	}
	return (0);
}

void	check_move_patrol(t_root *root)
{
	int	new_direction;
	int	i;

	srand(time(NULL));
	new_direction = rand() % 200;
	if (new_direction < 50)
		new_direction = UP;
	else if (new_direction < 100)
		new_direction = DOWN;
	else if (new_direction < 150)
		new_direction = LEFT;
	else if (new_direction < 200)
		new_direction = RIGHT;
	i = root->quant.quant_patrol - 1;
	while (i >= 0)
	{
		if (check_patrol_allow(root, root->patrol[i], new_direction))
			move_sprite(root, &root->patrol[i], &root->floor, new_direction);
		i--;
	}
}
