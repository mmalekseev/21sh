/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects_hub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:57 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 17:47:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_opened_fd(t_main *main, int nbr)
{
	t_fds	*last;

	if (!main->opfds)
	{
		main->opfds = ft_memalloc(sizeof(t_fds));
		main->opfds->nbr = nbr;
		main->opfds->next = NULL;
	}
	else
	{
		last = main->opfds;
		while (last->next)
			last = last->next;
		last->next = ft_memalloc(sizeof(t_fds));
		last->next->nbr = nbr;
		last->next->next = NULL;
		last = NULL;
	}
}

void	sh_redirect_from_heredoc(t_exec *exec, t_redirect *here, t_main *main)
{
	pid_t	here_pid;
	int		here_fd[2];

	pipe(here_fd);
	here_pid = fork();
	if (here_pid == 0)
	{
		dup2(here_fd[1], STDOUT_FILENO);
		ft_fprintf(here_fd[1], "%s", here->filename);
		close(here_fd[0]);
		exit(0);
	}
	else
	{
		dup2(here_fd[0], STDIN_FILENO);
		close(here_fd[1]);
		close(here_fd[0]);
		waitpid(here_pid, NULL, 0);
	}
}

int		sh_redirects_hub(t_exec *exec, t_main *main)
{
	t_redirect	*new;

	new = exec->redir;
	while (new && new->error >= 0)
	{
		if (new->envvar)
			sh_change_envvars_in_redirs(main, new);
		if (new->type == GREAT)
			sh_redirect_to_file(new, main);
		else if (new->type == GREATAND)
			sh_redirect_to_ionumber(new, main);
		else if (new->type == DGREAT)
			sh_redirect_to_file_append(new, main);
		else if (new->type == LESS)
			sh_redirect_from_file(new, main);
		else if (new->type == DLESS)
			sh_redirect_from_heredoc(exec, new, main);
		else if (new->type == LESSAND)
			sh_redirect_from_ionumber(new, main);
		if (new->error >= 0)
			new = new->next;
		else
			return (new->error);
	}
	return (0);
}
