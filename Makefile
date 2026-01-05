NAME = Scop
CC = g++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -Isrcs/include
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
BUILD_DIR = .build
SRCS_DIR = srcs
SRCS = main shader texture
CPPFILES = $(addsuffix .cpp, $(SRCS))
GLAD_C = .deps/glad.c
GLAD_INC = .deps
OBJS = $(addprefix $(BUILD_DIR)/,$(CPPFILES:.cpp=.o)) $(BUILD_DIR)/glad.o
DEBUG = -D DEBUG=1

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	@echo "\n$(NAME) is ready for use!\n"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(GLAD_INC) -c $< -o $@

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

run: all
	@./$(NAME)

debug: CFLAGS += $(DEBUG)
debug: clean all

.PHONY: all clean fclean re debug run

.gitignore: Makefile
	@echo '.build' > .gitignore
	@echo '.vscode' >> .gitignore
	@echo $(NAME) >> .gitignore