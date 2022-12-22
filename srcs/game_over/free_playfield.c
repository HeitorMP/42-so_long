/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_playfield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:09:30 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:09:34 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	playfield_free(t_root *root)
{
	size_t	lines;

	lines = 0;
	if (!root->playfield.playfield)
		return (0);
	while (lines < root->playfield.lin)
	{
		free(root->playfield.playfield[lines]);
		lines++;
	}
	free(root->playfield.playfield);
	lines = 0;
	if (!root->playfield.playfield_mask)
		return (0);
	while (lines < root->playfield.lin)
	{
		free(root->playfield.playfield_mask[lines]);
		lines++;
	}
	free(root->playfield.playfield_mask);
	return (1);
}
