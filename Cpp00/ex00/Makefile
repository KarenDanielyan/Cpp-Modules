NAME	=	megaphone

BUILD	=	build

SRC		=	megaphone.cpp

OBJS		=	$(patsubst %.cpp, $(BUILD)/%.o, $(SRC))

# Compilation Options

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

# Colors

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m

# Rules

all:		$(BUILD) $(NAME)

$(BUILD):
			@mkdir -p $(BUILD)

$(BUILD)/%.o:	%.cpp
			@echo "$(BLUE)Compiling: $<$(RESET)"
			@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) has been created.$(RESET)"

clean:
			@rm -rf $(BUILD)
			@echo "$(RED)Objects have been removed.$(RESET)"

fclean:	clean
			@rm -f $(NAME)
			@echo "$(RED)$(NAME) has been removed.$(RESET)"

re:		fclean all

.PHONY:	all clean fclean re