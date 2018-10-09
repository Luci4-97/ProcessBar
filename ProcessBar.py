import ctypes


def Update(percent, log):
    ProcessBar = ctypes.cdll.LoadLibrary('libProcessBar.so')
    b_string = log.encode('utf-8')
    ProcessBar.Update(ctypes.c_float(percent), ctypes.create_string_buffer(b_string))