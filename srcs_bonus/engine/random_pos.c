/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:55 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/01/03 18:09:12 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	random_patrol_pos(t_root *root)
{
	size_t	x;
	size_t	y;

	srand(time(NULL));
	y = rand() % root->playfield.lin;
	x = rand() % root->playfield.col;
	if (root->playfield.playfield[y][x] == '0')
	{
		root->patrol.y = y;
		root->patrol.x = x;
		root->counters.count_patrol--;
		root->playfield.playfield[y][x] = 'M';
	}
	else
		random_patrol_pos(root);
}
