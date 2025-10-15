PROJECT   = calculator
OBJECTS   = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

run: build
	bin/$(PROJECT)

build: $(OBJECTS)
	gcc build/*.o -lreadline -lm -o bin/$(PROJECT)

build/%.o: src/%.c 
	gcc -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/* bin/$(PROJECT)

