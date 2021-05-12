ROOT	=		.

SRC_DIR	=		src

CC		=		gcc

NAME	=		my_rpg

REAL	=		$(ROOT)/build

SRC		=	$(SRC_DIR)/main.c\
			$(SRC_DIR)/generic.c\
			$(SRC_DIR)/utils/file_loading.c\
			$(SRC_DIR)/utils/math_trigo.c\
			$(SRC_DIR)/utils/my_get.c\
			$(SRC_DIR)/utils/randomizer.c\
			$(SRC_DIR)/utils/window_creator.c\
			$(SRC_DIR)/utils/string_stuff1.c\
			$(SRC_DIR)/utils/string_stuff2.c\
			$(SRC_DIR)/utils/string_stuff3.c\
			$(SRC_DIR)/utils/my_free.c\
			$(SRC_DIR)/loader/load_home.c\
			$(SRC_DIR)/loader/load_game1.c\
			$(SRC_DIR)/loader/load_game2.c\
			$(SRC_DIR)/loader/load_keys.c\
			$(SRC_DIR)/loader/load_pause.c\
			$(SRC_DIR)/loader/load_editor1.c\
			$(SRC_DIR)/loader/load_editor2.c\
			$(SRC_DIR)/loader/load_editor3.c\
			$(SRC_DIR)/loader/load_editor4.c\
			$(SRC_DIR)/loader/load_custom.c\
			$(SRC_DIR)/loader/load_settings.c\
			$(SRC_DIR)/loader/load_dispatch.c\
			$(SRC_DIR)/loader/load_save_selector.c\
			$(SRC_DIR)/drawer/draw_game.c\
			$(SRC_DIR)/drawer/draw_game2.c\
			$(SRC_DIR)/drawer/draw_home.c\
			$(SRC_DIR)/drawer/draw_pause.c\
			$(SRC_DIR)/drawer/draw_editor1.c\
			$(SRC_DIR)/drawer/draw_editor2.c\
			$(SRC_DIR)/drawer/draw_editor3.c\
			$(SRC_DIR)/drawer/draw_custom.c\
			$(SRC_DIR)/drawer/drawer_utils.c\
			$(SRC_DIR)/drawer/draw_settings1.c\
			$(SRC_DIR)/drawer/draw_settings2.c\
			$(SRC_DIR)/drawer/draw_save_selector.c\
			$(SRC_DIR)/drawer/drawer_dispatch.c\
			$(SRC_DIR)/items/instanciate.c\
			$(SRC_DIR)/items/usage.c\
			$(SRC_DIR)/items/data/get.c\
			$(SRC_DIR)/events/event_editor1.c\
			$(SRC_DIR)/events/event_editor2.c\
			$(SRC_DIR)/events/event_editor3.c\
			$(SRC_DIR)/events/event_editor4.c\
			$(SRC_DIR)/events/event_editor5.c\
			$(SRC_DIR)/events/event_home.c\
			$(SRC_DIR)/events/event_game1.c\
			$(SRC_DIR)/events/event_game2.c\
			$(SRC_DIR)/events/event_pause.c\
			$(SRC_DIR)/events/event_custom.c\
			$(SRC_DIR)/events/event_settings.c\
			$(SRC_DIR)/events/event_dispatch.c\
			$(SRC_DIR)/events/event_save_selector.c\
			$(SRC_DIR)/initer/init_button.c\
			$(SRC_DIR)/initer/init_slider.c\
			$(SRC_DIR)/initer/init_player.c\
			$(SRC_DIR)/initer/init_trigger.c\
			$(SRC_DIR)/event_utils/scroling.c\
			$(SRC_DIR)/event_utils/triforce.c\
			$(SRC_DIR)/event_utils/key_strokes.c\
			$(SRC_DIR)/event_utils/slider.c\
			$(SRC_DIR)/event_utils/trigger.c\
			$(SRC_DIR)/event_utils/strokes_count.c\
			$(SRC_DIR)/options/mapping.c\
			$(SRC_DIR)/editor/brush.c\
			$(SRC_DIR)/saver/save_player.c\
			$(SRC_DIR)/saver/save_map.c\
			$(SRC_DIR)/saver/save_scenario.c\
			$(SRC_DIR)/parser/parse_utils.c\
			$(SRC_DIR)/parser/parse_map.c\
			$(SRC_DIR)/parser/parse_map_utils.c\
			$(SRC_DIR)/parser/parse_dic.c\
			$(SRC_DIR)/parser/parse_saves.c\
			$(SRC_DIR)/parser/parse_items.c\
			$(SRC_DIR)/parser/parse_inline.c\
			$(SRC_DIR)/freeder/free1.c\
			$(SRC_DIR)/ennemies/instanciate.c\
			$(SRC_DIR)/ennemies/animation.c\
			$(SRC_DIR)/ennemies/mouvement.c\
			$(SRC_DIR)/player/movement.c\
			$(SRC_DIR)/player/animation.c\
			$(SRC_DIR)/player/inventory.c\
			$(SRC_DIR)/player/instanciate.c\
			$(SRC_DIR)/particle_system/heal.c\
			$(SRC_DIR)/particle_system/fire.c\
			$(SRC_DIR)/levels/utils.c\

CFLAGS	=		-I $(ROOT)/inc $(EFLAGS) -g

LFLAGS	=		-L $(ROOT)/lib/ -lprintf -lmy -lm

EFLAGS	=		-Werror -Wall -Wextra  -Wpedantic

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio #-fsanitize=address

LIB 	=		lib/%.a

DEBUG_FLAG	=	--no-print-directory

V		=		@

OBJS	=		$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC))

#COLOR
WHITE	=	\e[0m
RED		=	\e[1;31m
GREEN	=	\e[1;32m
ORANGE	=	\e[1;33m
BLUE	=	\e[1;34m
PURPLE  = 	\033[35m
CYAN    =	\033[36m

all:		intro $(NAME)

intro:		
	$(V) printf "$(RED)+------------------------------+\n$(WHITE)"
	$(V) printf "$(RED)|          MY_RPG_V0.1         |\n$(WHITE)"
	$(V) printf "$(RED)+------------------------------+\n\n$(WHITE)"

$(NAME): $(REAL)/$(NAME) 
	$(V) cp $(REAL)/$(NAME) $(ROOT)
	$(V) printf "$(PURPLE)\nDup $(GREEN)$(PURPLE)$(NAME)$(WHITE)$(PURPLE) into root directory.$(WHITE)\n"
	$(V) printf "$(GREEN)Project compilation success\n$(WHITE)"
$(REAL)/$(NAME): lib/libprintf.a			$(OBJS)
	$(V) printf "$(GREEN)[OK]$(PURPLE) Linking obj and libraries.$(WHITE)\n"
	$(V) $(CC) -o $(REAL)/$(NAME) $(OBJS) $(LFLAGS) $(CSFMLFLAGS)
	$(V) printf "$(GREEN)[OK]$(PURPLE) Binary link done.$(WHITE)\n"

$(REAL)/%.o: $(SRC_DIR)/%.c | $(REAL)
	$(V) mkdir -p $(dir $@)
	$(V) printf "$(PURPLE)Compiling $(GREEN)$(PURPLE)[$(WHITE)$(PURPLE)$(notdir $<)$(GREEN)$(PURPLE) -> $(CYAN)$(notdir $@)$(GREEN)$(PURPLE)]\n$(WHITE)"
	$(V) $(CC) -o $@ -c $< $(CFLAGS) $(LFLAGS)

lib/lib%.a:
	$(V) $(MAKE) -C lib/$* $(DEBUG_FLAG)

$(REAL):
	$(V) mkdir $@

clean:
	$(V) rm -rf $(OBJS)
	$(V) printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:	clean
	$(V) rm -f $(REAL)/$(NAME)
	$(V) rm -f $(ROOT)/$(NAME)
	$(V) rm -rf $(REAL)
	$(V) printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:	fclean
	$(V) make --no-print-directory all

.PHONY: clean fclean debug all re intro