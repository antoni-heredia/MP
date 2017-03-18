# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.o
# Construrye el objeto saludo.o a partir de saludo.cpp
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/I_MezclaArrays $(BIN)/I_PosMayor


$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o $(OBJ)/array_numeros.o
	@echo Generando $(BIN)/I_MezclaArrays...
	@g++ -std=c++11 -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o $(OBJ)/array_numeros.o
	@echo ...Generado correctamente

$(BIN)/I_PosMayor : $(OBJ)/I_PosMayor.o $(OBJ)/array_numeros.o
	@echo Generando $(BIN)/I_PosMayor...
	@g++ -std=c++11 -o $(BIN)/I_PosMayor $(OBJ)/I_PosMayor.o $(OBJ)/array_numeros.o
	@echo ...Generado correctamente

$(OBJ)/I_PosMayor.o : $(SRC)/I_PosMayor.cpp
	@echo Generando $(OBJ)/I_PosMayor.o...
	@g++ -std=c++11 -c -o $(OBJ)/I_PosMayor.o $(SRC)/I_PosMayor.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp
	@echo Generando $(OBJ)/I_MezclaArrays.o...
	@g++ -std=c++11 -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/array_numeros.o : $(SRC)/array_numeros.cpp
	@echo Generando $(OBJ)/array_numeros.o...
	@g++ -std=c++11 -c -o  $(OBJ)/array_numeros.o $(SRC)/array_numeros.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

# Esta regla especifia un destino sin lista de dependencia
clean :
	@echo Borrando ficheros objetos
# Con el guion ejecuta la orden pero si da error sigue trabjando
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
