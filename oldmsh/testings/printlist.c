static void 	print_list(t_env_lair *env_lair)
{
	int 	test;

	test = 1;
	t_env_list *current;

	current = env_lair->start;
	printf("| DEBUT | \n");
	while (current != NULL)
	{
		printf("%d-> %s\n", test, current->content);
		current = current->next;
		test++;
	}
	printf("\n***\nsize env_lair -> %d\n", env_lair->size);
	printf("first env_lair -> %s\n", env_lair->start->content);
	printf("end  env_lair -> %s\n", env_lair->end->content);
	printf("| FIN |\n");
}



// static void 	print_list(t_env_lair *env_lair)
// {
// 	int 	test; // pour le printf

// 	test = 1; // pour le printf
// 	t_env_list *current;

// 	current = env_lair->start;
// 	printf("| DEBUT | \n");
// 	while (current->next != NULL)
// 	{
// 		printf("[%d][%s]\n", test, current->content);
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("[hors boucle][%d][%s]\n", test, current->content);
// 	printf("| FIN |\n");
// 	printf("[size env_lair][%d]\n", env_lair->size);
// 	printf("[first env_lair][%s]\n", env_lair->start->content);
// 	printf("[end  env_lair][%s]\n", env_lair->end->content);
// }
//
//
//
//
// ////////////////////////////////////////////////////////////////
// FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
static void 	print_list(t_env_lair *env_lair)
{
	int 	test; // pour le printf

	test = 1; // pour le printf
	t_env_list *current;

	current = env_lair->start;
	printf("| DEBUT | \n");
	while (current != NULL)
	{
		printf("%d-> %s\n", test, current->content);
		current = current->next;
		test++; // pour le printf
	}
	printf("| FIN |\n");
	printf("size env_lair -> %d\n", env_lair->size);
	printf("first env_lair -> %s\n", env_lair->start->content);
	printf("end  env_lair -> %s\n", env_lair->end->content);
}
////////////////////////////////////////////////////////////////
