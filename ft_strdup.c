
#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, size);
	return (dest);
}