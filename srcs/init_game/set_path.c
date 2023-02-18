/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:57:38 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/02/18 12:07:52 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_elements_path(t_root *root)
{
	root->path.floor = "./textures/floor.xpm";
	root->path.hero_right = "./textures/hero/hero_right.xpm";
	root->path.hero_left = "./textures/hero/hero_left.xpm";
	root->path.hero_up = "./textures/hero/hero_up.xpm";
	root->path.hero_down = "./textures/hero/hero_down.xpm";
	root->path.border_wall_hu = "./textures/walls/hu.xpm";
	root->path.border_wall_vl = "./textures/walls/vl.xpm";
	root->path.border_wall_bl = "./textures/walls/bl.xpm";
	root->path.border_wall_br = "./textures/walls/br.xpm";
	root->path.border_wall_ul = "./textures/walls/ul.xpm";
	root->path.border_wall_ur = "./textures/walls/ur.xpm";
	root->path.inner_wall = "./textures/walls/inner.xpm";
	root->path.closed_door = "./textures/elements/door_closed.xpm";
	root->path.opened_door = "./textures/elements/door_opened.xpm";
}

void	set_collect_path(t_root *root)
{
	root->path.collect = malloc(sizeof(char *) * 8);
	root->path.collect[0] = "./textures/elements/collect0.xpm";
	root->path.collect[1] = "./textures/elements/collect1.xpm";
	root->path.collect[2] = "./textures/elements/collect2.xpm";
	root->path.collect[3] = "./textures/elements/collect3.xpm";
	root->path.collect[4] = "./textures/elements/collect4.xpm";
	root->path.collect[5] = "./textures/elements/collect5.xpm";
	root->path.collect[6] = "./textures/elements/collect6.xpm";
	root->path.collect[7] = "./textures/elements/collect7.xpm";
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
