#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

void	free_terrain(t_terrain*	terrain)
{
	t_terrain*	tmp;
	
	while (terrain != 0)
	{
		tmp = terrain->next;
		free(terrain);
		terrain = tmp;
	}
	free(terrain);
}

int	generate_coord(t_terrain* terrain)
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
			if (terrain->next == 0)
				return 1;
			terrain->i = i;
			terrain->x = x;
			terrain->y = y;
			terrain->color = 0;
			if (i == 27 || i == 36)
				terrain->color = 1;
			if (i == 28 || i == 35)
				terrain->color = 2;
			terrain = terrain->next;
			x = x + 1;
			i = i + 1;
		}
		y = y + 1;
	}
	return 0;
}
