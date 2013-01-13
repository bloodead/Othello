#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_bot_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	move;
	t_terrain*	begin;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->y <= 5)
	{
		while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y + i))
			move = move->next;
		while (move->color == 1)
		{
			move = begin;
			while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y + i))
				move = move->next;
			count = count + 1;
			i = i + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}

int	found_top_black(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrain*	move;
	t_terrain*	begin;

	i = 1;
	begin = terrain;
	move = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->y >= 2)
	{
		while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y - i))
			move = move->next;
		while(move->color == 1)
		{
			move = begin;
			while (move->x != terrain->x || move->y != terrain->y - i)
			{
				move = move->next;
				if (move->next == 0)
					break;
			}
			count = count + 1;
			i = i + 1;
		}
	}
	if (check_end_black(move) == 0)
		return (0);
	return (count);
}

void	bot_capture_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	t_terrain*	begin;
	GdkColor	black;

	move = terrain;
	begin = terrain;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y + count))
		move = move->next;
	while (count != 0)
	{
		while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y + count))
			move = move->next;
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = begin;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

void	top_capture_black(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	t_terrain*	begin;
	GdkColor	black;

	move = terrain;
	begin = terrain;
	gdk_color_parse ("black", &black);
	while (terrain->button != button)
		terrain = terrain->next;
	while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y - count))
		move = move->next;
	while (count != 0)
	{
		while (move->next != 0 && (move->x != terrain->x || move->y != terrain->y - count))
			move = move->next;
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &black);
		move->color = 2;
		move = begin;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &black);
	terrain->color = 2;
}

int	found_vertical_black(t_terrain* terrain, GtkWidget* button)
{
	int	count;
	int	count2;

	count = found_top_black(terrain, button, 0);
	if (count != 0)
		top_capture_black(terrain, button, count);
	count2 = found_bot_black(terrain, button, 0);
	if (count2 != 0)
		bot_capture_black(terrain, button, count2);
	if (count == 0 && count2 == 0)
		return (0);
	return (1);
}
