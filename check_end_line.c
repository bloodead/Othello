#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"

int	check_end_black(t_terrain* move)
{
	if (move->color != 2)
		return (0);
	return (1);
}

int	check_end_white(t_terrain* move)
{       
	if (move->color != 1)
		return (0);
	return (1);
}
