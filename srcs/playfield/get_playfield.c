/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_playfield.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:38:15 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/15 20:38:19 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_map_size(t_root *root)
{
	char	*temp;

	root->playfield.lin = 0;
	temp = get_next_line(root->map_file.fd);
	while (temp)
	{
		root->playfield.col = ft_strlen(temp);
		root->playfield.lin++;
		free(temp);
		temp = get_next_line(root->map_file.fd);
	}
	free(temp);
	close(root->map_file.fd);
	return (1);
}

void	get_playfield(t_root *root)
{
	size_t	lines;

	lines = 0;
	get_map_size(root);
	root->playfield.playfield = malloc(sizeof(char *) * root->playfield.lin);
	root->playfield.playfield_mask = malloc(sizeof(char *) \
		* root->playfield.lin);
	root->map_file.fd = open(root->map_file.path, O_RDONLY);
	while (lines < root->playfield.lin)
	{
		root->playfield.playfield[lines] = get_next_line(root->map_file.fd);
		root->playfield.playfield_mask[lines] = \
			ft_strdup(root->playfield.playfield[lines]);
		if (!root->playfield.playfield[lines])
			break ;
		lines++;
	}
	close(root->map_file.fd);
}
