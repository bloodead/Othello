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


typedef struct s_convert_pion
{
	int	i;
	struct	s_convert_pion*	next;
}	t_convert_pion;

typedef struct	s_env_game
{
	int	round;
	t_terrain*	terrain;
	
}	env_game;

void	generate_coord(t_terrain* terrain);

int	found_right_top_black(t_terrain* terrain, GtkWidget* button);
int	found_right_top_white(t_terrain* terrain, GtkWidget* button);
void	capture_right_top_black(t_terrain* terrain, GtkWidget* button, int count);
void	capture_right_top_white(t_terrain* terrain, GtkWidget* button, int count);
void	found_diagonal_black(t_terrain* terrain, GtkWidget* button);
void	found_diagonal_white(t_terrain* terrain, GtkWidget* button);

int	check_end_black(t_terrain* move);
int	check_end_white(t_terrain* move);

int	found_horizontal_black(t_terrain* terrain, GtkWidget* button);
int	found_horizontal_white(t_terrain* terrain, GtkWidget* button);

int    verti_bas(t_terrain*   terrain, t_terrain* terrain_all);
int    verti_haut(t_terrain*   terrain, t_terrain* terrain_all);
void    white_to_black(t_convert_pion* convert, t_terrain* terrain,t_terrain* button);
void    add_list_change(t_terrain* start, t_convert_pion* convert);
int check_case(t_terrain* terrain, t_terrain*  button, int round);
#endif
