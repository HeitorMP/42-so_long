/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:07:24 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:07:29 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_collect(t_root *root)
{
	int	i;

	i = root->quant.quant_collect - 1;
	while (i >= 0)
	{
		put_sprite(root, &root->collect[i], root->collect[i].y, \
		root->collect[i].x);
		i--;
	}
}

void	render_sprites(t_root *root)
{
	put_sprite(root, &root->hero, root->hero.y, root->hero.x);
	render_collect(root);
	put_sprite(root, &root->exit, root->exit.y, root->exit.x);
}

int	game_loop(t_root *root)
{
	animation(root);
	if (!root->flags.is_game_over)
	{
		check_collision_events(root);
		game_events(root);
		render_sprites(root);
	}
	else
		game_over_sucess(root);
	return (0);
}
