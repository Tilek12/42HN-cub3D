/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:58:58 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/10/28 19:28:19 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/*-------------------------------*/
/*  Set limit for weapon frames  */
/*-------------------------------*/
int	set_frame_limit(t_weapon weapon)
{
	if (weapon == RIFLE)
		return (6);
	else if (weapon == PISTOL)
		return (9);
	else if (weapon == KNIFE)
		return (7);
	return (0);
}

/*-------------------------------*/
/*  Set limit for weapon frames  */
/*-------------------------------*/
mlx_image_t	*set_current_frame(t_weapon weapon, t_sprite *sprite, int frame)
{
	if (weapon == RIFLE)
		return (sprite->rifle[frame]);
	else if (weapon == PISTOL)
		return (sprite->pistol[frame]);
	else if (weapon == KNIFE)
		return (sprite->knife[frame]);
	return (NULL);
}
