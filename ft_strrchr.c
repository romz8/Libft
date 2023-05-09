/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:11 by rjobert           #+#    #+#             */
/*   Updated: 2023/05/09 18:27:29 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_ptr;

	last_ptr = NULL;
	while (*str)
	{
		if (*str == c)
			last_ptr = (char *) str;
		str++;
	}
	if (*str == c)
		last_ptr = (char *) str;
	return (last_ptr);
}
