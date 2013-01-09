#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_diagonal_white(t_terrain* terrain, GtkWidget* button)
{
	int	count;
	int	count2;

	count = found_right_top_white(terrain, button);
	if (count != 0)
		capture_right_top_white(terrain, button, count);
	count2 = found_left_top_white(terrain, button);
	if(count2 != 0)
		capture_left_top_white(terrain, button, count2);
	if (count == 0 && count2 == 0)
		return (0);
	return (1);
}

