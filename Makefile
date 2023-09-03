CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/matop.o $(OBJ)/factorial.o $(OBJ)/fibonacci.o 
HDRS = $(INC)/factorial.h $(INC)/fibonacci.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/matop

run:  $(EXE)
	$(EXE) -i -n 5
	$(EXE) -j -n 5
	$(EXE) -k -n 8
	$(EXE) -s -n 8

$(BIN)/matop: $(OBJS)
	$(CC) -g -o $(BIN)/matop $(OBJS) $(LIBS)

$(OBJ)/matop.o: $(HDRS) $(SRC)/matop.c
	$(CC) $(CFLAGS) -o $(OBJ)/matop.o $(SRC)/matop.c 

$(OBJ)/factorial.o: $(HDRS) $(SRC)/factorial.c
	$(CC) $(CFLAGS) -o $(OBJ)/factorial.o $(SRC)/factorial.c 

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
