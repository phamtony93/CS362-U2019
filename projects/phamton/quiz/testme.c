#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	char randomChar;

	int range = 125 - 32 + 1;

	randomChar = (rand() % range) + 32;
    return randomChar;
}

char *inputString()
{
    // TODO: rewrite this function
	//int i;

	char randomString[6];
	//int randomConsanance = (rand() % (117 - 113 + 1)) + 113;

	char vowels[5];
	vowels[0] = 'a';
	vowels[1] = 'e';
	vowels[2] = 'i';
	vowels[3] = 'o';
	vowels[4] = 'u';

	int randomVowel = rand() % 5;

	//for (int i = 0; i < 5; i++) {
	//	greeting[i] = (rand() % randomRandge) + 101;
	//	//printf("%c \n", greeting[i]);
	//};

	randomString[0] = ((rand() % (122 - 97 + 1)) + 97);
	randomString[1] = vowels[randomVowel];
	randomString[2] = ((rand() % (122 - 97 + 1)) + 97);
	randomString[3] = vowels[randomVowel];
	randomString[4] = ((rand() % (122 - 97 + 1)) + 97);
	randomString[5] = 0;

	//printf("%s \n", greeting);
	//strcpy(greeting, "hello");
    return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    //printf("c = %c, state = %d\n", c, state);
	
    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' 
		&& s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();

	//char* s;
	//s = inputString();
	//strcpy(random, inputString());
	//printf("%s \n", s);

	system("pause");
    return 0;
}
