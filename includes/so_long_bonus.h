/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:24:37 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/01/03 18:10:23 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"
# include <time.h>

void	patrol_animation(t_root *root);
int		game_over(t_root *root);
void	check_move_patrol(t_root *root);
void	random_patrol_pos(t_root *root);

#endif
