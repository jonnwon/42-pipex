/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:41:28 by jonchoi           #+#    #+#             */
/*   Updated: 2023/02/15 18:41:42 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!(s1) || !(s2))
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[size] = '\0';
	return (result);
}
