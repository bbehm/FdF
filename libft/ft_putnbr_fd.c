/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:08:15 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:48:13 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(2, fd);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n >= 0 && n < 10)
			ft_putchar_fd((n + '0'), fd);
		else if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd((n % 10 + '0'), fd);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
	}
}
