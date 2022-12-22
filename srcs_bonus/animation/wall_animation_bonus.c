/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:54:25 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 08:54:26 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	wall_animation(t_root *root)
{
	if (root->wall.y == 0 && root->wall.x == 0)
		root->wall.path = root->path.border_wall_ul;
	else if (root->wall.y == 0 && root->wall.x == (root->playfield.col - 2))
		root->wall.path = root->path.border_wall_ur;
	else if (root->wall.y == (root->playfield.lin - 1) && root->wall.x == 0)
		root->wall.path = root->path.border_wall_bl;
	else if (root->wall.y == (root->playfield.lin - 1) && root->wall.x == \
		(root->playfield.col - 2))
		root->wall.path = root->path.border_wall_br;
	else if (root->wall.x == 0 || root->wall.x == root->playfield.col - 2)
		root->wall.path = root->path.border_wall_vl;
	else if (root->wall.y == 0 || root->wall.y == root->playfield.lin - 1)
		root->wall.path = root->path.border_wall_hu;
	else
		root->wall.path = root->path.inner_wall;
}
