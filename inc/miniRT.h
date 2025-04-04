#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/ft_printf/ft_printf.h"
# ifdef linux
#  include "../libmlx/mlx.h"
#  define ESCKEY 65307
# else
//#  include "../libmlx_opengl/mlx.h"
#  define ESCKEY 53
# endif

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef WINHEIGHT
#  define WINHEIGHT 800
# endif

# ifndef WINWIDTH
#  define WINWIDTH 800
# endif

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_sphere
{
	t_vec3	pos;
	float	dia;
	int		colour[3];
}   t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	vector;
	int		colour[3];
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	axis;
	float	dia;
	float	height;
	int		colour[3];
}	t_cylinder;

typedef struct s_light
{
	t_vec3	pos;
	float	ratio;
	int		colour[3];
}	t_light;

typedef struct s_ambient
{
	float	ratio;
	int		colour[3];
}	t_ambient;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orient;
	int		fov;
}	t_camera;

typedef struct s_scene
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			sp_qty;
	int			pl_qty;
	int			cy_qty;
	t_light		light;
	t_ambient	ambient;
	t_camera	camera;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
}   t_scene;

/* parse folder */
int		parse(char *file, t_scene *scene);
char	*white_space(char *line);
int		check_colour_range(char *str);
int		init_ambient(t_scene *scene, char **line);
int		init_camera(t_scene *scene, char **line);
int 	init_light(t_scene *scene, char **line);
int		init_shapes(t_scene *scene);
int		init_sphere(t_scene *scene, char **line, int *shape_inedx);
int		init_plane(t_scene *scene, char **line, int *shape_index);
int		init_cylinder(t_scene *scene, char **line, int *shape_index);
int		store_info(t_scene *scene, char *line, int *shape_index);

/* render */
void	render(t_scene *scene);

/* mlx render functions */
void	mlx_draw(t_scene *data, int x, int y, int color);
int		mlx_exit(int keycode, t_scene *mlx);
int		create_rgb(int r, int g, int b);

/* utilities */
float	str_to_float(char *str);
int		free_strs(char **strs);
int		print_error(char *str);
int		ft_isspace(char c);

/* helpers */
t_vec3	vec3(float x, float y, float z);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(t_vec3 v, float scalar);
float	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
float	vec_length(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);

/* raytrace */
float	sphere_intersect(t_vec3 center, float radius, t_ray ray);
float	plane_intersect(t_vec3 point, t_vec3 vector, t_ray ray);

#endif
