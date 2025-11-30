all: bin/calculator bin/percentof bin/percentwhat bin/percentchange bin/percentadd bin/percentsub

bin/calculator: src/main.c src/tinyexpr.c include/tinyexpr.h
	gcc src/main.c src/tinyexpr.c -Iinclude -lreadline -lm -o bin/calculator

bin/percentof: src/percentof.c
	gcc src/percentof.c -o bin/percentof

bin/percentwhat: src/percentwhat.c
	gcc src/percentwhat.c -o bin/percentwhat

bin/percentchange: src/percentchange.c
	gcc src/percentchange.c -o bin/percentchange

bin/percentadd: src/percentadd.c
	gcc src/percentadd.c -o bin/percentadd

bin/percentsub: src/percentsub.c
	gcc src/percentsub.c -o bin/percentsub

clean:
	rm -rf bin/*

