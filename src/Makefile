OBJ = main.o EventsManager.o Button.o ButtonsPack.o Icon.o IconsPack.o TextsPack.o HTTP.o
SFML =  -L/usr/lib/x86_64-linux-gnu/lib -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
SERIAL = -L/tmp/usr/local/lib/ -lserial
CXXFLAGS=-Wall  

IOT: $(OBJ)
	g++ -o IOT $(OBJ) $(SFML) $(SERIAL)

-include dependencies

.PHONY: depend clean cleanall

depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o
cleanall:
	rm IOT -f *.o
