// Timofeev_lab7.cpp: определяет точку входа для консольного приложения.


#include "stdafx.h"
#include <cctype>
#include "str_unit.h"
#include "testing.h"
#include <string>

int textToWords(const char text[20][81], int strCount, char words[40][21]);
int strToWords(const char *str, int start, char words[40][21]);
int test_strToWords();
int test_textToWords();
int _оnlyWord_();
int _someWords_();
int _emptyString_();
int оnlyWords();
int someWords();
int noWords();
int delimetsFirst();
int delimetsAfter();
void tests_all_functions();

int _tmain(int argc, _TCHAR* argv[])
{
	tests_all_functions();
	int strCount;                                 //Количество строк
	char text[20][81];                            //Исходный текст
	char words[40][21];                           //Массив слов
	int wordIndex=0;                              //Индекс искомого слова, вводимый с клавиатуры.
	//Ввод индекса искомого слова.
	input_printf("\n Введите индекс искомого слова: ");
	scanf_s("%d", &wordIndex);
	//Ввод количества строк
	input_printf ("\n Введите количество строк: ");
	scanf_s ("%d", &strCount);
	//Проверка массива на принадлежность диапазону
	if (strCount < 0 || strCount > 20)
	{
		error_printf("Некорректное число строк");
		WAIT_ANY_KEY
			return 0;
	}
	//Цикло ввода текста.
	input_printf(" В тексте не должны использоваться символы кириллицы");
	//Используется функция gets для заполнения массива с исходным текстом. if используется для пропуска первого прохода цикла из-за его неработоспособности.
	for (int L=0; L<=strCount; L++)  
	{
		if (L!=0) input_printf(" \n Введите %d строку: ", L);
		char stroka[81];
		gets(stroka);
		//Если в строку не осуществленн ввод символов, добавляем символ конца строки для корректной работы программы
		if (strlen(stroka) == 0)
		{
			stroka[0]=' ';
			stroka[1]='\0';
		}
		strcpy(text[L-1],stroka);
	}
	//Вызов функции textToWords
	int Out=textToWords(text, strCount, words);
	
	//Проверка введенного индекса на принадлежность к диапазону возможных значений.
	if (wordIndex>Out-1)
	{
		printf(" no solution");
	}
	else
	{
		input_printf(" Искомое слово:");
		printf(" %s", words[wordIndex]);
	}
	WAIT_ANY_KEY
		return 0;
}
int textToWords(const char text[20][81], int strCount, char words[40][21])
{
	//Объявляем указатель на массив с текстом для передачи в функицю strToWords
	const char * pText = &text[0][0];	
	//Обнуляем количество найденных слов.
	int wordsCount=0;
	//Цикл передачи строк в функцию strToWords. Вид pText+(k*81) обуславливается особенностью работы с указателями.
	for ( int k=0; k < strCount; k++)
		{
			wordsCount+=strToWords(pText+(k*81), wordsCount, words);
		}
		return wordsCount;
	}

int strToWords(const char * str, int start, char words[40][21])
{
	int wst=0;                       //Вспомогательная переменная, содержащая индекс первой буквы слова в строке.
	int wfin=0;                      //Вспомогательная переменная, содержащая индекс последней буквы слова в строке.
	int wordsCount=0;                //Количество найденных слов.
	//Цикл поиска слов в строке, полученной из функции textToWords
	int a = (strlen(str)-1);
	for (int i=0; i <= a; i++)
	{
		//Обрабатываются случаи нахождения символа-разделителя или конца исследуемой строки.
		const char tChar = (const char) *(str+i);
		if(!isalnum((unsigned char) tChar ) || i==(strlen(str)-1))
		{
			//Убеждаемся в наличии слова перед текущей исследуемой позицией.
			const char tChar2 = (const char) *(str+i-1);
			if(isalnum((unsigned char) tChar2) && i!=0)
			{
				//Обновляем данные, необходимые для обработки следующего найденного слова.
				wfin=i-1; 
				int diff=wfin-wst;
				//Непосредственно копирование найденного слова в массив words и обозначение конца строки в нём.
				if(i==(strlen(str)-1))
				{
					//Проверяем последний символ в строке. Если это не разделитель, выполняется копирование слова целиком. Иначе, выполняется копирование до предыдущей позиции.
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
				//Наращиваем значение счётчика найденных слов.
				wordsCount+=1;
			}
			else wst=i+1;
		}
	}
	return wordsCount;
}
// ------------------------ Модульные тесты ----------------------
void tests_all_functions()
{
	input_printf("\n-----------------------------------------------\n");
	input_printf("\n Тестирование функции strToWords...\n");
	if(test_strToWords())
	{
		input_printf ("\n function correct\n");
	}
	input_printf("\n-----------------------------------------------\n");
	input_printf("\n Тестирование функции textToWords...\n");
	if(test_textToWords())
	{
		input_printf ("\n function correct\n");
	}
	input_printf("\n-----------------------------------------------\n");
}
// ---------------------- API тестирования ----------------------
/*Производим анализ функций strToWords и textToWords путем сравнения эталонных данных с данными, полученным при выполнении функций.
*Сравнивает кол-во слов, массив, заполненный словами.
*\param [in] count - кол-во слов в строке
*/
int test_strToWords()
{
	int isOk = 1;
	isOk = isOk && _оnlyWord_();
	isOk = isOk && _someWords_();
	isOk = isOk && _emptyString_();
	return isOk;
}
int _оnlyWord_()
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
		// Печатаем неудачный тест ...
		input_printf("Error at _оnlyWord_");
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
		// Печатаем неудачный тест ...
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
		// Печатаем неудачный тест ...
		input_printf("\n Error at _emptyString_");
	}
	return isOk;
}
int test_textToWords()
{
	int isOk = 1;
	isOk = isOk && оnlyWords();
	isOk = isOk && someWords();
	isOk = isOk && noWords();
	isOk = isOk && delimetsFirst();
	isOk = isOk && delimetsAfter();
	return isOk;
}
int оnlyWords()
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
		// Печатаем неудачный тест ...
		input_printf("\n Error at оnlyWords");
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
		// Печатаем неудачный тест ...
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
		// Печатаем неудачный тест ...
		input_printf("\n Error at noWords");
	}
	return isOk;
}
int delimetsFirst()
{
	int isOk = 1;
	const char inpStrings[20][81] = {"   !!!   Hello", "     !!  World", "   №;:'''''''№;   Words"}; 
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
		// Печатаем неудачный тест ...
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
		// Печатаем неудачный тест ...
		input_printf("\n Error at delimetsAfter");
	}
	return isOk;
}