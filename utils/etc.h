/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:30:40 by juahn             #+#    #+#             */
/*   Updated: 2021/05/14 15:47:38 by juahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ETC_H
# define ETC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
unsigned short	ft_rand(void);

#endif
