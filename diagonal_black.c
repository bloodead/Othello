#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

void	found_diagonal_black(t_terrain* terrain, GtkWidget* button)
{
	int	count;

	count = found_right_top_black(terrain, button);
	if (count != 0)
		capture_right_top_black(terrain, button, count);
}
