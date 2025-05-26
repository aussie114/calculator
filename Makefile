OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

run: build
	./bin/calculator

build: $(OBJECTS)
	gcc -lm -lreadline build/*.o -o ./bin/calculator

build/main.o: src/main.c
	gcc -c -Iinclude src/main.c -o build/main.o

build/tinyexpr.o: src/tinyexpr.c include/tinyexpr.h
	gcc -c -Iinclude src/tinyexpr.c -o build/tinyexpr.o

clean:
	rm build/*o ./bin/calculator
