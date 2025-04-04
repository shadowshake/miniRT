/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:15:48 by shulee            #+#    #+#             */
/*   Updated: 2024/05/29 16:16:43 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Pass each ray and sphere center into this to see if the ray intersects with it
   if return -1 then no intersections otherwise it returns the interesection point closest to the camera*/
float	sphere_intersect(t_vec3 center, float radius, t_ray ray)
{
    t_vec3	length;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	t0;
	float	t1;

	length = vec_sub(ray.origin, center);
	a = 1.0;
	b = 2 * vec_dot(ray.direction, length);
	c = vec_dot(length, length) - (radius * radius);
	discriminant = (b * b) - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	discriminant = sqrt(discriminant);
	t0 = (-b - discriminant) / 2;
	t1 = (-b + discriminant) / 2;
	if (t0 > 0 && t0 < t1)
		return (t0);
	if (t1 > 0)
		return (t1);
	return (-1);
}

float	plane_intersect(t_vec3 point, t_vec3 vector, t_ray ray)
{
	t_vec3	norm_vec;
	float	denominator;
	t_vec3	ray_to_plane;
	float	t;
	
	norm_vec = vec_normalize(vector);
	denominator = vec_dot(ray.direction, norm_vec);
	if (denominator < 0.001)
		return (-1);
	ray_to_plane = vec_sub(point, ray.origin);
	t = vec_dot(ray_to_plane, vector) / denominator;
	if (t < 0)
		return (-1);
	return (t);
}

float	cylinder_intersect(t_vec3 point, t_vec3 vector, t_ray ray)
{
	
}

