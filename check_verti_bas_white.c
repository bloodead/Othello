#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"


void	black_to_white(t_convert_pion* convert, t_terrain* terrain,t_terrain* button)
{
	t_terrain*	start;
	GdkColor        white;

	gdk_color_parse ("white", &white);

	while (convert->next !=  0)
	{
		start = terrain;

		while (start != 0)
		{
			if (convert->i == start->i)
			{
				gtk_widget_modify_bg(start->button, GTK_STATE_NORMAL, &white);
				start->color = 1;
			}
			start = start->next;
		}
		convert = convert->next;
	}
	gtk_widget_modify_bg(button->button, GTK_STATE_NORMAL, &white);

}

int     check_first_case_bas_white(t_terrain* terrain, t_terrain* terrain_all, int* i)
{
	t_terrain*      start;
          
	start = terrain_all;
	while (start->next != 0)
	{
		if (terrain->x == start->x && terrain->y + *i == start->y)
		{
			if (start->color == 0 || start->color == 1)
			{
				*i = 7 - terrain->y;
				return 0;
			}
		}
		start = start->next;
	}
	return 1;
}

int	check_verti_bas_white(t_terrain* terrain, t_terrain* terrain_all, t_convert_pion* convert, int* i)
{
	t_terrain*	start;
	t_convert_pion*	start_convert;

	start = terrain_all;	
	start_convert = convert;
		while (start->next != 0)
		{
			if (terrain->x == start->x && terrain->y + *i == start->y)
			{
					if (start->color == 2)
						add_list_change(start, convert);
					else if (start->color == 1)
					{ 	
						*i = 7 - terrain->y;
						black_to_white(start_convert, terrain_all, terrain);
						return 1;
					}
					else if (start->color == 0)
					{
						*i = 7 - terrain->y;
						return 0;
					}
			}
			start = start->next;
		}
	return 0;
}

int	verti_bas_white(t_terrain*	terrain, t_terrain* terrain_all)
{
	int	i;
	int	ret;
	t_convert_pion*	convert;

	ret = 0;
	convert = malloc(sizeof(t_convert_pion));
	i = 1;
	if (check_first_case_bas_white(terrain, terrain_all, &i))
		while (terrain->y + i != 8)
		{
			printf("passe\n");
			ret = check_verti_bas_white(terrain, terrain_all,convert,&i);
			i = i + 1;
		}
	return ret;
}
