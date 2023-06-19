/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:23:04 by alsaeed           #+#    #+#             */
/*   Updated: 2023/06/14 21:24:49 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_line(char *stash)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	i = ft_strlen_nl(stash) + 1;
	ret = (char *)malloc(sizeof(char) * i);
	if (!ret)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		ret[i] = stash[i];
		i++;
	}
	if (stash[i] == '\0' || stash[i] == '\n')
	{
		ret[i] = stash[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
