/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:31:52 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/09 20:00:40 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//------------------------------------//
//				STRUCTURES			  //
//------------------------------------//
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		positions_start;
	int		pos_x;
	int		pos_y;
	int		number_of_lines;
	int		error_letter;
	int		collectibles_acces;
	int		exit_acces;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	t_img	player;
	t_img	wall;
	t_img	floor;
	t_img	collectibles;
	t_img	exit;
}	t_textures;

typedef struct s_vars
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_textures			textures;
	t_map				map;
	int					player_x;
	int					player_y;
	int					collected;
	int					victory;
	int					end_game;
	int					moves_count;
}	t_vars;

void	struct_map_init(t_map *map);
void	struct_textures_init(t_textures *textures);
void	struct_vars_init(t_vars *vars);
int		close_with_key(int keycode, t_vars *vars);
int		close_with_souris(t_vars *vars);
int		mouvements_with_key(int keycode, t_vars *vars);
int		handle_esc_key(t_vars *vars, int keycode);
void	display_moves_count(t_vars *vars);
int		handle_mouvements_keys(t_vars *vars, int keycode, int step);
int		handle_page_victory(t_vars *vars, int grid_x, int grid_y);
int		check_collision_with_wall(t_vars *vars, int save_x,
			int save_y, int step);
void	update_map_after_mouvement(t_vars *vars, int temp_x,
			int temp_y, int step);
int		make_mouvement(t_vars *vars, int keycode, int step);
int		read_the_map(char *filename, t_map *map);
int		count_the_lines(int fd, t_map *map);
int		stock_line_in_grid(t_map *map, char *filename);
int		infos_for_alloc_grid(char *filename, t_map *map);
int		accept_or_not_the_map(t_map *map);
int		extract_and_check_map_elements(t_map *map);
int		check_walls(t_map *map);
int		check_accessibility(t_map *map);
void	extract_elements(t_map *map);
int		check_elements(t_map *map);
char	**ft_duplicate_the_map(t_map *map);
void	floodfill(char **map_copy, int x, int y, t_map *map);
void	free_struct_map(t_map *map);
int		initialize_game(t_vars *vars, char *argv_one);
int		load_textures(t_vars *vars);
int		load_people_textures(t_vars *vars);
int		load_floor_and_wall_textures(t_vars *vars);
int		load_exit_and_collectibles_textures(t_vars *vars);
void	free_textures(t_vars *vars);
int		render(t_vars *vars);
void	print_things(t_vars *vars, int pos_x, int pos_y, char cell_map);
void	print_player_and_enemies(t_vars *vars);
int		check_taille_map(t_map *map);
int		is_valid_position(t_vars *vars, int x, int y);
int		handle_player_defeat(t_vars *vars);
void	clean_before_exit(t_vars *vars);
int		check_extension(char *filename);
int		is_rectangular(t_map *map, char *line, int fd);
int		open_map_file(char *filename, int *fd);

//------------------------------------//
//				Get Next Line		  //
//------------------------------------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_explore_text(char *principal_buff, int fd);
char	*ft_create_line(char *principal_buff);
char	*ft_new_buff(char *principal_buff);
char	*freebuff(char **principal_buff);
char	*get_next_line(int fd);
#endif
