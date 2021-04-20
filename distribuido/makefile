CC = g++
LDFLAGS = 
BLDDIR = .
INCDIR = $(BLDDIR)/inc
SRCDIR = $(BLDDIR)/src
OBJDIR = $(BLDDIR)/obj
CFLAGS = -c -Wall -I $(INCDIR) -o2 -static 

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
EXE = bin/bin

IP_CENTRAL = 192.168.0.53
PORTA1 = 10029
PORTA2 = 10129

all:	clean $(EXE) 

$(EXE): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJDIR)/*.o -pthread -lncurses -lform -lwiringPi -o $@ 

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJDIR)/*.o $(EXE)


.PHONY: run
run : $(EXE)
	./$(EXE) $(PORTA1) $(IP_CENTRAL) $(PORTA2)