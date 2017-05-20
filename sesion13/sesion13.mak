# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src


all : $(BIN)/NumeraLineas $(BIN)/SumasPorGrupos $(BIN)/VI_Demo-Lista-ES \
      $(BIN)/MensajesOcultos $(BIN)/MensajesOcultos-2

#ejecutables

$(BIN)/NumeraLineas : $(OBJ)/NumeraLineas.o
	g++ -g -o $(BIN)/NumeraLineas $(OBJ)/NumeraLineas.o -std=c++11

$(BIN)/SumasPorGrupos : $(OBJ)/SumasPorGrupos.o
	g++ -g -o $(BIN)/SumasPorGrupos $(OBJ)/SumasPorGrupos.o -std=c++11

$(BIN)/VI_Demo-Lista-ES : $(OBJ)/VI_Demo-Lista-ES.o $(LIB)/libLista.a
	g++ -g -o $(BIN)/VI_Demo-Lista-ES $(OBJ)/VI_Demo-Lista-ES.o \
	-lLista -L$(LIB) -std=c++11

$(BIN)/MensajesOcultos : $(OBJ)/MensajesOcultos.o
	g++ -g -o $(BIN)/MensajesOcultos $(OBJ)/MensajesOcultos.o -std=c++11

$(BIN)/MensajesOcultos-2 : $(OBJ)/MensajesOcultos-2.o
	g++ -g -o $(BIN)/MensajesOcultos-2 $(OBJ)/MensajesOcultos-2.o -std=c++11

#librerias

$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o

#objetos del main
$(OBJ)/VI_Demo-Lista-ES.o : $(SRC)/VI_Demo-Lista-ES.cpp \
							 $(INCLUDE)/Lista.h
	g++ -g -c -o $(OBJ)/VI_Demo-Lista-ES.o $(SRC)/VI_Demo-Lista-ES.cpp \
	-I$(INCLUDE) -std=c++11

$(OBJ)/NumeraLineas.o : $(SRC)/NumeraLineas.cpp
	g++ -g -c -o $(OBJ)/NumeraLineas.o $(SRC)/NumeraLineas.cpp -std=c++11

$(OBJ)/SumasPorGrupos.o : $(SRC)/SumasPorGrupos.cpp
	g++ -g -c -o $(OBJ)/SumasPorGrupos.o $(SRC)/SumasPorGrupos.cpp -std=c++11

$(OBJ)/MensajesOcultos.o : $(SRC)/MensajesOcultos.cpp
	g++ -g -c -o $(OBJ)/MensajesOcultos.o $(SRC)/MensajesOcultos.cpp -std=c++11

$(OBJ)/MensajesOcultos-2.o : $(SRC)/MensajesOcultos-2.cpp
	g++ -g -c -o $(OBJ)/MensajesOcultos-2.o $(SRC)/MensajesOcultos-2.cpp \
    -std=c++11

#objetos


$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
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
