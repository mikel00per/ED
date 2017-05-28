SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
LDXFLAGS = -std=c++11


all: $(BIN)/pruebacronologia documentacion

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/pruebacronologia: $(LIB)/libcrono.a $(OBJ)/pruebacronologia.o
	$(CXX) $(OBJ)/pruebacronologia.o $(OBJ)/listaeventos.o $(OBJ)/cronologia.o -o $(BIN)/pruebacronologia

$(OBJ)/listaeventos.o: $(SRC)/listaeventos.cpp $(INC)/listaeventos.h
	$(CXX) $(CPPFLAGS) $(SRC)/listaeventos.cpp -o $(OBJ)/listaeventos.o

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CXX) $(CPPFLAGS) $(SRC)/cronologia.cpp -o $(OBJ)/cronologia.o

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebacronologia.cpp  -o $(OBJ)/pruebacronologia.o

$(LIB)/libcrono.a: $(OBJ)/cronologia.o $(OBJ)/listaeventos.o
	ar -rsv $(LIB)/libcrono.a: $(OBJ)/cronologia.o $(OBJ)/listaeventos.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ 

mrproper : clean
	-rm -r $(BIN)/* doc/html doc/latex doc/rtf
