#ifndef GC_H
# define GC_H
typedef struct s_garbage_collector
{
	void							*g;
	int								immune;
	struct s_garbage_collector *	n;
	struct s_garbage_collector *	p;
}									t_gc;
static t_gc *g_gc = NULL;

int		gc_push(t_gc **gc, void ***g);
void	*gc_malloc(size_t size);
void	*to_gc(void *ptr, void *ptr2);
int		collect(void);
#endif
