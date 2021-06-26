/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <bember@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:32:40 by student           #+#    #+#             */
/*   Updated: 2021/01/05 17:43:12 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[11];
	char	*ptr;

	ptr = &nbr[10];
	*ptr = '\0';
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= (-1);
	}
	while (n > 0)
	{
		*(--ptr) = '0' + (n % 10);
		n = n / 10;
	}
	ft_putstr_fd(ptr, fd);
}
