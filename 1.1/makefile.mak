#--------------------------------------------
# makefile zur Erzeugung der .exe zur Kaltluft
#--------------------------------------------
.PHONY: all clean

# Definition der Variablen
CXX := g++
CXXFLAGS := -std=c++11 -c -Wall -IS:\Datenban\Wetter\Programme\Kaltluft\1.1\lib\\
LDFLAGS := -g
HEADERS := $(wildcard S\:\Datenban\Wetter\Programme\Kaltluft\1.1\lib\*.h)
objs := main.o file_handling.o

all: kaltluft_v1-1.exe

# Ziel 1
kaltluft_v1-1.exe: $(objs)
	$(CXX) $(LDFLAGS) -o $@ $^

# Ziel 2
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $<

# Ziel 3
file_handling.o: file_handling.cpp 
	$(CXX) $(CXXFLAGS) $<


# Alle *.o Dateien löschen
clean:
	del $(objs)

