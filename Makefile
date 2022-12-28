
NAME            =       ft_container
NAME_S			=		stack_test
NAME_V			=		vector_test
NAME_M			=		map_test


CC            	=       clang++
MKDIR           =       /bin/mkdir -p
RM              =       /bin/rm -rf


CFLAGS        =        -I incl/ -Wall -Wextra -Werror -c -std=c++98 -g -MMD -MP


OBJS_D          =       objs/


SRCS_L          =       main.cpp
TEST_STACK		=		stack_main.cpp
TEST_MAP		=		map_main.cpp
TEST_VECTOR		=		vector_main.cpp


OBJS_L  =               $(SRCS_L:.cpp=.o)
OBJS_L  :=              $(addprefix $(OBJS_D), $(OBJS_L))
OBJS_STACK	=			$(TEST_STACK:.cpp=.o)
DEPS_STACK	=			$(TEST_STACK:.cpp=.d)
OBJS_VECTOR	=			$(TEST_VECTOR:.cpp=.o)
DEPS_VECTOR	=			$(TEST_VECTOR:.cpp=.d)
OBJS_MAP	=			$(TEST_MAP:.cpp=.o)
DEPS_MAP	=			$(TEST_MAP:.cpp=.d)


DEP_L   =               $(OBJS_L:.o=.d)


all:                    $(NAME)

stack:	$(NAME_S)

vector: $(NAME_V)

map:	$(NAME_M)

$(NAME_S):		$(OBJS_STACK)
	$(CC) $(OBJS_STACK) $(OUTPUT_OPTION) -o $(NAME_S)
$(NAME_V):		$(OBJS_VECTOR)
	$(CC) $(OBJS_VECTOR) $(OUTPUT_OPTION) -o $(NAME_V)
$(NAME_M):		$(OBJS_MAP)
	$(CC) $(OBJS_MAP) $(OUTPUT_OPTION) -o $(NAME_M)

$(NAME):                $(OBJS_L)
						$(CC) $(OBJS_L) $(OUTPUT_OPTION)

-include $(DEP_L)

$(OBJS_D)%.o:   %.cpp
								$(MKDIR) $(OBJS_D)
								$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

clean:
						$(RM) $(OBJS_D) $(OBJS_MAP) $(OBJS_STACK) $(OBJS_VECTOR)

fclean:                 clean
						$(RM) $(NAME) $(NAME_M) $(NAME_S) $(NAME_V)

re:                     fclean all

.PHONY:                 all clean fclean re stack map vector