/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:21:23 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/06/07 18:12:05 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t destsize)
{
	size_t		i;
	size_t		j;
	char		*ddest;
	char		*ssrc;

	ddest = dest;
	ssrc = (char *)src;
	i = ft_strlen(ddest);
	j = ft_strlen(ssrc);
	if (i > destsize)
		return (j + destsize);
	if (i < destsize)
	{
		ft_strncat(dest, ssrc, destsize - 1);
		dest[destsize - 1] = '\0';
	}
	return (i + j);
}
