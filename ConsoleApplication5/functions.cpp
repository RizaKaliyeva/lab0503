#include<iostream>
#include<locale.h>
#include"Header.h"
#include<time.h>
#include<stdio.h>

using namespace std;

void dinstr(char *str, int r)
{
	unsigned char * word = (unsigned char*)calloc(50, sizeof(unsigned char));

	int n = 0, kon = 0, ws = 0;
	while (kon < r)
	{
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if (kon != r)
				kon++;
			else break;

		}
		for (int i = n;i < kon;i++)
		{
			word[ws] = str[i];
			ws++;
		}
		word[ws] = '\0';
		if (kon - n != 1)
		{
			/*if (isupper(word[0]))
			{*/
			//word[0] = tolower(word[0]);
			if (tolower(word[0]) == tolower(word[ws - 1]))
				cout << word << endl;
			/*}*/
			/*else
			{
			if (word[0] == word[ws - 1])
			cout << word << endl;
			}*/
		}
		n = kon + 1;
		if (str[kon] != ' ' || str[kon] != ',') kon++;
		ws = 0;
	}
}

int * createDunamic(int len)
{
	return (int *)malloc(len * sizeof(int));
}

char * createDunamicChar(int len)
{
	return (char *)malloc(len * sizeof(char));
}

char * reallocDunamicChar(char * str, int len)
{
	return (char*)realloc(str, len * sizeof(char));
}

void replacestr(char *str, char * old, char * tonew)
{
	int count = 0;
	int lenOld = strlen(old);
	int strLen = strlen(str);


	for (int i = 0;i < strlen(str);i++)
	{
		if (str[i] == *old)
		{
			count++;
			old++;
		}
		else
		{
			old = old - count;
			count = 0;
		}

		if (count == lenOld)
		{
			int different = strlen(tonew) - lenOld;
			if (different > 0)
			{
				str = reallocDunamicChar(str, (strLen + different + 1));
				if (str == NULL) break;
				//�������� 
				for (int j = strlen(str) + 1;j > i;j--)
				{
					*(str + j) = *(str + j - 1);

				}
				//*(str + strlen + different + 1) = '\0';

				for (int j = i - lenOld;j <= i;j++)
				{
					*(str + j) = *(tonew);
					tonew++;
				}
			}
			else if (different == 0)
				for (int j = 0;j < lenOld;j++)
					*(str + j) = *(tonew + j);
		}
	}

}

static int cSymb(char *str, char symb)
{
	int count = 0;
	for (int i = 0;i < strlen(str);i++)
		if (*(str + i) == symb) count++;
	return count;
}

void repl2(char*str)
{
	int c = cSymb(str, ' ');
	str = (char*)realloc(str, sizeof(char)*(strlen(str) + c));
	int n = 0, kon = 0, ws = 0;
	while (kon < strlen(str))
	{
		while (str[kon] != ' ')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str) + 1;i >= kon;i--)
		{
			*(str + i) = *(str + i - 1);
		}
		*(str + kon) = ',';
		kon = kon + 2;
	}
	printf("\n\n%s\n\n", str);
}

void alf(char *str)
{
	unsigned char symb;

}