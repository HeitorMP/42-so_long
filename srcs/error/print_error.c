/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:40:46 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/16 11:40:48 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	print_error(t_root *root)
{
	if (root->flags.has_init_error)
	{
		if (root->flags.is_collect_present == 0)
			ft_printf("Error: No collectable is present!\n");
		else if (root->flags.is_exit_present != 1)
			ft_printf("Error: No exit or more then one exit in map!\n");
		else if (root->flags.is_player_present != 1)
			ft_printf("Error: No player spawn or more then one spawn in map!\n");
		else if (root->flags.is_not_square)
			ft_printf("Error: The map is not a rectangle\n");
		else if (root->flags.is_not_border)
			ft_printf("Error: The map is not completely surrounded by walls!\n");
		else if (root->flags.is_not_way_out)
			ft_printf("Error: Your map is invalid. No way out!\n");
		else if (root->flags.is_invalid_element)
			ft_printf("Error: Your map is invalid. Invalid element!\n");
		else if (root->flags.is_not_ber)
			ft_printf("Error: Your map is not a ber file!\n");
		exit_game_init_error(root);
	}
	return (0);
}
