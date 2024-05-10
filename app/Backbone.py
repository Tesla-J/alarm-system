from SerialWrapper import SerialWrapper as Serial
import ctypes

class Backbone:
    # importing shared library
    flag_lib = ctypes.CDLL('./flag.so')

    def __init__(self):
        self.serial = Serial()


    def assign_flag(self, flag, data):
        fun = flag_lib.assign_data
        fun.args = [ctypes.c_int, ctypes.c_int]
        fun.restype = ctypes.c_int

        return fun(flag, data)


    def remove_flag(self, data):
        fun = flag_lib.remove_flag
        fun.args = [ctypes.c_int]
        fun.restype = ctypes.c_int

        return fun(data)

    
    def read_flag(self, data):
        fun = flag_lib.read_flag
        fun.args = [ctypes.c_int]
        fun.restype = ctypes.c_int

        return fun(data)


    # easily access flag values flags
    def flag_value(self, flag_name):
        return ctypes.c_int.in_dll(flag_lib, flag_name).value

    
    # Returns a tuple containing sensor data
    # The sensor data contains: flag and data
    def get_data(self):
        data = self.serial.read()
        flag = self.read_flag(data)
        data = self.remove_flag(data)

        return (flag, data)


    def send_data(self, flag, data):
        data = self.assign_flag(flag, data)
        self.serial.write(data)
