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

void	generate_coord(t_terrain* terrain);
#endif
