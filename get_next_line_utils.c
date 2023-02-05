/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:17:08 by abouramd          #+#    #+#             */
/*   Updated: 2023/02/05 21:17:09 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    str_chr(const char *s, char c)
{
    size_t    i;

    i = 0;
    while (s && s[i])
        if (s[i++] == c)
            return (0);
    return (1);
}


char *join_str(char *s1, char *s2)
{
    char *r;
    int len1;
    int len2;
    int i = 0;;
    int j = 0;

    if (!s2)
        return NULL;
    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return NULL;
        *s1 = '\0';
    }
    len1 = 0;
    len2 = 0;
    while (s1[len1] || s2[len2])
    {
        if (s1[len1])
            len1++;
        if (s2[len2])
            len2++;
    }
    r = (char *)malloc(len1 + len2 + 1);
    if (r)
    {
        j = len1;
        len1 = 0;
        len2 = 0;
        while (s1[len1] || s2[len2])
        {
            if (s1[len1])
                r[i++] = s1[len1++];
            if (s2[len2])
                r[j++] = s2[len2++];
        }
        r[j] = '\0';
    }
    free(s1);
    return r;
}
