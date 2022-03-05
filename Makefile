NAMEC   =   client
SRCC    =   client.c utils.c utils2.c
NAMES   =   server
SRCS    =   server.c utils.c utils2.c
OBJS	=	$(SRCS:c=o)
OBJC	=	$(SRCC:c=o)
FLAGS   =   -Wall -Wextra -Werror
HEADER	=	minitalk.h
NAME = minitalk

all:	$(NAME)
$(NAME): $(NAMES) $(NAMEC)
.c.o:       %.c $(HEADER)
			gcc $(FLAGS) -c -o $@ $<
$(NAMEC):	$(OBJC) $(HEADER)
			gcc $(OBJC) -o $(NAMEC)
$(NAMES):	$(OBJS) $(HEADER)
			gcc $(OBJS) -o $(NAMES)
clean:
			rm -f $(OBJS)
			rm -f $(OBJC)
fclean:     clean
			rm -f $(NAMEC)
			rm -f $(NAMES)
re:         fclean all

.PHONY:     all clean fclean re