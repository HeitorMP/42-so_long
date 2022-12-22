/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:08:04 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:08:08 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_root *root, t_sprite *element, char behind)
{
	root->playfield.playfield[element->y][element->x] = behind;
	element->y--;
	element->direction = UP;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_down(t_root *root, t_sprite *element, char behind)
{
	root->playfield.playfield[element->y][element->x] = behind;
	element->y++;
	element->direction = DOWN;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_right(t_root *root, t_sprite *element, char behind)
{
	root->playfield.playfield[element->y][element->x] = behind;
	element->x++;
	element->direction = RIGHT;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_left(t_root *root, t_sprite *element, char behind)
{
	root->playfield.playfield[element->y][element->x] = behind;
	element->x--;
	element->direction = LEFT;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_sprite(t_root *root, t_sprite *element, char behind, int direction)
{
	if (direction == UP)
		move_up(root, element, behind);
	if (direction == DOWN)
		move_down(root, element, behind);
	if (direction == RIGHT)
		move_right(root, element, behind);
	if (direction == LEFT)
		move_left(root, element, behind);
}
