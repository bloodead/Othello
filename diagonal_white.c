#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	found_diagonal_white(t_terrain* terrain, GtkWidget* button)
{
	int	count;
	int	count2;
	int	count3;
	int	count4;

	count = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;
	count = found_right_top_white(terrain, button);
	if (count != 0)
		capture_right_top_white(terrain, button, count);
	count2 = found_left_top_white(terrain, button);
	if(count2 != 0)
		capture_left_top_white(terrain, button, count2);
	count3 = found_right_bot_black(terrain, button, count3);
	if (count3 != 0)
		capture_right_bot_black(terrain, button, count3);
	count4 = found_left_bot_black(terrain, button, count4);
	if (count4 != 0)
		capture_left_bot_black(terrain, button, count4)
	if (count == 0 && count2 == 0 && count3 == 0 && count == 4)
		return (0);
	return (1);
}

