/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:24:06 by alsaeed           #+#    #+#             */
/*   Updated: 2023/06/14 21:24:51 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*update_stash(char *stash)
{
	char	*update;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (NULL);
	i = ft_strlen_nl(stash);
	update = NULL;
	if (i < ft_strlen(stash))
		update = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!update)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
	{
		update[j] = stash[i];
		j++;
		i++;
	}
	update[j] = '\0';
	if (update[0] == '\0')
		return (free(update), free(stash), NULL);
	return (free(stash), update);
}
