/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:04:05 by lmkhwana          #+#    #+#             */
/*   Updated: 2018/05/28 10:11:11 by lmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *a;
	char *b;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		a = (char *)s1;
		b = (char *)s2;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
