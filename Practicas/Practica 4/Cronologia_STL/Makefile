SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -O2 -std=c++11
CPPFLAGS = -Wall -I$(INC) -c


exe = pruebacronologia union_cronologia filtrado_palabra 

all: $(exe) documentacion

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
#$(BIN)/pruebacronologia:

# Colección de objetos a compilar


# COMPILACION (asi de chulo)
$(exe):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cpp $(SRC)/Cronologia.cpp $(SRC)/EventoHistorico.cpp -I$(INC) $(LDFLAGS)


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
