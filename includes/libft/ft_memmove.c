#include <string.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char	*s;
	unsigned char	*d;

	if (!dest && !src)
		return (0);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s < d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (d);
	}
	else
		return (ft_memcpy(dest, src, n));    
}
