/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:24 by igomez-c          #+#    #+#             */
/*   Updated: 2025/12/02 12:17:59 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
        while (*s != '\0')
        {
                if (*s == (char)c)
                        return ((char *)s);
                s++;
        }
        if ((char)c == '\0')
                return ((char *)s);
        return (0);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sub;
        size_t  i;
        size_t  s_len;

        if (!s)
                return (NULL);
        s_len = ft_strlen(s);
        if ((size_t)start >= s_len)
        {
                len = 0;
                start = 0;
        }
        else if (len > s_len - (size_t)start)
                len = s_len - start;
        sub = malloc(sizeof(char) * (len + 1));
        if (!sub)
                return (NULL);
        i = 0;
        while (i < len && s[(size_t)start + i])
        {
                sub[i] = s[(size_t)start + i];
                i++;
        }
        sub[i] = '\0';
        return (sub);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
        char    *str;
        size_t  len;

        len = nmemb * size;
        str = (char *)malloc(len);
        if (!str)
                return (NULL);
        ft_bzero(str, len);
        return ((void *)str);
}

void    ft_bzero(void *s, size_t n)
{
        unsigned char   *ptr;
        size_t                  i;

        ptr = (unsigned char *)s;
        i = 0;
        while (i < n)
        {
                ptr[i] = '\0';
                i++;
        }
}
