#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

void	generate_coord(t_terrain* terrain)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i != 64)
	{
		x = 0;
		while (x != 8)
		{
			terrain->next = malloc(sizeof(t_terrain));
			terrain->i = i;
			terrain->x = x;
			terrain->y = y;
			terrain->color = 0;
			if (i == 27 || i == 36 || i == 42 || i == 49 || i == 51 || i == 38)
				terrain->color = 1;
			if (i == 28 || i == 35 || i == 45 || i == 52)
				terrain->color = 2;
			terrain = terrain->next;
			x = x + 1;
			i = i + 1;
		}
		y = y + 1;
	}
}
