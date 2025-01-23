tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Daireselliste.o -c ./src/Daireselliste.cpp
	g++ -I ./include/ -o ./lib/Dna.o -c ./src/Dna.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/SatirDugum.o -c ./src/SatirDugum.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Daireselliste.o ./lib/Dna.o ./lib/Dugum.o ./lib/SatirDugum.o ./src/main.cpp

calistirma:
	cls
	./bin/program
