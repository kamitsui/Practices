/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:56:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/23 14:29:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "conversion.h"

void	do_conversion(t_state_machine *machine)
{
	static t_conversion conversion[1] = {decimal};

	int	i;
	// NULL guard is required ??
	if (machine == NULL)
	{
		machine->state = -1;
		return ;
	}
	i = 0;
	while (i < NB_CONV)
	{
		if ((machine->flag & (1 << i) << 8))
			conversion[i](machine);
		i++;
	}
}
