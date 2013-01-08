#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"


void	check_verti_haut(t_terrain* terrain, t_terrain* terrain_all, t_convert_pion* convert, int* i)
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
						break;
					}
					else if (start->color == 0)
					{
						*i = terrain->y;
						break;
					}
			}
			start = start->next;
		}
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
				return 0;
			}
		}
		start = start->next;
	}
	return 1;
}

void	verti_haut(t_terrain*	terrain, t_terrain* terrain_all)
{
	int	i;
	t_convert_pion*	convert;

	convert = malloc(sizeof(t_convert_pion));
	i = 1;

	if (check_first_case(terrain, terrain_all, &i))
		while (terrain->y - i != -1)
		{
			printf("passe\n");
			check_verti_haut(terrain, terrain_all,convert,&i);
			printf("DEBUG\n");

			i = i + 1;
		}
}

