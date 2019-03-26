
#include"hash.hpp"

int main()
{
	c_hashTable test(10);
	test.upload("words.txt");
	char str[100] = {0};

	scanf("%s", str);

	if(test.cmp(str) == true)
		printf("Yep!\n");
	else
		printf("Nope!\n");
	
	return 0;
}



