# Fichero: makefile
HOME = .


BIN=$(HOME)/bin
OBJ=$(HOME)/obj
INCLUDE=$(HOME)/include
LIB=$(HOME)/lib
SRC=$(HOME)/src


all : $(BIN)/CopiaTodo $(BIN)/CopiaExceptoVocales $(BIN)/CuentaCaracteres \
      $(BIN)/CuentaLineasNoVacias  $(BIN)/MuestraLineasNoVacias \
      $(BIN)/ComprimeLineas $(BIN)/CopiaLineasSinAlmohadilla \
      $(BIN)/CopiaEnteros $(BIN)/CopiaEnterosSeparados $(BIN)/SumaEnteros \
      $(BIN)/CuentaCaracteresConcretos

#ejecutables
$(BIN)/CopiaTodo : $(OBJ)/CopiaTodo.o 
	g++ -g -o $(BIN)/CopiaTodo $(OBJ)/CopiaTodo.o -std=c++11

$(BIN)/CopiaExceptoVocales : $(OBJ)/CopiaExceptoVocales.o 
	g++ -g -o $(BIN)/CopiaExceptoVocales $(OBJ)/CopiaExceptoVocales.o -std=c++11

$(BIN)/CuentaCaracteres : $(OBJ)/CuentaCaracteres.o 
	g++ -g -o $(BIN)/CuentaCaracteres $(OBJ)/CuentaCaracteres.o -std=c++11
       
$(BIN)/CuentaLineasNoVacias : $(OBJ)/CuentaLineasNoVacias.o 
	g++ -g -o $(BIN)/CuentaLineasNoVacias $(OBJ)/CuentaLineasNoVacias.o \
	-std=c++11

$(BIN)/MuestraLineasNoVacias : $(OBJ)/MuestraLineasNoVacias.o 
	g++ -g -o $(BIN)/MuestraLineasNoVacias $(OBJ)/MuestraLineasNoVacias.o \
	-std=c++11

$(BIN)/ComprimeLineas : $(OBJ)/ComprimeLineas.o 
	g++ -g -o $(BIN)/ComprimeLineas $(OBJ)/ComprimeLineas.o \
	-std=c++11

$(BIN)/CopiaLineasSinAlmohadilla : $(OBJ)/CopiaLineasSinAlmohadilla.o 
	g++ -g -o $(BIN)/CopiaLineasSinAlmohadilla \
    $(OBJ)/CopiaLineasSinAlmohadilla.o 	-std=c++11

$(BIN)/CopiaEnteros : $(OBJ)/CopiaEnteros.o 
	g++ -g -o $(BIN)/CopiaEnteros $(OBJ)/CopiaEnteros.o 	-std=c++11

$(BIN)/CopiaEnterosSeparados : $(OBJ)/CopiaEnterosSeparados.o 
	g++ -g -o $(BIN)/CopiaEnterosSeparados $(OBJ)/CopiaEnterosSeparados.o \
    -std=c++11

$(BIN)/SumaEnteros : $(OBJ)/SumaEnteros.o 
	g++ -g -o $(BIN)/SumaEnteros $(OBJ)/SumaEnteros.o -std=c++11

$(BIN)/CuentaCaracteresConcretos : $(OBJ)/CuentaCaracteresConcretos.o 
	g++ -g -o $(BIN)/CuentaCaracteresConcretos \
    $(OBJ)/CuentaCaracteresConcretos.o -std=c++11
#objetos del main
$(OBJ)/CopiaTodo.o : $(SRC)/CopiaTodo.cpp
	g++ -g -c -o $(OBJ)/CopiaTodo.o $(SRC)/CopiaTodo.cpp -std=c++11

$(OBJ)/CopiaExceptoVocales.o : $(SRC)/CopiaExceptoVocales.cpp
	g++ -g -c -o $(OBJ)/CopiaExceptoVocales.o $(SRC)/CopiaExceptoVocales.cpp \
    -std=c++11

$(OBJ)/CuentaCaracteres.o : $(SRC)/CuentaCaracteres.cpp
	g++ -g -c -o $(OBJ)/CuentaCaracteres.o $(SRC)/CuentaCaracteres.cpp \
	-std=c++11

$(OBJ)/CuentaLineasNoVacias.o : $(SRC)/CuentaLineasNoVacias.cpp
	g++ -g -c -o $(OBJ)/CuentaLineasNoVacias.o $(SRC)/CuentaLineasNoVacias.cpp \
	-std=c++11

$(OBJ)/MuestraLineasNoVacias.o : $(SRC)/MuestraLineasNoVacias.cpp
	g++ -g -c -o $(OBJ)/MuestraLineasNoVacias.o $(SRC)/MuestraLineasNoVacias.cpp \
	-std=c++11
  
$(OBJ)/ComprimeLineas.o : $(SRC)/ComprimeLineas.cpp
	g++ -g -c -o $(OBJ)/ComprimeLineas.o $(SRC)/ComprimeLineas.cpp \
	-std=c++11

$(OBJ)/CopiaLineasSinAlmohadilla.o : $(SRC)/CopiaLineasSinAlmohadilla.cpp
	g++ -g -c -o $(OBJ)/CopiaLineasSinAlmohadilla.o \
    $(SRC)/CopiaLineasSinAlmohadilla.cpp -std=c++11
            
$(OBJ)/CopiaEnteros.o : $(SRC)/CopiaEnteros.cpp
	g++ -g -c -o $(OBJ)/CopiaEnteros.o $(SRC)/CopiaEnteros.cpp -std=c++11
            
$(OBJ)/CopiaEnterosSeparados.o : $(SRC)/CopiaEnterosSeparados.cpp
	g++ -g -c -o $(OBJ)/CopiaEnterosSeparados.o \
    $(SRC)/CopiaEnterosSeparados.cpp -std=c++11

$(OBJ)/SumaEnteros.o : $(SRC)/SumaEnteros.cpp
	g++ -g -c -o $(OBJ)/SumaEnteros.o $(SRC)/SumaEnteros.cpp -std=c++11   

$(OBJ)/CuentaCaracteresConcretos.o : $(SRC)/CuentaCaracteresConcretos.cpp
	g++ -g -c -o $(OBJ)/CuentaCaracteresConcretos.o \
    $(SRC)/CuentaCaracteresConcretos.cpp -std=c++11        
cleanlib :
	@echo Borrando librerias
	@-rm $(LIB)/*.a

clean :
	@echo Borrando ficheros objetos
	@-rm $(OBJ)/*.o
mr-proper : clean cleanlib

	@echo Borrando ejecutables
	@-rm $(BIN)/*
