
NAME            =       ft_container


CC            	=       c++
MKDIR           =       /bin/mkdir -p
RM              =       /bin/rm -rf


CFLAGS        =        -I incl/ -Wall -Wextra -Werror -c -std=c++98 -g -MMD -MP


OBJS_D          =       objs/


SRCS_L          =       main.cpp


OBJS_L  =               $(SRCS_L:.cpp=.o)
OBJS_L  :=              $(addprefix $(OBJS_D), $(OBJS_L))


DEP_L   =               $(OBJS_L:.o=.d)


all:                    $(NAME)

$(NAME):                $(OBJS_L)
						$(CC) $(OBJS_L) $(OUTPUT_OPTION)

-include $(DEP_L)

$(OBJS_D)%.o:   %.cpp
								$(MKDIR) $(OBJS_D)
								$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

clean:
						$(RM) $(OBJS_D)

fclean:                 clean
						$(RM) $(NAME)

re:                     fclean all

.PHONY:                 all clean fclean re