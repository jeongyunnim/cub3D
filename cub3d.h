/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:02:15 by jeseo             #+#    #+#             */
/*   Updated: 2023/04/04 18:42:22 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

# define ERROR -1

typedef enum e_type
{
	NORTH=0x01,
	SOUTH=0x02,
	WEST=0x04,
	EAST=0x08,
	FLOOR=0x10,
	CEILING=0x20
}	t_type;

typedef struct s_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor[3];
	int		ceiling[3];
	int		flag;
}				t_info;

char	**split_is_function(const char *s, int (*f)(int));

#endif
