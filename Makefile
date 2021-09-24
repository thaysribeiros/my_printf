# -*- Makefile -*-
CC = gcc
CFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address
LINKERFLAG = -lm
SOURCES = main.c my_printf.c helper_functions.c conversion_functions.c my_printf.h 
OBJECTS = $(SOURCES: .c=.o)
TARGET = my_printf

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean fclean re

clean:
	@rm -f *.o

fclean:
	@rm $(TARGET)
	$(clean)

re: $(fclean)
	$(MAKE)
