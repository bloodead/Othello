#ifndef	_BASE_H_
#define	_BASE_H_

typedef struct	s_terrain
{
	int			i;
	int			x;
	int			y;
	int			color;
	struct s_terrain*	next;
	GtkWidget*		button;
}		t_terrain;

typedef struct	s_env_game
{
	int		round;
	int		i;
	GtkWidget*	label;
	GtkWidget**	button;
	GtkWidget**	hbox;
	GtkWidget*	window;
	GtkWidget*	vbox;
	t_terrain*	terrain;
	int		score_black;
	GtkWidget*	button_black;
	int		score_white;
	GtkWidget*	button_white;
	
}		env_game;

void	assign_button_coord(GtkWidget* widget, t_terrain* terrain, int i);
void	generated_platform(GtkWidget** hbox, GtkWidget* vbox, GtkWidget** button);
void	generate_all_button(GtkWidget** button, GdkColor* color);
int	generate_coord(t_terrain* terrain);
int	found_vertical_black(t_terrain* terrain, GtkWidget* button);
int	found_vertical_white(t_terrain* terrain, GtkWidget* button);
int	check_global_black(t_terrain* terrain, t_terrain* button, int count);
int	check_global_white(t_terrain* terrain, t_terrain* button, int count);
int	check_for_black(t_terrain* terrain_tmp, t_terrain* button_p, int count);
int	check_for_white(t_terrain* terrain_tmp, t_terrain* button_p, int count);
int	check_diagonal(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color);
int	check_vertical(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color);
int	check_horizontal(t_terrain* terrain_tmp, t_terrain* button_p, int count, int color);
int	found_right_top_black(t_terrain* terrain, GtkWidget* button, int count);
int	found_right_top_white(t_terrain* terrain, GtkWidget* button, int count);
int	found_left_top_black(t_terrain* terrain, GtkWidget* button, int count);
int	found_left_top_white(t_terrain* terrain, GtkWidget* button, int count);
void	capture_right_top_black(t_terrain* terrain, GtkWidget* button, int count);
void	capture_right_top_white(t_terrain* terrain, GtkWidget* button, int count);
void	capture_left_top_black(t_terrain* terrain, GtkWidget* button, int count);
void	capture_left_top_white(t_terrain* terrain, GtkWidget* button, int count);
int	found_right_bot_black(t_terrain* terrain, GtkWidget* button, int count);
int	found_right_bot_white(t_terrain* terrain, GtkWidget* button, int count);
int	found_left_bot_black(t_terrain* terrain, GtkWidget* button, int count);
int	found_left_bot_white(t_terrain* terrain, GtkWidget* button, int count);
void	capture_right_bot_black(t_terrain* terrain, GtkWidget* button, int count);
void	capture_right_bot_white(t_terrain* terrain, GtkWidget* button, int count);
void	capture_left_bot_black(t_terrain* terrain, GtkWidget* button, int count);
void	capture_left_bot_white(t_terrain* terrain, GtkWidget* button, int count);
int	found_diagonal_black(t_terrain* terrain, GtkWidget* button);
int	found_diagonal_white(t_terrain* terrain, GtkWidget* button);
int	check_end_black(t_terrain* move);
int	check_end_white(t_terrain* move);
int	found_horizontal_black(t_terrain* terrain, GtkWidget* button);
int	found_horizontal_white(t_terrain* terrain, GtkWidget* button);
int	check_case(t_terrain* terrain, t_terrain*  button, int round);
int    init_game(env_game* game);
void    init_score(env_game* game);
void    refresh_score(env_game* game);
void    free_terrain(t_terrain* terrain);
void	free_all(env_game* game);
#endif
