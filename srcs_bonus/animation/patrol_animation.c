/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:26:54 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 11:26:55 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	patrol_counter(t_root *root)
{
	root->counters.count_patrol_animation++;
	if (root->counters.count_patrol_animation > 30)
		root->counters.count_patrol_animation = 0;
}

void	patrol_animation(t_root *root)
{
	patrol_counter(root);
	if (root->counters.count_patrol_animation < 10)
		root->patrol.path = root->path.patrol1;
	else if (root->counters.count_patrol_animation < 20)
		root->patrol.path = root->path.patrol2;
	else if (root->counters.count_patrol_animation < 30)
		root->patrol.path = root->path.patrol3;
}
