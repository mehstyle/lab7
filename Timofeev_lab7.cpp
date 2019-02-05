// Timofeev_lab7.cpp: ���������� ����� ����� ��� ����������� ����������.


#include "stdafx.h"
#include <cctype>
#include "str_unit.h"
#include "testing.h"
#include <string>

int textToWords(const char text[20][81], int strCount, char words[40][21]);
int strToWords(const char *str, int start, char words[40][21]);
int test_strToWords();
int test_textToWords();
int _�nlyWord_();
int _someWords_();
int _emptyString_();
int �nlyWords();
int someWords();
int noWords();
int delimetsFirst();
int delimetsAfter();
void tests_all_functions();

int _tmain(int argc, _TCHAR* argv[])
{
	tests_all_functions();
	int strCount;                                 //���������� �����
	char text[20][81];                            //�������� �����
	char words[40][21];                           //������ ����
	int wordIndex=0;                              //������ �������� �����, �������� � ����������.
	//���� ������� �������� �����.
	input_printf("\n ������� ������ �������� �����: ");
	scanf_s("%d", &wordIndex);
	//���� ���������� �����
	input_printf ("\n ������� ���������� �����: ");
	scanf_s ("%d", &strCount);
	//�������� ������� �� �������������� ���������
	if (strCount < 0 || strCount > 20)
	{
		error_printf("������������ ����� �����");
		WAIT_ANY_KEY
			return 0;
	}
	//����� ����� ������.
	input_printf(" � ������ �� ������ �������������� ������� ���������");
	//������������ ������� gets ��� ���������� ������� � �������� �������. if ������������ ��� �������� ������� ������� ����� ��-�� ��� �������������������.
	for (int L=0; L<=strCount; L++)  
	{
		if (L!=0) input_printf(" \n ������� %d ������: ", L);
		char stroka[81];
		gets(stroka);
		//���� � ������ �� ������������ ���� ��������, ��������� ������ ����� ������ ��� ���������� ������ ���������
		if (strlen(stroka) == 0)
		{
			stroka[0]=' ';
			stroka[1]='\0';
		}
		strcpy(text[L-1],stroka);
	}
	//����� ������� textToWords
	int Out=textToWords(text, strCount, words);
	
	//�������� ���������� ������� �� �������������� � ��������� ��������� ��������.
	if (wordIndex>Out-1)
	{
		printf(" no solution");
	}
	else
	{
		input_printf(" ������� �����:");
		printf(" %s", words[wordIndex]);
	}
	WAIT_ANY_KEY
		return 0;
}
int textToWords(const char text[20][81], int strCount, char words[40][21])
{
	//��������� ��������� �� ������ � ������� ��� �������� � ������� strToWords
	const char * pText = &text[0][0];	
	//�������� ���������� ��������� ����.
	int wordsCount=0;
	//���� �������� ����� � ������� strToWords. ��� pText+(k*81) ��������������� ������������ ������ � �����������.
	for ( int k=0; k < strCount; k++)
		{
			wordsCount+=strToWords(pText+(k*81), wordsCount, words);
		}
		return wordsCount;
	}

int strToWords(const char * str, int start, char words[40][21])
{
	int wst=0;                       //��������������� ����������, ���������� ������ ������ ����� ����� � ������.
	int wfin=0;                      //��������������� ����������, ���������� ������ ��������� ����� ����� � ������.
	int wordsCount=0;                //���������� ��������� ����.
	//���� ������ ���� � ������, ���������� �� ������� textToWords
	int a = (strlen(str)-1);
	for (int i=0; i <= a; i++)
	{
		//�������������� ������ ���������� �������-����������� ��� ����� ����������� ������.
		const char tChar = (const char) *(str+i);
		if(!isalnum((unsigned char) tChar ) || i==(strlen(str)-1))
		{
			//���������� � ������� ����� ����� ������� ����������� ��������.
			const char tChar2 = (const char) *(str+i-1);
			if(isalnum((unsigned char) tChar2) && i!=0)
			{
				//��������� ������, ����������� ��� ��������� ���������� ���������� �����.
				wfin=i-1; 
				int diff=wfin-wst;
				//��������������� ����������� ���������� ����� � ������ words � ����������� ����� ������ � ��.
				if(i==(strlen(str)-1))
				{
					//��������� ��������� ������ � ������. ���� ��� �� �����������, ����������� ����������� ����� �������. �����, ����������� ����������� �� ���������� �������.
					if(isalnum((unsigned char) tChar))
					{
						strncpy (words[start+wordsCount], str+wst, diff+2);
						words[start+wordsCount][diff+2]='\0';
					}
					else
					{
						strncpy (words[start+wordsCount], str+wst, diff+1);
						words[start+wordsCount][diff+1]='\0';
					}
				}
				else
				{
					strncpy (words[start+wordsCount], str+wst, diff+1);
					words[start+wordsCount][diff+1]='\0';
				}
				wst=i+1;
				//���������� �������� �������� ��������� ����.
				wordsCount+=1;
			}
			else wst=i+1;
		}
	}
	return wordsCount;
}
// ------------------------ ��������� ����� ----------------------
void tests_all_functions()
{
	input_printf("\n-----------------------------------------------\n");
	input_printf("\n ������������ ������� strToWords...\n");
	if(test_strToWords())
	{
		input_printf ("\n function correct\n");
	}
	input_printf("\n-----------------------------------------------\n");
	input_printf("\n ������������ ������� textToWords...\n");
	if(test_textToWords())
	{
		input_printf ("\n function correct\n");
	}
	input_printf("\n-----------------------------------------------\n");
}
// ---------------------- API ������������ ----------------------
/*���������� ������ ������� strToWords � textToWords ����� ��������� ��������� ������ � �������, ���������� ��� ���������� �������.
*���������� ���-�� ����, ������, ����������� �������.
*\param [in] count - ���-�� ���� � ������
*/
int test_strToWords()
{
	int isOk = 1;
	isOk = isOk && _�nlyWord_();
	isOk = isOk && _someWords_();
	isOk = isOk && _emptyString_();
	return isOk;
}
int _�nlyWord_()
{
	int isOk = 1;
	const char inpString[10] = "Hello"; 
	const char * pInpStr = inpString;
	const int expCount = 1;
	char words[40][21];
	int testStart = 3;
	int wordCount;
	wordCount = strToWords(pInpStr, testStart, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = testStart; i < testStart + wordCount; i++)
	{
		const char * pWords = words[i];
		isOk = isOk && !strcmp(pInpStr, pWords);
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("Error at _�nlyWord_");
	}
	return isOk;
}
int _someWords_()
{
	int isOk = 1;
	const char inpString[60] = "Hello world";
	char exp_words[40][21] = {"Hello", "world"};
	const char * pInpStr = inpString;
	const int expCount = 2;
	char words[40][21];
	int testStart = 3;
	int wordCount;
	wordCount = strToWords(pInpStr, testStart, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < wordCount; i++)
	{
		char * pExpWords = exp_words[i];
		char * pWords = words[i+testStart];
		isOk = isOk && !strncmp(pWords, pExpWords, (strlen(pExpWords)));
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at _someWords_");
	}
	return isOk;
}
int _emptyString_()
{
	int isOk = 1;
	const char inpString[60] = "";
	char exp_words[40][21];
	const char * pInpStr = inpString;
	const int expCount = 0;
	char words[40][21];
	int testStart = 3;
	int wordCount;
	wordCount = strToWords(pInpStr, testStart, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < wordCount; i++)
	{
		char * pExpWords = exp_words[i];
		char * pWords = words[i+testStart];
		isOk = isOk && !strncmp(pWords, pExpWords, strlen(pExpWords));
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at _emptyString_");
	}
	return isOk;
}
int test_textToWords()
{
	int isOk = 1;
	isOk = isOk && �nlyWords();
	isOk = isOk && someWords();
	isOk = isOk && noWords();
	isOk = isOk && delimetsFirst();
	isOk = isOk && delimetsAfter();
	return isOk;
}
int �nlyWords()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"Hello", "there!", "Wooooords!"}; 
	char exp_words[40][21] = {"Hello", "there", "Wooooords"};
	const int strCount = 3;
	const int expCount = 3;
	char words[40][21];
	int wordCount;
	wordCount = textToWords(inpStrings, strCount, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < 3; i++)
	{
		const char * pWords = words[i];
		char * pExpWords = exp_words[i];
		isOk = isOk && !strcmp(pExpWords, pWords);
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at �nlyWords");
	}
	return isOk;
}
int someWords()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"Hello world", "some! words", "more words!"}; 
	char exp_words[40][21] = {"Hello", "world", "some","words", "more", "words"};
	const int strCount = 3;
	const int expCount = 6;
	char words[40][21];
	int wordCount;
	wordCount = textToWords(inpStrings, strCount, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < 10; i++)
	{
		const char * pWords = words[i];
		char * pExpWords = exp_words[i];
		isOk = isOk && !strncmp(pExpWords, pWords, strlen(pExpWords));
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at someWords");
	}
	return isOk;
}
int noWords()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"!!! ", " :?*(", "     "}; 
	const int strCount = 3;
	const int expCount = 0;
	char words[40][21];
	int wordCount;
	wordCount = textToWords(inpStrings, strCount, words);
	isOk = isOk && (wordCount == expCount);
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at noWords");
	}
	return isOk;
}
int delimetsFirst()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"   !!!   Hello", "     !!  World", "   �;:'''''''�;   Words"}; 
	char exp_words[40][21] = {"Hello", "World", "Words"};
	const int strCount = 3;
	const int expCount = 3;
	char words[40][21] ;
	int wordCount;
	wordCount = textToWords(inpStrings, strCount, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < 10; i++)
	{
		const char * pWords = words[i];
		char * pExpWords = exp_words[i];
		isOk = isOk && !strncmp(pExpWords, pWords, strlen(pExpWords));
	}

	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at delimetsFirst");	
	}
	return isOk;
}
int delimetsAfter()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"Hello    #^$@#", "World @#$*****^%%", "Words)(*&^^%$"}; 
	char exp_words[40][21] = {"Hello", "World", "Words"};
	const int strCount = 3;
	const int expCount = 3;
	char words[40][21] ;
	int wordCount;
	wordCount = textToWords(inpStrings, strCount, words);
	isOk = isOk && (wordCount == expCount);
	for (int i = 0; i < 10; i++)
	{
		const char * pWords = words[i];
		char * pExpWords = exp_words[i];
		isOk = isOk && !strncmp(pExpWords, pWords, strlen(pExpWords));
	}
	if(!isOk)
	{
		// �������� ��������� ���� ...
		input_printf("\n Error at delimetsAfter");
	}
	return isOk;
}