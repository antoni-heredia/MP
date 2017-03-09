# Fichero: makefile
# Construye el ejecutable saludo a partir de saludo.cpp

bin/saludo : src/saludo.cpp
	@echo Generando bin/saludo...
	@g++ src/saludo.cpp -o bin/saludo
	@echo ...Generado correctamente
