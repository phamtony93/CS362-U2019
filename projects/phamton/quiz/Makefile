CFLAGS= -Wall -fpic -coverage -lm -std=c99

randomTest: testme.c
	echo "randomTest BEGIN:" >> randomTestresults.out
	gcc -o randomTest testme.c -g $(CFLAGS)
	randomTest >> randomTestresults.out
	gcov testme.c -b -f >> randomTestresults.out

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out randomTest
