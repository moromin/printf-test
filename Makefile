MAIN_PATH	= /usr/local/src/googletest-release-1.11.0/googletest/src/gtest_main.cc
GTEST_PATH	= /usr/local/src/gtest/gtest-all.cc
IN_GUACAMOLE=TRUE

PRINTF_PATH		= ../srcs
FT_HEADER_PATH	= ../includes
HEADER_PATH		= ./tests
MANDATORY		= c s p d i u x X pct
# TODO
# BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap

SRCNAME			= $(wildcard *.c)
# B_SRCNAME		= ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
				ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS    		= $(addprefix $(PRINTF_PATH)/, $(SRCNAME))
# B_SRC			= $(addprefix $(PRINTF_PATH)/, $(B_SRCNAME))

OBJS    		= $(SRCNAME:%.c=%.o)
# B_OBJS			= $(B_SRCNAME:%.c=%.o)
CFLAGS			= -std=c++11
CC				= gcc
GCCFLAG   		= -Wall -Wextra -Werror

TEST_SRCNAME	= ft_printf_c_test.cpp ft_printf_s_test.cpp ft_printf_p_test.cpp ft_printf_d_test.cpp \
				ft_printf_i_test.cpp ft_printf_u_test.cpp ft_printf_x_test.cpp ft_printf_X_test.cpp \
				ft_printf_pct_test.cpp				

# TODO
# TEST_B_SRCNAME	= ft_lstsize_test.cpp ft_lstlast_test.cpp ft_lstadd_front_test.cpp ft_lstadd_back_test.cpp \
				ft_lstnew_test.cpp ft_lstdelone_test.cpp ft_lstclear_test.cpp ft_lstiter_test.cpp ft_lstmap_test.cpp
TESTS_PATH		= tests/
TEST_SRCS   	= $(addprefix $(TESTS_PATH), $(TEST_SRCNAME))
# TEST_B_SRCS   	= $(addprefix $(TESTS_PATH), $(TEST_B_SRCNAME))


ifeq ($(IN_GUACAMOLE),TRUE)
	MAIN_PATH	= googletest-release-1.11.0/googletest/src/gtest_main.cc
    GTEST_PATH	= gtest/gtest-all.cc
    # FT_HEADER_PATH = ..
endif

m: mstart
	g++ $(CFLAGS) $(TEST_SRCS) $(MAIN_PATH) $(GTEST_PATH) -I$(FT_HEADER_PATH) -L$(PRINTF_PATH) -lft
	@./a.out
	@rm -f a.out *.o

b: bstart
	g++ $(CFLAGS) $(TEST_B_SRCS) $(MAIN_PATH) $(GTEST_PATH) -I. -L$(PRINTF_PATH) -lft
	@./a.out
	@rm -f a.out *.o

$(MANDATORY): mstart
	g++ $(CFLAGS) $(TESTS_PATH)ft_printf_$@_test.cpp $(MAIN_PATH) -I$(FT_HEADER_PATH) $(GTEST_PATH) -L$(PRINTF_PATH) -lft
	@./a.out
	@rm -f a.out *.o

# $(BONUS): bstart
# 	g++ $(CFLAGS) $(TESTS_PATH)ft_$@_test.cpp $(MAIN_PATH) -I. $(GTEST_PATH) -L$(PRINTF_PATH) -lft
# 	@./a.out
# 	@rm -f a.out ft_$@.o

init:
	curl -OL 'https://github.com/google/googletest/archive/release-1.11.0.tar.gz'
	tar zxvf release-1.11.0.tar.gz
	rm -f release-1.11.0.tar.gz
	IN_GUACAMOLE=TRUE
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py ./

mstart:
	make -C ../
# make -C $(PRINTF_PATH)

# bstart:
# 	make bonus -C $(PRINTF_PATH)

clean:
	make clean -C $(PRINTF_PATH)
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C $(PRINTF_PATH)

.PHONY: all init
