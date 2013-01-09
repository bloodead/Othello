#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

void	found_diagonal_white(t_terrain* terrain, GtkWidget* button)
{
	int	count;

	count = found_right_top_white(terrain, button);
	printf("count %d \n", count);
	if (count != 0)
		capture_right_top_white(terrain, button, count);
}

