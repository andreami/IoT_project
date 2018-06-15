/*#include "SerialLib.h"

SerialLib::SerialLib()
{
    serial.setPort("/dev/ttyACM0");
    serial.setBaudrate(9600);
    t.simpleTimeout(2000);
    serial.setTimeout(t);
}

SerialLib::~SerialLib()
{
    serial.close();
}

bool SerialLib::serialIsOpen()
{
    return serial.isOpen();
}

void SerialLib::checkConnection()
{
    if(!serial.isOpen()){
        try {
            serial.open();
        }
        catch(IOException) {
            serial.close();
        }
        catch(SerialException){
            serial.close();
        }
	}
}
*/
