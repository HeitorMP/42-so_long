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
	if (root->counters.count_collect_animation >= 640)
		root->counters.count_collect_animation = 0;
}

void	collect_all_animation(t_root *root, int i)
{
	if (root->counters.count_collect_animation < 80)
		root->collect[i].path = root->path.collect[0];
	else if (root->counters.count_collect_animation < 160)
		root->collect[i].path = root->path.collect[1];
	else if (root->counters.count_collect_animation < 240)
		root->collect[i].path = root->path.collect[2];
	else if (root->counters.count_collect_animation < 320)
		root->collect[i].path = root->path.collect[3];
	else if (root->counters.count_collect_animation < 400)
		root->collect[i].path = root->path.collect[4];
	else if (root->counters.count_collect_animation < 480)
		root->collect[i].path = root->path.collect[5];
	else if (root->counters.count_collect_animation < 560)
		root->collect[i].path = root->path.collect[6];
	else
		root->collect[i].path = root->path.collect[7];
}

void	collect_animation(t_root *root)
{
	int	i;

	i = root->quant.quant_collect - 1;
	collect_counter(root);
	while (i >= 0)
	{
		collect_all_animation(root, i);
		i--;
	}
}
