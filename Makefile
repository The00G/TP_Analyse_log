CC = g++
CFLAGS = -c -ansi -pedantic -Wall -std=c++11
DFLAGS = -DMAP
OBJ = Main.o Graph.o
EXE = analog

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS := $(CFLAGS) $(DFLAGS)
endif

$(EXE) : $(OBJ)
	@echo edition des liens
	$(CC) $(OBJ) -o $(EXE)

%.o : %.cpp
	@echo compilation de $<
	$(CC) $(CFLAGS) $<

Main.o : Statistiques.h 
Statistiques.o : Statistiques.h

.PHONY : remake clean debug

debug : clean $(EXE)

remake : clean $(EXE)

clean :
	rm -f $(EXE) *.o
