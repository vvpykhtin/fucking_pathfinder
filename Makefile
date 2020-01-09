NAME = test

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SRCS = src/main.c src/pathfinder.c src/path.c src/print_result.c src/printer.c src/isdigits.c src/mx_isalf.c src/digits.c src/mx_errorcase_1.c src/mx_errorcase_2.c src/count_lines.c src/mx_ss.c src/mx_printline.c src/mx_errors.c src/mx_matrix.c src/mx_onlywords.c src/file_open.c
RSRCS = $(SRCS:src/%=%)
INC = inc/libmx.h inc/pathfinder.h
RINC = $(INC:inc/%=%)
LIB = libmx/libmx.a
RLIB = libmx.a
RLOBJ = mx_binary_search.o \
	mx_bubble_sort.o \
	mx_count_substr.o \
	mx_count_words.o \
	mx_create_node.o \
	mx_del_extra_spaces.o \
	mx_del_strarr.o \
	mx_file_to_str.o \
	mx_foreach.o \
	mx_get_char_index.o \
	mx_get_substr_index.o \
	mx_hex_to_nbr.o \
	mx_itoa.o \
	mx_list_size.o \
	mx_memccpy.o \
	mx_memchr.o \
	mx_memcmp.o \
	mx_memcpy.o \
	mx_memmem.o \
	mx_memmove.o \
	mx_memrchr.o \
	mx_memset.o \
	mx_nbr_to_hex.o \
	mx_pop_back.o \
	mx_pop_front.o \
	mx_pow.o \
	mx_printchar.o \
	mx_printint.o \
	mx_print_strarr.o \
	mx_printstr.o \
	mx_print_unicode.o \
	mx_push_back.o \
	mx_push_front.o \
	mx_quicksort.o \
	mx_read_line.o \
	mx_realloc.o \
	mx_replace_substr.o \
	mx_sort_list.o \
	mx_sqrt.o \
	mx_strcat.o \
	mx_strcmp.o \
	mx_strcpy.o \
	mx_strdel.o \
	mx_strdup.o \
	mx_strjoin.o \
	mx_strlen.o \
	mx_strncpy.o \
	mx_strndup.o \
	mx_strnew.o \
	mx_str_reverse.o \
	mx_strsplit.o \
	mx_strstr.o \
	mx_strtrim.o \
	mx_swap_char.o

RSOBJ = $(RSRCS:%.c=%.o)

all: install clean

install: 
	@cp $(INC) $(SRCS)  $(LIB) .
	@ar x $(LIB)
	@clang $(CFLAGS) -c $(RSRCS) -I $(RINC)
	@clang $(CFLAGS) -o $(NAME) $(RLOBJ) $(RSOBJ)
	@mkdir obj
	@mv $(RSOBJ) $(RLOBJ) ./obj

uninstall: 
	@rm -rf $(NAME)

clean: 
	@rm -rf $(RSRCS) $(RINC) $(RLIB)
	@rm -rf ./obj
	@rm -rf __.SYMDEF\ SORTED libmx.h.gch 

reinstall: uninstall all
