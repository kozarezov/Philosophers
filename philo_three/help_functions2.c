/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:45:44 by ceccentr          #+#    #+#             */
/*   Updated: 2020/10/25 15:00:19 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			ft_strlcat(char *dst, const char *src, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (src[j] != '\0')
		j++;
	while (dst[k] != '\0' && k < size)
		k++;
	if (size == 0)
		return (j);
	if (size <= k)
		return (j + size);
	while (i < (size - k - 1) && src[i] != '\0')
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (j + k);
}

int			ft_strlcpy(char *dst, const char *src, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(dst = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(dst, s1, (len_s1 + 1));
	ft_strlcat(dst, s2, (len_s1 + len_s2 + 1));
	return (dst);
}
