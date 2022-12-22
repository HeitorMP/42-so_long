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

int	game_loop(t_root *root)
{
	animation(root);
	if (!root->flags.is_game_over)
	{
		check_collision_events(root);
		game_events(root);
		render_map(root);
	}
	else
		game_over_sucess(root);
	return (0);
}
