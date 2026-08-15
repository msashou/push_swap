
#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*r;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	r = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	k = 0;
	while (i < s1_len)
		r[i++] = s1[k++];
	k = 0;
	while (k < s2_len)
		r[i++] = s2[k++];
	r[i] = '\0';
	return (r);
}