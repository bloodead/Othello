#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	init_game(env_game* game)
{
	game->vbox = gtk_vbox_new(TRUE, 0);
	game->i = 0;
	game->button = malloc(64 * sizeof(GtkWidget*));
	game->round = 0;
	game->terrain = malloc(sizeof(t_terrain));
	game->hbox = malloc(9 * sizeof(GtkWidget*));
	generate_coord(game->terrain);
	game->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(game->window), 800, 800);
	gtk_window_set_position(GTK_WINDOW(game->window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(game->window), 0);
	game->hbox[0] = gtk_hbox_new(TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox), game->hbox[0], TRUE, TRUE, 0);
	game->label = gtk_label_new("COUCOU JOUEUR");
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->label, TRUE, TRUE, 0);
}
