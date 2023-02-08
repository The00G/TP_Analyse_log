CC = g++
CFLAGS = -c -ansi -pedantic -Wall -std=c++11
DFLAGS = -DMAP
OBJ = Main.o Statistiques.o FluxLog.o Connexion.o
EXE = analog

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS := $(CFLAGS) $(DFLAGS)
endif

$(EXE) : $(OBJ)
	@echo edition des liens
	$(CC) $(OBJ) -o $(EXE)
	cp $(EXE) ./Tests/bin/$(EXE)

%.o : %.cpp
	@echo compilation de $<
	$(CC) $(CFLAGS) $<

Main.o : Statistiques.h 
Statistiques.o : Statistiques.h
FluxLog.o : FluxLog.h
Connexion.o : Connexion.h

.PHONY : remake clean debug

debug : clean $(EXE)

remake : clean $(EXE)

clean :
	rm -f $(EXE) *.o
