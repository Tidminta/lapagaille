#include "shlib.h"

t_gc *g_gc = NULL;
int	gc_push(t_gc **gc, void ***g)
{
	t_gc	*new;

	new = malloc(sizeof(t_gc));
	if (!new)
		return (0);
	new->g = g;
	new->n = NULL;
	if (!*gc)
	{
		*gc = new;
		return (1);
	}
	new->n = *gc;
	*gc = new;
	return (1);
}

void	*gc_malloc(size_t size)
{
	void	*ret;
	ret = malloc(size);
	gc_push(&g_gc, ret);
	return (ret);
}

void	*to_gc(void *ptr, void *ptr2)
{
	t_gc	*tmp2;

	tmp2 = g_gc;
	while (tmp2)
	{
		if (ptr == tmp2->g)
		{
			g_gc = tmp2->n;
			free(tmp2->g);
			free(tmp2);
			return (ptr2);
		}
		tmp2 = tmp2->n;
	}
	return (ptr2);
}

int		collect()
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp2 = g_gc;
	while (tmp2)
	{
		tmp = tmp2;
		free(tmp->g);
		tmp2 = tmp2->n;
		free(tmp);
	}
}
