#include "push_swap.h"

static size_t	get_number_of_digits(int n)
{
	int	nd;

	nd = 1;
	n = n / 10;
	while (n != 0)
	{
		nd++;
		n = n / 10;
	}
	return (nd);
}

void	create_str(int n, char **r, size_t r_len, size_t space_of_negative)
{
	int	d;

	d = 0;
	(*r)[--r_len] = '\0';
	if (n == 0)
		(*r)[--r_len] = '0';
	while (n != 0)
	{
		d = n % 10;
		if (d < 0)
			d = -d;
		(*r)[--r_len] = d + '0';
		n = n / 10;
	}
	if (space_of_negative > 0)
		(*r)[--r_len] = '-';
}

char	*ft_itoa(int n)
{
	size_t	nd;
	size_t	space_of_negative;
	size_t	r_len;
	char	*r;

	space_of_negative = 0;
	nd = get_number_of_digits(n);
	if (n < 0)
		space_of_negative = 1;
	r_len = nd + 1 + space_of_negative;
	r = (char *)malloc(sizeof(char) * (r_len));
	if (r == NULL)
		return (NULL);
	create_str(n, &r, r_len, space_of_negative);
	return (r);
}