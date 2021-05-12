/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** parse_map
*/

#include "my_rpg.h"

void setup_map(gen_t *prm, scenario_t *sce, int i, int v)
{
    for (int k = 0; k < 4; ++k) {
        sce->vmap[i][v][k] = 0;
        sce->spmap[i][v][k] = sfSprite_create();
        sfSprite_setPosition(sce->spmap[i][v][k], get_vector(256 * v, 256 * i));
        sfSprite_setTexture(sce->spmap[i][v][k], prm->tilesets[k], sfTrue);
        sfSprite_setTextureRect(sce->spmap[i][v][k], get_intrect(0, 0, 0, 0));
    }
}

void fill_map(scenario_t *sce, char **data)
{
    char **buff;
    int id = 0;
    vec3_t coord;

    for (int i = 0; 1; i++) {
        char **block = get_nbalise_content(data, "region", i);
        if (block == NULL)
            break;
        char *coord_text = get_inline_content(block, "coord");
        char *id_text = get_inline_content(block, "id");
        if (!my_strcmp(coord_text, "") || !my_strcmp(id_text, ""))
            continue;
        buff = my_str_splitter(coord_text, ':');
        id = my_getnbr(id_text);
        if (!buff || id == 0)
            continue;
        coord = (vec3_t){my_getnbr(buff[0]),
            my_getnbr(buff[1]), my_getnbr(buff[2])};
        sce->vmap[coord.x][coord.y][coord.z] = id;
    }
}

void reload_spmap_insider(gen_t *prm, scenario_t *sce, int i, int v)
{
    for (int k = 0; k < 4; ++k) {
        int x = sce->vmap[i][v][k] / 6 * 256;
        int y = sce->vmap[i][v][k] % 6 * 256;
        if (sce->vmap[i][v][k] > 0 && k == 0) {
            sfSprite_setTextureRect(sce->spmap[i][v][0],
            get_intrect(x, y, 256, 256));
        } else if (sce->vmap[i][v][k] != 0 && k == 3)
            sfSprite_setTextureRect(sce->spmap[i][v][3],
            get_intrect(0, (sce->vmap[i][v][k] == -1) ?
        0 : sce->vmap[i][v][k] * 256, 256, 256));
        else if (sce->vmap[i][v][k] > 0 && k == 1)
            sfSprite_setTextureRect(sce->spmap[i][v][1],
            prm->editor.liste_deco[sce->vmap[i][v][k]]);
    }
}

void reload_spmap(gen_t *prm, scenario_t *sce)
{
    for (int i = 0; i < sce->mapsize.y; ++i) {
        for (int v = 0; v < sce->mapsize.x; ++v) {
            reload_spmap_insider(prm, sce, i, v);
        }
    }
}