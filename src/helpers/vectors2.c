/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:15:48 by shulee            #+#    #+#             */
/*   Updated: 2024/05/29 16:16:43 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float vec_dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3 vec_cross(t_vec3 a, t_vec3 b)
{
    return (vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    ));
}

float vec_length(t_vec3 v)
{
    return (sqrt(vec_dot(v, v)));
}

t_vec3 vec_normalize(t_vec3 v)
{
    float len;

    len = vec_length(v);
    if (len == 0)
        return v;
    return (vec_scale(v, 1.0 / len));
}