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


typedef struct	s_convert_pion
{
	int			i;
	struct	s_convert_pion*	next;
}		t_convert_pion;

typedef struct	s_env_game
{
	int		round;
	int		i;
	GtkWidget*	label;
	GtkWidget**	button;
	GtkWidget**	hbox;
	GtkWidget*      window;
	GtkWidget*      vbox;
	t_terrain*	terrain;
	
}		env_game;

void	generate_coord(t_terrain* terrain);
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
int	verti_bas(t_terrain*   terrain, t_terrain* terrain_all);
int	verti_haut(t_terrain*   terrain, t_terrain* terrain_all);
int	verti_bas_white(t_terrain*   terrain, t_terrain* terrain_all);
int	verti_haut_white(t_terrain*   terrain, t_terrain* terrain_all);
void	white_to_black(t_convert_pion* convert, t_terrain* terrain,t_terrain* button);
void	black_to_white(t_convert_pion* convert, t_terrain* terrain,t_terrain* button);
void	add_list_change(t_terrain* start, t_convert_pion* convert);
int	check_case(t_terrain* terrain, t_terrain*  button, int round);
void    free_convert(t_convert_pion* convert);
void    init_game(env_game* game);
#endif
