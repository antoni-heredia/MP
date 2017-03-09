# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.o
# Construrye el objeto saludo.o a partir de saludo.cpp

bin/saludo : obj/saludo.o
	@echo Generando bin/saludo...
	@g++ -o bin/saludo obj/saludo.o 
	@echo ...Generado correctamente

obj/saludo.o : src/saludo.cpp
	@echo Generando obj/saludo.o...
	@g++ -c -o obj/saludo.o src/saludo.cpp	
	@echo ...Generado correctamente
