/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** structs
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct vec3 {
    int x;
    int y;
    int z;
} vec3_t;

typedef struct vec {
    int x;
    int y;
} vec_t;

typedef struct particle {
    sfSprite *core;
    sfVector2f pos;
    sfVector2f dir;
    int lifetime;
} parti_c;

typedef struct enemy {
    sfVector2f pos;
    int angle;
    int hp;
    int armor;
    int range;
    int speed;
    int number;
    int zone;
    int look_dir;
    char *sp_path;
    sfSprite *sprite;
    int skin_id;
} enemy_t;

typedef struct interactable {
    int id;
    int type;
    vec_t pos;
    sfSprite *sprite;
    int sprite_pos;
} interactable_t;

typedef struct btn_definition {
    vec_t coo;
    vec_t size;
    sfVector2f scale;
    vec3_t t_i;
} btn_def;

typedef struct item {
    char *name;
    int type;
    sfSprite *icon;
    char **data;
} item_t;

typedef struct slot {
    int item_id;
    item_t item;
    int count;
} slot_t;

typedef struct progress_bar {
    int value;
    sfVector2f coo;
    sfSprite *bar;
    sfSprite *frame;
    sfTexture *texture;
} progress_bar_t;

enum win_step {
    HOME,
    SETTINGS,
    SAVE_SELECTOR,
    EDITOR_ENGINE,
    CUSTOM,
    GAME,
    PAUSE,
    PAUSE_SAVE,
    G_SETTINGS,
    GAME_OVER,
    GAME_WIN,
    OUT,
};

typedef struct scenario {
    char *name;
    char *path;
    char **row_data;
    vec_t start;
    vec_t end;
    enemy_t *dictionnary;
    interactable_t *inter;
    enemy_t *enemies;
    int enemies_count;
    int inter_count;
    int dic_count;
    vec_t mapsize;
    int ***vmap;
    sfSprite ****spmap;
} scenario_t;

typedef struct keys {
    int tab;
    int space;
    int mouse;
    int mv_up;
    int mv_left;
    int mv_down;
    int mv_right;
    int arr_up;
    int arr_left;
    int arr_down;
    int arr_right;
} keys_t;

typedef struct keymap {
    sfKeyCode forward;
    sfKeyCode backward;
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode inventory;
    sfKeyCode space;
    sfKeyCode interact;
    sfKeyCode num1;
    sfKeyCode num2;
    sfKeyCode num3;
    sfKeyCode num4;
    sfKeyCode num5;
    sfKeyCode num6;
    sfKeyCode num7;
    sfKeyCode num8;
    sfKeyCode num9;
} keymap_t;

typedef struct slider {
    int value;
    sfText *text;
    sfText *digit;
    sfVector2f coo;
    sfSprite *p_box;
    sfSprite *bar_empty;
    sfSprite *bar_filled;
    struct button *cursor;
} slider_t;

typedef struct stats {
    int mov_speed;
    sfText *mov_speed_t;
    int atk_speed;
    sfText *atk_speed_t;
    int damage;
    sfText *damage_t;
    int level;
    sfText *level_t;
    int xp;
    int xp_next;
    sfText *xp_t;
} p_stat;

typedef struct player {
    sfSprite *player_sheet;
    sfSprite *stats_icon;
    slot_t *inventory;
    struct button *atk_plus;
    struct button *mv_speed_plus;
    struct button *atk_speed_plus;
    sfVector2f coo;
    int attack_id;
    float vision;
    p_stat stats;
    int skin_id;
    int gmode;
    int idle;
    float life;
    int fly;
    int dir;
} player_t;

typedef struct p_save_info {
    sfText *level;
    sfText *a_spd;
    sfText *a_dmg;
    sfText *m_spd;
} p_save_i;

typedef struct playersave {
    char *save;
    player_t save1;
    player_t save2;
    player_t save3;
} playersave_t;

struct button {
    sfText *text;
    sfVector2f coo;
    sfVector2f size;
    sfSprite *icon;
    sfSprite *sprite;
};

struct trigger {
    int state;
    sfText *text;
    sfVector2f coo;
    sfVector2f size;
    sfSprite *sprite;
    sfSprite *check;
};

typedef struct pause_menu {
    sfSprite *calc;
    struct button *transp;
    struct button *transp2;
    struct button *resume_b;
    struct button *restart_b;
    struct button *settings_b;
    struct button *menu_b;
    struct button *exit_b;
    struct button *save_y;
    struct button *save_n;
} pause_menu_t;

typedef struct home_menu {
    sfSprite *background;
    struct button *transp;
    struct button *play_b;
    struct button *edit_b;
    struct button *cstm_b;
    struct button *sett_b;
    struct button *abou_b;
    struct button *exit_b;
} home_t;

enum editor_step {
    ENEMIES_CREAT,
    ENEMIES_INFO,
    ENEMIES_STAT,
    CHEST_INFO,
    DEFAULT,
    EXITING,
};

enum setting_step {
    SET_GRAPH,
    SET_KEYS,
    SET_SOUND,
    SET_GUI,
    SET_HOME,
};

typedef struct custom_menu {
    struct button *transp;
    struct button *save;
    sfSprite *expl;
    sfColor color;
    struct slider *red;
    struct slider *green;
    struct slider *blue;
} cstm_menu_t;

typedef struct setti_menu {
    int mapselect;
    sfSprite *background;
    slider_t *main_volume;
    slider_t *music;
    slider_t *effects;
    slider_t *ennemis;
    slider_t *alerts;
    slider_t *wind;
    struct trigger *vsync;
    struct trigger *focus;
    struct trigger *high_res;
    struct button *go_up;
    struct button *go_right;
    struct button *go_down;
    struct button *go_left;
    struct button *attack;
    sfText *t_up;
    sfText *t_right;
    sfText *t_down;
    sfText *t_left;
    sfText *t_atck;
    slider_t *luminosity;
    slider_t *contrast;
    slider_t *saturation;
    struct button *transp;
    struct button *transp2;
    struct button *graphic_b;
    struct button *binding_b;
    struct button *sounds_b;
    struct button *gui_b;
    struct button *menu_b;
    enum setting_step set_step;
} setti_menu_t;

enum pen_mode {
    SELECT = 0,
    FLOOR,
    WALL,
    DECO,
    ITEMS,
    ZONES,
    HITBOX,
    SPAWN,
    END,
};

typedef struct editor_menu {
    struct button *hp_plus;
    struct button *hp_moins;
    struct button *hp_text;
    struct button *armor_plus;
    struct button *armor_moins;
    struct button *armor_text;
    struct button *range_plus;
    struct button *range_moins;
    struct button *range_text;
    struct button *speed_plus;
    struct button *speed_moins;
    struct button *speed_text;
    struct button *nb_plus;
    struct button *nb_moins;
    struct button *nb_text;
    sfText *hp_val;
    sfText *armor_val;
    sfText *range_val;
    sfText *speed_val;
    sfText *nb_val;
    sfSprite *enemy_sprite;
    struct button *save_enemy_set;
    struct button *trans;
    struct button *retour;
    struct button *exit_save;
    struct button *exit_brut;
    struct trigger *hide_zones;
    sfIntRect *liste_deco;
    sfSprite *block_tileset;
    vec_t last_mouse_pos;
    vec_t mouse_tile_pos;
    struct button *hitbox;
    struct button *enemies;
    struct button *spawnpoint;
    struct button *endpoint;
    int enemy_selected;
    enum editor_step edit_step;
    enum pen_mode pmod;
    struct button *gum;
    sfView *edit_win;
    sfView *interface;
    sfSprite *view_rect;
    sfSprite *select;
    sfSprite *bar;
    sfSprite *cursor;
    sfSprite *cursor_locked;
    struct button *pop_info;
    struct button *pop_stat;
    slider_t *zones_selector;
    struct button *texture_reset;
    scenario_t *scenario;
    int texture_selected;
    int texture_locked;
    sfVector2f cam_pos;
    int zoom;
    int pencil_type;
    int zone_id;
    sfSprite *edit_cursor;
    struct button **pen_type;
    struct button **enemies_tab;
    struct button **deco_type;
    int deco_selected;
} editor_t;

enum game_status {
    PLAY,
    INVENTORY,
};

typedef struct corroutine {
    int id;
    int time;
    void *tt;
} corroutine_t;

typedef struct save_selector {
    struct button *save_one;
    struct button *save_two;
    struct button *save_tre;
    struct button *choose;
    p_save_i *inf_one;
    p_save_i *inf_two;
    p_save_i *inf_tre;
    int selected;
} sv_slt;

typedef struct game {
    int zoom;
    parti_c *part_l;
    player_t *player;
    sfView *interface;
    sfView *rendering;
    scenario_t scenario;
    vec_t last_mouse_pos;
    vec_t mouse_tile_pos;
    struct button *inv_tansp;
    struct button **inv_btn;
    enum game_status g_status;
    struct progress_bar lifebar;
} game_t;

typedef struct gen {
    sfTexture **tilesets;
    sfSprite *hitbox;
    sfSprite *loading;
    playersave_t saves;
    char *path;
    item_t *items;
    int item_count;
    keys_t keys;
    keymap_t keymap;
    sfEvent event;
    sfRenderWindow *window;
    enum win_step game_step;
    sfClock *animation_clock;
    home_t home;
    game_t game;
    sv_slt save_sel;
    editor_t editor;
    cstm_menu_t custom;
    pause_menu_t *pause;
    setti_menu_t *setting;
} gen_t;