/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartet_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:34:32 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:34:34 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns a hex character representing a quartet of bytes.
*/

char	quartet_to_hex(unsigned char quartet)
{
	quartet = quartet & 0xf;
	if (quartet < 10)
		return (quartet + '0');
	else
		return ((quartet - 10) + 'a');
}
