import serial
import serial.tools.list_ports as ports

class SerialWrapper:
    BAUDRATE = 9600
    BUFFER = 4 #TODO modify according to the project

    def __init__(self):
        self.port = self.select_port()
        self.connection = serial.Serial(port.device, BAUDRATE)
        self.connection.open()


    def read(self):
        return self.connection.read(BUFFER)


    def write(self, data):
        self.conneciton.write(data)
        self.connection.flush()


    # Returns the port where Arduino is connected
    # raises an IOException if couldn't find it. 
    def select_port(self):
        for port in ports.comports():
            if "Arduino" in port.description:
                return port
        raise IOException("No Arduino device detected.")


    # closes connection if open
    def close(self):
        if self.connection.is_open : self.connection.close()
        
