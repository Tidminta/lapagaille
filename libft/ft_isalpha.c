/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:46:56 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/13 22:12:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	unsigned char new_c;

	new_c = (unsigned char)c;
	if ((new_c >= 'a' && new_c <= 'z') || (new_c >= 'A' && new_c <= 'Z'))
		return (1);
	else
		return (0);
}
