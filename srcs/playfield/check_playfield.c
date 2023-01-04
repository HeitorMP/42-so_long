/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playfield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:47:20 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/18 23:47:23 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_horizontal_borders(t_root *root)
{
	size_t	i;
	size_t	lin;

	lin = root->playfield.lin - 1;
	i = 0;
	while (i < root->playfield.col - 2)
	{
		if (root->playfield.playfield[0][i] != '1' || \
			root->playfield.playfield[lin][i] != '1')
		{
			root->flags.has_init_error = 1;
			root->flags.is_not_border = 1;
			break ;
		}
		i++;
	}
}

void	check_vertical_borders(t_root *root)
{
	size_t	i;
	size_t	col;

	col = root->playfield.col - 2;
	i = 0;
	while (i < root->playfield.lin)
	{
		if (root->playfield.playfield[i][0] != '1' || \
			root->playfield.playfield[i][col] != '1')
		{
			root->flags.has_init_error = 1;
			root->flags.is_not_border = 1;
			break ;
		}
		i++;
	}
}

void	check_playfield(t_root *root)
{
	size_t	lines;
	size_t	len;

	len = ft_strlen(root->playfield.playfield[0]);
	lines = 1;
	while (lines < root->playfield.lin)
	{
		if (len != ft_strlen(root->playfield.playfield[lines]))
		{
			root->flags.has_init_error = 1;
			root->flags.is_not_square = 1;
			break ;
		}
		lines++;
	}
	check_horizontal_borders(root);
	check_vertical_borders(root);
}
