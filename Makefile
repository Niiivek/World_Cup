CC=g++
#CCFLAGS= -Wall -Werror -std=c++11 -g 
CCFLAGS= -Wall -std=c++11 -g 
#sur macos m1
LIBFLAGS= `pkg-config --cflags --libs sdl2 sdl2_image sdl2_ttf sdl2_mixer`
#sur linux
#LIBFLAGS= -lsdl2 -lsdl2_image -lsdl2_ttf -lsdl2_mixer
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= jeu


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC)  $(CCFLAGS)  $^ -o $@  $(LIBFLAGS)

%.o: %.cc
	$(CC) $(LIBFLAGS) $(CCFLAGS) -o $@ -c $<

.depend:
	$(CC) $(CCFLAGS) $(LIBFLAGS) -MM $(SRC) > .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest