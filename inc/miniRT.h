#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libmlx/mlx.h"

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

typedef struct s_sphere
{
	float	pos[3];
	float	dia;
	int		colour[3];
}   t_sphere;

typedef struct s_plane
{
	float	pos[3];
	float	vector[3];
	int		colour[3];
}	t_plane;

typedef struct s_cylinder
{
	float	pos[3];
	float	vector[3];
	float	dia;
	float	height;
	int		colour[3];
}	t_cylinder;

typedef struct s_light
{
	float	pos[3];
	float	bright;
}	t_light;

typedef struct s_ambient
{
	float	ratio;
	int		colour[3];
}	t_ambient;

typedef struct s_camera
{
	float	pos[3];
	float	vector[3];
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
int		correct_file(char *str);
int		read_file(int fd, t_scene *scene);
char	*white_space(char *line);
float	str_to_float(char *str);
int		check_colour_range(char *str);
int		init_ambient(t_scene *scene, char **line);
int		init_camera(t_scene *scene, char **line);
int		init_sphere(t_scene *scene, char **line);
int		store_info(t_scene *scene, char *line);

/* render */
void	render(t_scene *scene);

/* mlx render functions */
void	mlx_draw(t_scene *data, int x, int y, int color);
int		mlx_exit(int keycode, t_scene *mlx);

/* utilities */
void	free_strs(char **strs);
int		print_error(char *str);

#endif
