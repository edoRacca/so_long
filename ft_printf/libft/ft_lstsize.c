/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:21:23 by edraccan          #+#    #+#             */
/*   Updated: 2024/11/24 13:32:36 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* 
int	main()
{
	t_list	**lst = (t_list **)malloc(sizeof(t_list *) * 3);
	t_list	*p1 = ft_lstnew("ciao");
	t_list	*p2 = ft_lstnew("mondo");
	t_list	*p3 = ft_lstnew("bastardo");
	ft_lstadd_front(lst, p3);
	ft_lstadd_front(lst, p2);
	ft_lstadd_front(lst, p1);
	printf("%d\n", ft_lstsize(*lst));
} */