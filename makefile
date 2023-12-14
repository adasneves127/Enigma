
all: main.o plugboard.o reflector.o rotor.o
	g++ -o Enigma ./src/main.o ./src/plugboard.o ./src/reflector.o ./src/rotor.o
	mkdir -p messages

rotor.o:
	cd src;	g++ -c rotor.cpp

reflector.o:
	cd src; g++ -c reflector.cpp

plugboard.o:
	cd src; g++ -c plugboard.cpp

main.o:
	cd src;	g++ -c main.cpp

clean:
	rm -f ./src/*.o Enigma ./messages/*.txt