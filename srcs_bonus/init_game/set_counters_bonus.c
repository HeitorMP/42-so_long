/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_counters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:10:04 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:10:07 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	set_counters(t_root *root)
{
	root->counters.count_collect = 0;
	root->counters.count_collect_animation = 0;
	root->counters.count_move = 0;
	root->counters.count_patrol = MONSTERS;
	root->counters.count_patrol_animation = 0;
	root->counters.count_wall_animation = 0;
	root->counters.count_floors = 0;
}
