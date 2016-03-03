##
## Makefile for tekdoom in /gfx_tekdoom
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Mon Jan 11 20:31:57 2016 Antoine Baché
## Last update Wed Jan 27 08:33:36 2016 Luka Boulagnon
##

DEBUG=			no

SRC_PREFIX=		src/tekdoom/

SRC_FILES=		tekdoom.c			\
			menu/goto_menu.c		\
			menu/buttons.c			\
			menu/dont_click.c		\
			menu/glitch.c			\
			menu/intro.c			\
			menu/menu.c			\
			menu/rick_roll.c		\
			menu/graphics/basics.c		\
			menu/graphics/text.c		\
			menu/graphics/pixels.c		\
			menu/graphics/shapes.c		\
			menu/graphics/useful.c		\
			menu/graphics/projection.c	\
			menu/graphics/inits.c		\
			menu/graphics/colors.c		\
			menu/graphics/loader.c		\
			menu/graphics/videos.c		\
			menu/text/funcs/punctuation2.c	\
			menu/text/funcs/maths.c		\
			menu/text/funcs/abcde.c		\
			menu/text/funcs/uvwxy.c		\
			menu/text/funcs/z_backspace.c	\
			menu/text/funcs/pqrst.c		\
			menu/text/funcs/01234.c		\
			menu/text/funcs/56789.c		\
			menu/text/funcs/fghij.c		\
			menu/text/funcs/punctuation.c	\
			menu/text/funcs/klmno.c		\
			menu/text/funcs/dos.c		\
			menu/text/keys.c		\
			tchat/connect.c 		\
			tchat/input_addr.c 		\
			tchat/input_name.c 		\
			tchat/input_prt.c 		\
			tchat/inputs.c			\
			tchat/set.c			\
			tchat/open_graphic_client.c	\
			rebind/rebind.c			\
			inits_conf.c			\
			main.c

SRCENGINE_PREFIX=	src/engine/

SRCENGINE_FILES=	apply_move.c		\
			clear_zbuf.c		\
			count_render_test.c	\
			get_line.c		\
			get_triangle.c		\
			draw_chunk.c		\
			draw_polygon.c		\
			l2v.c			\
			launch_doom.c		\
			load_full_game.c	\
			load_map_polygon.c	\
			main.c			\
			matrix.c		\
			matrix2.c		\
			my_bunny.c		\
			my_escape.c		\
			my_puterr.c		\
			recalc_dir.c		\
			rotate_cam.c		\
			set_frame.c		\
			set_proj_mtx.c		\
			set_shadow.c		\
			tekfill.c		\
			trigo.c			\
			trigo2.c		\
			vector.c

SRCSERV_PREFIX=		src/server/

SRCSERV_FILES=		main.c				\
			socket.c			\
			socket2.c			\
			server.c			\
			udp.c				\
			udp_function.c			\
			server_functions.c		\
			debug_tools.c			\
			chat_msg.c			\
			pseudo_handler.c		\
			pseudo_handler2.c		\
			gen_seed.c			\
			udp_other.c			\
			player_assignation.c

SRCGCLIENT_PREFIX=	src/server/graphic_client/

SRCGCLIENT_FILES=	main.c				\
			background.c			\
			buttons.c			\
			cursor.c			\
			free_all.c			\
			keys.c				\
			mouse_area.c			\
			mouse.c				\
			player_name.c			\
			socket.c			\
			socket2.c			\
			socket3.c			\
			udp.c				\
			udp_msg_tools.c			\
			udp_msg_tools2.c		\
			udp_functions.c			\
			pseudo_handler.c		\
			player_status.c			\
			player_status2.c		\
			player_tab.c			\
			prepare_client.c		\
			print_letter.c			\
			transparency.c			\
			write_chat.c			\
			write_chat2.c			\
			text/01234.c			\
			text/56789.c			\
			text/abcde.c			\
			text/fghij.c			\
			text/klmno.c			\
			text/maths.c			\
			text/pqrst.c			\
			text/punctuation.c		\
			text/punctuation2.c		\
			text/uvwxy.c			\
			text/z_backspace.c

GRAPH_PREFIX=		src/tekdoom/menu/graphics/

GRAPH_FILES=		loader.c			\
			pixels.c			\
			colors.c			\
			shapes.c			\
			basics.c			\
			text.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		my_strlen.c 			\
			my_getnbr.c			\
			my_strcmp.c			\
			my_strncmp.c			\
			my_strncpy.c			\
			my_strncat.c			\
			my_put_nbr.c			\
			my_putstr.c			\
			my_strcpy.c			\
			my_bzero.c			\
			my_strndup.c

UI_FILES=		game.c				\
			core.c				\
			keys.c				\
			init_game.c			\
			interface.c			\
			toggle_chat.c			\
			write_chat.c			\
			interface/crosshair.c		\
			interface/game_chat.c		\
			interface/life.c		\
			interface/minimap.c		\
			interface/cursor.c		\
			interface/weapon.c		\
			chat_keys/01234.c		\
			chat_keys/56789.c		\
			chat_keys/abcde.c		\
			chat_keys/fghij.c		\
			chat_keys/klmno.c		\
			chat_keys/maths.c		\
			chat_keys/pqrst.c		\
			chat_keys/punctuation.c		\
			chat_keys/punctuation2.c	\
			chat_keys/uvwxy.c		\
			chat_keys/z_backspace.c		\
			chat_keys/print_letter.c

UI_PREFIX=		src/tekdoom/game/

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRCSERV=		$(addprefix $(SRCSERV_PREFIX),$(SRCSERV_FILES))

SRCGCLIENT=		$(addprefix $(SRCGCLIENT_PREFIX),$(SRCGCLIENT_FILES))

GRAPH=			$(addprefix $(GRAPH_PREFIX),$(GRAPH_FILES))

TOOLS=			$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRCUI=			$(addprefix $(UI_PREFIX),$(UI_FILES))

ENGINE=			$(addprefix $(SRCENGINE_PREFIX),$(SRCENGINE_FILES))

SRC+=			$(TOOLS)

SRC+=			$(SRCGCLIENT)

SRC+=			$(ENGINE)

SRC+=			$(SRCUI)

SRCSERV+=		$(TOOLS)

NAME=			tekdoom

NAMESERV=		server_tekdoom

NAMEGCLIENT=		graphical_client

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
		CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG -O1
else
		CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

LIB=			-L/usr/local/lib		\
			-L/home/${USER}/.froot/lib	\
			-I/home/${USER}/.froot/include	\
			-llapin				\
			-lsfml-audio			\
			-lsfml-graphics			\
			-lsfml-window			\
			-lsfml-system			\
			-lstdc++ -ldl			\
			-lm				\
			-lpthread

OBJ=			$(SRC:.c=.o)

OBJSERV=		$(SRCSERV:.c=.o)

OBJGCLIENT=		$(SRCGCLIENT:.c=.o)

OBJUI=			$(SRCUI:.c=.o)

$(NAMESERV):	$(NAME) $(OBJSERV)
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled server"
	@$(CC) $(OBJSERV) -o $(NAMESERV) $(LIB)

$(NAME):	$(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled game"
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME) $(NAMESERV)

clean:
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK"; tput sgr0
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJSERV)

fclean:	clean
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)
	@$(RM) $(NAMESERV)

re:	fclean all

ui:	$(OBJUI)
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled ui"
	@$(CC) $(OBJUI) -o ui $(LIB)

.PHONY:	all clean fclean re
