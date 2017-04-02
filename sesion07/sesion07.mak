# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src



all : $(BIN)/II_Demo-Matriz2D_1 $(BIN)/II_Demo-Matriz2D_2

$(BIN)/II_Demo-Matriz2D_1 : $(OBJ)/II_Demo-Matriz2D_1.o $(OBJ)/Matriz2D_1.o \
														$(OBJ)/GeneradorAleatorioEnteros.o

	g++ -o $(BIN)/II_Demo-Matriz2D_1  $(OBJ)/II_Demo-Matriz2D_1.o \
				 $(OBJ)/Matriz2D_1.o $(OBJ)/GeneradorAleatorioEnteros.o -std=c++11

$(BIN)/II_Demo-Matriz2D_2 : $(OBJ)/II_Demo-Matriz2D_2.o $(OBJ)/Matriz2D_2.o \
														$(OBJ)/GeneradorAleatorioEnteros.o

	g++ -o $(BIN)/II_Demo-Matriz2D_2  $(OBJ)/II_Demo-Matriz2D_2.o \
				 $(OBJ)/Matriz2D_2.o $(OBJ)/GeneradorAleatorioEnteros.o -std=c++11

$(OBJ)/II_Demo-Matriz2D_2.o : $(SRC)/II_Demo-Matriz2D_2.cpp
	g++ -c -o $(OBJ)/II_Demo-Matriz2D_2.o $(SRC)/II_Demo-Matriz2D_2.cpp \
					 -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_2.o :  $(SRC)/Matriz2D_2.cpp
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/II_Demo-Matriz2D_1.o : $(SRC)/II_Demo-Matriz2D_1.cpp
	g++ -c -o $(OBJ)/II_Demo-Matriz2D_1.o $(SRC)/II_Demo-Matriz2D_1.cpp \
					 -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1.o :  $(SRC)/Matriz2D_1.cpp
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
                                     $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
              $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++11

clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
