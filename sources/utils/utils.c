#include "tokenization.h"
#include "utils.h"
// TEXAPOXEL HEADER FILE-I MEJ!!!

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int	ft_is_operator(char *s, int i)
{
	int	op_len;

	if (s[i] == '|' || s[i] == '&' || s[i] == '>' || s[i] == '<')
	{
		if (s[i + 1] && s[i] == s[i + 1])
			op_len = 2;
		else
			op_len = 1;
	}
	else
		op_len = 0;
	return (op_len);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

void	print_token_list(t_token *token_list)
{
	if (!token_list)
		return ;
	while (token_list)
	{
		printf("\033[0;030m(%d)\033[0;032m[%s]\033[0m",
			token_list->type, token_list->value);
		if (token_list && token_list->next)
			printf("\033[0;036m -> \033[0m");
		else
			printf("\n");
		token_list = token_list->next;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return ("");
	if (len <= ft_strlen(s))
		str = (char *) malloc(sizeof(char) * (len + 1));
	else
		str = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}