import ctypes


def Update(percent, log):
    ProcessBar = ctypes.cdll.LoadLibrary('ProcessBar.so')
    string = "test" + str(percent)
    b_string = string.encode('utf-8')
    ProcessBar.Update(ctypes.c_float(percent), ctypes.create_string_buffer(b_string))