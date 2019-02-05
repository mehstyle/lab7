#ifndef STRUNIT_TEST
#define STRUNIT_TEST
#include <string.h>

#ifdef TESTING
	// Файл str_unit.h подключен после testing.h,
	// необходимо str_unit.h подключать до подключения testing.h.
	1 //You must include str_unit.h before testing.h
#endif

#pragma comment (lib, "str_unit.lib")
//#pragma comment (lib, "..\\Debug\\str_unit.lib")

// Общие функции
void UnitTesting();

// 1
int selectWords(const char *str, int min, int max, char words[30][21]);
extern int (*_1_selectWords)(const char *str, int min, int max, char words[30][21]);
void findWord(const char *str, int start, int *begin, int *end);
extern void (*_1_findWord)(const char *str, int start, int *begin, int *end);

//2
int textToWords(const char text[20][81], int strCount, char words[40][21]);
extern int (*_2_textToWords)(const char text[20][81], int strCount, char words[40][21]);
int strToWords (const char *str, int start, char words[40][21]);
extern int (*_2_strToWords)(const char *str, int start, char words[40][21]);

//3
int crossStrings (const char str1[81], const char str2[81], char words[40][21]);
extern int (*_3_crossStrings) (const char str1[81], const char str2[81], char words[40][21]);
int strToWords(const char str[81], char words[40][21]);
extern int (*_3_strToWords)(const char str[81], char words[40][21]);

//4
void delCharacters (char str[81], const char characters[256]);
extern void (*_4_delCharacters) (char str[81], const char characters[256]);
void cutString(char str[81], int beginPos, int endPos);
extern void (*_4_cutString) (char str[81], int beginPos, int endPos);

//5
int textToWords (const char text[20][81], int strCount, char *words[800], char wordLength[800]);
extern int (*_5_textToWords) (const char text[20][81], int strCount, char *words[800], char wordLength[800]);
int textLength(const char text[20][81], int strCount);
extern int (*_5_textLength)(const char text[20][81], int strCount);

//6
int getNumbers (const char str[81], int numbers[40]);
extern int (*_6_getNumbers) (const char str[81], int numbers[40]);
int findInteger(const char str[81], char **end);
extern int (*_6_findInteger)(const char str[81], char **end);

//7
void sortByStringLength(char stringList[40][21], int count);
extern void (*_7_sortByStringLength)(char stringList[40][21], int count);

//8
int insertString (char destinString[81], const char sourceString[81],  int characterIndex);
extern int (*_8_insertString) (char destinString[81], const char sourceString[81],  int characterIndex);
int findCharInText (const char text[20][81], int N, char character, int *line, int *column);
extern int (*_8_findCharInText)(const char text[20][81], int N, char character, int *line, int *column);

//9
void findPairBrackets (const char text[20][81], int strCount, int lineIndex, int characterIndex, int brackets[4]);
extern void (*_9_findPairBrackets) (const char text[20][81], int strCount, int lineIndex, int characterIndex, int brackets[4]);

//10
void markWords(char str[81], const char word[21]);
extern void (*_10_markWords)(char str[81], const char word[21]);
int searchWord(const char str[81], const char word[21]);
extern int (*_10_searchWord)(const char str[81], const char word[21]);
void slideString(char str[81], int pos, int growth, char spacer);
extern void (*_10_slideString)(char str[81], int pos, int growth, char spacer);

//11
void deleteBlanks(char str[81]);
extern void (*_11_deleteBlanks)(char str[81]);

//12
int markWords(const char word[21], const char words[40][21], int nWords,int isEqual[40]);
extern int (*_12_markWords)(const char word[21], const char words[40][21], int nWords,int isEqual[40]);

//13
int searchString (const char stringList[30][41], int count, const char str[41]);
extern int (*_13_searchString) (const char stringList[30][41], int count, const char str[41]);
int slideStringList (char stringList[30][41], int count, int strIndex);
extern int (*_13_slideStringList) (char stringList[30][41], int count, int strIndex);

//14
void countWordsByLetter (char * const words[40], const int wordLength[40], int wordCount, int letters[32]);
extern void (*_14_countWordsByLetter) (char * const words[40], const int wordLength[40], int wordCount, int letters[32]);

//15
int strToWords (const char str[81], int words[40][2]);
extern int (*_15_strToWords) (const char str[81], int words[40][2]);
int compareByContents (const char str1[21], const char str2[21]);
extern int (*_15_compareByContents)(const char str1[21], const char str2[21]);

//16
int strToWords(const char str[81], char *words[40], int wordLength[40]);
extern int (*_16_strToWords)(const char str[81], char *words[40], int wordLength[40]);
int selectWords( char * const words[40],const int wordLength[40], int wordCount, const char prefix[40],int wordIndexes[40]);
extern int (*_16_selectWords)(char * const words[40],const int wordLength[40], int wordCount, const char prefix[40],int wordIndexes[40]);

// #17
void reverseWords(char str[81], const char word[21]);
extern void (*_17_reverseWords)(char str[81], const char word[21]);

// #18
void deleteWords(char str[81], const char word[21]);
extern void (*_18_deleteWords)(char str[81], const char word[21]);

//19
void toMorseCode(char symbol, char MorseCode[7]);
extern void (*_19_toMorseCode)(char symbol, char MorseCode[7]);
void strToMorse(const char str[81],char MorseCode[324]);
extern void (*_19_strToMorse)(const char str[81],char MorseCode[324]);

//20
int searchPhrase(const char text[20][81], int strCount, const char phrase[41], int location[40][2]);
extern int (*_20_searchPhrase)(const char text[20][81], int strCount, const char phrase[41], int location[40][2]);

//21
void replaceWords(char str[81], const char originalWord[21], const char targetWord[21]);
extern void (*_21_replaceWords )(char str[81], const char originalWord[21], const char targetWord[21]);

//22
int stringToSubstrings(const char str[81], const char separators[31], char *substrings[30][2]);
extern int (*_22_stringToSubstrings)(const char str[81], const char separators[31], char *substrings[30][2]);
int countRepeats(const char str[81], char * const substrings[30][2], int countSubstrings, char *startpos);
extern int (*_22_countRepeats)(const char str[81], char * const substrings[30][2], int countSubstrings, char *startpos);

//23
int wordMeaning(const char str[81],const char word[21],const char satellites[5][21], int range);
extern int (*_23_wordMeaning)(const char str[81],const char word[21],const char satellites[5][21], int range);
int strToWords(const char str[81], char *words[40][2]);
extern int (*_23_strToWords)(const char str[81], char *words[40][2]);

//24
void stringInText(const char text[20][81], int strCount, const char str[81], int *lineIndex, int *colIndex);
extern void (*_24_stringInText)(const char text[20][81], int strCount, const char str[81], int *lineIndex, int *colIndex);

//25
int parseSynonym(const char synonym[61],char synonymDictionary[2][31]);
extern int (*_25_parseSynonym)(const char synonym[61],char synonymDictionary[2][31]);
void findSynonym(const char synonymDictionary[20][2][31],int count, const char word[31], char synonym[31]);
extern void (*_25_findSynonym)(const char synonymDictionary[20][2][31],int count, const char word[31], char synonym[31]);

//26
int findString (const char stringList[20][21], int count, const char str[21]);
extern int (*_26_findString) (const char stringList[20][21], int count, const char str[21]);

//27
int findWord(const char divisionOfWords[20][2][31], int count, const char word[21]);
extern int (*_27_findWord)(const char divisionOfWords[20][2][31], int count, const char word[21]);
int divideWord(const char divisionOfWord[31], int n);
extern int (*_27_divideWord)(const char divisionOfWord[31], int n);

//29
int distanceBetweenWords(const char text[20][81], int count,const int locationWord1[2],const int locationWord2[2]);
extern int (*_29_distanceBetweenWords)(const char text[20][81], int count,const int locationWord1[2],const int locationWord2[2]);

//30
void censorWords (char str[81], const char word[21]);
extern void (*_30_censorWords) (char str[81], const char word[21]);

//others
int distanceBetweenWords (const char str[81], const char word1[21], const char word2[21]);
extern int (*_b40a3_distanceBetweenWords) (const char str[81], const char word1[21], const char word2[21]);
int getWords(const char str[81],int startIndex, int endIndex, char selectWords[20][21]);
extern int (*_24cb3_getWords)(const char str[81],int startIndex, int endIndex, char selectWords[20][21]);
int minimum (const char arr[800], int count, int mins[800]);
extern int (*_a46a5_minimum) (const char arr[800], int count, int mins[800]);
void deleteBlanksFromText(char text[20][81], int strCount);
extern void (*_eb290_deleteBlanksFromText)(char text[20][81], int strCount);
int strToWords (const char str[81], int start, char *words[800], char wordLength[800]);
extern int (*_597e4_strToWords) (const char str[81], int start, char *words[800], char wordLength[800]);
int cutBracketsFromText (char text[20][81], int strCount);
extern int (*_c46f2_cutBracketsFromText) (char text[20][81], int strCount);
void replaceWordsInText(char text[20][81], int strCount, const char originalWord[21], const char targetWord[21]);
extern void (*_d2e14_replaceWordsInText)(char text[20][81], int strCount, const char originalWord[21], const char targetWord[21]);
void markWordsInText(char text[20][81],int strCount, const char word[21]);
extern void (*_25b24_markWordsInText)(char text[20][81],int strCount, const char word[21]);
int searchWordInText(const char text[20][81], int strCount, const char word[21], int location[40][2]);
extern int (*_6a4eb_searchWordInText)(const char text[20][81], int strCount, const char word[21], int location[40][2]);
int getNumbers (const char str[81], float numbers[40]);
extern int (*_8f7d2_getNumbers) (const char str[81], float numbers[40]);
void searchWordInText(const char text[20][81], int strCount, const char word[21], int direction, int location[2]);
extern void (*_024d7_searchWordInText)(const char text[20][81], int strCount, const char word[21], int direction, int location[2]);
int searchPhrase(const char text[20][81], int strCount, const char phrase[20][41], int wordCount, int location[40][2]);
extern int (*_04ca43_searchPhrase)(const char text[20][81], int strCount, const char phrase[20][41], int wordCount, int location[40][2]);
int uniqueStrings (char stringList[40][21], int strCount);
extern int (*_7e880_uniqueStrings)(char stringList[40][21], int strCount);
void textToStr(const char text[20][81], int strCount, char str[1621]);
extern void (*_530ec_textToStr)(const char text[20][81], int strCount, char str[1621]);
void translateText(char text[20][324],char strCount);
extern void (*_f3342_translateText)(char text[20][324],char strCount);
int cutText(char text[20][81],int strCount,int startStrIndex, int startCharIndex, int endStrIndex, int endCharIndex);
extern int (*_1bec2_cutText)(char text[20][81],int strCount,int startStrIndex, int startCharIndex, int endStrIndex, int endCharIndex);
void checkSpelling(const char dictionary[20][21], int count, const char str[81], char checkedString[81]);
extern void (*_e82bb_checkSpelling)(const char dictionary[20][21], int count, const char str[81], char checkedString[81]);
void deleteWordsFromText(char text[20][81],int strCount, const char word[21]);
extern void (*_3eac1_deleteWordsFromText)(char text[20][81],int strCount, const char word[21]);
void delFromText(char text[20][81], int strCount, const char characters[256]);
extern void (*_6ec83_delFromText)(char text[20][81], int strCount, const char characters[256]);
void reversePhraseInText(char text[20][81], int strCount, const char word1[21], const char word2[21]);
extern void (*_05789_reversePhraseInText)(char text[20][81], int strCount, const char word1[21], const char word2[21]);
void reverseWordsInText(char text[20][81], int strCount,const char word[21]);
extern void (*_a7490_reverseWordsInText)(char text[20][81], int strCount,const char word[21]);
void insertStringBefore (char text[20][81],int N, const char str[81], char character);
extern void (*_aaaa9_insertStringBefore)(char text[20][81],int N, const char str[81], char character);
int findWordFromText(const char text[20][81], int count, const char prefix[21], char words[30][21]);
extern int (*_58b3b_findWordFromText)(const char text[20][81], int count, const char prefix[21], char words[30][21]);
int separateToSentences (const char str[81], char sentences [20][81]);
extern int (*_63e44_separateToSentences) (const char str[81], char sentences [20][81]);
void getWord(const char text[20][81], int strCount, int index, char word[21]);
extern void (*_b4974_getWord)(const char text[20][81], int strCount, int index, char word[21]);
int equalWords (const char str[81], char word_groups[10][10][21]);
extern int (*_f8595_equalWords)(const char str[81], char word_groups[10][10][21]);
void censorText(char text[20][81], int count,const char * word);
extern void (*_5d510_censorText)(char text[20][81], int count,const char * word);
void sortByStringLength(char stringList[40][21], int count, int direction);
extern void (*_3643e_sortByStringLength)(char stringList[40][21], int count, int direction);
int distanceBetweenWordsValue(const char text[20][81], int count,const char word1[21], const char word2[21]);
extern int (*_10c6c_distanceBetweenWordsValue)(const char text[20][81], int count,const char word1[21], const char word2[21]);
int startWords (const char text[20][81], int strCount, char letters[33]);
extern int (*_a120f_startWords) (const char text[20][81], int strCount, char letters[33]);
int findSubstrInText (const char text[20][81], int strCount, char substring[81], int * line, int * column);
extern int (*_622d9_findSubstrInText) (const char text[20][81], int strCount, char substring[81], int * line, int * column);
void insertFirstLineIndent(char text[20][81], int count);
extern void (*_ce079_insertFirstLineIndent)(char text[20][81], int count);
int countWords(const char words[40][21],int count,const char word[21]);
extern int (*_93be5_countWords)(const char words[40][21],int count,const char word[21]);
void addSynonyms (const char synonymDictionary[20][2][31], int count, char str[81]);
extern void (*_2ae89_addSynonyms) (const char synonymDictionary[20][2][31], int count, char str[81]);
int divisionOfWordInDictionary(const char divisionOfWords[20][2][31], int count, const char word[21], int n, int *hyphenIndex);
extern int (*_27cd9_divisionOfWordInDictionary)(const char divisionOfWords[20][2][31], int count, const char word[21], int n, int *hyphenIndex);
void insertToStringList (char stringList[30][41], int count, const char str[41]);
extern void (*_02b98_insertToStringList)(char stringList[30][41], int count, const char str[41]);
void translateSubstrings(char str[81], const char substrings[20][31], int substrCount);
extern void (*_fc6a9_translateSubstrings)(char str[81], const char substrings[20][31], int substrCount);
int spellString(const char str[81], const char dictionary[20][21], int count);
extern int (*_54ded_spellString)(const char str[81], const char dictionary[20][21], int count);
int getNumbersFromText(const char text[20][81], int strCount, int numbers[40]);
extern int (*_beb12_getNumbersFromText)(const char text[20][81], int strCount, int numbers[40]);
int findSynonymAll(const char synonymDictionary[20][2][31],int count, const char word[31], char synonyms[20][31]);
extern int (*_20579_findSynonymAll)(const char synonymDictionary[20][2][31],int count, const char word[31], char synonyms[20][31]);
int insertString (char text[20][81], int count, int index, const char str[81]);
extern int (*_df735_insertString) (char text[20][81], int count, int index, const char str[81]);
int compositionStrings(const char str1[81], const char str2[81]);
extern int (*_2ae70_compositionStrings)(const char str1[81], const char str2[81]);
int stringInTextAll(const char text[20][81], int strCount, const char str[81], int location[20][2]);
extern int (*_65b6e_stringInTextAll)(const char text[20][81], int strCount, const char str[81], int location[20][2]);
int selectPhrases(const char str[1621],int min, int max, char phrases[30][41]);
extern int (*_59053_selectPhrases)(const char str[1621],int min, int max, char phrases[30][41]);
int uniteStrings(const char str1[81], const char str2[81], char words[40][21]);
extern int (*_c1d1b_uniteStrings) (const char str1[81], const char str2[81], char words[40][21]);
void delSubstring (char str[81], const char substring[81]);
extern void (*_1f2a9_delSubstring) (char str[81], const char substring[81]);
void delWord (char str[81], const char word[21]);
extern void (*_97af7_delWord) (char str[81], const char word[21]);
int isEndOfSentence (const char text[20][81], int N, char * const word);
extern int (*_f579b_isEndOfSentence) (const char text[20][81], int N, char * const word);
int iterativeWordLocation(const char text[20][81], int strCount, int location[40][2]);
extern int (*_a4eb3_iterativeWordLocation)(const char text[20][81], int strCount, int location[40][2]);
float findFloat(const char * str, char **end);
extern float (*_8f7d2_findFloat)(const char * str, char **end);
int compareString(const char str1[21], const char str2[21], const char alphabet[256]);
extern int (*_ae399_compareString)(const char str1[21], const char str2[21], const char alphabet[256]);
int insertStrToText (char text[20][81], int strCount, const char str[81], int strIndex);
extern int (*_1191a_insertStrToText) (char text[20][81], int strCount, const char str[81], int strIndex);
int countInvalidBrackets (char text[20][81], int strCount, int errors[60][2]);
extern int (*_7a70f_countInvalidBrackets) (char text[20][81], int strCount, int errors[60][2]);
void duplicateWords(char text[20][81], int strCount, const char word[21]);
extern void (*_efc2b_duplicateWords)(char text[20][81], int strCount, const char word[21]);
int entryCount(const char text[20][81], int strCount, const char word[21]);
extern int (*_e18c0_entryCount)(const char text[20][81], int strCount, const char word[21]);
void deleteDelimiters(char str[81]);
extern void (*_3ec7d_deleteDelimiters)(char str[81]);
int findNextQuote(char text[20][81], int strCount, int *line,int *column);
extern int (*_b37fd_findNextQuote)(char text[20][81], int strCount, int *line,int *column);
int compareStringList (const char stringList1[40][21], int count1, const char stringList2[40][21], int count2);
extern int (*_62a5d_compareStringList) (const char stringList1[40][21], int count1, const char stringList2[40][21], int count2);
int strToWords (const char str[81], char words[40][21], char delimeters[81]);
extern int (*_05967_strToWords) (const char str[81], char words[40][21], char delimeters[81]);
float getRating(char str[41]);
extern float (*_d5d5b_getRating)(char str[41]);
int packStringList (char stringList[30][41], int count, int strIndex);
extern int (*_69305_packStringList) (char stringList[30][41], int count, int strIndex);
int startWords (char * const words[40], int count, const char character);
extern int (*_2ffe4_startWords) (char * const words[40], int count, const char character);
int lettersString (const char str[21]);
extern int (*_0523c_lettersString) (const char str[21]);
int differenceByContents(const char str1[21], const char str2[21]);
extern int (*_a77a5_differenceByContents)(const char str1[21], const char str2[21]);
int findFIO (const char str[81], const char surname[21], int location[30]);
extern int (*_142d2_findFIO) (const char str[81], const char surname[21], int location[30]);
void reversePhrase(char str[81], const char word1[21], const char word2[21]);
extern void (*_f3c74_reversePhrase)(char str[81], const char word1[21], const char word2[21]);
int deleteString(char text[20][81], int strCount, int index);
extern int (*_1af88_deleteString)(char text[20][81], int strCount, int index);
void deleteDuplicateWordsFromText(char text[20][81], int strCount);
extern void (*_50b16_deleteDuplicateWordsFromText)(char text[20][81], int strCount);
void translateFromMorseCode(const char strMorseCode[324], char str[81]);
extern void (*_fa4a6_translateFromMorseCode)(const char strMorseCode[324], char str[81]);
int insertStringToText(char text[20][81], int strCount, const int location[2], const char substr[21]);
extern int (*_e3a83_insertStringToText)(char text[20][81], int strCount, const int location[2],const char substr[21]);
int iterativeWordCount (const char str[81], const char separators[31], int separator);
extern int (*_235bc_iterativeWordCount) (const char str[81], const char separators[31], int separator);
int sentenceLocation (const char text[20][81], int strCount, int location[40][2]);
extern int (*_fcb68_sentenceLocation) (const char text[20][81], int strCount, int location[40][2]);
void delRegionOfText (char text[20][81], int count, const int region[4]);
extern void (*_84c95_delRegionOfText) (char text[20][81], int count, const int region[4]);
void appendString (char destinationStr[81],const char sourceStr[81], int place, char excessive[81]);
extern void (*_8eb83_appendString) (char destinationStr[81],const char sourceStr[81], int place, char excessive[81]);
void synonymString (const char synonymDictionary[20][2][31], int count, const char sourceStr[81], char resultStr[81]);
extern void (*_d9542_synonymString) (const char synonymDictionary[20][2][31], int count, const char sourceStr[81], char resultStr[81]);
int fixSpelling(const char dictionary[20][21], int count, char str[81]);
extern int (*_0a49d_fixSpelling)(const char dictionary[20][21], int count, char str[81]);
void divideString (const char divisionOfWords [20][2][31], int count, char str[81], int maxLength);
extern void (*_bb159_divideString) (const char divisionOfWords [20][2][31], int count, char str[81], int maxLength);
int insertEmptyString (char text[20][81], int count, int index);
extern int (*_d26a2_insertEmptyString) (char text[20][81], int count, int index);
int fillLettersAndNumbers(char text[20][81], int count, int locationWord1[2], int locationWord2[2]);
extern int (*_5ebf2_fillLettersAndNumbers)(char text[20][81], int count, int locationWord1[2], int locationWord2[2]);
int distanceBeetwenPhrases(const char text[20][81], int count, const char phrase1[41], const char phrase2[41]);
extern int (*_64dd0_distanceBeetwenPhrases)(const char text[20][81], int count, const char phrase1[41], const char phrase2[41]);
void cutString (char str[21], int max);
extern void (*_454fb_cutString) (char str[21], int max);

char * secure_strcat(char * dest, const char * src);
char * secure_strcpy(char * dest, const char * src);
#endif