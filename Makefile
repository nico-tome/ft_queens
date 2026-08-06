NAME		:=	ft_queens

SRC_DIR		:=	src/
BUILD_DIR	:=	build/

SRC			:=	main.c \
				memory.c \
				parser.c \
				printer.c \
				solver.c

OBJ = $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

HEADERS = include/

CC = cc

FLAGS = -Wall -Werror -Wextra -g

TPUT = tput -T xterm-256color
_RESET := $(shell $(TPUT) sgr0)
_BOLD := $(shell $(TPUT) bold)
_ITALIC := $(shell $(TPUT) sitm)
_UNDER := $(shell $(TPUT) smul)
_GREEN := $(shell $(TPUT) setaf 2)
_YELLOW := $(shell $(TPUT) setaf 3)
_RED := $(shell $(TPUT) setaf 1)
_GRAY := $(shell $(TPUT) setaf 8)
_PURPLE := $(shell $(TPUT) setaf 5)

OBJS_TOTAL = $(words $(OBJ))
CURR_OBJ = 0

all: ${NAME} banner

no-banner:	${NAME}

banner: 
	@echo "███████╗████████╗     ██╗     ███████╗";
	@echo "██╔════╝╚══██╔══╝     ██║     ██╔════╝";
	@echo "█████╗     ██║        ██║     ███████╗";
	@echo "██╔══╝     ██║        ██║     ╚════██║";
	@echo "██║        ██║███████╗███████╗███████║";
	@echo "╚═╝        ╚═╝╚══════╝╚══════╝╚══════╝";
	@echo "                                      ";

$(NAME): ${LIBS} ${OBJ}
	@${CC} -o ${NAME} ${FLAGS} ${OBJ}
	@printf "${_BOLD}$(NAME)${_RESET} compiled ${_GREEN}${_BOLD}successfully${_RESET}\n\n"

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@${CC} -o $@ -I $(HEADERS) -c $< ${FLAGS}
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "${_GREEN}(${_BOLD}%3s%%${_RESET}${_GREEN}) ${_RESET}Compiling ${_BOLD}${_PURPLE}$<${_RESET}\n" "$(PERCENT)"

clean:
	@rm -rf $(BUILD_DIR)
	@printf "\n${_BOLD}All objects are ${_RED}cleaned${_RESET}! 🎉\n\n"

fclean: clean
	@rm -f ${NAME}
	@printf "Cleaned ${_BOLD}${NAME}${_RESET} !\n\n"

help:
	@printf "\n${_BOLD}${_PURPLE}Project Makefile Help${_RESET}\n"
	@printf "${_GRAY}----------------------------------------${_RESET}\n\n"

	@printf "${_BOLD}${_YELLOW}Usage:${_RESET}\n"
	@printf "  make ${_GREEN}[target]${_RESET}\n\n"

	@printf "${_BOLD}${_YELLOW}Available targets:${_RESET}\n\n"

	@printf "  ${_GREEN}all${_RESET}\n"
	@printf "      Build the project\n\n"

	@printf "  ${_GREEN}$(NAME)${_RESET}\n"
	@printf "      Compile the binary\n\n"

	@printf "  ${_GREEN}clean${_RESET}\n"
	@printf "      Remove object files (${_ITALIC}$(BUILD_DIR)${_RESET})\n\n"

	@printf "  ${_GREEN}fclean${_RESET}\n"
	@printf "      Remove object files and binary\n\n"

	@printf "  ${_GREEN}re${_RESET}\n"
	@printf "      Full rebuild (${_ITALIC}fclean + all${_RESET})\n\n"

	@printf "  ${_GREEN}help${_RESET}\n"
	@printf "      Display this help message\n\n"

	@printf "${_BOLD}${_YELLOW}Variables:${_RESET}\n\n"

	@printf "  ${_GREEN}PREFIX${_RESET}\n"
	@printf "      Installation prefix (default: ${_ITALIC}/usr/local${_RESET})\n\n"

	@printf "  ${_GREEN}BINDIR${_RESET}\n"
	@printf "      Binary installation directory (default: ${_ITALIC}\$$PREFIX/bin${_RESET})\n\n"

	@printf "${_BOLD}${_YELLOW}Examples:${_RESET}\n\n"

	@printf "  ${_ITALIC}make${_RESET}\n"
	@printf "  ${_ITALIC}make re${_RESET}\n"
	@printf "  ${_ITALIC}make install${_RESET}\n"
	@printf "  ${_ITALIC}make install PREFIX=\$$HOME/.local${_RESET}\n\n"

	@printf "${_BOLD}${_YELLOW}Credits:${_RESET}\n\n"

	@printf "  ${_GREEN}Project:${_RESET} ${NAME}\n"
	@printf "  ${_GREEN}Author:${_RESET} ntome\n"
	@printf "  ${_GREEN}Language:${_RESET} C\n"
	@printf "  ${_GREEN}Build System:${_RESET} Makefile\n\n"

	@printf "${_GRAY}----------------------------------------${_RESET}\n\n"

re: fclean all

.PHONY: all clean fclean re banner no-banner help
