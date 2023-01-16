/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_request.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:20 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:09:24 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_game_request(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_display(root->mlx.mlx);
	free(root->mlx.mlx);
	free(root->path.collect);
	playfield_free(root);
	free(root->collect);
	ft_printf("Good bye and thanks for playing!!\n");
	exit (EXIT_SUCCESS);
	return (0);
}
