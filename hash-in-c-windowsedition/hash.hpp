
#include<iostream>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ START OF DEFINES ~~~~~~~~~~~~~~~~~~~~~~~~~~ //

#define HASH_KEY		42
#define STR_SIZE		100

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF DEFINES ~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int myStrlen(char *str);
int myStrcopy(char *strTo, char *strFrom);
int myStrclean(char *str, int size);

class c_hashTable
{
	private:
		class std::list<char*>* _data;
		unsigned int _size;

		int getHash(char* word);

	public:
		c_hashTable(unsigned int size);
		~c_hashTable(void);
		unsigned int getSize(void);
		bool cmp(char* word);
		int upload(const char* fileName);
		int add(char* word);
};

//----------------------------------//
//	private function description	//
//----------------------------------//

int c_hashTable::getHash(char* word)
{
	unsigned int pos = 0;
	unsigned int key = 1;
	int i = 0;

	while(word[i] != '\0')
	{
		pos = pos + word[i] * key;
		key = key * HASH_KEY;
		i++;
	}

	return (pos % this->_size);
}

//----------------------------------//
//		Constructor & destructor	//
//----------------------------------//

c_hashTable::c_hashTable(unsigned int size)
{
	this->_data = new std::list<char*> [size];
	this->_size = size;
}

c_hashTable::~c_hashTable(void)
{
	delete [] this->_data;
}

//----------------------------------//
//	public functions description	//
//----------------------------------//

unsigned int c_hashTable::getSize(void)
{
	return this->_size;
}



int c_hashTable::upload(const char* fileName)
{
	FILE *file = fopen(fileName, "r+");
	int ret = 2;
	int len = 0;
	char enter = 0;
	char next_enter = 0;
	char tmpStr[100] = {0};
	char *str = NULL;

	if(file == NULL)
		return -1;

	while(ret == 2) ///!?!?!?
	{
		//ret = fscanf(file, "%s%c%c", tmpStr, &enter, &next_enter);
		ret = fscanf(file, "%s%c", tmpStr, &enter);

		if(ret != 2)
			break;

		len = myStrlen(tmpStr) + 1;
		str = new char [len];
		printf(">>> !%s!\n", tmpStr);
		myStrcopy(str, tmpStr);
		this->add(str);
		delete [] str;
		myStrclean(tmpStr, STR_SIZE);
	}

	fclose(file);
	return 0;
}


int c_hashTable::add(char* word)
{
	int pos = this->getHash(word);
	this->_data[pos].push_back(word);
    return 0;
}


bool c_hashTable::cmp(char* word)
{
	int pos = this->getHash(word);
	std::list<char*>::iterator iter = this->_data[pos].begin();

	while(iter != this->_data[pos].end())
	{
		if(strcmp(*iter, word) == 0)
			return true;

		++iter;
	}

	return false;
}

#undef HASH_KEY
#undef STR_SIZE

//--------------------------//
//		Help functions		//
//--------------------------//

int myStrcopy(char *strTo, char *strFrom)
{
	int i = 0;

	while(strFrom[i] != ' ' && strFrom[i] != '\n' && strFrom[i] != '\t' && strFrom[i] != '\0')
	{
		strTo[i] = strFrom[i];
		i++;
	}

	return 0;
}

int myStrclean(char *str, int size)
{
	int i = 0;

	while(i != size)
		str[i++] = '\0';

	return 0;
}

int myStrlen(char *str)
{
	int i = 0;

	while(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		i++;

	return i;
}



