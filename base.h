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

void	generate_coord(t_terrain* terrain);
void    found_move(t_terrain*   terrain, t_terrain* terrain_all);
#endif
