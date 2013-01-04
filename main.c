#include <gtk/gtk.h>
#include <stdio.h>
#include "base.h"


static void destroy(GtkWidget* widget, gpointer data)
{
	(void) widget;
	(void) data;
	gtk_main_quit();
}

static void hello(GtkWidget* widget, gpointer data)
{
         (void) widget;
	int	i;
	i = 10;
	struct s_terrain	*terrain = data;
         GdkColor        color;

	gdk_color_parse ("white", &color);
	 gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &color);
	while (i != terrain->i)
	{
		printf("coucou\n");
		terrain = terrain->next;
	}
	printf("terrain %d \n",terrain->i);
}


void	generated_platform(GtkWidget** hbox,GtkWidget* vbox, GtkWidget** button)
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

void	generate_all_button(GtkWidget** button,GdkColor* color)
{
	int	i;

	i = 0;

	while (i != 64)
	{
		button[i] = gtk_button_new_with_label("J1");
		gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, color);
		i = i + 1;
		
	}
}

int	main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	int 	i;
	i = 0;
	
	t_terrain	terrain;
	GtkWidget*	window;
	GtkWidget*	button[64];
	GtkWidget*	vbox;
	GtkWidget*	hbox[8];
	GdkColor	color;


	generate_coord(&terrain);
	gdk_color_parse ("green", &color);
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);

	generate_all_button(button, &color);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy),NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 0);



	while (i != 64)
	{

		g_signal_connect(button[i], "clicked", G_CALLBACK(hello),&terrain);
		i = i + 1;
	}



	vbox = gtk_vbox_new(TRUE, 0);

	generated_platform(hbox,vbox,button);

	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(vbox));
	
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
