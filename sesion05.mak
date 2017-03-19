# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/I_MezclaArrays $(BIN)/I_PosMayor $(BIN)/I_Sucursales_Matriz_Clasica


$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o $(OBJ)/array_numeros.o
	@echo Generando $(BIN)/I_MezclaArrays...
	@g++ -std=c++11 -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o \
										 $(OBJ)/array_numeros.o
	@echo ...Generado correctamente

$(BIN)/I_PosMayor : $(OBJ)/I_PosMayor.o $(OBJ)/array_numeros.o
	@echo Generando $(BIN)/I_PosMayor...
	@g++ -std=c++11 -o $(BIN)/I_PosMayor $(OBJ)/I_PosMayor.o \
										 $(OBJ)/array_numeros.o
	@echo ...Generado correctamente


$(BIN)/I_Sucursales_Matriz_Clasica : $(OBJ)/sucursales.o \
																		 $(OBJ)/I_Sucursales_Matriz_Clasica.o
	@echo Generando $(BIN)/I_Sucursales_Matriz_Clasica...
	@g++ -o $(BIN)/I_Sucursales_Matriz_Clasica $(OBJ)/sucursales.o \
																			$(OBJ)/I_Sucursales_Matriz_Clasica.o
	@echo ...Generado correctamente


$(OBJ)/I_PosMayor.o : $(SRC)/I_PosMayor.cpp
	@echo Generando $(OBJ)/I_PosMayor.o...
	@g++ -std=c++11 -c -o $(OBJ)/I_PosMayor.o $(SRC)/I_PosMayor.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp
	@echo Generando $(OBJ)/I_MezclaArrays.o...
	@g++ -std=c++11 -c -o $(OBJ)/I_MezclaArrays.o \
												$(SRC)/I_MezclaArrays.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/array_numeros.o : $(SRC)/array_numeros.cpp
	@echo Generando $(OBJ)/array_numeros.o...
	@g++ -std=c++11 -c -o  $(OBJ)/array_numeros.o \
												 $(SRC)/array_numeros.cpp -I$(INCLUDE)
	@echo ...Generado correctamente



$(OBJ)/I_Sucursales_Matriz_Clasica.o : $(SRC)/I_Sucursales_Matriz_Clasica.cpp
	@echo Generando $(OBJ)/I_Sucursales_Matriz_Clasica.o...
	@g++ -std=c++11 -c -o  $(OBJ)/I_Sucursales_Matriz_Clasica.o \
												 $(SRC)/I_Sucursales_Matriz_Clasica.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/sucursales.o : $(SRC)/sucursales.cpp
	@echo Generando $(OBJ)/sucursales.o...
	@g++ -std=c++11 -c -o  $(OBJ)/sucursales.o \
												 $(SRC)/sucursales.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

clean :
	@echo Borrando ficheros objetos
	@- rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@- rm $(BIN)/*
