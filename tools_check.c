#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	check_global_white(t_terrain* terrain, t_terrain* button, int count)
{
	int	i;

	count = check_for_white(terrain, button, count);
	i = 0;
	if (count > 0)
	{
		while (count != 0)
		{
			if (found_vertical_white(terrain, (GtkWidget*)button->button)
			    || found_horizontal_white(terrain, (GtkWidget*)button->button))
			{
				printf("pass funk %d\n", count);
				count = count - 1;
				i = i + 1;
				button->color = 0;
			}
			else
				count = count - 1;
		}
		if (i > 0)
			button->color = 1;
	}
	printf("fonctions lignes blanches executees %d\n", i);
	return (i);
}

int	check_global_black(t_terrain* terrain, t_terrain* button, int count)
{
	int	i;

	count = check_for_black(terrain, button, count);
	i = 0;
	if (count > 0)
	{
		while (count != 0)
		{
			if (found_vertical_black(terrain, (GtkWidget*)button->button)
			   || found_horizontal_black(terrain, (GtkWidget*)button->button))
			{
				printf("pass funk %d\n", count);
				count = count - 1;
				i = i + 1;
				button->color = 0;
			}
			else
				count = count - 1;
		}
		if (i > 0)
			button->color = 2;
	}
	printf("fonctions lignes noires executees %d\n", i);
	return (i);
}

int	check_diagonal(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color)
{
	if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y - 1 == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y + 1 == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y - 1 == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y + 1 == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	return (count);
}

int	check_vertical(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color)
{
	if (terrain_tmp->y == button_p->y + 1 && terrain_tmp->x == button_p->x)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	if (terrain_tmp->y == button_p->y - 1 && terrain_tmp->x == button_p->x)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	return (count);
}

int	check_horizontal(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color)
{
	if (terrain_tmp->x == button_p->x + 1 && terrain_tmp->y == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	if (terrain_tmp->x == button_p->x - 1 && terrain_tmp->y == button_p->y)
	{
		if (terrain_tmp->color == color)
			count = count + 1;
	}
	return (count);
}
