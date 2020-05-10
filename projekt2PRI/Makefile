app : main.o funkcje.o
	cc -o app main.o funkcje.o
main.o : main.c funkcje.h
	cc -c main.c
funkcje.o : funkcje.c funkcje.h
	cc -c funkcje.c

clear :
	rm main.o funkcje.o app