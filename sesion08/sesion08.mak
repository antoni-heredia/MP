# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src



all : $(BIN)/II_BasicosLista $(BIN)/II_OrdenarLista \
			$(BIN)/II_GestionarListaOrdenada $(BIN)/II_MezclarListasOrdenadas \
			$(BIN)/II_GestionTareas

#ejecutables
$(BIN)/II_BasicosLista : $(OBJ)/II_BasicosLista.o $(LIB)/liblista.a
	g++ -g -o $(BIN)/II_BasicosLista $(OBJ)/II_BasicosLista.o -llista -L$(LIB) \
	-std=c++11

$(BIN)/II_OrdenarLista : $(OBJ)/II_OrdenarLista.o $(LIB)/liblista.a
	g++ -g -o $(BIN)/II_OrdenarLista $(OBJ)/II_OrdenarLista.o -llista -L$(LIB) \
	-std=c++11

$(BIN)/II_GestionarListaOrdenada : $(OBJ)/II_GestionarListaOrdenada.o \
																	 $(LIB)/liblista.a
	g++ -g -o $(BIN)/II_GestionarListaOrdenada $(OBJ)/II_GestionarListaOrdenada.o \
	-llista -L$(LIB) -std=c++11

$(BIN)/II_MezclarListasOrdenadas : $(OBJ)/II_MezclarListasOrdenadas.o \
 																	 $(LIB)/liblista.a
	g++ -g -o $(BIN)/II_MezclarListasOrdenadas $(OBJ)/II_MezclarListasOrdenadas.o\
	 -llista -L$(LIB) -std=c++11

$(BIN)/II_GestionTareas : $(OBJ)/II_GestionTareas.o $(LIB)/liblistatareas.a
	g++ -g -o $(BIN)/II_GestionTareas $(OBJ)/II_GestionTareas.o \
	-llistatareas -L$(LIB) -std=c++11

#librerias
$(LIB)/liblista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/liblista.a $(OBJ)/Lista.o

$(LIB)/liblistatareas.a : $(OBJ)/ListaTareas.o
	ar -rvs $(LIB)/liblistatareas.a $(OBJ)/ListaTareas.o

#objetos
$(OBJ)/II_BasicosLista.o : $(SRC)/II_BasicosLista.cpp
	g++ -g -c -o $(OBJ)/II_BasicosLista.o $(SRC)/II_BasicosLista.cpp -I$(INCLUDE) \
	-std=c++11

$(OBJ)/II_OrdenarLista.o : $(SRC)/II_OrdenarLista.cpp
	g++ -g -c -o $(OBJ)/II_OrdenarLista.o $(SRC)/II_OrdenarLista.cpp -I$(INCLUDE) \
	-std=c++11

$(OBJ)/II_GestionarListaOrdenada.o : $(SRC)/II_GestionarListaOrdenada.cpp
	g++ -g -c -o $(OBJ)/II_GestionarListaOrdenada.o \
	$(SRC)/II_GestionarListaOrdenada.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/II_MezclarListasOrdenadas.o : $(SRC)/II_MezclarListasOrdenadas.cpp
	g++ -g -c -o $(OBJ)/II_MezclarListasOrdenadas.o \
	$(SRC)/II_MezclarListasOrdenadas.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/II_GestionTareas.o : $(SRC)/II_GestionTareas.cpp 
	g++ -g -c -o $(OBJ)/II_GestionTareas.o $(SRC)/II_GestionTareas.cpp  \
	-I$(INCLUDE) -std=c++11

$(OBJ)/Lista.o :  $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
	g++ -g -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/ListaTareas.o :  $(SRC)/ListaTareas.cpp $(INCLUDE)/ListaTareas.h
	g++ -g -c -o $(OBJ)/ListaTareas.o $(SRC)/ListaTareas.cpp \
	-I$(INCLUDE) -std=c++11




clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o
mr-proper : clean

	@echo Borrando ejecutables
	@-rm $(BIN)/*
