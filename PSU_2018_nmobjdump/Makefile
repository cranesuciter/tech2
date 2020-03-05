##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

CC	=	gcc -g3

NAMENM	=	my_nm

NAMEOBJ	=	my_objdump

SRCNM	=	srcs/nm/main.c

SRCOBJ	=	srcs/objdump/main.c

OBJNM	=	$(SRCNM:.c=.o)

OBJOBJ	=	$(SRCOBJ:.c.=o)

all:		nm objdump

nm:	$(NAMENM)

objdump:	$(NAMEOBJ);

$(NAMENM): 	$(OBJNM)
		$(CC) $(OBJNM) -o $(NAMENM)

$(NAMEOBJ):	$(OBJNM)
		$(CC) $(OBJOBJ) -o $(NAMEOBJ)

clean:
		rm -f $(OBJOBJ)
		rm -f $(OBJNM)

fclean: 	clean
		rm -f $(NAMENM)
		rm -f $(NAMEOBJ)

re:		fclean all

.PHONY:		all clean fclean re

