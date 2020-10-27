/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:06:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/27 19:00:09 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int						ft_check_save(t_mapinfos *m, int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strncmp("--save", av[2], 6))
			ft_error(&m->garbage, "Error\nBad --save option\n", 0, m);
		m->screenshoot = 1;
	}
	return (1);
}

static unsigned char	*ft_bmp_header(int resx, int resy)
{
	static unsigned char	bmp_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	bmp_header[0] = (unsigned char)(40);
	bmp_header[4] = (unsigned char)(resx);
	bmp_header[5] = (unsigned char)(resx >> 8);
	bmp_header[6] = (unsigned char)(resx >> 16);
	bmp_header[7] = (unsigned char)(resx >> 24);
	bmp_header[8] = (unsigned char)(resy);
	bmp_header[9] = (unsigned char)(resy >> 8);
	bmp_header[10] = (unsigned char)(resy >> 16);
	bmp_header[11] = (unsigned char)(resy >> 24);
	bmp_header[12] = (unsigned char)(1);
	bmp_header[14] = (unsigned char)(3 * 8);
	return (bmp_header);
}

static unsigned char	*ft_file_header(int resx, int resy)
{
	int						nb_oct;
	int						padding;
	static unsigned char	file_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	padding = (4 - (resx * 3) % 4) % 4;
	nb_oct = 14 + 40 + (3 * resx + padding) * resy;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(nb_oct);
	file_header[3] = (unsigned char)(nb_oct >> 8);
	file_header[4] = (unsigned char)(nb_oct >> 16);
	file_header[5] = (unsigned char)(nb_oct >> 24);
	file_header[10] = (unsigned char)(54);
	return (file_header);
}

static void				ft_fill_bmp(int fd, t_mapinfos *map)
{
	unsigned char	rgb[3];
	int				x;
	int				y;

	y = 0;
	while (y < map->res->y)
	{
		x = 0;
		while (x < map->res->x)
		{
			rgb[0] = (240 & map->mlx->img->data[(map->res->y - 1 - y)
				* map->res->x + x] >> 16);
			rgb[1] = (240 & map->mlx->img->data[(map->res->y - 1 - y)
				* map->res->x + x] >> 8);
			rgb[2] = (240 & map->mlx->img->data[(map->res->y - 1 - y)
				* map->res->x + x]);
			write(fd, rgb + 2, 1);
			write(fd, rgb + 1, 1);
			write(fd, rgb + 0, 1);
			x++;
		}
		y++;
	}
}

int						ft_create_bmp(t_mapinfos *map)
{
	int				fd;
	unsigned char	*file_header;
	unsigned char	*bmp_header;

	file_header = ft_file_header(map->res->x, map->res->y - 1);
	bmp_header = ft_bmp_header(map->res->x, map->res->y - 1);
	if ((fd = open("save.bmp", O_RDWR, S_IRUSR | S_IWUSR)) < 0)
		ft_error(&map->garbage, "Error\nScreenshot failled 2!\n", 0, map);
	write(fd, file_header, 14);
	write(fd, bmp_header, 40);
	ft_fill_bmp(fd, map);
	close(fd);
	(void)file_header;
	(void)bmp_header;
	ft_clear_map(map);
	system("leaks Cub3D");
	exit(0);
}
