#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		is_negative;
	size_t	i;
	int		result;
	char	*tmp_nptr;

	tmp_nptr = (char *)nptr;
	is_negative = 1;
	i = 0;
	result = 0;
	while ((tmp_nptr[i] >= 9 && tmp_nptr[i] <= 13) || tmp_nptr[i] == ' ')
		i++;
	if (tmp_nptr[i] == '+')
		i++;
	else if (tmp_nptr[i] == '-')
	{
		i++;
		is_negative = -is_negative;
	}
	while (is_num(tmp_nptr[i]))
		result = result * 10 + (tmp_nptr[i++] - '0');
	return (result * is_negative);
}