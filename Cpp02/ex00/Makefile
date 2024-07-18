NAME	=	fixed

BUILD	=	build

SRC		=	main.cpp Fixed.cpp

INC		=	Fixed.h

OBJS	=	$(patsubst %.cpp, $(BUILD)/%.o, $(SRC))

DEP		=	$(INC) Makefile

# Compilation Options

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

INCFLAGS	=	-I .

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m

# Rules

all:		$(BUILD) $(NAME)

$(BUILD):
			@mkdir -p $(BUILD)

$(BUILD)/%.o:	%.cpp $(DEP)
			@echo "$(BLUE)Compiling: $<$(RESET)"
			@$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			@$(CXX) $(CXXFLAGS) $(INCFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) has been created.$(RESET)"

clean:
			@rm -rf $(BUILD)
			@echo "$(RED)Objects have been removed.$(RESET)"

fclean:	clean
			@rm -f $(NAME)
			@echo "$(RED)$(NAME) has been removed.$(RESET)"

re:		fclean all

.PHONY:	all clean fclean re