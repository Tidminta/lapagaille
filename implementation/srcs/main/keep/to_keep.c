// void	insert_things(t_msh **msh, t_cut_cmd **env_lst, t_cut_cmd *new_block)
// {
// 	t_cut_cmd	**tracer;
// 	t_cut_cmd	**go_to;
// 	char		*str;
// 	size_t		len;

// 	(void)go_to;
// 	tracer = env_lst;
// 	str = new_block->elem;
// 	len = ft_strlen(str);
// 	printf("[new block = %s]\n", new_block->elem);
// 	while ((*tracer) != NULL && (ft_strncmp((*tracer)->elem, str, len) < 1))
// 		(tracer) = &(*tracer)->n;
// 	if (*tracer)
// 	{
// 		new_block->p = (*tracer);
// 		new_block->n = (*tracer)->n;
// 		(*tracer)->n = new_block;
// 		(*tracer)->n->p = new_block;
// 	}
// 	else
// 	{
// 		new_block->p = (*msh)->env->tail;
// 		(*msh)->env->tail->n = new_block;
// 		(*msh)->env->tail = new_block;
// 	}
// 	(*msh)->env->size++;
// }
