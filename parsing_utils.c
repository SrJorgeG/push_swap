#include "push_swap.h"

#include "libft.h"

static size_t	ft_wlength(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_chrcounter(const char *s, char c)
{
	size_t	cont;
	size_t	i;

	cont = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cont++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (cont);
}

static void	*ft_free(char **spl, int i)
{
	while (i)
		free(spl[--i]);
	free(spl);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**spl;	

	i = 0;
	j = 0;
	spl = malloc(sizeof(char *) * (ft_chrcounter(s, c) + 1));
	if (!spl)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			spl[j] = ft_substr(s + i, 0, ft_wlength(s + i, c));
			if (!spl[j])
				return (ft_free(spl, j));
			j++;
			i += ft_wlength(s + i, c);
		}
		else
			i++;
	}
	spl[j] = NULL;
	return (spl);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}
