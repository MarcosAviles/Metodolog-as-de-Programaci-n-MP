BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
OPC=-Wall -g
ZIP=./zip/
PRJ=practica3

$(BIN)esteganografia: $(OBJ)esteganografia.o $(OBJ)codificar.o $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(LIB)libcodificar.a $(OBJ)testimagen.o $(OBJ)testcodificar.o
	g++ -o $(BIN)esteganografia $(OBJ)esteganografia.o $(OBJ)codificar.o $(OBJ)pgm.o $(OBJ)imagen.o $(OBJ)byte.o 
	g++ -o $(BIN)testimagen $(OBJ)testimagen.o $(OBJ)pgm.o $(OBJ)imagen.o 
	g++ -o $(BIN)testcodificar $(OBJ)testcodificar.o $(OBJ)pgm.o $(OBJ)imagen.o $(OBJ)codificar.o $(OBJ)byte.o
$(OBJ)testimagen.o: $(SRC)testimagen.cpp $(INC)imagen.h 
	g++ $(OPC) -c $(SRC)testimagen.cpp -o $(OBJ)testimagen.o -I$(INC)
$(OBJ)testcodificar.o: $(SRC)testcodificar.cpp $(INC)imagen.h $(INC)codificar.h $(INC)byte.h
	g++ $(OPC) -c $(SRC)testcodificar.cpp -o $(OBJ)testcodificar.o -I$(INC)
$(OBJ)esteganografia.o: $(SRC)esteganografia.cpp $(INC)imagen.h $(INC)codificar.h $(INC)byte.h
	g++ $(OPC) -c $(SRC)esteganografia.cpp -o $(OBJ)esteganografia.o -I$(INC)
$(OBJ)codificar.o: $(SRC)codificar.cpp $(INC)codificar.h $(INC)imagen.h 
	g++ $(OPC) -c $(SRC)codificar.cpp -o $(OBJ)codificar.o -I$(INC)
$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)pgm.h $(INC)imagen.h
	g++ $(OPC) -c $(SRC)imagen.cpp -o $(OBJ)imagen.o -I$(INC)
$(OBJ)pgm.o: $(SRC)pgm.cpp $(INC)pgm.h
	g++ $(OPC) -c $(SRC)pgm.cpp -o $(OBJ)pgm.o -I$(INC)
$(OBJ)byte.o: $(SRC)byte.cpp $(INC)byte.h 
	g++ $(OPC) -c $(SRC)byte.cpp -o $(OBJ)byte.o -I$(INC)
$(LIB)libcodificar.a: $(OBJ)codificar.o $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(OBJ)esteganografia.o
	ar rsv $(LIB)libcodificar.a $(OBJ)codificar.o $(OBJ)pgm.o $(OBJ)imagen.o $(OBJ)byte.o $(OBJ)esteganografia.o
mrproper:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
zip: install mrproper
	@echo "Empaquetando el proyecto"
	@zip -r $(ZIP)$(PRJ).zip ./ -i *.cpp *.h *makefile *.pdf
install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(ZIP)
