#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"


void	white_to_black(t_convert_pion* convert, t_terrain* terrain,t_terrain* button)
{
	t_terrain*	start;
	GdkColor        black;

	gdk_color_parse ("black", &black);

	while (convert->next !=  0)
	{
		start = terrain;

		while (start != 0)
		{
			if (convert->i == start->i)
			{
				gtk_widget_modify_bg(start->button, GTK_STATE_NORMAL, &black);
				start->color = 2;
			}
			start = start->next;
		}
		convert = convert->next;
	}
	gtk_widget_modify_bg(button->button, GTK_STATE_NORMAL, &black);

}


void	add_list_change(t_terrain* start, t_convert_pion* convert)
{
	convert->i = start->i;
	convert->next = malloc(sizeof(struct s_convert_pion));
	convert = convert->next;
	convert->next = 0;


}


int     check_first_case_bas(t_terrain* terrain, t_terrain* terrain_all, int* i)
{
	t_terrain*      start;
          
	start = terrain_all;
	while (start->next != 0)
	{
		if (terrain->x == start->x && terrain->y + *i == start->y)
		{
			if (start->color == 0 || start->color == 2)
			{
				*i = 7 - terrain->y;
				return 0;
			}
		}
		start = start->next;
	}
	return 1;
}

int	check_verti_bas(t_terrain* terrain, t_terrain* terrain_all, t_convert_pion* convert, int* i)
{
	t_terrain*	start;
	t_convert_pion*	start_convert;

	start = terrain_all;	
	start_convert = convert;
		while (start->next != 0)
		{
			if (terrain->x == start->x && terrain->y + *i == start->y)
			{
					if (start->color == 1)
						add_list_change(start, convert);
					else if (start->color == 2)
					{ 	
						*i = 7 - terrain->y;
						white_to_black(start_convert, terrain_all, terrain);
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

int	verti_bas(t_terrain*	terrain, t_terrain* terrain_all)
{
	int	i;
	int	ret;
	t_convert_pion*	convert;

	ret = 0;
	convert = malloc(sizeof(t_convert_pion));
	i = 1;
	if (check_first_case_bas(terrain, terrain_all, &i))
		while (terrain->y + i != 8)
		{
			ret = check_verti_bas(terrain, terrain_all,convert,&i);
			i = i + 1;
		}
	return ret;
}
