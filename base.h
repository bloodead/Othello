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
void	found_horizontal_black(t_terrain* terrain, GtkWidget* button);
void	found_horizontal_white(t_terrain* terrain, GtkWidget* button);
void    verti_bas(t_terrain*   terrain, t_terrain* terrain_all);
void    verti_haut(t_terrain*   terrain, t_terrain* terrain_all);
void    white_to_black(t_convert_pion* convert, t_terrain* terrain,t_terrain* button);
void    add_list_change(t_terrain* start, t_convert_pion* convert);
#endif
