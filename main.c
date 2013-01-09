#include <gtk/gtk.h>
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

	while (a != i)
	{
		terrain = terrain->next;
		a = a + 1;
	}
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
	printf("BUTTON N %d \n",terrain->i);

	if (check_case(terrain_all, terrain,game->round))
	{
		printf("DEBUG\n");
		if (game->round % 2 == 0)
		{
			printf("LE NOIR JOUE\n");
			game->round = game->round + 1;
		}
		else if (game->round % 2 == 1)
		{
			printf("LE BLANC JOUE\n");
			game->round = game->round + 1;
		}
	}
}

void		generated_platform(GtkWidget** hbox,GtkWidget* vbox, GtkWidget** button)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	b = 0;
	while (i != 8)
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

void		generate_all_button(GtkWidget** button,GdkColor* color)
{
	int	i;
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
	int 		i;
	env_game	game;
	t_terrain	terrain;
	GtkWidget*	window;
	GtkWidget*	info;
	GtkWidget*	button[64];
	GtkWidget*	vbox;
	GtkWidget*	hbox[8];
	GdkColor	color;

	i = 0;
	game.round = 0;
	gtk_init(&argc, &argv);
	generate_coord(&terrain);
	game.terrain = &terrain;
	gdk_color_parse ("green", &color);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	info = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);
	gtk_window_set_default_size(GTK_WINDOW(info), 800, 200);
	gtk_window_set_transient_for(GTK_WINDOW(info), GTK_WINDOW(window));

	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER); 
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ON_PARENT); 
	generate_all_button(button, &color);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy),NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 0);
	while (i != 64)
	{
		g_signal_connect(button[i], "clicked", G_CALLBACK(move), &game);
		assign_button_coord(button[i], game.terrain, i);
		i = i + 1;
	}
	vbox = gtk_vbox_new(TRUE, 0);
	generated_platform(hbox,vbox,button);
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(vbox));
	gtk_widget_show_all(window);
	gtk_widget_show_all(info);
	gtk_main();
	return 0;
}
