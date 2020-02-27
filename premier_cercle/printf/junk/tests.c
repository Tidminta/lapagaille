/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/27 18:14:37 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sumnum(int nb, ...)
{
	va_list list_ptr;
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	va_start(list_ptr, nb);
	while (i < nb)
	{
		sum += va_arg(list_ptr, int);
		i++;
	}
	va_end(list_ptr);
	return (sum);
}

int		main(void)
{
	int		somme;
	char	alpha;
	const char *str;
	char		*str2;

	str2 = str;
	somme = ft_sumnum(5, 2, 3, 4, 5, 6);
	alpha = 'a';
	printf("somme = %d\n", somme);
	printf("char = %.3c", alpha);
	return (0);
}

