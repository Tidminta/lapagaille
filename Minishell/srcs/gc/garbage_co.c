#include "../../includes/libshell.h"

/*
int	gc_push(t_gc **gc, void ***g)
{
	t_gc	*new;
	t_gc	*ptr;

	ptr = *gc;
	new = malloc(sizeof(t_gc));
	if (!new)
		return (0);
	new->g = g;
	new->immune = 0;
	new->n = NULL;
	if (!*gc)
	{
		*gc = new;
		return (1);
	}
	new->n = *gc;
	(*gc)->p = new;
	*gc = new;
	return (1);
}
*/

int			gc_push(t_gc **gc, void ***g)
{
	t_gc *new;

	(void)gc;
	new = malloc(sizeof(t_gc));
	if (!new)
		return (0);
	new->g = g;
	new->immune = 0;
	new->n = NULL;
	new->p = NULL;
	if (!g_gc)
	{
		g_gc = new;
		return (1);
	}
	new->n = g_gc;
	g_gc->p = new;
	g_gc = new;
	return (1);
}

void	*gc_malloc(size_t size)
{
	void	*ret;
	ret = malloc(size);
	gc_push(&g_gc, ret);
	return (ret);
}

void	pop_elem(t_gc *to_find)
{
	t_gc *i;

	i = g_gc;
	while (i)
	{
		if (i == to_find)
		{
			i->p->n = i->n;
			i->n->p = i->p;
			free(i->g);
			free(i);
			return ;
		}
		i = i->n;
	}
}

void	*to_gc(void *ptr, void *ptr2)
{
	t_gc *ptr3;

	ptr3 = g_gc;
	while (ptr3->g != ptr)
		ptr3 = ptr3->n;
	if (ptr3)
		pop_elem(ptr3);
	return (ptr2);
}

int		collect()
{
	
	return (1);
}
