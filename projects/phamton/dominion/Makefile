CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unitTest1: unitTest1.c dominion.o rngs.o
	gcc -o unitTest1 -g unitTest1.c dominion.c rngs.c $(CFLAGS)

unitTest2: unitTest2.c dominion.o rngs.o
	gcc -o unitTest2 -g unitTest2.c dominion.c rngs.c $(CFLAGS)

unitTest3: unitTest3.c dominion.o rngs.o
	gcc -o unitTest3 -g unitTest3.c dominion.c rngs.c $(CFLAGS)

unitTest4: unitTest4.c dominion.o rngs.o
	gcc -o unitTest4 -g unitTest4.c dominion.c rngs.c $(CFLAGS)

unitTest5: unitTest5.c dominion.o rngs.o
	gcc -o unitTest5 -g unitTest5.c dominion.c rngs.c $(CFLAGS)

cardTest1: cardTest1.c dominion.o rngs.o
	gcc -o cardTest1 -g cardTest1.c dominion.c rngs.c $(CFLAGS)

cardTest2: cardTest2.c dominion.o rngs.o
	gcc -o cardTest2 -g cardTest2.c dominion.c rngs.c $(CFLAGS)

cardTest3: cardTest3.c dominion.o rngs.o
	gcc -o cardTest3 -g cardTest3.c dominion.c rngs.c $(CFLAGS)

cardTest4: cardTest4.c dominion.o rngs.o
	gcc -o cardTest4 -g cardTest4.c dominion.c rngs.c $(CFLAGS)

cardTest5: cardTest5.c dominion.o rngs.o
	gcc -o cardTest5 -g cardTest5.c dominion.c rngs.c $(CFLAGS)

unittestresults: unitTest1.c unitTest2.c unitTest3.c unitTest4.c unitTest5.c cardTest1.c cardTest2.c cardTest3.c cardTest4.c cardTest5.c dominion.o randomtestcard1.c randomtestcard2.c randomtestcard3.c
	echo "unitTest1 BEGIN:" >> unittestresults.out
	gcc -o unitTest1 -g unitTest1.c dominion.c rngs.c $(CFLAGS)
	unitTest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unitTest2 BEGIN:" >> unittestresults.out
	gcc -o unitTest2 -g unitTest2.c dominion.c rngs.c $(CFLAGS)
	unitTest2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unitTest3 BEGIN:" >> unittestresults.out
	gcc -o unitTest3 -g unitTest3.c dominion.c rngs.c $(CFLAGS)
	unitTest3 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unitTest4 BEGIN:" >> unittestresults.out
	gcc -o unitTest4 -g unitTest4.c dominion.c rngs.c $(CFLAGS)
	unitTest4 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out	

	echo "unitTest5 BEGIN:" >> unittestresults.out
	gcc -o unitTest5 -g unitTest5.c dominion.c rngs.c $(CFLAGS)
	unitTest5 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out	

	echo "cardTest1 BEGIN:" >> unittestresults.out
	gcc -o cardTest1 -g cardTest1.c dominion.c rngs.c $(CFLAGS)
	cardTest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "cardTest2 BEGIN:" >> unittestresults.out
	gcc -o cardTest2 -g cardTest2.c dominion.c rngs.c $(CFLAGS)
	cardTest2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "cardTest3 BEGIN:" >> unittestresults.out
	gcc -o cardTest3 -g cardTest3.c dominion.c rngs.c $(CFLAGS)
	cardTest3 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "cardTest4 BEGIN:" >> unittestresults.out
	gcc -o cardTest4 -g cardTest4.c dominion.c rngs.c $(CFLAGS)
	cardTest4 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "cardTest5 BEGIN:" >> unittestresults.out
	gcc -o cardTest5 -g cardTest5.c dominion.c rngs.c $(CFLAGS)
	cardTest5 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "randomtestcard1 BEGIN:" >> unittestresults.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion rngs.c $(CFLAGS)
	randomtestcard1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "randomtestcard2 BEGIN:" >> unittestresults.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion rngs.c $(CFLAGS)
	randomtestcard2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "randomtestcard3 BEGIN:" >> unittestresults.out
	gcc -o randomtestcard3 -g randomtestcard3.c dominion rngs.c $(CFLAGS)
	randomtestcard3 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: unitTest1 unitTest2 unitTest3 unitTest4 unitTest5

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe