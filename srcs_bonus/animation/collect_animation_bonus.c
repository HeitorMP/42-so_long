/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:29:35 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 08:29:36 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	collect_counter(t_root *root)
{
	root->counters.count_collect_animation++;
	if (root->counters.count_collect_animation >= 80)
		root->counters.count_collect_animation = 0;
}

void	collect_animation(t_root *root)
{
	collect_counter(root);
	if (root->counters.count_collect_animation < 10)
		root->collect.path = root->path.collect[0];
	else if (root->counters.count_collect_animation < 20)
		root->collect.path = root->path.collect[1];
	else if (root->counters.count_collect_animation < 30)
		root->collect.path = root->path.collect[2];
	else if (root->counters.count_collect_animation < 40)
		root->collect.path = root->path.collect[3];
	else if (root->counters.count_collect_animation < 50)
		root->collect.path = root->path.collect[4];
	else if (root->counters.count_collect_animation < 60)
		root->collect.path = root->path.collect[5];
	else if (root->counters.count_collect_animation < 70)
		root->collect.path = root->path.collect[6];
	else
		root->collect.path = root->path.collect[7];
}
