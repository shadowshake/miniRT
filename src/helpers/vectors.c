/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:15:48 by shulee            #+#    #+#             */
/*   Updated: 2024/05/29 16:16:43 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3(float x, float y, float z)
{
    t_vec3 v = {x, y, z};
    return (v);
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
    return (vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
    return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3	vec_scale(t_vec3 v, float scalar)
{
    return (vec3(v.x * scalar, v.y * scalar, v.z * scalar));
}
