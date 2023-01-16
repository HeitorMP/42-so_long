/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:49:12 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/19 19:49:13 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	game_over_sucess(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, 32, 16711680, \
		"Congratulations!");
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, root->playfield.lin * 32, \
	16711680, "Image credits: https://pipoya.itch.io/");
	return (0);
}

int	game_over_fail(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, 32, 16711680, \
		"You Die!");
	mlx_string_put(root->mlx.mlx, root->mlx.win, 32, root->playfield.lin * 32, \
	16711680, "Image credits: https://pipoya.itch.io/");
	return (0);
}

int	game_over(t_root *root)
{
	if (root->flags.is_game_over_fail)
		game_over_fail(root);
	else
		game_over_sucess(root);
	return (0);
}
