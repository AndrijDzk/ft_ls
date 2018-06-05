NAME = ft_ls
CC = gcc
CFLAGS =
SRCS = ft_scan.c\
		ft_scan_flags.c\
		ft_flag_funcs.c\
		ft_flag_funcs2.c\
		ft_plist_pal.c\
		ft_ilist.c\
		ft_ilist_del.c\
		ft_alist.c\
		ft_get_info.c\
		ft_get_perm.c\
		ft_read_dir.c\
		ft_proc_places.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) main.c
	make -C cstdlib
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) cstdlib/cstdlib.a

debug :
	make debug -C cstdlib
	$(CC) -g -o $(NAME) main.c $(SRCS) cstdlib/*.o

drun : debug dclean
	lldb $(NAME)
	make dfclean

clean :
	make clean -C cstdlib
	rm -f $(OBJ)

fclean : clean
	rm -f cstdlib/cstdlib.a
	rm -f $(NAME)

dclean :
	make dclean -C cstdlib

dfclean : dclean
	rm -Rf $(NAME) $(NAME).dSYM

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
