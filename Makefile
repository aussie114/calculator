NAME = calculator
OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

run: build
	bin/$(NAME)

build: $(OBJECTS)
	gcc -lm `pkg-config --libs gtk4` build/*.o -o bin/$(NAME)

build/%.o: src/%.c
	gcc -Wall -Wextra -Iinclude `pkg-config --cflags gtk4` -c $< -o $@

clean:
	rm -rf build/* bin/$(NAME)
