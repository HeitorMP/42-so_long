/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:03:34 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/11/27 16:50:33 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_digits(long long int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
nb *= -1;
digits = 1;
	}
	while (nb > 0)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}
