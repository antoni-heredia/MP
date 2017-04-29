# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src


all : $(BIN)/IV_DemoVectorDinamico_Asignacion-Acceso \
			$(BIN)/IV_DemoMatriz2D_1_Asignacion-Acceso \
			$(BIN)/IV_DemoLista_Asignacion-Acceso

#ejecutables
$(BIN)/IV_DemoVectorDinamico_Asignacion-Acceso : \
															$(OBJ)/IV_DemoVectorDinamico_Asignacion-Acceso.o \
															$(LIB)/libVectorDinamico_Asignacion-Acceso.a
	g++ -g -o $(BIN)/IV_DemoVectorDinamico_Asignacion-Acceso \
	$(OBJ)/IV_DemoVectorDinamico_Asignacion-Acceso.o \
	-lVectorDinamico_Asignacion-Acceso -L$(LIB) -std=c++11

$(BIN)/IV_DemoMatriz2D_1_Asignacion-Acceso : \
																$(OBJ)/IV_DemoMatriz2D_1_Asignacion-Acceso.o \
																$(LIB)/libMatriz2D_1_Asignacion-Acceso.a
	g++ -g -o $(BIN)/IV_DemoMatriz2D_1_Asignacion-Acceso \
	$(OBJ)/IV_DemoMatriz2D_1_Asignacion-Acceso.o \
	-lMatriz2D_1_Asignacion-Acceso -L$(LIB) -std=c++11

$(BIN)/IV_DemoLista_Asignacion-Acceso : \
																			$(OBJ)/IV_DemoLista_Asignacion-Acceso.o \
																			$(LIB)/libLista_Asignacion-Acceso.a
	g++ -g -o $(BIN)/IV_DemoLista_Asignacion-Acceso \
	$(OBJ)/IV_DemoLista_Asignacion-Acceso.o \
	-lLista_Asignacion-Acceso -L$(LIB) -std=c++11

#librerias
$(LIB)/libVectorDinamico_Asignacion-Acceso.a : \
																			$(OBJ)/VectorDinamico_Asignacion-Acceso.o
	ar -rvs $(LIB)/libVectorDinamico_Asignacion-Acceso.a \
	$(OBJ)/VectorDinamico_Asignacion-Acceso.o

$(LIB)/libMatriz2D_1_Asignacion-Acceso.a : \
																			$(OBJ)/Matriz2D_1_Asignacion-Acceso.o
	ar -rvs $(LIB)/libMatriz2D_1_Asignacion-Acceso.a \
	$(OBJ)/Matriz2D_1_Asignacion-Acceso.o

$(LIB)/libLista_Asignacion-Acceso.a : \
																			$(OBJ)/Lista_Asignacion-Acceso.o
	ar -rvs $(LIB)/libLista_Asignacion-Acceso.a $(OBJ)/Lista_Asignacion-Acceso.o

#objetos del main
$(OBJ)/IV_DemoVectorDinamico_Asignacion-Acceso.o : \
															$(SRC)/IV_DemoVectorDinamico_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/IV_DemoVectorDinamico_Asignacion-Acceso.o \
	$(SRC)/IV_DemoVectorDinamico_Asignacion-Acceso.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/IV_DemoMatriz2D_1_Asignacion-Acceso.o : \
															$(SRC)/IV_DemoMatriz2D_1_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/IV_DemoMatriz2D_1_Asignacion-Acceso.o \
	$(SRC)/IV_DemoMatriz2D_1_Asignacion-Acceso.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/IV_DemoLista_Asignacion-Acceso.o : \
															$(SRC)/IV_DemoLista_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/IV_DemoLista_Asignacion-Acceso.o	\
	$(SRC)/IV_DemoLista_Asignacion-Acceso.cpp -I$(INCLUDE) \
	-std=c++11

#objetos
$(OBJ)/VectorDinamico_Asignacion-Acceso.o : \
																		$(SRC)/VectorDinamico_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/VectorDinamico_Asignacion-Acceso.o \
	$(SRC)/VectorDinamico_Asignacion-Acceso.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1_Asignacion-Acceso.o : \
																			$(SRC)/Matriz2D_1_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/Matriz2D_1_Asignacion-Acceso.o \
	$(SRC)/Matriz2D_1_Asignacion-Acceso.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Lista_Asignacion-Acceso.o : \
																			$(SRC)/Lista_Asignacion-Acceso.cpp
	g++ -g -c -o $(OBJ)/Lista_Asignacion-Acceso.o \
	$(SRC)/Lista_Asignacion-Acceso.cpp -I$(INCLUDE) -std=c++11
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
