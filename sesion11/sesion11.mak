# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src


all : $(BIN)/IV_DemoVectorDinamico-Todo \
			$(BIN)/IV_DemoMatriz2D_1-Todo \
			$(BIN)/IV_DemoLista-Todo

#ejecutables
$(BIN)/IV_DemoVectorDinamico-Todo : $(OBJ)/IV_DemoVectorDinamico-Todo.o \
			       $(LIB)/libVectorDinamico.a
	g++ -g -o $(BIN)/IV_DemoVectorDinamico-Todo \
	$(OBJ)/IV_DemoVectorDinamico-Todo.o -lVectorDinamico -L$(LIB) -std=c++11

$(BIN)/IV_DemoMatriz2D_1-Todo : $(OBJ)/IV_DemoMatriz2D_1-Todo.o \
						   $(LIB)/libMatriz2D_1.a

	g++ -g -o $(BIN)/IV_DemoMatriz2D_1-Todo $(OBJ)/IV_DemoMatriz2D_1-Todo.o\
	 -lMatriz2D_1 -L$(LIB) -std=c++11

$(BIN)/IV_DemoLista-Todo : $(OBJ)/IV_DemoLista-Todo.o $(LIB)/libLista.a
	g++ -g -o $(BIN)/IV_DemoLista-Todo $(OBJ)/IV_DemoLista-Todo.o \
	-lLista -L$(LIB) -std=c++11

#librerias
$(LIB)/libVectorDinamico.a : $(OBJ)/VectorDinamico.o
	ar -rvs $(LIB)/libVectorDinamico.a $(OBJ)/VectorDinamico.o

$(LIB)/libMatriz2D_1.a : $(OBJ)/Matriz2D_1.o
	ar -rvs $(LIB)/libMatriz2D_1.a \
	$(OBJ)/Matriz2D_1.o

$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o

#objetos del main
$(OBJ)/IV_DemoVectorDinamico-Todo.o : $(SRC)/IV_DemoVectorDinamico-Todo.cpp
	g++ -g -c -o $(OBJ)/IV_DemoVectorDinamico-Todo.o \
	$(SRC)/IV_DemoVectorDinamico-Todo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/IV_DemoMatriz2D_1-Todo.o : $(SRC)/IV_DemoMatriz2D_1-Todo.cpp
	g++ -g -c -o $(OBJ)/IV_DemoMatriz2D_1-Todo.o  \
	$(SRC)/IV_DemoMatriz2D_1-Todo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/IV_DemoLista-Todo.o : $(SRC)/IV_DemoLista-Todo.cpp
	g++ -g -c -o $(OBJ)/IV_DemoLista-Todo.o $(SRC)/IV_DemoLista-Todo.cpp \
	-I$(INCLUDE) -std=c++11

#objetos
$(OBJ)/VectorDinamico.o : $(SRC)/VectorDinamico.cpp
	g++ -g -c -o $(OBJ)/VectorDinamico.o $(SRC)/VectorDinamico.cpp \
	 -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp
	g++ -g -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp \
	 -I$(INCLUDE) -std=c++11

$(OBJ)/Lista.o : $(SRC)/Lista.cpp
	g++ -g -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11
#opciones de limpieza
cleanlib :
	@echo Borrando librerias
	@-rm $(LIB)/*.a

clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o
mr-proper : clean cleanlib

	@echo Borrando ejecutables
	@-rm $(BIN)/*
