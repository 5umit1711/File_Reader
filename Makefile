
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

APP = file_reader.exe

SOURCES = main.cpp scan.cpp read.cpp search.cpp index.cpp

.PHONY: all clean

all: $(APP)

$(APP): $(SOURCES) functions.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(APP)

clean:
	rm -f $(APP)
