/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:30:05 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/25 11:36:08 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int			ft_atoi(char *str)
{
	int		i;
	int		min;
	int		res;

	res = 0;
	min = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * min);
}

int			len_num(long x)
{
	int		count;

	count = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		count++;
		x = x * -1;
	}
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		i;
	long	x;

	x = n;
	i = len_num(x);
	if (!(dst = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	dst[i--] = '\0';
	if (x == 0)
		dst[0] = 0 + '0';
	if (x < 0)
	{
		dst[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		dst[i] = x % 10 + '0';
		x = x / 10;
		i--;
	}
	return (dst);
}
