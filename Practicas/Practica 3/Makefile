SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(SRC) -I$(INC) -c

all: $(BIN)/usopilas_max

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) $(OBJ)/usopilas_max.o -o $(BIN)/usopilas_max

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o



# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
