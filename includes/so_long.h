/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:37:50 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/26 16:03:28 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*=======struct=======*/

/* window thing */

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/***************/

/* data */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
/*******/

/*====================*/

# include "../libft/libft.h"
# include "../mlx/mlx.h"


#endif
