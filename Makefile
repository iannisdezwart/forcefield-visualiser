forces: forces.o
	g++ forces.o -o forces `libpng-config --ldflags` -pthread
	mkdir -p output
	echo "Successfully compiled the program. Now execute it with './forces'"

forces.o: index.cpp
	g++ -c index.cpp -o forces.o `libpng-config --cflags`

clean:
	rm -f forces forces.o
