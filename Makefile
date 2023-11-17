.PHONY: build run test Octagon_test Point_test Square_test Triangle_test

build: clean-build
	mkdir build
	git submodule init
	git submodule update
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test:
	./build/*_test

Octagon_test:
	./build/Octagon_test

Triangle_test:
	./build/Triangle_test

Square_test:
	./build/Square_test

Point_test:
	./build/Point_test

clean-build:
	rm -rf ./build/