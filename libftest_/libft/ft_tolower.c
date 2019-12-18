/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:55:17 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/14 16:02:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	unsigned char new_c;

	new_c = (unsigned char)c;
	if (new_c >= 'A' && new_c <= 'Z')
		new_c = new_c + 32;
	c = (int)new_c;
	return (c);
}
