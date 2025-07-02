# **************************************************************************** #
#		General variables													   #
# **************************************************************************** #

NAME				= PmergeMe

SRC_DIR				= src

OBJ_DIR				= obj

INC_DIR				= inc

FUNC				= main.cpp \
					PmergeMe.cpp \
					parsing.cpp \
					StopWatch.cpp \
					MergeInsertList.cpp \
					MergeInsertVector.cpp

HEAD				= PmergeMe.hpp \
					StopWatch.hpp \
					Color.hpp \
					Log.hpp

SRC					= $(addprefix $(SRC_DIR)/, $(FUNC))

HEADER				= $(addprefix $(INC_DIR)/, $(HEAD))

INC					= -I$(INC_DIR)

OBJ					= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEP					= $(OBJ_DIR) $(HEADER)

CC					= c++

FLAGS				= -Wall -Wextra -Werror -std=c++98

# **************************************************************************** #
#		Compilation															   #
# **************************************************************************** #

all:				$(NAME)

$(NAME):			$(DEP) $(OBJ)
					$(CC) $(FLAGS) $(INC) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
					$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
					mkdir -p $@

# **************************************************************************** #
#		Debug																   #
# **************************************************************************** #

debug:				$(DEP) $(OBJ)
					@echo "Compiling with debug flag"
					$(CC) $(CFLAGS) -g $(INC) -o $(NAME) $(SRC) $(LIB)

verbose:			$(DEP) $(OBJ)
					@echo "Compiling with additional logging info"
					$(CC) $(CFLAGS) -D PRINT -g $(INC) -o $(NAME) $(SRC) $(LIB)

# **************************************************************************** #
#		Clean up															   #
# **************************************************************************** #

clean:
					rm -rf $(OBJ_DIR)

fclean:
					rm -rf $(OBJ_DIR)
					rm -rf $(NAME)

re:					fclean all

.PHONY:				all clean fclean re debug
