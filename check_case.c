#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	check_for_black(t_terrain* terrain_tmp, t_terrain* button_p, int count)
{
	while (terrain_tmp->next != 0)
	{
		count = check_vertical(terrain_tmp, button_p, count, 1);
		count = check_horizontal(terrain_tmp, button_p, count, 1);
		count = check_diagonal(terrain_tmp, button_p, count, 1);
		terrain_tmp = terrain_tmp->next;
	}
	printf("blanches a capturer %d\n", count);
	return (count);
}

int	check_for_white(t_terrain* terrain_tmp, t_terrain* button_p, int count)
{
	while (terrain_tmp->next != 0)
	{
		count = check_vertical(terrain_tmp, button_p, count, 2);
		count = check_horizontal(terrain_tmp, button_p, count, 2);
		count = check_diagonal(terrain_tmp, button_p, count, 2);
		terrain_tmp = terrain_tmp->next;
	}
	printf("noires a capturer %d\n", count);
	return (count);
}

int	check_case(t_terrain* terrain, t_terrain* button, int round)
{
	t_terrain*	button_p;
	int		count;

	button_p  = terrain;
	while (button_p->i != button->i)
		button_p = button_p->next;
	printf("couleur bouton avant %d\n", button_p->color);
	if (button->color == 0)
	{
		if (round % 2 == 0)
		{
			count = check_global_black(terrain, button_p, 0);
		}
		else if (round % 2 == 1)
		{
			count = check_global_white(terrain, button_p, 0);
		}
			if (count > 0)
				return (1);
	}
	return (0);
}
