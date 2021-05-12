/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "structs.h"
#include "macros.h"
#include "my_printf.h"

#define DRAW_S(X) sfRenderWindow_drawSprite(prm->window, X, NULL)
#define DRAW_T(X) sfRenderWindow_drawText(prm->window, X, NULL)
#define SPOS(X, Y, Z) sfSprite_setPosition(X, get_vector(Y, Z));
#define SPOSI(X, Y) sfSprite_setPosition(X, get_vector(710 + Y % 9 * 56, 520 \
+ Y / 9 * 56 + (Y / 9 == 3 ? 25 : 0)));
#define SPOSE(X) sfSprite_setPosition(X.sprite, X.pos);
#define SCOL(X, Y, Z, A, B) sfSprite_setColor(X, (sfColor){Y, Z, A, B})
#define SFDP(X) X = sfSprite_copy(X);
#define GV(X, Y) get_vector(X, Y)
#define T_FROMFILE(X) sfTexture_createFromFile(X, NULL)


//main.c
void dispose(gen_t *prm);
void refresh_window(gen_t *prm);
void game_calculation(gen_t *prm);
int main(void);

//loader/load_game1.c
void setup_bar(gen_t *prm);
void load_game_views(gen_t *prm);

//generic.c
void enemy_t_push(enemy_t **array, int *size, enemy_t new);
void interactable_t_push(interactable_t **array, int *size, interactable_t new);
void enemy_t_delete_index(enemy_t **array, int *size, int index);

//loader/load_editor3.c
void load_editor_background(gen_t *prm);
void load_editor_exit_menu(gen_t *prm);
void load_editor_gui_tools(gen_t *prm);
void load_editor_gui(gen_t *prm);
void load_editor_scenario_stuff(gen_t *prm);

//loader/load_keys.c
keys_t load_keys(void);

//loader/load_editor2.c
void load_editor_enemies_list(gen_t *prm);
void load_editor_deco_textures(gen_t *prm);
void load_editor_pen_selector(gen_t *prm);
void load_editor_struct(gen_t *prm);
void load_editor_enemies_menu(gen_t *prm);

//loader/load_home.c
void load_home_struct_buttons(gen_t *prm);
void load_home_struct(gen_t *prm);

//loader/load_dispatch.c
gen_t *get_struct_settings(void);

//loader/load_editor4.c
void editor_enemy_setup_loading4(gen_t *prm);
void editor_enemy_setup_loading(gen_t *prm);
void load_editor_cursor_stuff(gen_t *prm);
void load_editor_initialisation(gen_t *prm);

//loader/load_custom.c
void load_custom_color(gen_t *prm);
void load_custom_struct(gen_t *prm);

//loader/load_game2.c
void load_game_buttons(gen_t *prm);
void load_game_particle(gen_t *prm);
void load_game_scenario(gen_t *prm);
void load_game_struct(gen_t *prm);

//options/mapping.c
void update_keys(gen_t *prm, setti_menu_t *me, sfKeyCode key);

//loader/load_save_selector.c
void load_selector_save_data_bis(int i, player_t *data, p_save_i *temp);
p_save_i *load_selector_save_data(int i, player_t *data);
void load_save_selector(gen_t *prm);

//loader/load_editor1.c
void load_editor_deco_btn2(gen_t *prm);
void load_editor_deco_btn3(gen_t *prm);
void load_editor_deco_btn(gen_t *prm);
void editor_enemy_setup_loading2(gen_t *prm);
void editor_enemy_setup_loading3(gen_t *prm);

//ennemies/animation.c
void enemies_animation(enemy_t *mob, int angle);

//loader/load_pause.c
void load_pause_save_verif(struct pause_menu *temp);
void load_pause_buttons(struct pause_menu *temp);
struct pause_menu *get_pause_s(void);

//ennemies/instanciate.c
void load_enemies(scenario_t *sce);
void set_random_pos(scenario_t *sce, enemy_t *en);

//drawer/draw_save_selector.c
void draw_save_data(gen_t *prm, p_save_i *data);
void draw_save_selector(gen_t *prm);

//ennemies/mouvement.c
sfVector2f get_enemy_vector(float angle);
float get_angle_to_player(gen_t *prm, enemy_t *self);

//drawer/drawer_utils.c
void draw_slider(sfRenderWindow *window, struct slider *slider);
void draw_trigger(sfRenderWindow *window, struct trigger *trigger);
void draw_simplified_slider(sfRenderWindow *window, struct slider *slider);

//loader/load_settings.c
void setup_sub_settings(setti_menu_t *temp);
void setup_settings_btns_text(setti_menu_t *temp);
void setup_settings_btns(setti_menu_t *temp);
void load_settings_keymap(setti_menu_t *temp);
setti_menu_t *load_settings_menu(void);

//drawer/draw_home.c
void draw_home(gen_t *prm);

//drawer/draw_game.c
void print_scenario_map_insider(gen_t *prm, int j, int k);
void print_scenario_map(gen_t *prm);
void print_enemies(gen_t *prm);
void print_interactable(gen_t *prm);
void draw_game_inventory(gen_t *prm);
void draw_game_toolbar(gen_t *prm);
void draw_lifebar(gen_t *prm);
void draw_game(gen_t *prm);

//drawer/draw_editor3.c
void draw_editor_exiting(gen_t *prm);
void draw_editor_print_deco(gen_t *prm);
void draw_editor(gen_t *prm);
void draw_editor_wall_floor(gen_t *prm);

//drawer/draw_pause.c
void draw_pause_menu(gen_t *prm);
void draw_pause_save(gen_t *prm);
void draw_pause(gen_t *prm);

//drawer/draw_editor1.c
void draw_editor_print_map_insider(gen_t *prm, int i, int j);
void draw_editor_print_map(gen_t *prm);
void draw_editor_print_cursor(gen_t *prm);

//drawer/draw_settings.c
void draw_settings_menu_text(gen_t *prm);
void draw_settings_menu(gen_t *prm);
void draw_settings_sounds(gen_t *prm);
void draw_settings_gui(gen_t *prm);
void draw_settings_graph(gen_t *prm);
void draw_settings_keys_bis(gen_t *prm);
void draw_settings_keys(gen_t *prm);
void draw_settings(gen_t *prm);

//utils/math_trigo.c
float tange(double x);
float cosinus(double x);
float sinus(double x);

//utils/my_free.c
void my_free(int nb, ...);

//utils/string_stuff3.c
char *str_add(char *str1, char *str2);
char *sanitize_str(char *str);

//drawer/draw_game2.c
void print_scenario_map_insider(gen_t *prm, int j, int k);
void print_scenario_map(gen_t *prm);
void print_enemies(gen_t *prm);
void print_interactable(gen_t *prm);

//utils/file_loading.c
char *my_file_loader(char *path);
char **my_str_splitter(char *str, char sep);
int check_file(char *path);

//drawer/drawer_dispatch.c
void window_update(gen_t *prm);

//drawer/draw_editor2.c
void draw_editor_print_gui(gen_t *prm);
void draw_editor_enemies_tabs(gen_t *prm);
void draw_editor_enemies_stats_text(gen_t *prm);
void draw_editor_enemies_stats(gen_t *prm);

//utils/randomizer.c
int random_gen(int min, int max);

//particle_system/fire.c
void fire_animation(gen_t *prm);

//freeder/free1.c
void free_2dchar(char **arr);
void free_3dint(int ***arr);

//drawer/draw_custom.c
void draw_custom(gen_t *prm);

//events/event_editor4.c
void editor_events_mouse_visibility(gen_t *prm);
void editor_events_enemies_menu_add_enemy(gen_t *prm);
void editor_events_enemies_menu_get_stats(gen_t *prm);
void editor_events_enemies_menu(gen_t *prm);
void editor_events_pen_selector(gen_t *prm);

//utils/my_get.c
sfSprite *get_sprite(char *path);
sfIntRect get_intrect(int top, int left, int width, int height);
sfVector2f get_vector(double x, double y);
char *get_str(int val);
int score_debugger(int nbr);

//utils/string_stuff2.c
int my_getnbr(char *str);
int my_strlen(char *str);
int my_str_find(char *c, char *arr);
int my_char_nbfind(char c, char *arr);
int my_str_isnum(char *str);

//events/event_editor5.c
void editor_events_drawing(gen_t *prm);
void editor_events_enemies_zone_selector(gen_t *prm);
void editor_events_texture_selection(gen_t *prm);
void editor_events_deco_brush(gen_t *prm);
void editor_events(gen_t *prm);

//events/event_dispatch.c
void manage_events_bis(gen_t *prm);
void manage_events(gen_t *prm);

//particle_system/heal.c
void heal_animation(gen_t *prm);

//parser/parse_map.c
vec_t get_map_size(char **file);
int get_positions(scenario_t *sce);
int get_map(gen_t *prm, scenario_t *sce);

//saver/save_player.c
int save_sessions(playersave_t *save);
void save_player(player_t player, int nbr, int fd);
void save_stats(p_stat stats, int fd);
void save_inventory(slot_t *inv, int fd);

//parser/parse_dic.c
int get_dictionnary(scenario_t *sce);
void fill_dic(scenario_t *sce, char **block);

//utils/window_creator.c
sfRenderWindow *window_creator(void);

//saver/save_map.c
void save_vmap(scenario_t *sce, int fd);
void save_map_block_writer(scenario_t *sce, vec_t coord, int fd, int k);
void save_map_block(scenario_t *sce, vec_t coord, int fd);

//parser/parse_items.c
int get_items(gen_t *prm);
void fill_item(gen_t *prm, char **block);

//events/event_settings.c
void events_sub_settings_graph(gen_t *prm);
void events_sub_settings_sound(gen_t *prm);
void events_sub_settings_keys(gen_t *prm);
void settings_event(gen_t *prm);

//utils/string_stuff1.c
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *str_truncate(char *str, int nbr);
char *my_strdup(char *src);
char *char_to_str(char c);

//events/event_editor1.c
void delete_enemy_btn(editor_t *edit, int index);
void view_movement(gen_t *prm);
void save_menu_event(gen_t *prm);

//parser/parse_inter.c
int get_interactable(scenario_t *sce);
void fill_interactable(scenario_t *sce, char **block);

//events/event_pause.c
void pause_menu_event1(gen_t *prm);
void pause_menu_event2(gen_t *prm);
void pause_menu_event(gen_t *prm);

//parser/parse_map_utils.c
void setup_map(gen_t *prm, scenario_t *sce, int i, int v);
void fill_map(scenario_t *sce, char **data);
void reload_spmap_insider(gen_t *prm, scenario_t *sce, int i, int v);
void reload_spmap(gen_t *prm, scenario_t *sce);

//parser/parse_saves.c
int get_saves(gen_t *prm);
void fill_stats(player_t *ply, char **stats);
void fill_inv(gen_t *prm, player_t *ply, char **inv);
int fill_player(gen_t *prm, player_t *ply, char **block);

//events/event_editor2.c
void reload_editor_deco_button_event(gen_t *prm);
void editor_deco_button_event(gen_t *prm);
void editor_update_enemy_stat(gen_t *prm);
void taskbar_reset(gen_t *prm);

//parser/parse_utils.c
char **get_balise_content(char **file, char *balise);
char **get_nbalise_content(char **file, char *balise, int n);
int balise_content_length(char **file, char *balise);

//saver/save_scenario.c
int save(scenario_t *sce);
void save_interactable(scenario_t *sce, int fd);
void save_positions(scenario_t *sce, int fd);
void save_dictionnary(scenario_t *sce, int fd);

//events/event_save_selector.c
void events_save_selector_bis(gen_t *prm);
void events_save_selector(gen_t *prm);

//parser/parse_inline.c
char *get_inline_content_u(char *start, char *end, char *buff, int len);
char *get_inline_content(char **file, char *balise);
char *get_inline_ncontent(char **file, char *balise, int n);

//events/event_custom.c
void custom_events(gen_t *prm);

//initer/init_slider.c
void init_slider_name(slider_t *temp, int px, int py, char *name);
void init_slider_digit(slider_t *temp, int px, int py, int val);
void init_slider_sprites(slider_t *temp, int px, int py, int val);
struct button *initialize_slider_trigger(int px, int py, int sx, int sy);
slider_t *initialize_slider(int px, int py, int val, char *name);

//initer/init_button.c
struct button *initialize_button(vec_t coo, vec_t size, sfVector2f scale
, char *path);
void load_text_button(struct button *btn, vec3_t t_i, char *text);
sfText *load_text_str(char *str, int size, vec_t pos);
void load_icon_button(struct button *btn, char *path, vec_t coo
, sfVector2f size);

//initer/init_trigger.c
struct trigger *initialize_trigger(sfVector2f pos, char *str);

//player/inventory.c
int swap_item(gen_t *prm, int slotid, int toswap);
int have_item(player_t *ply, int id);
void new_inventory(player_t *ply);

//events/event_editor3.c
void editor_events_taskbar_bis(gen_t *prm);
void editor_events_taskbar(gen_t *prm);
void editor_enemy_stat_event_plus(gen_t *prm);
void editor_enemy_stat_event_moins(gen_t *prm);
void editor_enemy_stat_event(gen_t *prm);

//player/animation.c
void player_animation(gen_t *prm);

//event_utils/slider.c
void slider_event(slider_t *slider, sfEvent event);

//player/movement.c
int can_move(gen_t *prm, int dir, float speed);
int diagonal_movement_bis(gen_t *prm);
int diagonal_movement(gen_t *prm);
void regular_movement(gen_t *prm);
void player_movement(gen_t *prm);

//event_utils/triforce.c
int click_rel(sfEvent event, struct button *target);
int click_pre(sfEvent event, struct button *target);
int click_is_up(sfEvent event, struct button *target);
int triforce(sfEvent event, struct button *target);
int duoforce(sfEvent event, struct button *target, int size);

//items/usage.c
int item_use(gen_t *prm, slot_t *item_slot);
void usage(gen_t *prm, int type);

//initer/init_player.c
void setup_player_text(player_t *ply);
void setup_player_text_bis(player_t *ply);
void get_player_stats(player_t *ply);
void select_player(gen_t *prm, int nbr);
void init_player(gen_t *prm);

//event_utils/scroling.c
void editor_zoom(gen_t *prm);
void game_engine_zoom(gen_t *prm);

//levels/utils.c
int get_xp_for_level(int level);

//events/event_game.c
void game_re_up_inventory(gen_t *prm);
void game_re_down_inventory(gen_t *prm);
void game_inventory_events(gen_t *prm);
void game_get_mouse_pos(gen_t *prm);
void game_attack_heal_inventory_event(gen_t *prm);
void game_events(gen_t *prm);

//event_utils/trigger.c
void trigger_event(struct trigger *trigger, sfEvent event);

//editor/brush.c
void draw_wall(editor_t *edit, vec_t pos);
void draw_texture(editor_t *edit, vec_t pos, int is_deco);
void draw_zone(editor_t *edit, vec_t pos, int id);
void draw_start(editor_t *edit, vec_t pos);
void draw(editor_t *edit, vec_t pos);

//event_utils/strokes_count.c
int strokes_count(keys_t key);

//event_utils/key_strokes.c
void key_pressed(gen_t *prm);
void key_released(gen_t *prm);
void directional_pressed(gen_t * prm);
void directional_released(gen_t * prm);
void keys_stuff(gen_t *prm);

//player/instanciate.c
void new_stats(player_t *ply);
void new_player(player_t *ply);

//items/instanciate.c
void item_t_push(item_t **array, int *size, item_t new);
item_t get_item_by_id(item_t *items, int id);
int check_for_slot(gen_t *prm, int id, int nbr);
int add_item(gen_t *prm, int id, int nbr);

//events/event_home.c
void home_event_bis(gen_t *prm);
void home_event(gen_t *prm);

//items/data/get.c
int get_int_data(char *balise, char **json);
