 # Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src

all : $(BIN)/II-RedimensionaVectorDinamico \
			$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
			$(BIN)/II-VectorDinamicoCadenas

#Apartir de aqui se generan los ejecutables

$(BIN)/II-RedimensionaVectorDinamico : $(OBJ)/II-RedimensionaVectorDinamico.o \
																			 $(OBJ)/vector_dinamico.o


	@echo Generando $(BIN)/II-RedimensionaVectorDinamico...
	@g++ -std=c++11 -o $(BIN)/II-RedimensionaVectorDinamico \
										 $(OBJ)/II-RedimensionaVectorDinamico.o \
										 $(OBJ)/vector_dinamico.o
	@echo ...Generado correctamente



$(BIN)/II-FactoresPrimos_VectorDinamicoPrimos : \
																$(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o\
																$(OBJ)/vector_dinamico.o
	@echo Generando $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos...
	@g++ -std=c++11 -o $(BIN)/II-FactoresPrimos_VectorDinamicoPrimos \
										 $(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o \
										 $(OBJ)/vector_dinamico.o
	@echo ...Generado correctamente

$(BIN)/II-VectorDinamicoCadenas : $(OBJ)/II-VectorDinamicoCadenas.o \
															$(OBJ)/vector_dinamico.o


	@echo Generando $(BIN)/II-VectorDinamicoCadenas...
	@g++ -std=c++11 -o $(BIN)/II-VectorDinamicoCadenas \
										 $(OBJ)/II-VectorDinamicoCadenas.o \
										 $(OBJ)/vector_dinamico.o
	@echo ...Generado correctamente

#Apartir de aqui se generan los objetos
$(OBJ)/II-RedimensionaVectorDinamico.o : $(SRC)/II-RedimensionaVectorDinamico.cpp

	@echo Generando $(OBJ)/II-RedimensionaVectorDinamico.o...
	@g++ -std=c++11 -c -o $(OBJ)/II-RedimensionaVectorDinamico.o \
												$(SRC)/II-RedimensionaVectorDinamico.cpp -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o : \
															$(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp
	@echo Generando $(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o...
	@g++ -std=c++11 -c -o $(OBJ)/II-FactoresPrimos_VectorDinamicoPrimos.o \
												$(SRC)/II-FactoresPrimos_VectorDinamicoPrimos.cpp \
											 -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/II-VectorDinamicoCadenas.o : \
															$(SRC)/II-VectorDinamicoCadenas.cpp
	@echo Generando $(OBJ)/II-VectorDinamicoCadenas.o...
	@g++ -std=c++11 -c -o $(OBJ)/II-VectorDinamicoCadenas.o \
												$(SRC)/II-VectorDinamicoCadenas.cpp \
											 -I$(INCLUDE)
	@echo ...Generado correctamente

$(OBJ)/vector_dinamico.o : $(SRC)/vector_dinamico.cpp
	@echo Generando $(OBJ)/vector_dinamico.o...
	@g++ -std=c++11 -c -o $(OBJ)/vector_dinamico.o \
												$(SRC)/vector_dinamico.cpp \
											 -I$(INCLUDE)
	@echo ...Generado correctamente
	
clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o

mr-proper : clean
	@echo Borrando ejecutables
	@-rm $(BIN)/*
