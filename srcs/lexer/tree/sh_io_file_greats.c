/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_file_greats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:43:56 by eboris            #+#    #+#             */
/*   Updated: 2020/09/27 16:42:14 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** !!! Main file -- sh_io_file.c !!!
**
** io_file          : DGREAT    filename
*/

t_node	*sh_iofile_dgreat_filename(t_main *main)
{
	t_node	*temp;
	t_node	*first;
	t_token	*token;

	temp = NULL;
	token = main->token_curr;
	if ((main->token_curr != NULL) && (main->token_curr->type == DGREAT))
	{
		first = sh_lexer_create_node(main, main->token_curr, DGREAT);
		main->token_curr = main->token_curr->next;
		if ((temp = sh_filename(main)) != NULL)
		{
			sh_lexer_add_node(first, NULL, temp);
			main->token_curr = main->token_curr->next;
			return (first);
		}
		else
		{
			// Ошибка лексемы?
			sh_lexer_del_node(&first);
			main->token_curr = token;
			return (NULL);
		}
	}
	return (NULL);
}

/*
** io_file          : LESSGREAT filename
*/

t_node	*sh_iofile_lessgreat_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_file          : CLOBBER   filename
*/

t_node	*sh_iofile_clobber_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
