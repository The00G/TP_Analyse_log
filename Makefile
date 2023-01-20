CC = g++
CFLAGS = -c -ansi -pedantic -Wall -std=c++11
DFLAGS = -DMAP
OBJ = Main.o Statistiques.o FluxLog.o LogApache.o
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
FluxLog.o : FluxLog.h
LogApache.o : LogApache.h

.PHONY : remake clean debug

debug : clean $(EXE)

remake : clean $(EXE)

clean :
	rm -f $(EXE) *.o
