/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:39:10 by aherriau          #+#    #+#             */
/*   Updated: 2018/01/05 07:05:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <time.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_mixer/SDL_mixer.h>
# include <OpenCL/opencl.h>
# include "./libft/libft.h"

/*
** Define window size
*/
# define SCREENW	1094
# define SCREENH	1024

/*
** Define game size
*/
# define W			1024
# define H			820

# define SA			1
# define SS			2
# define WHITE		3
# define DOG		4
# define SERGENT	5
# define BUTCHER	6
# define SPIKE_BOSS	7
# define HITLER_F	8
# define HITLER_M	9

# define FOOD		1
# define MEDKIT		2
# define AMMO		3
# define CUP		4
# define DIAMOND	5
# define CHEST		6
# define KEY		7
# define SMG		8
# define MINIGUN	9

# define BLOOD		10
# define P2_HEALTH	2000

# define GAME_OVER	1
# define SUCCESS	2

/*
** Define maximum item number not blocking the player
*/
# define BLOCK_SPRITE_INDEX	17
# define SHOOT_DIST 12

/*
** Define number of textures
*/
# define WALL		142
# define ITEM		49
# define ENEMY		9
# define HUD		4
# define PROJ		2

/*
** Define status of enemies
*/
# define MOVE		1
# define ATTACK		2
# define HURT		3
# define DIE		4
# define SWIPE		5
# define GOBACK		6
# define TRANSFORM	7

typedef struct s_env	t_env;
typedef struct s_enemy	t_enemy;
typedef struct s_sprite	t_sprite;

/*
** 2D Point
*/
typedef struct			s_xy
{
	double				x;
	double				y;
}						t_xy;

typedef struct			s_argb
{
	int					a;
	int					r;
	int					g;
	int					b;
}						t_argb;

typedef struct			s_parser
{
	int					fd;
	int					index;
	int					pos_start;
	int					pos_end;
	int					pos_start_x;
	int					pos_start_y;
	int					pos_end_x;
	int					pos_end_y;
	int					start;
	int					i;
	int					j;
	int					k;
	char				*line;
	char				**tab;
	char				**tab2;
}						t_parser;

typedef struct			s_maper
{
	t_list				*tmp;
	t_enemy				*enemy;
	t_sprite			*sprite;
	int					fd;
	int					index;
	int					i;
	int					j;
	char				**tab;
	char				**tab2;
	char				*line;
}						t_maper;

typedef struct			s_item
{
	int					(* func)(t_env *);
}						t_item;

typedef struct			s_process
{
	int					(* process)(t_env *, t_enemy *);
}						t_process;

typedef struct			s_init
{
	void				(* init)(t_enemy *);
}						t_init;

struct					s_sprite
{
	t_xy				pos;
	t_xy				dir;
	t_xy				plane;
	t_xy				init_dir;
	t_xy				last_pos_seen;
	int					type;
	int					state;
	int					number;
	int					animation_state;
	int					animation_index;
	int					animation_movement;
	int					swipe_index;
	int					visible;
	int					width;
	int					height;
	int					x_screen_start;
	int					x_screen_end;
	int					fast_index;
	int					fast_index_2;
	int					swipe_iterations;
	int					is_freeable;
};

/*
** Projectile variable
*/
typedef struct			s_projectile
{
	t_enemy				*enemy;
	t_sprite			*sprite;
	double				speed;
	int					id;
	int					phases;
	int					is_freeable;
}						t_projectile;

/*
** Weapon variable
*/
typedef struct			s_weapon
{
	int					id;
	int					spread;
	int					fire_rate;
	int					damage;
	int					animation_counter;
	void				(*process)(t_env *);
}						t_weapon;

/*
** Static textures
*/
typedef struct			s_stex
{
	SDL_Surface			*wall[WALL];
	SDL_Surface			*item[ITEM];
}						t_stex;

/*
** Dynamic texture variable
*/
typedef struct			s_dtexture
{
	SDL_Surface			*s[100];
}						t_dtexture;

/*
** All dynamic textures
*/
typedef struct			s_dtex
{
	t_dtexture			enemy[ENEMY];
	t_dtexture			hud[HUD];
	t_dtexture			projectile[PROJ];
}						t_dtex;

/*
** Raycasting variable
*/
typedef struct			s_raycasting
{
	t_xy				ray_pos;
	t_xy				ray_dir;
	t_xy				side_dist;
	t_xy				delta_dist;
	double				camera_x;
	double				perp_wall_dist;
	double				perp_wall_dist_2;
	double				wall_x;
	double				wall_x_2;
	double				z_buff[W];
	double				door_timer;
	double				door_dist;
	double				secret_door;
	int					map_x;
	int					map_x_2;
	int					map_y;
	int					map_y_2;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					side_2;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	int					tex_x;
	int					tex_y;
	int					*pix;
	int					*pix2;
	int					x;
	int					y1;
	int					y2;
	int					d;
	int					color;
	int					door;
}						t_raycasting;

typedef	struct			s_movement
{
	t_list				*tmp;
	double				new_x;
	double				new_y;
	double				norme;
	int					map_x;
	int					map_y;
	int					move;
}						t_movement;

typedef	struct			s_proj_dir
{
	double				rand_x;
	double				rand_y;
	double				compensation_x;
	double				compensation_y;
}						t_proj_dir;

/*
** Enemy variable
*/
struct					s_enemy
{
	t_list				*pos_stack;
	t_sprite			*sprite;
	t_weapon			weapon;
	double				old_dir_x;
	double				old_plane_x;
	double				speed_walk;
	double				range;
	int					id;
	int					health;
	int					dead;
	int					first_shot;
	int					reaction_time;
	int					drop;
	int					rotation_speed;
	int					die_count;
	int					move_frames;
	int					side;
	int					index_hurt_1;
	int					index_hurt_2;
	int					index_attack;
	int					index_die;
	int					ear_length;
	int					triggered;
	int					index_halt;
	int					index_achtung;
	int					index_death1;
	int					index_death2;
	int					boss;
	int					phase;
	int					(*process)(t_env *, t_enemy *);
	int					(*attack)(t_env *, t_enemy *);
	void				(*init)(t_enemy *);
};

/*
** Player variable:
** - pos: camera position
** - dir: camera direction vector
** - plane: projection plane vector
** - shoulders_width: ?
** - sensitivity: ?
** - yrel: ?
** - weapons: list of weapons
*/
typedef struct			s_player
{
	t_weapon			weapon;
	t_xy				pos;
	t_xy				dir;
	t_xy				plane;
	double				old_dir_x;
	double				old_plane_x;
	double				speed_walk;
	double				speed_rotation;
	double				s_width;
	double				sensitivity;
	int					health;
	int					ammo;
	int					score;
	int					score_floor;
	int					floor;
	int					lives;
	int					win;
	int					forward;
	int					backward;
	int					left;
	int					right;
	int					rotate_left;
	int					rotate_right;
	int					has_key;
	int					shooting;
	int					did_not_shoot;
	int					best_weapon;
	int					picked;
	int					hurt;
	int					dead;
	int					died;
	int					current_filter;
	int					can_shoot;
	int					nb_enter;
	int					kill_vodoo;
	int					kill_butcher;
}						t_player;

/*
** Square Data:
** - wall: 	= 0 (no wall)
**			> 0 (texture wall, door, secret passage, stationary object, ...)
** If no wall: item, pickable object
*/
typedef struct			s_squaredata
{
	double				door_timer;
	int					wall;
	int					item;
	int					door_state;
	int					door_index;
}						t_squaredata;

/*
** Map variable:
** - data: array of stationary elements (wall, floor, ceiling, item)
** - nb_enemy: number of enemies
** - enemies: array of enemies
** - projectiles: list of projectiles
** - start: player starting position in the map
** - end: player finishing position in the map
*/
typedef struct			s_map
{
	t_squaredata		**data;
	t_list				*projectiles;
	t_list				*sprites;
	t_enemy				*enemies;
	t_xy				start;
	t_xy				end;
	double				secret_door_timer;
	int					width;
	int					height;
	int					nb_enemy;
	int					secret_door;
}						t_map;

/*
** SDL2 variable
*/
typedef struct			s_sdl
{
	SDL_Rect			screen;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_Texture			*menu[46];
	SDL_Texture			*hud[24];
	Mix_Music			*music[10];
	Mix_Chunk			*sfx[100];
	t_xy				d;
	int					menu_img;
	int					sound;
	int					musik;
	int					mouse;
	int					hud_timer;
	int					hud_face;
	int					pause;
	int					can_pause;
	int					just_pause;
	int					levelup;
	int					levelup_timer;
	int					filter_timer;
	int					transition_timer;
	int					just_transitate;
	int					door;
}						t_sdl;

/*
** Environment variable
*/
struct					s_env
{
	t_sdl				sdl;
	t_map				map;
	t_player			player;
	t_raycasting		raycast;
	t_stex				stex;
	t_dtex				dtex;
	t_item				itemfunc[10];
	t_process			enemy_process[10];
	t_init				enemy_init[10];
	int					menu;
	int					transition;
};

typedef struct			s_render_sprite
{
	t_list				*ptr;
	t_sprite			*sprite;
	double				sprite_x;
	double				sprite_y;
	double				invdet;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_width;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					draw_start_x;
	int					draw_end_x;
	int					texture_x;
	int					texture_y;
	int					y;
	int					d;
	int					color;
	int					*data;
	int					*pix;
	int					stripe;
	int					visible;
}						t_render_sprite;

double					ft_min(double a, double b);
double					ft_max(double a, double b);
double					ft_clamp(double a, double mi, double ma);
int						ft_init_sdl(t_env *e);
int						ft_map_error(char **t, char **t2, int i, char *s);
void					ft_verify_map(t_env *e, char *filename);
void					ft_init_map(t_env *e, char *filename);
void					ft_init_player_levelup(t_env *e);
void					ft_init_player(t_env *e, int lives);
int						ft_init(t_env *e);
void					ft_keydown_menu(t_env *e, SDL_Event event);
void					ft_keydown_game(t_env *e, SDL_Event event);
void					ft_keydown(t_env *e, SDL_Event event);
void					ft_keyup(t_env *e, SDL_Event event);
void					ft_motion_mouse_menu(t_env *e, SDL_Event event);
void					ft_motion_mouse(t_env *e, SDL_Event event);
void					ft_mouse_down_menu(t_env *e, SDL_Event event);
void					ft_mouse_down(t_env *e, SDL_Event event);
void					ft_mouse_up(t_env *e, SDL_Event event);
void					ft_move(t_env *e);
void					ft_vline(t_env *e);
void					ft_render(t_env *e);
void					ft_render_sprites(t_env *e);
void					ft_render_weapon(t_env *e);
t_sprite				*new_sprite(int type, int number);
t_xy					*new_xy(double x, double y);
void					ft_pick(t_env *e);
void					ft_init_functions(t_env *e);
t_weapon				ft_new_knife(void);
t_weapon				ft_new_pistol(void);
t_weapon				ft_new_smg(t_player *player);
t_weapon				ft_new_minigun(t_player *player);
void					ft_process_weapon(t_env *e);
void					ft_process_knife(t_env *e);
void					ft_process_pistol(t_env *e);
void					ft_process_smg(t_env *e);
void					ft_process_minigun(t_env *e);
void					ft_process_enemies(t_env *e);
void					ft_init_process(t_env *e);
int						ft_process_ss(t_env *e, t_enemy *this);
int						ft_no_enemy(t_env *e, double x, double y);
int						ft_no_enemy_door(t_env *e, int x, int y);
int						ft_no_enemy_beside(t_env *e, t_enemy *t, double x,
		double y);
void					ft_apply_filter(t_env *e);
t_xy					ft_lstpop(t_list **list);
void					ft_door(t_env *e);
void					ft_init_init(t_env *e);
int						ft_process_boss_spike(t_env *e, t_enemy *this);
int						ft_process_boss_butcher(t_env *e, t_enemy *this);
int						ft_process_sergent(t_env *e, t_enemy *this);
int						ft_spike_boss_attack(t_env *e, t_enemy *this);
int						ft_vodoo_attack(t_env *e, t_enemy *this);
int						ft_hitler_attack(t_env *e, t_enemy *this);
int						ft_process_vodoo(t_env *e, t_enemy *this);
int						ft_process_hitler(t_env *e, t_enemy *this);
int						ft_butcher_attack(t_env *e, t_enemy *this);
int						ft_sergent_attack(t_env *e, t_enemy *this);
int						ft_can_see_player(t_env *e, t_enemy *this);
void					ft_look_toward_player(t_env *e, t_enemy *this);
void					ft_hurt_player(t_env *e, t_enemy *this);
void					ft_drop_item(t_env *e, t_enemy *this);
double					dist_player(t_enemy enemy, t_env *e);
void					ft_render_hud(t_env *e);
void					ft_init_sounds(t_env *e);
void					ft_play_sound(t_env *e, int index);
void					ft_play_music(t_env *e, int index);
void					ft_transite(t_env *e);
void					ft_process_projectiles(t_env *e);
void					ft_process_movement_boss(t_env *e, t_enemy *this);
t_projectile			*new_knife(t_env *e, t_enemy *this);
t_projectile			*new_ball(t_env *e, t_enemy *this);
void					add_proj(t_env *e, t_enemy *this);
void					ft_error(char *str);
void					ft_stackdel(t_list **list);
void					ft_free_map(t_env *e);
void					ft_free_sdl(t_env *e);
t_list					*ft_lstnew_ptr(void const *c, size_t size);
int						ft_pick_up_food(t_env *e);
int						ft_pick_up_medkit(t_env *e);
int						ft_pick_up_ammo(t_env *e);
int						ft_pick_up_cup(t_env *e);
int						ft_pick_up_diamond(t_env *e);
int						ft_pick_up_chest(t_env *e);
int						ft_pick_up_key(t_env *e);
int						ft_pick_up_smg(t_env *e);
int						ft_pick_up_minigun(t_env *e);
int						ft_pick_up_bowl(t_env *e);
void					ft_restore_health(t_player *player, int value);
void					ft_restore_ammo(t_player *player, int value);
void					ft_hurt_player(t_env *e, t_enemy *enemy);
void					ft_apply_die_filter(t_env *e);
void					ft_apply_pick_filter(t_env *e);
void					ft_apply_hurt_filter(t_env *e);
void					ft_apply_pause_filter(t_env *e);
void					ft_free_textures(t_env *e);
void					ft_free_sounds(t_env *e);
SDL_Texture				*ld_t(SDL_Renderer *renderer, char *filename);
SDL_Surface				*ld_s(char *filename);
void					ft_error(char *str);
int						ft_map_error(char **t, char **t2, int d, char *s);
void					ft_init_sdl_menu_textures(t_env *e);
void					ft_init_sdl_hud_textures(t_env *e);
void					ft_init_wall_textures(t_env *e);
void					ft_init_wall_textures_5(t_env *e);
void					ft_init_wall_textures_6(t_env *e);
void					ft_init_projectiles(t_env *e);
void					ft_init_item_sprites(t_env *e);
void					ft_init_hud(t_env *e);
void					ft_init_enemy_sprites_1(t_env *e);
void					ft_init_enemy_sprites_2(t_env *e);
void					ft_init_enemy_sprites(t_env *e);
void					ft_init_parser(t_env *e, t_parser *p, char *f);
void					ft_verify_map_1(t_env *e, t_parser *parser);
void					ft_verify_map_2(t_parser *parser);
void					ft_initialize_map(t_env *e);
void					ft_init_map_1(t_env *e, char *f, t_maper *m);
void					init_sa(t_enemy *this);
void					init_ss(t_enemy *this);
void					init_dog(t_enemy *this);
void					init_white(t_enemy *this);
void					init_sergent(t_enemy *this);
void					init_butcher(t_enemy *this);
void					init_spike_boss(t_enemy *this);
void					init_vodoo(t_enemy *this);
void					init_hitler(t_enemy *this);
void					ft_player_fire(t_env *e);
void					ft_player_attack(t_env *e);
void					ft_keydown_door(t_env *e);
void					ft_keydown_door_2_process(t_env *e);
void					ft_menu_options_1(t_env *e, SDL_Event event);
void					ft_menu_options_2(t_env *e, SDL_Event event);
void					ft_menu_options_3(t_env *e, SDL_Event event);
void					ft_menu_options(t_env *e, SDL_Event event);
void					ft_menu_games_1(t_env *e, SDL_Event event);
void					ft_menu_games_2(t_env *e, SDL_Event event);
void					ft_menu_games_3(t_env *e, SDL_Event event);
void					ft_menu_games(t_env *e, SDL_Event event);
void					ft_menu_sounds_1_process(t_env *e, SDL_Event event);
void					ft_menu_sounds_1(t_env *e, SDL_Event event);
void					ft_menu_sounds_2_process(t_env *e, SDL_Event event);
void					ft_menu_sounds_2(t_env *e, SDL_Event event);
void					ft_menu_sounds_3_process(t_env *e, SDL_Event event);
void					ft_menu_sounds_3(t_env *e, SDL_Event event);
void					ft_menu_sounds_4_process(t_env *e, SDL_Event event);
void					ft_menu_sounds_4(t_env *e, SDL_Event event);
void					ft_menu_sounds(t_env *e, SDL_Event event);
void					ft_menu_controls(t_env *e, SDL_Event event);
void					ft_menu_sound_2(t_env *e, int menu_img, int sound);
void					ft_games_menu_click(t_env *e, SDL_Event event);
void					ft_sounds_menu_click(t_env *e, SDL_Event event);
void					ft_controls_menu_click(t_env *e, SDL_Event event);
void					ft_process_game(t_env *e);
void					ft_switch_process_door(t_env *e);
void					ft_move_forward_x(t_env *e);
void					ft_move_forward_y(t_env *e);
void					ft_move_backward_x(t_env *e);
void					ft_move_backward_y(t_env *e);
void					ft_move_right_x(t_env *e);
void					ft_move_right_y(t_env *e);
void					ft_move_left_x(t_env *e);
void					ft_move_left_y(t_env *e);
void					ft_render_1(t_env *e);
void					ft_render_2(t_env *e);
void					ft_render_3(t_env *e);
void					ft_render_4(t_env *e, int x);
void					ft_render_5(t_env *e);
void					ft_render_6(t_env *e, int x);
void					ft_render_3_1_1(t_env *e);
void					ft_render_3_1_2(t_env *e);
void					ft_render_3_1_3(t_env *e);
void					ft_render_3_1_4_1(t_env *e);
void					ft_render_3_1_4_2(t_env *e);
void					ft_render_3_1_4_3(t_env *e);
void					ft_render_3_1_4(t_env *e);
void					ft_render_3_1(t_env *e);
void					ft_render_3_2(t_env *e);
void					ft_render_3_3(t_env *e);
void					ft_render_3_4(t_env *e);
void					ft_render_5_1_1(t_env *e);
void					ft_render_5_1_2(t_env *e);
void					ft_render_5_1(t_env *e);
void					ft_render_5_2(t_env *e);
void					ft_render_6_1(t_env *e, int x);
void					ft_can_see_player_1(t_env *e, t_enemy *this);
void					ft_can_see_player_2(t_env *e);
void					ft_can_see_player_3(t_env *e, t_enemy *this);
void					ft_can_see_player_4(t_env *e);
void					ft_can_see_player_5(t_env *e, t_enemy *this,
		t_render_sprite *rs);
int						ft_can_see_player_6(t_env *e, t_render_sprite *rs);
void					ft_can_see_player_3_1_1(t_env *e, t_enemy *this);
void					ft_can_see_player_3_1_2(t_env *e);
void					ft_can_see_player_3_1_3_1(t_env *e);
void					ft_can_see_player_3_1_3_2(t_env *e, t_enemy *this);
void					ft_can_see_player_3_1_3_3(t_env *e, t_enemy *this);
void					ft_can_see_player_3_1_3(t_env *e, t_enemy *this);
void					ft_can_see_player_3_1(t_env *e, t_enemy *this);
void					ft_can_see_player_3_2(t_env *e);
void					ft_can_see_player_3_3(t_env *e);
void					ft_can_see_player_3_4(t_env *e);
void					get_index_process(double val, int *index);
int						get_index(t_player player, t_sprite sprite);
void					ft_enemy_swipe_process(t_enemy *this, double *angle);
void					ft_enemy_swipe(t_enemy *this, t_player *player);
void					ft_process_can_see_player_1(t_env *e, t_enemy *this,
		int *move);
void					ft_process_can_see_player_2(t_env *e, t_enemy *this,
		int *move);
void					ft_process_can_see_player_3(t_env *e, t_enemy *this,
		int move);
void					ft_look_for_player_process_1(t_env *e, t_enemy *this,
		double *new_x, int *move);
void					ft_look_for_player_process_2(t_env *e, t_enemy *this,
		double *new_y, int *move);
void					ft_look_for_player_process_3(t_env *e, t_enemy *this,
		int move);
void					ft_look_for_player_process(t_env *e, t_enemy *this);
void					ft_look_for_player(t_env *e, t_enemy *this);
void					ft_look_toward_player(t_env *e, t_enemy *this);
void					ft_drop_item(t_env *e, t_enemy *this);
void					ft_go_back_1(t_env *e, t_enemy *this, t_xy next_pos);
void					ft_go_back_2(t_env *e, t_enemy *this, t_xy next_pos);
void					ft_go_back(t_env *e, t_enemy *this);
void					ft_get_hurt(t_env *e, t_enemy *this);
void					ft_attack_process_2(t_env *e, t_enemy *this);
void					ft_attack_process_1(t_env *e, t_enemy *this);
void					ft_attack(t_env *e, t_enemy *this);
void					ft_process_swipe(t_env *e, t_enemy *this);
void					ft_process_ss_process_1(t_env *e, t_enemy *this);
void					ft_process_ss_process_2(t_env *e, t_enemy *this);
void					sort_sprites(t_env *e);
double					dist(t_sprite *sprite, t_player player);
Mix_Music				*ft_load_music(char *filename);
Mix_Chunk				*ft_load_sound(char *filename);
void					ft_process_movement_hitler(t_env *e, t_enemy *this);
void					ft_process_movement_vodoo(t_env *e, t_enemy *this);
void					ft_process_movement_sergent(t_env *e, t_enemy *this);
int						ft_process_sergent_1(t_env *e, t_enemy *this);
void					ft_process_can_see_player_sergent(t_env *e, t_enemy *t);
void					ft_look_ser_1_2(t_env *e, t_enemy *t, t_movement *m);
void					ft_look_ser_1_1(t_env *e, t_enemy *t, t_movement *m);
void					ft_go_back_sergent_1(t_env *e, t_xy pos);
void					ft_process_can_see_player_boss(t_env *e, t_enemy *this);
void					ft_process_init_map(t_env *e, t_maper *maper);
void					ft_process_verify_map(t_env *e, t_parser *parser);
void					ft_verify_map_3(t_env *e, t_parser *parser);
void					ft_verify_map_4(t_parser *parser);
void					ft_verify_map_5(t_parser *parser);
void					ft_init_map_2(t_env *e, t_maper *maper);
void					ft_init_map_3(t_env *e, t_maper *maper);
void					ft_init_map_4(t_env *e, t_maper *maper);
void					ft_init_map_5(t_env *e, t_maper *maper);

#endif
