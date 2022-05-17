import ctypes

mylib = ctypes.CDLL('./MyLib.dll')

mylib.create_system.argtypes = [ctypes.c_void_p]
mylib.create_system.restype = ctypes.c_void_p

mylib.print_AllStations.argtypes = [ctypes.c_void_p]
mylib.print_AllStations.restype = ctypes.c_int

mylib.print_station.argtypes = [ctypes.c_int, ctypes.c_void_p]
mylib.print_station.restype = ctypes.c_int

mylib.print_system.argtypes = [ctypes.c_void_p]
mylib.print_system.restype = ctypes.c_int

end='\n'
print(" Hello, user! You can use my tram system! ")

while True:
    print(" Choose one of this actions:", end, "   1.Read tram system from file", end,"   2.Print all stations", end, "   3.Print station info", end, "   4.Print full tram system", end, "   5.Exit")
    action = int(input())
    if action == 1:
        print("Input name of file with .txt: ")
        filename = ctypes.c_char_p(input().encode('utf-8'))
        SYSTEM_TR = mylib.create_system(filename)
        print("Done!")
        key = 1;
    elif action == 2:
        mylib.print_AllStations(SYSTEM_TR)
    elif action == 3:
        try:
            id = int(input("Input station id: "))
            mylib.print_station(id, SYSTEM_TR)
        except:
            print("You entered not an integer")
    elif action == 4:
        mylib.print_system(SYSTEM_TR)
    elif action == 5:
        print("Goodbye! :)")
        break
    else:
        print("Incorrect Action!!!")

