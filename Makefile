
MODULE = parabolico
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self -fPIC
INCLUDE = -I/usr/include/python3.9
LIBS = -lpython3.9
SOURCES = parabolico.cpp parabolico_wrap.cpp
OUTPUT = _$(MODULE).so

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBS) -shared -o $@ $^

parabolico_wrap.cpp: parabolico.i
	swig -c++ -python -o $@ $<

clean:
	rm -f $(OUTPUT) parabolico_wrap.cpp parabolico.py