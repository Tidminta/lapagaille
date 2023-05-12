Pipex

int	is_empty_env(t_cut_cmd *env)
{
	if (!env || env == NULL)
		return (SUCCESS);
	return (ERROR);
}

int create_env_list(t_msh **msh, char *content)
{
    t_cut_cmd   *new_block;

    if (is_empty_env((*msh)->env->head))
    {
        new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd));
        if (!new_block)
            return (-1);
        new_block->elem = content;
        new_block->TOKEN = _UNASSIGNED;
        new_block->is_last = 0;
        new_block->p = NULL;
        new_block->n = NULL;
        (*msh)->env->head = new_block;
        (*msh)->env->tail = new_block;
        (*msh)->env->size = 1;
        return (SUCCESS);
    }
    return (ERROR);
}



int add_env(t_msh **msh, char *content, int mode)
{
    t_cut_cmd   *new_block;

    new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd));
    if (!new_block)
        return (-1);
    if (!(ft_strchr(content, '=') + 1))
        new_block->elem = ft_strjoin(content, "=\"\"");
    else
        new_block->elem = ft_strdup(content);
    new_block->n = NULL;
    new_block->p = (*msh)->env->tail;
    if (mode)
        new_block->TOKEN = ENV_SOLO;
    else
        new_block->TOKEN = _UNASSIGNED;
    (*msh)->env->tail->n = new_block;
    (*msh)->env->tail = new_block;
    (*msh)->env->size++;
    return (SUCCESS);
}
