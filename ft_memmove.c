/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-hac <imel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:04:55 by imel-hac          #+#    #+#             */
/*   Updated: 2026/11/10 09:51:47 by imel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dest);
	d = dest;
	s = src;
	if (d < s)
		ft_memcpy(dest, src, n);
	else if (s < d)
	{
		d += (n - 1);
		s += (n - 1);
		while (n--)
		{
			*d = *s;
			d--;
			s--;
		}
	}
	return (dest);
}
