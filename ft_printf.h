/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:15:57 by samcasti          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:59 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define BUFFER_SIZE (4096)

typedef struct s_format
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			precision;
	char		specifier;
}				t_format;

typedef struct s_data
{
	const char	*str;
	va_list		ap;
	int			written_chars;
	char		*buffer;
	int			buffer_index;

	t_format	format;
}				t_data;

void			ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);

#endif
