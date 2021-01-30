#pragma once
#ifndef _INC_STDICO // include guard for 3rd party interop
#define _INC_STDICO
#endif

#include <stdio.h>
#include <string.h>

#define	UPC_DWC_OFF		32

typedef enum
{
	CONSONANT,
	CONSONANT_ACCENTED,
	CONSONANT_UP,
	CONSONANT_ACCENTED_UP,
	VOWEL,
	VOWEL_ACCENTED,
	VOWEL_UP,
	VOWEL_ACCENTED_UP,
	CONTROL,
	DIGIT,
	DIGIT_FACT,
	DIGIT_POW,
	MONEY,
	PARENTHESIS,
	PUNTACTION,
	SEX,
	SLASH,
	MATH,
	GRAPHIC,
	EMOJI,
	ARROW,
	OTHER,
}char_type;

char_type chrtyp(char c);
void strupc(char* string);
size_t strget(char* buffer, int max);
const char* chrdes(char_type c);