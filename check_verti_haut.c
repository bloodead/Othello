#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

int	check_verti_haut(t_terrain* terrain, t_terrain* terrain_all, t_convert_pion* convert, int* i)
{
	t_terrain*	start;
	t_convert_pion*	start_convert;

	start = terrain_all;	
	start_convert = convert;
	while (start->next != 0)
	{
		if (terrain->x == start->x && terrain->y - *i == start->y)
		{
				if (start->color == 1)
					add_list_change(start, convert);
				else if (start->color == 2)
				{ 	
					*i = terrain->y;
					white_to_black(start_convert, terrain_all, terrain);
					return (1);
				}
				else if (start->color == 0)
				{
					*i = terrain->y;
					return (0);
				}
		}
		start = start->next;
	}
	return (0);
}

int	check_first_case(t_terrain* terrain, t_terrain* terrain_all, int* i)
{
	t_terrain*	start;

	start = terrain_all;	
	while (start->next != 0)
	{
		if (terrain->x == start->x && terrain->y - *i == start->y)
		{
			if (start->color == 0 || start->color == 2)
			{
				*i = terrain->y;
				return (0);
			}
		}
		start = start->next;
	}
	return (1);
}

int	verti_haut(t_terrain* terrain, t_terrain* terrain_all)
{
	int		i;
	int		ret;
	t_convert_pion*	convert;

	convert = malloc(sizeof(t_convert_pion));
	i = 1;
	ret = 0;
	if (check_first_case(terrain, terrain_all, &i))
	{
		while (terrain->y - i != -1)
		{
			ret = check_verti_haut(terrain, terrain_all,convert,&i);
			i = i + 1;
		}
	}
	return (ret);
}
