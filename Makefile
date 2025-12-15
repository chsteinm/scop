NAME = Scop
CC = g++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
BUILD_DIR = .build
SRCS = main
CPPFILES = $(addsuffix .cpp, $(SRCS))
GLAD_C = .deps/glad.c
GLAD_INC = .deps
OBJS = $(addprefix $(BUILD_DIR)/,$(CPPFILES:.cpp=.o)) $(BUILD_DIR)/glad.o
DEBUG = -D DEBUG=1

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	@echo "\n$(NAME) is ready for use!\n"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/glad.o: $(GLAD_C) Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(GLAD_INC) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make --no-print-directory

debug: CFLAGS += $(DEBUG)
debug: clean all

.PHONY: all clean fclean re debug

.gitignore: Makefile
	@echo '.build' > .gitignore
	@echo '.vscode' >> .gitignore
	@echo $(NAME) >> .gitignore