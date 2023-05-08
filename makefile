all:
	g++ primegen.cpp -o primegen -lgmp
	g++ primecheck.cpp -o primecheck -lgmp
	g++ keygen.cpp -o keygen -lgmp
	g++ encrypt.cpp -o encrypt -lgmp
	g++ decrypt.cpp -o decrypt -lgmp
clean:
	rm -f primegen primecheck keygen encrypt decrypt
