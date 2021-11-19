/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:28:56 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:56:11 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (j < len && s[start])
	{
		new[j] = s[start];
		start++;
		j++;
	}
	if (start > ft_strlen(s))
		new[0] = 0;
	new[j] = 0;
	return (new);
}
