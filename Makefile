run:
	rm -rf ./build/*
	mkdir -p ./build
	clang -o ./build/exe.out ./app.c ./object_pool.c ./object.c
	./build/exe.out
