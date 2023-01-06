/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:10:13 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:10:16 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	set_quant(t_root *root)
{
	root->quant.quant_collect = 0;
	root->quant.quant_patrol = MONSTERS;
	root->patrol = malloc(sizeof(t_sprite) * root->quant.quant_patrol);
}

void	set_flags(t_root *root)
{
	set_quant(root);
	root->flags.has_init_error = 0;
	root->flags.has_ingame_error = 0;
	root->flags.is_files_not_present = 0;
	root->flags.is_invalid_element = 0;
	root->flags.is_collect_present = 0;
	root->flags.is_player_present = 0;
	root->flags.is_exit_present = 0;
	root->flags.is_not_border = 0;
	root->flags.is_not_square = 0;
	root->flags.is_door_open = 0;
	root->flags.is_game_over = 0;
	root->flags.is_not_ber = 0;
	root->flags.is_not_way_out = 0;
	root->hero.direction = RIGHT;
}
