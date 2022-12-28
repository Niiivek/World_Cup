CC=g++
#CCFLAGS= -Wall -Werror -std=c++11 -g 
CCFLAGS= -Wall -std=c++11 -g 
LIBFLAGS=`pkg-config --cflags --libs sdl2 sdl2_image sdl2_ttf`
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= test


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC)  $(CCFLAGS)  $^ -o $@  $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(LIBFLAGS) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) $(LIBFLAGS) -MM $(SRC) > .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest