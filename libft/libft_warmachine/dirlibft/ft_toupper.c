/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:19:49 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/14 15:47:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	unsigned char new_c;

	new_c = (unsigned char)c;
	if (new_c >= 'a' && new_c <= 'z')
		new_c = new_c - 32;
	c = (int)new_c;
	return (c);
}
