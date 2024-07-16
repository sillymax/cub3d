/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:48:48 by ychng             #+#    #+#             */
/*   Updated: 2024/07/16 22:52:52y ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_main	main;	

	if (argc != 2)
		exit_with_error("wrong number of args.");
	init_main(&main);
	parse_map(&main, argv[1]);
	mlx_loop_hook(main.minilibx.mlx, render_frame, &main);
	mlx_loop(main.minilibx.mlx);
	return (PASS);
}
