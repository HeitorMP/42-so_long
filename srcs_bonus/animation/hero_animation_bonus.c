/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:18:29 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 08:18:32 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	hero_animation(t_root *root)
{
	if (root->hero.direction == UP)
		root->hero.path = root->path.hero_up;
	else if (root->hero.direction == DOWN)
		root->hero.path = root->path.hero_down;
	else if (root->hero.direction == LEFT)
		root->hero.path = root->path.hero_left;
	else if (root->hero.direction == RIGHT)
		root->hero.path = root->path.hero_right;
}
