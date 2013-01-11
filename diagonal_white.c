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
	count = found_right_top_white(terrain, button, count);
	if (count != 0)
		capture_right_top_white(terrain, button, count);
	//printf("je passe right top white %d\n", count);
	count2 = found_left_top_white(terrain, button, count2);
	if(count2 != 0)
		capture_left_top_white(terrain, button, count2);
	//printf("je passe left top white %d\n", count);
	count3 = found_right_bot_white(terrain, button, count3);
	if (count3 != 0)
		capture_right_bot_white(terrain, button, count3);
	//printf("je passe right bot white %d\n", count);
	count4 = found_left_bot_white(terrain, button, count4);
	if (count4 != 0)
		capture_left_bot_white(terrain, button, count4);
	//printf("je passe left bot white %d\n", count);
	if (count == 0 && count2 == 0 && count3 == 0 && count4 == 0)
		return (0);
	return (1);
}

