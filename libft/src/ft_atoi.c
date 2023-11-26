/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:19 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/11/26 19:05:46 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_length(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] || i > 11)
		return (0);
	return (i);
}

long long int	ft_atoi2(const char *str)
{
	long long int	nb;

	nb = 0;
	while ((*str && *str >= 9 && *str <= 13) || (*str && *str == 32))
		str++;
	if (check_length(str) == 0)
		return (2147483648);
	else
		nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (2147483648);
	return (nb);
}

long long int	ft_atoi(const char *str)
{
	long long int	nb;
	int				isneg;

	isneg = 0;
	nb = 0;
	while ((*str && *str >= 9 && *str <= 13) || (*str && *str == 32))
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		str++;
		isneg = 1;
	}
	while (ft_isdigit(*str))
	{
		nb *= 10;
		nb += *str - 48;
		str++;
	}
	if (isneg == 1)
		nb *= -1;
	return (nb);
}
