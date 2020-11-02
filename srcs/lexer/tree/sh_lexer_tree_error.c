/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:57:19 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 17:57:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_lexer_tree_error(t_main *main)
{
	ft_fprintf(STDERR_FILENO, "\n21sh: syntax error near unexpected token '%s'\n", main->token_curr->content);
	sh_remove_token(main);
	sh_remove_tree(main);
	sh_remove_exec(main);
}
