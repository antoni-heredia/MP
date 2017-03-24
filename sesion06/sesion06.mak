 # Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/II-RedimensionaVectorDinamico \
			$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos


$(BIN)/II-RedimensionaVectorDinamico : $(SRC)/II-RedimensionaVectorDinamico.cpp
	@echo Generando $(BIN)/II-RedimensionaVectorDinamico...
	@g++ -std=c++11 -o $(BIN)/II-RedimensionaVectorDinamico \
										 $(SRC)/II-RedimensionaVectorDinamico.cpp
	@echo ...Generado correctamente



$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos : \
$(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp
	@echo Generando $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos...
	@g++ -std=c++11 -o $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
										 $(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp
	@echo ...Generado correctamente

clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
