# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.o
# Construrye el objeto saludo.o a partir de saludo.cpp
HOME = /home/antonioheredia/Escritorio/Home/MP

BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/saludo

$(BIN)/saludo : $(OBJ)/saludo.o
	@echo Generando $(BIN)/saludo...
	@g++ -o $(BIN)/saludo $(OBJ)/saludo.o
	@echo ...Generado correctamente

$(OBJ)/saludo.o : $(SRC)/saludo.cpp
	@echo Generando $(OBJ)/saludo.o...
	@g++ -c -o $(OBJ)/saludo.o $(SRC)/saludo.cpp
	@echo ...Generado correctamente

# Esta regla especifia un destino sin lista de dependencia
clean :
	@echo Borrando ficheros objetos
# Con el guion ejecuta la orden pero si da error sigue trabjando
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
