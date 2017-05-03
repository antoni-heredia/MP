#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2016-2017
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# sesion10.mak
#
# Problemas de la Relación de Problemas IV: Clases (II)
#
#############################################################################


BIN = bin
BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

#................................................
all:  preambulo \
      bibliotecas\
      $(LIB)/libVectorDinamico_Asignacion-Acceso.a \
      $(LIB)/libMatriz2D_1_Asignacion-Acceso.a \
      $(LIB)/libMatriz2D_2_Asignacion-Acceso.a \
      $(LIB)/libLista_Asignacion-Acceso.a \
      fin-bibliotecas \
	  ejecutables \
      $(BIN)/IV_Demo-VectorDinamico_Asignacion-Acceso \
      $(BIN)/IV_Demo-Matriz2D_1_Asignacion-Acceso  \
      $(BIN)/IV_Demo-Matriz2D_2_Asignacion-Acceso \
      $(BIN)/IV_Demo-Lista_Asignacion-Acceso \
	  fin-ejecutables

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relacion de Problemas IV
	@echo Sesion 10 de Practicas
	@echo
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo B
	@echo CURSO 2016-2017
	@echo
	@echo "("c")" Francisco Jose CORTIJO BON
	@echo Depto. Ciencias de la Computacion e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo
#................................................

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados
	@echo 	

bibliotecas:
	@echo Creando bibliotecas...

fin-bibliotecas:
	@echo ...Creadas
	@echo 	
#................................................
# EJECUTABLES

$(BIN)/IV_Demo-VectorDinamico_Asignacion-Acceso : \
           $(OBJ)/IV_Demo-VectorDinamico_Asignacion-Acceso.o \
           $(LIB)/libVectorDinamico_Asignacion-Acceso.a
	g++ -o $(BIN)/IV_Demo-VectorDinamico_Asignacion-Acceso \
           $(OBJ)/IV_Demo-VectorDinamico_Asignacion-Acceso.o \
		   -L$(LIB) -lVectorDinamico_Asignacion-Acceso

$(BIN)/IV_Demo-Matriz2D_1_Asignacion-Acceso : \
           $(OBJ)/IV_Demo-Matriz2D_1_Asignacion-Acceso.o \
           $(LIB)/libMatriz2D_1_Asignacion-Acceso.a 
	g++ -o $(BIN)/IV_Demo-Matriz2D_1_Asignacion-Acceso \
           $(OBJ)/IV_Demo-Matriz2D_1_Asignacion-Acceso.o \
           -L$(LIB) -lMatriz2D_1_Asignacion-Acceso 

$(BIN)/IV_Demo-Matriz2D_2_Asignacion-Acceso : \
           $(OBJ)/IV_Demo-Matriz2D_2_Asignacion-Acceso.o \
           $(LIB)/libMatriz2D_2_Asignacion-Acceso.a 
	g++ -o $(BIN)/IV_Demo-Matriz2D_2_Asignacion-Acceso \
           $(OBJ)/IV_Demo-Matriz2D_2_Asignacion-Acceso.o \
           -L$(LIB) -lMatriz2D_2_Asignacion-Acceso 

$(BIN)/IV_Demo-Lista_Asignacion-Acceso : \
           $(OBJ)/IV_Demo-Lista_Asignacion-Acceso.o \
           $(LIB)/libLista_Asignacion-Acceso.a
	g++ -o $(BIN)/IV_Demo-Lista_Asignacion-Acceso \
           $(OBJ)/IV_Demo-Lista_Asignacion-Acceso.o \
           -L$(LIB) -lLista_Asignacion-Acceso 


#................................................
# OBJETOS

$(OBJ)/IV_Demo-VectorDinamico_Asignacion-Acceso.o : \
              $(SRC)/IV_Demo-VectorDinamico_Asignacion-Acceso.cpp \
              $(INCLUDE)/VectorDinamico_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/IV_Demo-VectorDinamico_Asignacion-Acceso.o \
              $(SRC)/IV_Demo-VectorDinamico_Asignacion-Acceso.cpp \
              -I$(INCLUDE) -std=c++11

$(OBJ)/IV_Demo-Matriz2D_1_Asignacion-Acceso.o : \
              $(SRC)/IV_Demo-Matriz2D_1_Asignacion-Acceso.cpp \
              $(INCLUDE)/Matriz2D_1_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/IV_Demo-Matriz2D_1_Asignacion-Acceso.o \
              $(SRC)/IV_Demo-Matriz2D_1_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(OBJ)/IV_Demo-Matriz2D_2_Asignacion-Acceso.o : \
              $(SRC)/IV_Demo-Matriz2D_2_Asignacion-Acceso.cpp \
              $(INCLUDE)/Matriz2D_2_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/IV_Demo-Matriz2D_2_Asignacion-Acceso.o \
              $(SRC)/IV_Demo-Matriz2D_2_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(OBJ)/IV_Demo-Lista_Asignacion-Acceso.o : \
              $(SRC)/IV_Demo-Lista_Asignacion-Acceso.cpp \
              $(INCLUDE)/Lista_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/IV_Demo-Lista_Asignacion-Acceso.o \
              $(SRC)/IV_Demo-Lista_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

$(OBJ)/VectorDinamico_Asignacion-Acceso.o : \
              $(SRC)/VectorDinamico_Asignacion-Acceso.cpp \
              $(INCLUDE)/VectorDinamico_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/VectorDinamico_Asignacion-Acceso.o \
              $(SRC)/VectorDinamico_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(LIB)/libVectorDinamico_Asignacion-Acceso.a : \
            $(OBJ)/VectorDinamico_Asignacion-Acceso.o 
	ar -rvs $(LIB)/libVectorDinamico_Asignacion-Acceso.a \
            $(OBJ)/VectorDinamico_Asignacion-Acceso.o


$(OBJ)/Matriz2D_1_Asignacion-Acceso.o : \
              $(SRC)/Matriz2D_1_Asignacion-Acceso.cpp \
              $(INCLUDE)/Matriz2D_1_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/Matriz2D_1_Asignacion-Acceso.o \
              $(SRC)/Matriz2D_1_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(LIB)/libMatriz2D_1_Asignacion-Acceso.a : \
            $(OBJ)/Matriz2D_1_Asignacion-Acceso.o 
	ar -rvs $(LIB)/libMatriz2D_1_Asignacion-Acceso.a \
            $(OBJ)/Matriz2D_1_Asignacion-Acceso.o 


$(OBJ)/Matriz2D_2_Asignacion-Acceso.o : \
              $(SRC)/Matriz2D_2_Asignacion-Acceso.cpp \
              $(INCLUDE)/Matriz2D_2_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/Matriz2D_2_Asignacion-Acceso.o \
              $(SRC)/Matriz2D_2_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(LIB)/libMatriz2D_2_Asignacion-Acceso.a : \
            $(OBJ)/Matriz2D_2_Asignacion-Acceso.o 
	ar -rvs $(LIB)/libMatriz2D_2_Asignacion-Acceso.a \
            $(OBJ)/Matriz2D_2_Asignacion-Acceso.o 


$(OBJ)/Lista_Asignacion-Acceso.o : \
              $(SRC)/Lista_Asignacion-Acceso.cpp \
              $(INCLUDE)/Lista_Asignacion-Acceso.h
	g++ -c -o $(OBJ)/Lista_Asignacion-Acceso.o  \
              $(SRC)/Lista_Asignacion-Acceso.cpp \
             -I$(INCLUDE) -std=c++11

$(LIB)/libLista_Asignacion-Acceso.a : $(OBJ)/Lista_Asignacion-Acceso.o 
	ar -rvs $(LIB)/libLista_Asignacion-Acceso.a \
            $(OBJ)/Lista_Asignacion-Acceso.o 

#................................................
# LIMPEZA

clean: clean-objs clean-objetos-bibliotecas clean-bibliotecas

clean-objs: 
	@echo Borrando objetos...

	-rm $(OBJ)/IV_Demo-VectorDinamico_Asignacion-Acceso.o
	-rm $(OBJ)/IV_Demo-Matriz2D_1_Asignacion-Acceso.o
	-rm $(OBJ)/IV_Demo-Matriz2D_2_Asignacion-Acceso.o
	-rm $(OBJ)/IV_Demo-Lista_Asignacion-Acceso.o

	@echo ...Borrados
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando modulos objeto usados en bibliotecas...

	-rm $(OBJ)/VectorDinamico_Asignacion-Acceso.o
	-rm $(OBJ)/Matriz2D_1_Asignacion-Acceso.o
	-rm $(OBJ)/Matriz2D_2_Asignacion-Acceso.o
	-rm $(OBJ)/Lista_Asignacion-Acceso.o

	@echo ...Borrados
	@echo 

clean-bibliotecas: 
	@echo Borrando bibliotecas...

	-rm $(LIB)/libVectorDinamico_Asignacion-Acceso.a
	-rm $(LIB)/libMatriz2D_1_Asignacion-Acceso.a
	-rm $(LIB)/libMatriz2D_2_Asignacion-Acceso.a
	-rm $(LIB)/libLista_Asignacion-Acceso.a

	@echo ...Borradas
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/IV_Demo-VectorDinamico_Asignacion-Acceso
	-rm $(BIN)/IV_Demo-Matriz2D_1_Asignacion-Acceso
	-rm $(BIN)/IV_Demo-Matriz2D_2_Asignacion-Acceso
	-rm $(BIN)/IV_Demo-Lista_Asignacion-Acceso

	@echo ...Borrados
	@echo 	

clean-bak : 
	@echo Borrando copias antiguas...

	-rm $(SRC)/Demo-VectorDinamico_Asignacion-Acceso.cpp~
	-rm $(SRC)/Demo-Matriz2D_1_Asignacion-Acceso.cpp~
	-rm $(SRC)/Demo-Matriz2D_2_Asignacion-Acceso.cpp~
	-rm $(SRC)/Demo-Lista_Asignacion-Acceso.cpp~
	-rm $(SRC)/VectorDinamico_Asignacion-Acceso.cpp~
	-rm $(SRC)/Matriz2D_1_Asignacion-Acceso.cpp~
	-rm $(SRC)/Matriz2D_2_Asignacion-Acceso.cpp~
	-rm $(SRC)/Lista_Asignacion-Acceso.cpp~
	-rm $(INCLUDE)/VectorDinamico_Asignacion-Acceso.h~
	-rm $(INCLUDE)/Matriz2D_1_Asignacion-Acceso.h~
	-rm $(INCLUDE)/Matriz2D_2_Asignacion-Acceso.h~
	-rm $(INCLUDE)/Lista_Asignacion-Acceso.h~

	@echo ...Borrados
	@echo 	

mr.proper:  clean clean-bins clean-bak

