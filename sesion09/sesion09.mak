# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src



all : $(BIN)/III_DemoVectorDinamico $(BIN)/III_DemoMatriz2D_1 \
			$(BIN)/III_DemoLista

#ejecutables
$(BIN)/III_DemoVectorDinamico : $(OBJ)/III_DemoVectorDinamico.o \
																$(LIB)/libVectorDinamico_ConstructorCopia.a
	g++ -g -o $(BIN)/III_DemoVectorDinamico $(OBJ)/III_DemoVectorDinamico.o \
	-lVectorDinamico_ConstructorCopia -L$(LIB) -std=c++11

$(BIN)/III_DemoMatriz2D_1 : $(OBJ)/III_DemoMatriz2D_1.o \
																$(LIB)/libMatriz2D_1_ConstructorCopia.a
	g++ -g -o $(BIN)/III_DemoMatriz2D_1 $(OBJ)/III_DemoMatriz2D_1.o \
	-lMatriz2D_1_ConstructorCopia -L$(LIB) -std=c++11

$(BIN)/III_DemoLista : $(OBJ)/III_DemoLista.o \
																$(LIB)/libLista_ConstructorCopia.a
	g++ -g -o $(BIN)/III_DemoLista $(OBJ)/III_DemoLista.o \
	-lLista_ConstructorCopia -L$(LIB) -std=c++11

#librerias
$(LIB)/libVectorDinamico_ConstructorCopia.a : \
																			$(OBJ)/VectorDinamico_ConstructorCopia.o
	ar -rvs $(LIB)/libVectorDinamico_ConstructorCopia.a \
	$(OBJ)/VectorDinamico_ConstructorCopia.o

$(LIB)/libMatriz2D_1_ConstructorCopia.a : \
																			$(OBJ)/Matriz2D_1_ConstructorCopia.o
	ar -rvs $(LIB)/libMatriz2D_1_ConstructorCopia.a \
	$(OBJ)/Matriz2D_1_ConstructorCopia.o

$(LIB)/libLista_ConstructorCopia.a : \
																			$(OBJ)/Lista_ConstructorCopia.o
	ar -rvs $(LIB)/libLista_ConstructorCopia.a $(OBJ)/Lista_ConstructorCopia.o

#objetos del main
$(OBJ)/III_DemoVectorDinamico.o : $(SRC)/III_DemoVectorDinamico.cpp
	g++ -g -c -o $(OBJ)/III_DemoVectorDinamico.o \
	$(SRC)/III_DemoVectorDinamico.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/III_DemoMatriz2D_1.o : $(SRC)/III_DemoMatriz2D_1.cpp
	g++ -g -c -o $(OBJ)/III_DemoMatriz2D_1.o \
	$(SRC)/III_DemoMatriz2D_1.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/III_DemoLista.o : $(SRC)/III_DemoLista.cpp
	g++ -g -c -o $(OBJ)/III_DemoLista.o	$(SRC)/III_DemoLista.cpp -I$(INCLUDE) \
	-std=c++11

#objetos
$(OBJ)/VectorDinamico_ConstructorCopia.o : \
																			$(SRC)/VectorDinamico_ConstructorCopia.cpp
	g++ -g -c -o $(OBJ)/VectorDinamico_ConstructorCopia.o \
	$(SRC)/VectorDinamico_ConstructorCopia.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1_ConstructorCopia.o : \
																			$(SRC)/Matriz2D_1_ConstructorCopia.cpp
	g++ -g -c -o $(OBJ)/Matriz2D_1_ConstructorCopia.o \
	$(SRC)/Matriz2D_1_ConstructorCopia.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Lista_ConstructorCopia.o : \
																			$(SRC)/Lista_ConstructorCopia.cpp
	g++ -g -c -o $(OBJ)/Lista_ConstructorCopia.o \
	$(SRC)/Lista_ConstructorCopia.cpp -I$(INCLUDE) -std=c++11
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
