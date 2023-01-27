CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
#sur macos m1
#LIBFLAGS= `pkg-config --cflags --libs sdl2 sdl2_image sdl2_ttf sdl2_mixer`
#sur linux
LIBFLAGS= -lsdl2 -lsdl2_image -lsdl2_ttf -lsdl2_mixer
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(LIBFLAGS) 

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase
