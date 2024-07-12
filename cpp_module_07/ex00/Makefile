NAME		= template
SRCS		= $(wildcard ./*.cpp)
INC			= $(wildcard ./*.hpp) $(wildcard ./*.h)
OBJS_DIR	= ./obj
OBJS		= $(SRCS:./%.cpp=$(OBJS_DIR)/%.o)
CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98 -I ./
MAKEFILE	= ./Makefile

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(SRCS) $(MAKEFILE) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(OBJS_DIR)/%.o: ./%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re