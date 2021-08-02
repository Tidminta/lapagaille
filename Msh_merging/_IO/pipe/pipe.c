#include "../../includes/libshell.h"

void		ispipe(t_msh *msh)
{//RENVOI LE NOMBRE DE PIPE
	t_cut_cmd	*cmd;
	int			cpt;

	cmd = msh->tools->tail;
	cpt = 0;
	while (cmd != NULL)
	{
		if (cmd->TOKEN == PIPE)
			cpt++;
		cmd = cmd->p;
	}
	msh->tools->nbpipe = cpt;
}

int			getnext_pipe(t_cut_cmd **cmd)
{//PERMET DE GET LA CMD APRES LE PROCHAIN PIPE
	while((*(cmd)) != NULL && (*(cmd))->TOKEN != PIPE)
		(*(cmd)) = (*(cmd))->p;
	if ((*(cmd)) != NULL && (((*(cmd))->p->TOKEN == C_ENV
		|| (*(cmd))->p->TOKEN == C_BUILTIN)))//SOUS ENTEND QUE NOUS SOMME SUR UN PIPE
		(*(cmd)) = (*(cmd))->p;
	//ICI SOIT NOUS SOMMES SUR UNE CMD SOIT SUR NUL |
	if ((*(cmd)))
		return (SUCCESS);
	else 
		return (-1);
}

void		whatpostions(t_msh *msh)
{
	t_cut_cmd	*cmd;
	t_cut_cmd	*tmp;
	
	cmd = msh->tools->tail;
	getnext_pipe(&cmd);
	while (cmd != NULL)
	{
		tmp = cmd;
		if (getnext_pipe(&cmd) == -1)
			tmp->TOKEN = LAST_CMD;
	}
}
