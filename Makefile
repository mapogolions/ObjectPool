test:
	rm -rf ./build/*
	mkdir -p ./build
	clang -o ./build/a.out ./src/*.c
	./build/a.out
