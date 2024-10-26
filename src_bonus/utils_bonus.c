/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:01 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/10/20 16:43:43 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/*----------------------------*/
/*  Convert degree to radian  */
/*----------------------------*/
double	radian(int degree)
{
	return (degree * (M_PI / 180));
}

/*------------------*/
/*  Get RGBA color  */
/*------------------*/
int	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}