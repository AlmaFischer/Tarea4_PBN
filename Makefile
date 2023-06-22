
MODULE = parabolico
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self -fPIC
INCLUDE = -I/usr/include/python3.9
LIBS = -lpython3.9
OUTPUT = _$(MODULE).so

$(OUTPUT): parabolico_wrap.cxx parabolico.o
	$(CXX) parabolico_wrap.cxx -c -o parabolico_wrap.o -fPIC $(INCLUDE)
	$(CXX) $(CXXFLAGS) -shared parabolico_wrap.o parabolico.o -o $(OUTPUT) $(LIBS)

parabolico_wrap.cxx: parabolico.i parabolico.h
	swig -c++ -python -o parabolico_wrap.cxx parabolico.i

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -fPIC -c -o $@ $<

clean:
	rm -f $(OUTPUT) *.cxx parabolico.py *.o