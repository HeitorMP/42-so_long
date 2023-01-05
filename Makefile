

NAME		=	solong.a
BONUS_NAME	=	solong_bonus.a
SRCSDIR		=	srcs
OBJSDIR		=	objs
B_SRCSDIR	=	srcs_bonus
B_OBJSDIR	=	objs_bonus
INCLUDES	=	includes

SRCS		=	so_long.c game_loop.c \
				game_over/exit_request.c game_over/free_playfield.c game_over/game_over.c \
				init_game/init_game.c init_game/set_counters.c init_game/set_flags.c init_game/set_path.c \
				init_game/game_init_render.c \
				playfield/check_playfield.c playfield/check_way_out.c playfield/get_playfield.c \
				events/game_events.c events/move_events.c events/collision_events.c \
				engine/put_sprite.c engine/move_sprite.c engine/collision.c \
				error/print_error.c error/exit_error.c \
				animation/animation.c animation/hero_animation.c animation/collect_animation.c animation/wall_animation.c \
				animation/exit_animation.c \

BONUS_SRCS	=	so_long_bonus.c game_loop_bonus.c \
				game_over/exit_request_bonus.c game_over/free_playfield_bonus.c game_over/game_over_bonus.c \
				init_game/init_game_bonus.c init_game/set_counters_bonus.c init_game/set_flags_bonus.c init_game/set_path_bonus.c \
				init_game/game_init_render_bonus.c \
				playfield/check_playfield_bonus.c playfield/check_way_out_bonus.c playfield/get_playfield_bonus.c \
				events/game_events_bonus.c events/move_events_bonus.c events/collision_events_bonus.c events/patrol_move_events_bonus.c \
				engine/put_sprite_bonus.c engine/move_sprite_bonus.c engine/collision_bonus.c engine/random_pos.c \
				error/print_error_bonus.c error/exit_error_bonus.c \
				animation/animation_bonus.c animation/hero_animation_bonus.c animation/collect_animation_bonus.c animation/wall_animation_bonus.c \
				animation/exit_animation_bonus.c animation/patrol_animation.c\


CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -lXext -lX11 -lm -lbsd

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)
BONUS_OBJ	= $(BONUS_SRCS:%.c=$(B_OBJSDIR)/%.o)

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@ar rc $(NAME) $(OBJS)
	$(CC) $(NAME) -L./mlx/. $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o so_long
	@echo "Done!"

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -I. -O3 $(CFLAGS) -g -I.. -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@ar rc $(BONUS_NAME) $(BONUS_OBJ)
	$(CC) $(BONUS_NAME) -L./mlx/. $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o so_long_bonus
	@echo "Done!"

$(BONUS_OBJ): $(B_OBJSDIR)/%.o: $(B_SRCSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -I. -O3 $(CFLAGS) -g -I.. -c $< -o $@

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJSDIR)
	rm -rf $(B_OBJSDIR)

fclean: clean
	rm -rf $(NAME) so_long
	rm -rf $(BONUS_NAME) so_long_bonus
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
