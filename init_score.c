#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"


void	search_score(env_game* game)
{
	t_terrain*	tmp;

	tmp = game->terrain;
	game->score_white = 0;
	game->score_black = 0;
	while (tmp->next != 0)
	{
		if (tmp->color == 1)
			game->score_white = game->score_white + 1;
		if (tmp->color == 2)
			game->score_black = game->score_black + 1;
		tmp = tmp->next;
	}
}

char*	convert_int(int i, char* score)
{
	score[0] = 48 + (i / 10);
	score[1] = 48 + (i % 10);
	score[2] = '\0';
	return (score);
}

void	refresh_game(env_game* game)
{
	if (game->round == 60)
	{
		if (game->score_black > game->score_white)
			gtk_label_set_text(GTK_LABEL(game->label), "BLACK WINNER");
		else
			gtk_label_set_text(GTK_LABEL(game->label), "WHITE WINNER");
	}
}

void	refresh_score(env_game* game)
{
	char*	score;

	search_score(game);	
	score = malloc(3 * sizeof(char));
	score = convert_int(game->score_black,score);
	gtk_button_set_label(GTK_BUTTON(game->button_black), (gchar*)score);
	score = convert_int(game->score_white,score);
	gtk_button_set_label(GTK_BUTTON(game->button_white), (gchar*)score);
	refresh_game(game);
	
}

void	init_score(env_game* game)
{
	game->button_white = gtk_button_new_with_label("0");
	game->button_black = gtk_button_new_with_label("0");
	game->label = gtk_label_new("COUCOU JOUEUR");
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->button_black, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->label, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->button_white, TRUE, TRUE, 0);
}
