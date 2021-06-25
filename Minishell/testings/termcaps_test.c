/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:40:37 by tidminta          #+#    #+#             */
/*   Updated: 2021/06/25 17:48:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

static void		sighandler(int sign)
{
	printf("YOU ARE TRYING TO CATCH THE [%d] SIGNAL !\n", sign);
	sleep(1);
	exit(0);
}

void		global(void)
{
	pid_t	ret_fork;
	pid_t	child_death;
	pid_t	this_pid;
	int		deathindicator;
	int		cpt;
	
	cpt = 0;	
	ret_fork = fork();
	if (ret_fork == 0)
	{
		this_pid = getpid();
		printf("we are in children process[%d]\n", this_pid);
		sleep(5);
		printf("[CHILD PROCESS]TRY NOW TO CATCH THE SIGNAL, READY ?\n");
		sleep(3);
		while (++cpt < 10)
		{
			printf("[CHILD PROCESS][LOOP]\n");
			sleep(1);
		}
		printf("[CHILD PROCESS][LOOP END]\n");
		sleep(5);
		kill(this_pid, SIGKILL);
	}
	else
	{
		child_death = wait(&deathindicator);
		printf("[FATHER PROCESS]THE FATHER IS NOW WAITING IS SONS'S DEATH ...\n");
		sleep(5);
		printf("THE CHILD IS DEAD by [%d] !\nWAIT RET : %d\n", deathindicator, child_death);
		sleep(30);
		printf("TRY NOW TO CATCH THE SIGNAL, READY ?\n");
		sleep(20);
		while (++cpt < 10)
		{
			printf("[FATHER PROCESS]\n");
			sleep(1);
		}
	}
}

static int color_test(void)
{
	char *aff_cap;
	char *reset_cmd;
	char *cursor_move;

	//declaration des capacité ...
	aff_cap = tgetstr("AF", NULL);
	reset_cmd = tgetstr("me", NULL);
	cursor_move = tgetstr("cm", NULL);
	//tputs pour la graphical output, tparm pour sa configutation 
	tputs(tparm(aff_cap, COLOR_RED), 1, putchar);
	printf("Paris\n");
	sleep(1);
	tputs(tparm(aff_cap, COLOR_BLUE), 1, putchar);
	printf("Est\n");
	sleep(1);
	tputs(tparm(aff_cap, COLOR_RED), 1, putchar);
	printf("Magique\n");
	sleep(1);
	tputs(tparm(aff_cap, COLOR_YELLOW), 1, putchar);
	printf("RESETING ...\n");
	sleep(2);
	tputs(reset_cmd, 1, putchar);
	printf("RESET SUCCESS\n");
	sleep(1);
	return (0);
}

int main(void)
{
	int init;
	char *term_type;

	term_type = getenv("TERM");
	init = tgetent(NULL, term_type);
	if (init > 0)
	{
		signal(SIGINT, sighandler);
		signal(SIGQUIT, sighandler);
		printf("HELLO GLOBAL\n");
		sleep(1);
		// global();
		color_test();
	}
	else
		printf("TERMCAP INIT FAILLED ...\n");
	
	return (0);
}
