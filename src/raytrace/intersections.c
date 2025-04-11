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

float	solve_quadratic(float a, float b, float c)
{
	float	discriminant;
	float	root_disc;
	float	t0;
	float	t1;

	discriminant = (b * b) - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	root_disc = sqrt(discriminant);
	t0 = (-b - root_disc) / (2 * a);
	t1 = (-b + discriminant) / (2 * a);
	if (t0 > 0 && t0 < t1)
		return (t0);
	if (t1 > 0)
		return (t1);
	return (-1);
}

/* Pass each ray and sphere center into this to see if the ray intersects with it
   if return -1 then no intersections otherwise it returns the interesection point closest to the camera*/
float	sphere_intersect(t_vec3 center, float radius, t_ray ray)
{
    t_vec3	length;
	float	a;
	float	b;
	float	c;
	float	intersect;

	length = vec_sub(ray.origin, center);
	a = 1.0;
	b = 2 * vec_dot(ray.direction, length);
	c = vec_dot(length, length) - (radius * radius);
	intersect = solve_quadratic(a, b, c);
	if (intersect > 0)
		return (intersect);
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

//Using formula a = D - dot(D,N) * N, b = m - dot(m,N) * N
//then using the quadratic formula dot(a,a)t^2 + 2(dot(a,b))t + (dot(b,b) - r^2) = 0
float	cylinder_intersect(t_cylinder cyl, t_ray ray)
{
	float	radius;
	t_vec3	d;
	t_vec3	m;
	t_vec3	a;
	float	A;
	t_vec3	b;
	float	B;
	float	C;
	float	side_intersect;
	t_vec3	p;
	float	k;

	radius = cyl.dia / 2.0;
	d = ray.direction;
	m = vec_sub(ray.origin, cyl.pos);
	a = vec_sub(d, vec_scale(cyl.axis, vec_dot(d, cyl.axis)));
	A = vec_dot(a, a);
	b = vec_sub(m, vec_scale(cyl.axis, vec_dot(m, cyl.axis)));
	B = 2.0 * vec_dot(a, b);
	C = vec_dot(b, b) - (radius * radius);
	side_intersect = solve_quadratic(A, B, C);
	if (side_intersect > 0)
	{
		p = vec_add(ray.origin, vec_scale(ray.direction, side_intersect));
		k = vec_dot(vec_sub(p, cyl.pos), cyl.axis);
		if (!(k >= -cyl.height/2.0 && k <= cyl.height/2.0))
			side_intersect = -1;
	}
	//NOT DONE YET it still needs to calculate if the ray intercepts the top or bottom of the cylinder
}

