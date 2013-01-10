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

void		assign_button_coord(GtkWidget* widget, t_terrain* terrain, int i)
{
	int	a;

	a = 0; 
	while (a != i)
	{
		terrain = terrain->next;
		a = a + 1;
	}
	printf("DEBUF\n");
	terrain->button = widget;
}

static void	move(GtkWidget* widget, gpointer data)
{

        (void)			widget;
	struct s_env_game*	game = data;
	t_terrain*	terrain_all = game->terrain;
	t_terrain*	terrain = game->terrain;
	while (terrain->button != widget)
		terrain = terrain->next;
	printf("BUTTON N %d \n", terrain->i);
	if (check_case(terrain_all, terrain, game->round))
	{
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

void		generated_platform(GtkWidget** hbox, GtkWidget* vbox, GtkWidget** button)
{
	int	i;
	int	j;
	int	b;

	i = 1;
	b = 0;
	while (i != 9)
	{
		hbox[i] = gtk_hbox_new(TRUE, 0);
		j = 0;
		while (j != 8)
		{
			gtk_box_pack_start(GTK_BOX(hbox[i]), button[b], TRUE, TRUE, 0);
			j = j + 1;
			b = b + 1;
		}
		gtk_box_pack_start(GTK_BOX(vbox), hbox[i], TRUE, TRUE, 0);
		i = i + 1;
	}
}

void		generate_all_button(GtkWidget** button, GdkColor* color)
{
	int		i;
	GdkColor        white;
	GdkColor        black;
	GdkColor        blue;

	gdk_color_parse ("black", &black);
	gdk_color_parse ("white", &white);
	gdk_color_parse ("blue", &blue);
	i = 0;
	while (i != 64)
	{
		button[i] = gtk_button_new();
		gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_PRELIGHT, &blue);
		if (i != 27 && i != 28 && i != 35 && i != 36)
			gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, color);
		if (i == 27 || i == 36)
			gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, &white);
		if (i == 35 || i == 28)
			gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, &black);
		i = i + 1;	
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
