##
## EPITECH PROJECT, 2019
## ASM_minilibc_2018
## File description:
## Makefile
##

AS	=	nasm
LD	=	ld

ASFLAGS	=	-f elf64
LDFLAGS = --share

RM	=	rm -f

NAME	=	libasm.so

SRCS	=	src/strlen.asm	\
			src/strchr.asm	\
			src/memset.asm	\
			src/memcpy.asm	\
			src/strcmp.asm	\
			src/memmove.asm	\
			src/strncmp.asm	\
			src/strcasecmp.asm	\
			src/rindex.asm

OBJS		= $(SRCS:.asm=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ld -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re