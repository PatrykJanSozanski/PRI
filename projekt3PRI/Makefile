app : main.o powloka.o funkcje.o pomocnicze.o pomocnicze2.o pomocnicze3.o
	cc -o app main.o powloka.o funkcje.o pomocnicze.o pomocnicze2.o pomocnicze3.o
main.o : main.c powloka.h
	cc -c main.c
powloka.o : powloka.c powloka.h funkcje.h
	cc -c powloka.c
funkcje.o : funkcje.c funkcje.h pomocnicze.h
	cc -c funkcje.c
pomocnicze.o : pomocnicze.c pomocnicze.h pomocnicze2.h
	cc -c pomocnicze.c
pomocnicze2.o : pomocnicze2.c pomocnicze2.h pomocnicze3.o
	cc -c pomocnicze2.c
pomocnicze3.o : pomocnicze3.c pomocnicze3.h
	cc -c pomocnicze3.c

clear :
	rm main.o powloka.o funkcje.o pomocnicze.o pomocnicze2.o pomocnicze3.o app
