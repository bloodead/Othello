#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_left_black(t_terrain* terrain, GtkWidget* button)
{
	int		count;
	t_terrain*	move;
	t_terrain*	begin;

	count = 0;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0)
	{
		while(move->next != terrain)
			move = move->next;
		while(move->color == 1)
		{
			move = begin;
			while (move->x != terrain->x - (1 + count) || move->y != terrain->y)
				move = move->next;
			count = count + 1;
		}
	}
	return (count - 1);
}

int	found_right_black(t_terrain* terrain, GtkWidget* button)
{
	int		count;
	t_terrain*	move;

	count = 0;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0)
	{
		move = terrain->next;
		while(move->color == 1)
		{
			move = move->next;
			count = count + 1;
		}
	}
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
	int		x;
	t_terrain*	move;
	GdkColor	black;

	x = 0;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	move = terrain->next;
	while (x <= count)
	{
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = move->next;
		x = x + 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

void	found_horizontal_black(t_terrain* terrain, GtkWidget* button)
{
	int	count;

	count = found_right_black(terrain, button);
	if (count != 0)
		right_capture_black(terrain, button, count);
	count = found_left_black(terrain, button);
	if (count > 0)
		left_capture_black(terrain, button, count);
}
