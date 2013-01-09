#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	check_for_black(t_terrain* terrain_tmp, t_terrain* button_p)
{
	while (terrain_tmp->next != 0)
	{
		if (terrain_tmp->y == button_p->y + 1 && terrain_tmp->x == button_p->x)
			if (terrain_tmp->color == 1)
			return 1;
		if (terrain_tmp->y == button_p->y - 1 && terrain_tmp->x == button_p->x)
			if (terrain_tmp->color == 1)
			return 1;
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y == button_p->y)
			if (terrain_tmp->color == 1)
			return 1;
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y == button_p->y)
			if (terrain_tmp->color == 1)
			return 1;
		terrain_tmp = terrain_tmp->next;
	}

	return 0;
}

int	check_for_white(t_terrain* terrain_tmp, t_terrain* button_p)
{
	while (terrain_tmp->next != 0)
	{
		if (terrain_tmp->y == button_p->y + 1 && terrain_tmp->x == button_p->x)
			if (terrain_tmp->color == 2)
			return 1;
		if (terrain_tmp->y == button_p->y - 1 && terrain_tmp->x == button_p->x)
			if (terrain_tmp->color == 2)
			return 1;
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y == button_p->y)
			if (terrain_tmp->color == 2)
			return 1;
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y == button_p->y)
			if (terrain_tmp->color == 2)
			return 1;
		terrain_tmp = terrain_tmp->next;
	}

	return 0;
}

int check_case(t_terrain* terrain, t_terrain*  button, int round)
{
	t_terrain*	terrain_tmp;
	t_terrain*	button_p;

	terrain_tmp = terrain;
	button_p  = terrain;
	while (button_p->i != button->i)
		button_p = button_p->next;
	if (round % 2 == 0)
	{
		if (check_for_black(terrain_tmp, button_p))
				if(verti_haut(button, terrain) || verti_bas(button, terrain)
				   || found_horizontal_black(terrain, (GtkWidget*)button_p->button))
					return 1;
	}
	else if (round % 2 == 1)
	{
		if (check_for_white(terrain_tmp, button_p))
				if (verti_haut_white(button, terrain) || verti_bas_white(button, terrain)
				    ||found_horizontal_white(terrain, (GtkWidget*)button_p->button))
				return 1;
	}

   printf("PASSE ICI \n");
	return 0;

}
