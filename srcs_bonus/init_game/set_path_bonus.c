/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:57:38 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/18 22:57:41 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	set_elements_path(t_root *root)
{
	root->path.floor = "./sprites/floor.xpm";
	root->path.hero_right = "./sprites/hero/hero_right.xpm";
	root->path.hero_left = "./sprites/hero/hero_left.xpm";
	root->path.hero_up = "./sprites/hero/hero_up.xpm";
	root->path.hero_down = "./sprites/hero/hero_down.xpm";
	root->path.border_wall_hu = "./sprites/walls/hu.xpm";
	root->path.border_wall_vl = "./sprites/walls/vl.xpm";
	root->path.border_wall_bl = "./sprites/walls/bl.xpm";
	root->path.border_wall_br = "./sprites/walls/br.xpm";
	root->path.border_wall_ul = "./sprites/walls/ul.xpm";
	root->path.border_wall_ur = "./sprites/walls/ur.xpm";
	root->path.inner_wall = "./sprites/walls/inner.xpm";
	root->path.closed_door = "./sprites/elements/door_closed.xpm";
	root->path.opened_door = "./sprites/elements/door_opened.xpm";
	root->path.patrol1 = "./sprites/patrol/patrol1.xpm";
	root->path.patrol2 = "./sprites/patrol/patrol2.xpm";
	root->path.patrol3 = "./sprites/patrol/patrol3.xpm";
}

void	set_collect_path(t_root *root)
{
	root->path.collect = malloc(sizeof(char *) * 8);
	root->path.collect[0] = "./sprites/elements/collect0.xpm";
	root->path.collect[1] = "./sprites/elements/collect1.xpm";
	root->path.collect[2] = "./sprites/elements/collect2.xpm";
	root->path.collect[3] = "./sprites/elements/collect3.xpm";
	root->path.collect[4] = "./sprites/elements/collect4.xpm";
	root->path.collect[5] = "./sprites/elements/collect5.xpm";
	root->path.collect[6] = "./sprites/elements/collect6.xpm";
	root->path.collect[7] = "./sprites/elements/collect7.xpm";
}

void	set_init_path(t_root *root)
{
	root->hero.path = root->path.hero_right;
	root->hero.control = 'P';
	root->wall.path = root->path.inner_wall;
	root->wall.control = '1';
	root->exit.path = root->path.closed_door;
	root->exit.control = 'E';
	root->floor.path = root->path.floor;
	root->floor.control = '0';
}

void	set_path(t_root *root)
{
	set_collect_path(root);
	set_elements_path(root);
	set_init_path(root);
}
