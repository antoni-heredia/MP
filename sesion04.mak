# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.o
# Construrye el objeto saludo.o a partir de saludo.cpp
HOME = /home/antonio/git/MP

BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/I_PosicionPrimerBlanco $(BIN)/I_SaltaPrimeraPalabra $(BIN)/I_DemoCadenasClasicas

$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	@echo Generando $(BIN)/I_PosicionPrimerBlanco...
	@g++ -o $(BIN)/I_PosicionPrimerBlanco $(SRC)/I_PosicionPrimerBlanco.cpp
	@echo ...Generado correctamente

$(BIN)/I_SaltaPrimeraPalabra : $(SRC)/I_SaltaPrimeraPalabra.cpp
	@echo Generando $(BIN)/I_SaltaPrimeraPalabra...
	@g++ -o $(BIN)/I_SaltaPrimeraPalabra $(SRC)/I_SaltaPrimeraPalabra.cpp
	@echo ...Generado correctamente

$(BIN)/I_DemoCadenasClasicas : $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	@echo Generando $(BIN)/I_DemoCadenasClasicas...
	@g++ -o $(BIN)/I_DemoCadenasClasicas $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	@echo ...Generado correctamente

$(OBJ)/I_DemoCadenasClasicas.o : $(SRC)/I_DemoCadenasClasicas.cpp $(INCLUDE)/adicion.h
	@echo Generando $(OBJ)/I_DemoCadenasClasicas.o...
	@g++ -c -o $(OBJ)/I_DemoCadenasClasicas.o $(SRC)/I_DemoCadenasClasicas.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/adicion.h
	@echo Generando $(OBJ)/MiCadenaClasica.o...
	@g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE)
	@echo ...Generado correctamente
# Esta regla especifia un destino sin lista de dependencia
clean :
	@echo Borrando ficheros objetos
# Con el guion ejecuta la orden pero si da error sigue trabjando
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
