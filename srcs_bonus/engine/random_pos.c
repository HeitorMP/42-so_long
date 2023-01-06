/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:55 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/01/03 14:34:43 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	random_patrol_pos(t_root *root)
{
	size_t	x;
	size_t	y;
	int		i;

	srand(time(NULL));
	y = rand() % root->playfield.lin;
	x = rand() % root->playfield.col;
	i = root->counters.count_patrol - 1;
	if (root->playfield.playfield[y][x] == '0')
	{
		while (i >= 0)
		{
			root->patrol[i].y = y;
			root->patrol[i].x = x;
			root->patrol[i].control = 'M';
			root->playfield.playfield[y][x] = 'M';
			i--;
		}
		root->counters.count_patrol--;
	}
	else
		random_patrol_pos(root);
}
