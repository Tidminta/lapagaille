#include "../../includes/libshell.h"
t_gc *g_gc = NULL;

void	gc_init()
{
	g_gc = malloc(sizeof(t_gc));
	if (!g_gc)
		return ;
	g_gc->normal = NULL;
	g_gc->mute = NULL;
	g_gc->dst = 0;
}

int		free_normal_target(void *target)
{
	t_addr *ptr;
	t_addr *ptr2;

	if (!g_gc->normal)
		return (0);
	ptr = g_gc->normal;
	while (ptr)
	{
		if (ptr->n && ptr->n->g == target)
		{
			ptr2 = ptr->n;
			ptr->n = ptr2->n;
			free(ptr2->g);
			free(ptr2);
			return (1);
		}
		ptr = ptr->n;
	}
	return (0);
}

int		free_mute_target(void *target)
{
	t_addr *ptr;
	t_addr *ptr2;

	if (!g_gc->mute)
		return (0);
	ptr = g_gc->mute;
	while (ptr)
	{
		if (ptr->n && ptr->n->g == target)
		{
			ptr2 = ptr->n;
			ptr->n = ptr2->n;
			free(ptr2->g);
			free(ptr2);
			return (1);
		}
		ptr = ptr->n;
	}
	return (0);
}

void	gc_free_calloc(char **_calloc)
{
	int i;

	i = -1;
	while (_calloc[++i])
		gc_free(_calloc[i]);
	gc_free(_calloc[i]);
	gc_free(_calloc);
}

void	gc_free(void *ptr)
{
	if (!free_mute_target(ptr))
		free_normal_target(ptr);
}

void	free_mute()
{
	t_addr *ptr;

	if (!g_gc->mute)
		return ;
	while (g_gc->mute)
	{
		ptr = g_gc->mute;
		free(ptr->g);
		free(ptr);
		g_gc->mute = g_gc->mute->n;
	}
	g_gc->mute = NULL;
}

void	free_normal()
{
	t_addr *ptr;

	while (g_gc->normal)
	{
		ptr = g_gc->normal;
		free(ptr->g);
		free(ptr);
		g_gc->normal = g_gc->normal->n;
	}
	g_gc->normal = NULL;
}

int		collect(int mode)
{
	if (!g_gc)
		return (0);
	if (!mode || mode == 2)
		free_normal();
	if (mode || mode == 2)
		free_mute();
	if (mode == 2)
	{
		free(g_gc);
		g_gc = NULL;
	}
	return (1);
}

void	gc(char *instr)
{
	if (!g_gc)
		gc_init();
	if (!ft_strncmp(instr, "pause", ft_strlen(instr)))
		g_gc->dst = 1;
	else if (!ft_strncmp(instr, "resume", ft_strlen(instr)))
		g_gc->dst = 0;
	else if (!ft_strncmp(instr, "collect", ft_strlen(instr)))
		collect(0);
	else if (!ft_strncmp(instr, "collect -mute", ft_strlen(instr)))
		collect(1);
	else if (!ft_strncmp(instr, "collect -all", ft_strlen(instr)))
		collect(2);
	else
	{
		write(2, "GC_BAD_INSTR", 12);
		exit (0);
	}
}

int		push_to_mute(t_addr *new)
{
	if (!g_gc->mute)
	{
		g_gc->mute = new;
		return (1);
	}
	if (g_gc->dst)
	{
		new->n = g_gc->mute;
		g_gc->mute->p = new;
		g_gc->mute = new;
		return (1);
	}
	return (1);
}

int		push_to_normal(t_addr *new)
{
	if (!g_gc->normal)
	{
		g_gc->normal = new;
		return (1);
	}
	if (g_gc->normal)
	{
		new->n = g_gc->normal;
		g_gc->normal->p = new;
		g_gc->normal = new;
		return (1);
	}
	return (1);
}

int			gc_push(void ***g)
{
	t_addr *new;

	new = malloc(sizeof(t_addr));
	if (!new)
		return (0);
	new->g = g;
	new->n = NULL;
	new->p = NULL;
	if (g_gc->dst)
		return (push_to_mute(new));
	else
		return (push_to_normal(new));
	return (1);
}

void	*gc_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	gc_push(ret);
	return (ret);
}
