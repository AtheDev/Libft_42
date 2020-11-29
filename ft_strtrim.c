/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:14:44 by adupuy            #+#    #+#             */
/*   Updated: 2020/11/20 10:39:38 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_sep(s1[i], set) && s1[i] != '\0')
		i++;
	len = ft_strlen(s1);
	while (ft_sep(s1[len - 1], set) && len > i)
		len--;
	if (!(str = malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	j = 0;
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
