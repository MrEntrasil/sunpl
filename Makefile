FILES = src/main.cpp
OUTPUT = build/SunPL

all:
	g++ -o $(OUTPUT) $(FILES)

clean:
	rm -rf ./build/SunPL.exe