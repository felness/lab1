.PHONY: build run test test_allocator test_list

build: clean-build
	mkdir build
	git submodule init
	git submodule update
	cd ./build; cmake ..; make all

run:
	./build/*_exe

test:
	./build/*_test

test_allocator:
	./build/test_allocator
	
test_list:
	./build/test_list


clean-build:
	rm -rf ./build/