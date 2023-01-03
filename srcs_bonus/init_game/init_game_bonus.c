/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:00:53 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/16 11:00:54 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_ber_file(t_root *root)
{
	int	begin;

	begin = ft_strlen(root->map_file.path) - 4;
	if (ft_strncmp(root->map_file.path + begin, ".ber", 4) != 0)
	{
		root->flags.has_init_error = 1;
		root->flags.is_not_ber = 1;
	}
}

void	set_elements(t_root *root, char element, size_t y, size_t x)
{
	if (element == 'C')
	{
		root->flags.is_collect_present = 1;
		root->counters.count_collect++;
	}
	else if (element == 'P')
	{
		root->flags.is_player_present++;
		root->hero.y = y;
		root->hero.x = x;
	}
	else if (element == 'E')
	{
		root->flags.is_exit_present++;
		root->exit.x = x;
		root->exit.y = y;
	}
	else if (element == '0' && root->counters.count_patrol)
	{
		root->counters.count_patrol--;
		root->playfield.playfield[y][x] = 'M';
		root->patrol.x = x;
		root->patrol.y = y;
	}
}

void	check_elements(t_root *root)
{
	size_t	lines;
	size_t	cols;

	lines = 0;
	cols = 0;
	while (lines < root->playfield.lin)
	{
		while (cols < root->playfield.col)
		{
			set_elements(root, root->playfield.playfield[lines][cols], \
			lines, cols);
			cols++;
		}
		cols = 0;
		lines++;
	}
	if (root->flags.is_player_present != 1 || root->flags.is_exit_present != 1 \
		|| root->flags.is_collect_present != 1)
		root->flags.has_init_error = 1;
}

void	init_game(t_root *root)
{
	root->map_file.fd = open(root->map_file.path, O_RDONLY);
	if (root->map_file.fd == -1)
	{
		ft_printf("Error: No map file found!\n");
		exit (EXIT_FAILURE);
	}
	set_flags(root);
	set_counters(root);
	set_path(root);
	get_playfield(root);
	check_playfield(root);
	check_elements(root);
	if (root->flags.has_init_error == 0)
		flood_fill(root);
	check_ber_file(root);
}
