BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
IMG=./imagenes/
LIB=./lib/
OPC=-Wall -g
ZIP=./zip/
PRJ=practicafinal

$(BIN)prueba: $(OBJ)prueba.o $(OBJ)codificar.o $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(LIB)libcodificar.a
	g++ -o $(BIN)prueba $(OBJ)prueba.o $(OBJ)codificar.o $(OBJ)pgm.o $(OBJ)imagen.o $(OBJ)byte.o 
$(OBJ)prueba.o: $(SRC)prueba.cpp $(INC)imagen.h $(INC)codificar.h $(INC)byte.h
	g++ $(OPC) -c $(SRC)prueba.cpp -o $(OBJ)prueba.o -I$(INC)
$(OBJ)codificar.o: $(SRC)codificar.cpp $(INC)codificar.h $(INC)imagen.h 
	g++ $(OPC) -c $(SRC)codificar.cpp -o $(OBJ)codificar.o -I$(INC)
$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)pgm.h $(INC)imagen.h
	g++ $(OPC) -c $(SRC)imagen.cpp -o $(OBJ)imagen.o -I$(INC)
$(OBJ)pgm.o: $(SRC)pgm.cpp $(INC)pgm.h
	g++ $(OPC) -c $(SRC)pgm.cpp -o $(OBJ)pgm.o -I$(INC)
$(OBJ)byte.o: $(SRC)byte.cpp $(INC)byte.h 
	g++ $(OPC) -c $(SRC)byte.cpp -o $(OBJ)byte.o -I$(INC)
$(LIB)libcodificar.a: $(OBJ)codificar.o $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(OBJ)prueba.o
	ar rsv $(LIB)libcodificar.a $(OBJ)codificar.o $(OBJ)pgm.o $(OBJ)imagen.o $(OBJ)byte.o $(OBJ)prueba.o
mrproper:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
zip: install mrproper
	@echo "Empaquetando el proyecto"
	@zip -r $(ZIP)$(PRJ).zip ./ -i *.cpp *.h *makefile 
install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(IMG)
