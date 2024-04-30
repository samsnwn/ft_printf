/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcasti <samcasti@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:15:50 by samcasti          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:52 by samcasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_args(const char *str);

int	ft_printf(const char *, ...)
{
	// loop over char* until we find a%,then we stop and say: this will be one argument.
	// count_args(const char *);
	return (0);
}

int	count_args(const char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}
