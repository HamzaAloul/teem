/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:30:31 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/06 19:54:12 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(const char *s, char c);

static void	ft_free_all(char **ptr, int i);

static char	*ft_letters_count(const char *s, char c, int *i);

char	**ft_split(const char *s, char c)
{
	int		i;
	int		word;
	int		j;
	char	**ptr;

	word = ft_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word)
	{
		ptr[j] = ft_letters_count(s, c, &i);
		if (!ptr[j])
		{
			ft_free_all(ptr, j);
			return (NULL);
		}
		j++;
	}
	ptr[word] = NULL;
	return (ptr);
}

static void	ft_free_all(char **ptr, int i)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
}

static int	ft_word(const char *s, char c)
{
	int		word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			word++;
		else if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static char	*ft_letters_count(const char *s, char c, int *i)
{
	char	*p;
	size_t	size_word;
	char	*end;

	while (s[*i] && s[*i] == c)
		(*i)++;
	if (!s[*i])
		return (NULL);
	end = ft_strchr(s + *i, c);
	if (!end)
		end = (char *)(s + *i + ft_strlen(s + *i));
	size_word = (size_t)(end - (s + *i));
	p = ft_substr(s, *i, size_word);
	if (!p)
		return (NULL);
	*i += size_word;
	return (p);
}
