/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:39:27 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/10/28 17:31:14 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*-----------------*/
/*  Custom perror  */
/*-----------------*/
void	ft_perror(char *error_msg)
{
	write(2, "Error\n", 6);
	if (error_msg != NULL)
	{
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
}

/*------------------------------------------------------------------*/
/*  Show error message, free all allocated memory and exit program  */
/*------------------------------------------------------------------*/
void	error_free_exit(t_data *data, char *error_msg)
{
	ft_perror(error_msg);
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	free_exit(data, EXIT_FAILURE);
}
