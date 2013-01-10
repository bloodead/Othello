#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	check_for_black(t_terrain* terrain_tmp, t_terrain* button_p, int count)
{
	while (terrain_tmp->next != 0)
	{
		if (terrain_tmp->y == button_p->y + 1 && terrain_tmp->x == button_p->x)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->y == button_p->y - 1 && terrain_tmp->x == button_p->x)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y - 1 == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y + 1 == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y - 1 == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y + 1 == button_p->y)
		{
			if (terrain_tmp->color == 1)
				count = count + 1;
		}
		terrain_tmp = terrain_tmp->next;
	}
	printf("blanches a capturer %d\n", count);
	return (count);
}

int	check_for_white(t_terrain* terrain_tmp, t_terrain* button_p, int count)
{
	while (terrain_tmp->next != 0)
	{
		if (terrain_tmp->y == button_p->y + 1 && terrain_tmp->x == button_p->x)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->y == button_p->y - 1 && terrain_tmp->x == button_p->x)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y - 1 == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y + 1 == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y - 1 == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y + 1 == button_p->y)
		{
			if (terrain_tmp->color == 2)
				count = count + 1;
		}
		terrain_tmp = terrain_tmp->next;
	}
	printf("noires a capturer %d\n", count);
	return (count);
}

int	check_case(t_terrain* terrain, t_terrain* button, int round)
{
	t_terrain*	terrain_tmp;
	t_terrain*	button_p;
	int		count;

	terrain_tmp = terrain;
	button_p  = terrain;
	count = 0;
	while (button_p->i != button->i)
		button_p = button_p->next;
	if (button->color == 0)
	{
		if (round % 2 == 0)
		{
			count = check_for_black(terrain_tmp, button_p, count);
			if (count > 0)
			{
				while (count != 0)
				{
					button_p->color = 0;
					if(verti_haut(button, terrain) || verti_bas(button, terrain)
					   || found_horizontal_black(terrain, (GtkWidget*)button_p->button)
					   || found_diagonal_black(terrain, (GtkWidget*)button_p->button))
						count = count - 1;
					else
					{
						printf("count %d\n", count);
						return(0);
					}
				}
				button_p->color = 2;
				return (1);
			}
		}
		else if (round % 2 == 1)
		{
			count = check_for_white(terrain_tmp, button_p, count);
			if (count > 0)
			{
				while (count != 0)
				{
					button_p->color = 0;
					if (verti_haut_white(button, terrain) || verti_bas_white(button, terrain)
					    || found_horizontal_white(terrain, (GtkWidget*)button_p->button)
					    || found_diagonal_white(terrain, (GtkWidget*)button_p->button))
						count = count - 1;
					else
					{
						printf("count %d\n", count);
						return(0);
					}
				}
				button_p->color = 1;
				return (1);
			}
		}
	}
	return (0);
}
