CFLAGS= -Wall -fpic -coverage -lm -std=c99

randomTest: testme.c
	gcc -o randomTest testme.c -coverage -fpic -lm

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out randomTest
