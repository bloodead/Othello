#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_left_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	move;
	t_terrain*	begin;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->x >= 2)
	{
		while(move->x != terrain->x - i || move->y != terrain->y)
			move = move->next;
		while(move->color == 1)
		{
			move = begin;
			while (move->x != terrain->x - i || move->y != terrain->y)
				move = move->next;
			count = count + 1;
			i = i + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}

int	found_right_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	begin;
	t_terrain*	move;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->x <= 5)
	{
		while(move->x != terrain->x + i || move->y != terrain->y)
			move = move->next;
		while(move->color == 1)
		{
			move = begin;
			while (move->x != terrain->x + i || move->y != terrain->y)
				move = move->next;
			count = count + 1;
			i = i + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}

void	left_capture_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	GdkColor	black;

	move = terrain;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	while (move->x != terrain->x - count || move->y != terrain->y)
		move = move->next;
	while (count != 0)
	{
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = move->next;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

void	right_capture_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	GdkColor	black;

	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	move = terrain->next;
	while (count != 0)
	{
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = move->next;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

int	found_horizontal_black(t_terrain* terrain, GtkWidget* button)
{
	int	count;
	int	count2;

	count = found_right_black(terrain, button, 0);
	if (count != 0)
		right_capture_black(terrain, button, count);
	count2 = found_left_black(terrain, button, 0);
	if (count2 != 0)
		left_capture_black(terrain, button, count2);
	if (count == 0 && count2 == 0)
		return (0);
	return (1);
}
