#ifndef GC_H
# define GC_H

typedef struct s_addr
{
	void							*g;
	int								immune;
	struct s_addr *					n;
	struct s_addr *					p;
}									t_addr;

typedef struct s_garbage_collector
{
	void							*to_ignore;
	int								dst;
	t_addr							*normal;
	t_addr							*mute;
}									t_gc;

extern t_gc *g_gc;

int		gcpush(void ***g);
void	gc_init();
void	*gc_malloc(size_t size);
void	*to_gc(void *ptr, void *ptr2);
void	gc(char *instr);
int		collect(int mode);
#endif
