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
				gtk_widget_modify_bg(start->button, GTK_STATE_NORMAL, &black);
			start = start->next;
		}
		convert = convert->next;
	}
	gtk_widget_modify_bg(button->button, GTK_STATE_NORMAL, &black);
	
}

void	found_move(t_terrain*	terrain, t_terrain* terrain_all)
{
	int	i;
	t_terrain*	start;
	t_convert_pion*	convert;
	t_convert_pion*	start_convert;

	start = terrain_all;
	convert = malloc(sizeof(t_convert_pion));
	start_convert = convert;
	i = 1;

	while (terrain->y + i != 8)
	{
		printf("passe\n");
		start = terrain_all;
		while (start->next != 0)
		{
			if (terrain->x == start->x)
			{
				if (terrain->y + i == start->y)
				{
					if (start->color == 1)
					{
						convert->i = start->i;
						convert->next = malloc(sizeof(struct s_convert_pion));
						convert = convert->next;
						convert->next = 0;
					}
					else if (start->color == 2)
					{ 	
						i = 7 - terrain->y;
						white_to_black(start_convert, terrain_all, terrain);
						break;
					}
					else if (start->color == 0)
					{
						i = 7 - terrain->y;
						break;
					}
				}
			}
			start = start->next;
		}
		i = i + 1;
	}
	
}
