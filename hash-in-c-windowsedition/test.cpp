#include <windows.h>
#include"hash.hpp"

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    system("chcp 65001 > nul");
	c_hashTable test(10);
	test.upload("C:\\Users\\bqbq4\\Desktop\\hash-in-c--master\\word_relase.txt");
	char str[100] = {0};

	scanf("%s", str);

	if(test.cmp(str) == true)
		printf("Yep!\n");
	else
		printf("Nope!\n");

	return 0;
}



