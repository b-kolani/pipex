NAME = pipex
BONUS_NAME = pipex_bonus

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
END = \033[0m

CC = cc 
FLAGS = -Wall -Wextra -Werror 
RMV = rm -rf

SRCS = pipex.c ft_strjoin.c ft_free_tab.c \
		ft_split.c utils.c ft_handle_path.c \

SRCS_BONUS = pipex_bonus.c ft_free_tab.c \
			ft_split.c utils_bonus.c \
			get_next_line.c here_doc_bonus.c \
			ft_strjoin.c ft_handle_path.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c pipex.h utils.h
	@echo "$(YELLOW)Creating binary...$(END)"
	$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Object file created!.$(END)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating $(NAME) program...$(END)"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!.$(END)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): pipex_bonus.h $(BONUS_OBJS)
	@echo "$(YELLOW)Creating $(BONUS_NAME) program...$(END)"
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) created!.$(END)"


clean:
	$(RMV) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)Object files were deleted.$(END)"

fclean: clean
	$(RMV) $(NAME) $(BONUS_NAME)
	@echo "$(RED)$(NAME) and $(BONUS_NAME) were deleted.$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
