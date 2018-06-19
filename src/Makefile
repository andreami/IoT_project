OBJ = main.cpp EventsManager.cpp ButtonsPack.cpp Button.cpp IconsPack.cpp Icon.cpp TextsPack.cpp HTTP.cpp 
SFML =  -L/usr/lib/x86_64-linux-gnu/lib -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
SERIAL = -L/tmp/usr/local/lib/ -lserial -I/tmp/usr/local/include/serial
CXXFLAGS=-Wall  

IOT: $(OBJ)
	g++ -o IOT $(OBJ) $(SFML) $(SERIAL)

-include dependencies

.PHONY: depend clean cleanall

debug:
	g++ -o IOT $(OBJ) $(SFML) $(SERIAL) -D DEBUG_MODE
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o
cleanall:
	rm IOT -f *.o
