/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:32:34 by edraccan          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:53 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* 
int main()
{
	int i = 0;
	t_list	**lst = (t_list **)malloc(sizeof(t_list *) * 3);
	t_list	*p1 = ft_lstnew("ciao");
	t_list	*p2 = ft_lstnew("mondo");
	t_list	*p3 = ft_lstnew("bastardo");
	ft_lstadd_front(lst, p3);
	ft_lstadd_front(lst, p2);
	ft_lstadd_front(lst, p1);
	while ((*lst)->next)
	{
		printf("%d: %s\n", i, (char *)(*lst)->content);
		*lst = (*lst)->next;
		i++;
	}
	printf("%d: %s\n", i, (char *)(*lst)->content);
} */