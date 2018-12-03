/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:38:22 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/03 17:38:42 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_power(unsigned long nbr, unsigned long pow)
{
	unsigned long long i;
	unsigned long long tmp;

	i = 1;
	tmp = nbr;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		nbr = nbr * tmp;
		i++;
	}
	return (nbr);
}
