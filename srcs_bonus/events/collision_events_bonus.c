/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:08:55 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:08:58 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_collision_exit(t_root *root)
{
	if (collision(&root->hero, &root->exit))
	{
		root->flags.is_game_over = 1;
		root->flags.is_game_over_fail = 0;
	}
}

void	check_collision_collect(t_root *root)
{
	int	i;

	i = root->quant.quant_collect - 1;
	while (i >= 0 && root->counters.count_collect)
	{
		if (collision(&root->hero, &root->collect[i]))
		{
			put_sprite(root, &root->collect[i], root->playfield.lin + 1, \
			root->counters.count_collect);
			root->counters.count_collect--;
		}
		i--;
	}
}

void	check_collision_patrol(t_root *root)
{
	int	i;

	i = root->quant.quant_patrol - 1;
	while (i >= 0)
	{
		if (collision(&root->hero, &root->patrol[i]))
		{
			root->flags.is_game_over_fail = 1;
			root->flags.is_game_over = 1;
		}
		i--;
	}
}

void	check_collision_events(t_root *root)
{
	check_collision_exit(root);
	check_collision_patrol(root);
	check_collision_collect(root);
}
