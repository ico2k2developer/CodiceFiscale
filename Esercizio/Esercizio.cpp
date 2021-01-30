#include <stdio.h>
#include <stdlib.h>
#include "ico2k2.h"


#define	MIN_SUR			3
#define	IGN_SUR			0
#define	COUNT_SUR		MIN_SUR + IGN_SUR
#define	MIN_NAME		3
#define	IGN_NAME		1
#define	COUNT_NAME		MIN_NAME + IGN_NAME
#define	MIN_NAMES		MIN_SUR + MIN_NAME
#define	MIN_YEAR		2
#define	MIN_MONTH		1
#define	MIN_DAY			2
#define	MIN_CODE		4
#define	MIN_CHECK		1
#define	START_SUR		0
#define	STOP_SUR		START_SUR + MIN_SUR
#define	START_NAME		STOP_SUR
#define	STOP_NAME		START_NAME + MIN_NAME
#define	START_YEAR		STOP_NAME
#define	STOP_YEAR		START_YEAR + MIN_YEAR
#define	START_MONTH		STOP_YEAR
#define	STOP_MONTH		START_MONTH + MIN_MONTH
#define	START_DAY		STOP_MONTH
#define	STOP_DAY		START_DAY + MIN_DAY
#define	START_CODE		STOP_DAY
#define	STOP_CODE		START_CODE + MIN_CODE
#define	START_CHECK		STOP_CODE
#define	STOP_CHECK		START_CHECK + MIN_CHECK

#define	DAY_MAX			31
#define DAY_MIN			1
#define MONTH_MAX		12
#define MONTH_MIN		1

#define	SIZE_BUF		50	+ 1
#define	SIZE_CODE		STOP_CHECK + 1

#define MONTHS			"ABCDEHLMPRST"

#define CHAR_FILL		'X'

#define FILE_TOWNS		"data.txt"

int main(int argc,char** argv)
{
	unsigned char i, l, a;
	long int ll;
	char_type t;
	char *buffer,*result;
	buffer = (char*)malloc(sizeof(char) * SIZE_BUF);
	result = (char*)malloc(sizeof(char) * SIZE_CODE);
	if (!buffer || !result)
		return 1;
	memset(result, 0, sizeof(char) * SIZE_CODE);

	printf("Nome: ");
	strget(buffer, SIZE_BUF);
	strupc(buffer);

	l = START_NAME;
	for (i = a = 0; buffer[i] != NULL && a < COUNT_NAME; i++)
	{
		t = chrtyp(buffer[i]);
		if (t & CONSONANT)
		{
			if (a != 1)
				result[l++] = buffer[i];
			a++;
		}
	}
	if (a <= 1)
		a++;
	for (i = 0; buffer[i] != NULL && a < COUNT_NAME; i++)
	{
		t = chrtyp(buffer[i]);
		if (t & VOWEL)
		{
			result[l++] = buffer[i];
			a++;
		}
	}
	while (a++ < COUNT_NAME)
		result[l++] = CHAR_FILL;

	printf("Cognome: ");
	strget(buffer, SIZE_BUF);
	strupc(buffer);

	l = START_SUR;
	for (i = l = 0; buffer[i] != NULL && l < START_SUR + COUNT_SUR; i++)
	{
		t = chrtyp(buffer[i]);
		if (t & CONSONANT)
		{
			result[l++] = buffer[i];
		}
	}
	for (i = 0; buffer[i] != NULL && l < START_SUR + COUNT_SUR; i++)
	{
		t = chrtyp(buffer[i]);
		if (t & VOWEL)
		{
			result[l++] = buffer[i];
		}
	}
	while (l < START_SUR + COUNT_SUR)
		result[l++] = CHAR_FILL;
	l = 1;
	while (l == 1)
	{
		printf("Inserisci il sesso (m o f): ");
		strget(buffer, SIZE_BUF);
		switch (buffer[0])
		{
			case 'M':
			case 'm':
			{
				l = 0;
				break;
			}
			case 'F':
			case 'f':
			{
				l = 40;
				break;
			}
			default:
			{
				printf("Valore non valido\n");
			}
		}
	}

	do
	{
		printf("Inserisci il giorno di nascita (in cifre): ");
		strget(buffer, SIZE_BUF);
		ll = (long int)atoi(buffer);
		if (DAY_MIN <= ll && DAY_MAX >= ll)
		{
			a = true;
			if (ll + l < 10)
				sprintf_s(result + START_DAY, MIN_DAY + 1, "0%i", (int)ll + l);
			else
				sprintf_s(result + START_DAY, MIN_DAY + 1, "%i", (int)ll + l);
		}
		else
		{
			printf("Valore non valido\n");
			a = false;
		}
	}
	while (!a);

	do
	{
		printf("Inserisci il mese di nascita (in cifre): ");
		strget(buffer, SIZE_BUF);
		ll = (long int)atoi(buffer);
		if (MONTH_MIN <= ll && MONTH_MAX >= ll)
		{
			a = true;
			result[START_MONTH] = MONTHS[ll - 1];
		}
		else
		{
			printf("Valore non valido\n");
			a = false;
		}
	}
	while (!a);

	printf("Inserisci l\'anno di nascita (in cifre): ");
	strget(buffer, SIZE_BUF);
	a = (unsigned char)strlen(buffer);
	if (a > 2)
		a = a - 2 - 1;
	else
		a = 0;
	ll = (long int)atoi(buffer + a);
	if (ll < 10)
		result[START_YEAR] = '0';
	else
		result[START_YEAR] = buffer[a];
	result[START_YEAR + 1] = buffer[a + 1];

	FILE* f;
	if (argc > 1)
		fopen_s(&f, argv[1], "r");
	else
		f = NULL;
	if(!f)
		fopen_s(&f, FILE_TOWNS, "r");
	if (f)
	{
		do
		{
			printf("Inserisci il nome del comune di appartenenza: ");
			strget(buffer + 1, SIZE_BUF);
			buffer[0] = ':';
			strupc(buffer);
			ll = ffind(f, buffer, strlen(buffer));
			if (a = (ll != EOF))
			{
				fseek(f, ll - 1, SEEK_SET);
				l = 0;
				do
				{
					ll = fgetc(f);
					fseek(f, ftell(f) - 2, SEEK_SET);
					l++;
				}
				while (ll != EOF && ll != '\n');
				fseek(f, ftell(f) + 2, SEEK_SET);
				fgets(result + START_CODE, l, f);
			}
			else
				printf("Comune non trovato\n");
		}
		while (!a);
		fclose(f);
	}
	else
	{
		printf("File comuni non trovato: impossibile completare il campo relativo\n");
		for (i = START_CODE; i < STOP_CODE; i++)
			result[i] = '_';
	}
	free(buffer);

	result[START_CHECK] = fisc_check(result,SIZE_CODE);

	printf("Codice fiscale: %s\n", result);
	
	free(result);
	return 0;
}