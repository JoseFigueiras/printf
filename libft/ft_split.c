#include "libft.h"

static t_uint	word_count(char const *str, char sep);
static int		init_list(char const *str, char sep, char **list, t_uint
					n_words);
static t_uint	count_letters(char const *str, char sep);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	t_uint	n_words;

	n_words = word_count(s, c);
	ret = malloc((n_words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	if (!(init_list(s, c, ret, n_words)))
		return (NULL);
	ret[n_words] = NULL;
	return (ret);
}

static int	init_list(char const *str, char sep, char **list, t_uint n_words)
{
	t_uint	word_index;
	t_uint	next_word_len;
	t_uint	i;

	word_index = 0;
	while (word_index < n_words)
	{
		while (*str == sep)
			str++;
		next_word_len = count_letters(str, sep);
		if (next_word_len == 0)
		{
			list[word_index] = NULL;
			return (1);
		}
		list[word_index] = malloc(next_word_len);
		if (!(list[word_index]))
			return (0);
		i = 0;
		while (*str != sep && *str)
			list[word_index][i++] = *str++;
		list[word_index][next_word_len] = '\0';
		word_index++;
	}
	return (1);
}

static t_uint	count_letters(char const *str, char sep)
{
	t_uint	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static t_uint	word_count(char const *str, char sep)
{
	t_uint	counter;
	t_uint	is_word;

	if (!str)
		return (0);
	is_word = FALSE;
	counter = 0;
	while (*str)
	{
		if (!is_word && *str != sep)
		{
			counter++;
			is_word = TRUE;
		}
		else if (is_word && *str == sep)
			is_word = FALSE;
		str++;
	}
	return (counter);
}
