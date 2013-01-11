#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

static void	destroy(GtkWidget* widget, gpointer data)
{
	(void)	widget;
	(void)	data;

	gtk_main_quit();
}

static void	move(GtkWidget* widget, gpointer data)
{

	struct s_env_game*	game;
	t_terrain*		terrain_all;
	t_terrain*		terrain;

	game = data;	
	terrain_all = game->terrain;
	terrain = game->terrain;
	while (terrain->button != widget)
		terrain = terrain->next;
	printf("BUTTON N %d \n", terrain->i);
	if (check_case(terrain_all, terrain, game->round))
	{
		printf("couleur bouton apres %d\n", terrain->color);
		if (game->round % 2 == 0)
		{
			gtk_label_set_text(GTK_LABEL(game->label), "AU BLANC DE JOUER");
			game->round = game->round + 1;
		}
		else if (game->round % 2 == 1)
		{
			gtk_label_set_text(GTK_LABEL(game->label), "AU NOIR DE JOUER");
			game->round = game->round + 1;
		}
	}
}

int		main(int argc, char** argv)
{
	(void)		argc;
	(void)		argv;
	env_game	game;
	GdkColor        color;
	
	gtk_init(&argc, &argv);
	init_game(&game);
	gdk_color_parse ("green", &color);
	gtk_window_set_position(GTK_WINDOW(game.window),GTK_WIN_POS_CENTER); 
	generate_all_button(game.button, &color);
	g_signal_connect(game.window, "destroy", G_CALLBACK(destroy),NULL);
	while (game.i != 64)
	{
		g_signal_connect(game.button[game.i], "clicked", G_CALLBACK(move), &game);
		assign_button_coord(game.button[game.i], game.terrain, game.i);
		game.i = game.i + 1;
	}
	generated_platform(game.hbox,game.vbox,game.button);
	gtk_container_add(GTK_CONTAINER(game.window), GTK_WIDGET(game.vbox));
	gtk_widget_show_all(game.window);
	gtk_main();
	return (0);
}
