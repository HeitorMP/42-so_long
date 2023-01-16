/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:07:43 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:07:47 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	input(int keycode, t_root *root)
{
	if (keycode == ESC)
		exit_game_request(root);
	else if (keycode == UP || keycode == DOWN || \
			keycode == LEFT || keycode == RIGHT)
	{
		root->score = ft_itoa(root->counters.count_move);
		mlx_string_put(root->mlx.mlx, root->mlx.win, 100, \
			(root->playfield.lin * 32) + 16, 0, root->score);
		free(root->score);
		check_move_sprite(root, keycode);
	}
	return (0);
}

void	setup_game(t_root *root)
{
	root->collect = malloc(sizeof(t_sprite) * root->quant.quant_collect);
	render_map(root);
}

int	main(int argc, char const *argv[])
{
	t_root	root;

	if (argc != 2)
	{
		ft_printf("Enter map file: ./solong map.ber !\n");
		return (1);
	}
	root.map_file.path = (char *)argv[1];
	init_game(&root);
	if (root.flags.has_init_error)
		print_error(&root);
	root.mlx.mlx = mlx_init();
	root.mlx.win = mlx_new_window(root.mlx.mlx, \
		(root.playfield.col - 1) * BITS, (root.playfield.lin + 2) \
		* BITS, "so long");
	setup_game(&root);
	mlx_key_hook(root.mlx.win, input, &root);
	mlx_loop_hook(root.mlx.mlx, game_loop, &root);
	mlx_hook(root.mlx.win, 17, 0, exit_game_request, &root);
	mlx_loop(root.mlx.mlx);
	exit(EXIT_SUCCESS);
	return (1);
}
