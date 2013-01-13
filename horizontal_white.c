#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_left_white(t_terrain* terrain, GtkWidget* button, int count)
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
		while(move->next != 0 && (move->x != terrain->x + i || move->y != terrain->y))
			move = move->next;
		while(move->color == 2)
		{
			move = begin;
			while (move->next != 0 && (move->x != terrain->x + i || move->y != terrain->y))
				move = move->next;
			i = i + 1;
			count = count + 1;
		}
	}
	if (check_end_white(move) == 0)
		return (0);
	return (count);
}
 
int	found_right_white(t_terrain* terrain, GtkWidget* button, int count)
{
	int		i;
	t_terrqin*	begin;
	t_terrain*	move;
    
	i = 1;
	begin = terrain;
	nove = begin;
	while (terrain->button != button)
		terrain = terrain->next;
	if (terrain->color == 0 && terrain->x <= 5)
	{
		while(move->next != 0 && (move->x != terrain->x + i || move->y != terrain->y))
			move = move->next;
		while(move->color == 2)
		{
			move = move->next;
			count = count + 1;
		}
	}
	if (check_end_white(move) == 0)
		return (0);
	return (count);
}

void	left_capture_white(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	GdkColor	white;

	move = terrain;
	gdk_color_parse ("white", &white);
	while (terrain->button != button)
	terrain = terrain->next;
	while (move->next == 0 && (move->x != terrain->x - count || move->y != terrain->y))
		move = move->next;
	while (count != 0)
	{
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &white);
		move->color = 1;
		move = move->next;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &white);
	terrain->color = 1;
}

void	right_capture_white(t_terrain* terrain, GtkWidget* button, int count)
{
	t_terrain*	move;
	GdkColor	white;

	gdk_color_parse ("white", &white);
	while (terrain->button != button)
		terrain = terrain->next;
	move = terrain->next;
	while (count != 0)
	{
		gtk_widget_modify_bg(GTK_WIDGET(move->button), GTK_STATE_NORMAL, &white);
		move->color = 1;
		move = move->next;
		count = count - 1;
	}
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &white);
	terrain->color = 1;
}

int	found_horizontal_white(t_terrain* terrain, GtkWidget* button)
{
	int	count;
	int	count2;

	count = found_right_white(terrain, button,0);
	if (count != 0)
		right_capture_white(terrain, button, count);
	count2 = found_left_white(terrain, button,0);
	if (count2 > 0)
		left_capture_white(terrain, button, count2);
	if (count == 0 && count2 == 0)
		return 0;
	return (1);
} 
