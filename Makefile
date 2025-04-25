run: build
	./bin/calculator

build: build/main.o build/gtk_helper_functions.o build/tinyexpr.o
	gcc `pkg-config --libs gtk4` -lm build/*.o -o ./bin/calculator

build/main.o: src/main.c
	gcc -c -Iinclude `pkg-config --cflags gtk4` src/main.c -o build/main.o

build/gtk_helper_functions.o: include/gtk_helper_functions.h src/gtk_helper_functions.c
	gcc -c -Iinclude `pkg-config --cflags gtk4` src/gtk_helper_functions.c -o build/gtk_helper_functions.o

build/tinyexpr.o: src/tinyexpr.c include/tinyexpr.h
	gcc -c -Iinclude src/tinyexpr.c -o build/tinyexpr.o

clean:
	rm build/*o ./bin/calculator
