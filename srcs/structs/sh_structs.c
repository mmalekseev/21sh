/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:47:56 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 15:13:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_main	*sh_add_main_struct(char **env)
{
	t_main	*new;

	if ((new = malloc(sizeof(t_main))) == NULL)
	{
		sh_term_errors_start(3);
		exit(0);
	}
	new->term_name = NULL;
	new->envp = env;
	new->envp_curr = NULL;
	new->path = NULL;
	new->hist = NULL;
	new->hist_curr = NULL;
	new->hist_end = NULL;
	sh_history_create(new);
	new->user = NULL;
	new->home = NULL;
	new->dir = ft_strnew(MAX_DIR_LEN);
	new->ks = ft_strnew(MAX_KS_LEN);
	new->ks_temp = NULL;
	new->cursor_sel_text = ft_strnew(MAX_KS_LEN);
	new->prompt = NULL;
	new->heredoc = NULL;
	new->token = NULL;
	new->token_curr = NULL;
	new->tree_first = NULL;
	new->tree_curr = NULL;
	new->exec_first = NULL;
	new->exec_curr = NULL;
	new->opfds = NULL;
	
	new->cpid = -1;
	sh_write_struct(new);
	return (new);
}

void	sh_copy_envp(t_main *main)
{
	int		i;
	char	**cur_envp;

	i = 0;
	if (main->envp)
	{
		while (main->envp[i])
			i++;
		if (i > 0)
		{
			cur_envp = malloc(sizeof(char *) * (i + 1));
			i = 0;
			while (main->envp[i])
			{
				cur_envp[i] = ft_strnew(ft_strlen(main->envp[i]));
				cur_envp[i] = ft_strcpy(cur_envp[i], main->envp[i]);
				i++;
			}
			cur_envp[i] = NULL;
			main->envp_curr = cur_envp;
		}
	}
}

void	sh_write_struct(t_main *new)
{
	int		i;
	char	*temp;

	i = -1;
	while (new->envp[++i])
		if (ft_strncmp(new->envp[i], "HOME=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->home = ft_strmancpy(temp, 5);
			ft_printf("\n%s\n", new->home);
		}
		else if (ft_strncmp(new->envp[i], "USER=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->user = ft_strmancpy(temp, 5);
		}
}
