/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:32:15 by eboris            #+#    #+#             */
/*   Updated: 2020/10/25 18:57:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_q(t_main *main)
{
	// uint64_t	i;

	// i = 0;
	// if (main->cursor_line > 1 && main->cursor_line_curr > 1)
	// {
	// 	while (i < main->term_col && main->cursor >= 0)
	// 	{
	// 		i++;
	// 		sh_cursor_minus(main);
	// 	}
	// }

	uint64_t	line;
	uint64_t	col;

	if (main->cursor_line > 1 && main->cursor_line_curr >= 1)
	{
		line = main->cursor_line_curr - 1;
		if (main->cursor_curr > main->curs[main->cursor_line_curr - 1])
		{
			col = main->curs[main->cursor_line_curr - 1];
		}
		else
		{
			col = main->cursor_curr;
		}
		if (main->cursor_line_curr == 1)
		{
			line = main->cursor_line_curr;
		}
		if (line == 1 && (col < (main->prompt_len + 1)))
		{
			col = main->prompt_len + 1;
		}
		while (main->cursor_line_curr != line)
		{
			sh_cursor_minus(main);
		}
		while (main->cursor_curr != col)
		{
			sh_cursor_minus(main);
		}
	}
}
