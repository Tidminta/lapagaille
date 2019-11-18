/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:41:28 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/13 22:51:50 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int c)
{
	unsigned char new_c;

	new_c = (unsigned char)c;
	if (new_c >= 0 && new_c <= 127)
		return (1);
	else
		return (0);
}
