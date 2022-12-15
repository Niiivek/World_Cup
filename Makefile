CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS=`pkg-config --cflags --libs sdl2 sdl2_image `
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= test


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $(CCFLAGS) $^ -o $@  

%.o: %.cpp
	$(CC) $(LIBFLAGS) -o $@ -c $<

.depend:
	g++ $(LIBFLAGS)  -MM $(SRC) > .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest