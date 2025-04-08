# **************************************************************************** #
#		General variables													   #
# **************************************************************************** #

NAME		= megaphone

SRC_DIR		= src

OBJ_DIR		= obj

FUNC		= megaphone.cpp

SRC			= $(addprefix $(SRC_DIR)/, $(FUNC))

HEADER		=

OBJ			= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEP			= $(OBJ_DIR) $(HEADER)

CC			= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#		Compilation															   #
# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(DEP) $(OBJ)
				$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
				$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
				mkdir -p $@

# **************************************************************************** #
#		Debug																   #
# **************************************************************************** #

debug:				$(DEP) $(OBJ)
					@echo "Compiling with debug flag"
					$(CC) $(CFLAGS) -g $(INC) -o $(NAME) $(SRC) $(LIB)

# **************************************************************************** #
#		Clean up															   #
# **************************************************************************** #

clean:
					rm -rf $(DIR_OBJ)

fclean:
					rm -rf $(DIR_OBJ)
					rm -rf $(NAME)

re:					fclean all

.PHONY:				all clean fclean re debug
