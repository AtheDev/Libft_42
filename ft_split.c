/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:03:35 by adupuy            #+#    #+#             */
/*   Updated: 2020/11/20 10:41:26 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_sep(s[i], c))
			if (i == 0 || ft_sep(s[i - 1], c))
				count++;
		i++;
	}
	return (count);
}

static char	*ft_new_str(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while ((!(ft_sep(s[i], c)) && s[i] != '\0'))
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while ((!(ft_sep(s[i], c)) && s[i] != '\0'))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	if (!(split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (!ft_sep(s[i], c))
			if (i == 0 || (ft_sep(s[i - 1], c)))
				split[j++] = ft_new_str(&s[i], c);
		i++;
	}
	split[j] = NULL;
	return (split);
}
