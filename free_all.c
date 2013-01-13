#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	free_all(env_game* game)
{
	free_terrain(game->terrain);
}
