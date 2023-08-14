#include "../../include/cub3d.h"

bool	load_color(UINT *c, char *line)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	colors = ft_split(line, ',');
	if (!colors)
		return (false);
	if (ft_arraylen(colors) < 3)
	{
		printf("\n");
		free_map(colors);
		return (false);
	}
	r = atoi(colors[0]);
	g = atoi(colors[1]);
	b = atoi(colors[2]);
	if(r < 0 || g < 0 || b < 0)
	{
		printf("%s\n", ERR_COLOR_FORMAT);
		return (false);
	}
	*c = get_rgba(r, g, b, 255);
	free_map(colors);
	return (true);
}