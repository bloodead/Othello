#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

void	capture_left_top_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	t_terrain*	begin;
	GdkColor	black;

	begin = terrain;
	move = begin;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	while (count != 0)
		{
			while (move->next != 0 && (move->x != terrain->x - count || move->y != terrain->y - count))
			move = move->next;
			gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = begin;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

void	capture_right_top_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	t_terrain*	begin;
	GdkColor	black;

	begin = terrain;
	move = begin;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	while (count != 0)
	{
		while (move->next != 0 && (move->x != terrain->x + count || move->y != terrain->y - count))
			move = move->next;
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = begin;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

int	found_left_top_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	move;
	t_terrain*	begin;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->y >= 2 && terrain->x >= 2)
	{
		while (move->next != 0 && (move->x != terrain->x - i || move->y != terrain->y - i))
			move = move->next;
		while (move->color == 1)
		{
			move = begin;
			i = i + 1;
			while (move->x != terrain->x - i || move->y != terrain->y - i)
			{
				move = move->next;
				if (move->next == 0)
					break;
			}
			count = count + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}

int	found_right_top_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	move;
	t_terrain*	begin;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->y >= 2 && terrain->x <= 5)
	{
		while (move->next != 0 && (move->x != terrain->x + i || move->y != terrain->y - i))
			move = move->next;
		while (move->color == 1)
		{
			move = begin;
			i = i + 1;
			while (move->next != 0 && (move->x != terrain->x + i || move->y != terrain->y - i))
				move = move->next;
			count = count + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}
