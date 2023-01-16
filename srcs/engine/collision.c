/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:07:56 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:07:59 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	collision(t_sprite *element1, t_sprite *element2)
{
	if (element1->x == element2->x && element1->y == element2->y)
		return (1);
	return (0);
}
