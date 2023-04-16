test:
	mkdir -p ./obj ./bin
	rm -rf ./obj/* ./bin/*
	gcc -c ./src/*.c
	mv *.o ./obj
	gcc ./obj/*.o -o ./bin/a.out
	./bin/a.out
