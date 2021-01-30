#include "stdico.h"

char_type chrtyp(char c)
{
	char_type result = OTHER;
	switch (c)
	{
		case -127:
		case -126:
		case -125:
		case -124:
		case -123:
		case -122:
		case -120:
		case -119:
		case -118:
		case -117:
		case -116:
		case -115:
		case -111:
		case -109:
		case -108:
		case -107:
		case -106:
		case -105:
		case -101:
		case -96:
		case -95:
		case -94:
		case -93:
		case -58:
		case -43:
		case -28:
		{
			result = VOWEL_ACCENTED;
			break;
		}
		case -121:
		case -104:
		case -92:
		case -26:
		case -20:
		{
			result = CONSONANT_ACCENTED;
			break;
		}
		case -114:
		case -113:
		case -112:
		case -110:
		case -103:
		case -102:
		case -99:
		case -75:
		case -74:
		case -73:
		case -57:
		case -46:
		case -45:
		case -44:
		case -42:
		case -41:
		case -40:
		case -34:
		case -32:
		case -30:
		case -29:
		case -27:
		case -23:
		case -22:
		case -21:
		{
			result = VOWEL_ACCENTED_UP;
			break;
		}
		case -128:
		case -91:
		case -47:
		case -19:
		{
			result = CONSONANT_ACCENTED_UP;
			break;
		}
		case -86:
		case -80:
		case -79:
		case -78:
		case -77:
		case -76:
		case -2:
		{
			result = GRAPHIC;
			break;
		}
		case -85:
		case -84:
		case -13:
		{
			result = DIGIT_FACT;
			break;
		}
		case 97:
		case 101:
		case 105:
		case 111:
		case 117:
		{
			result = VOWEL;
			break;
		}
		case 65:
		case 69:
		case 73:
		case 79:
		case 85:
		{
			result = VOWEL_UP;
			break;
		}
		case -100:
		case -67:
		case -66:
		case 36:
		{
			result = MONEY;
			break;
		}
		case -98:
		case -97:
		case -16:
		case -15:
		case -10:
		case 37:
		case 43:
		case 60:
		case 61:
		case 62:
		case 126:
		{
			result = MATH;
			break;
		}
		case -90:
		case -89:
		case -88:
		case -87:
		case -83:
		case -82:
		case -81:
		case -72:
		case -17:
		case -9:
		case -6:
		case 19:
		case 32:
		case 33:
		case 34:
		case 39:
		case 42:
		case 44:
		case 45:
		case 46:
		case 58:
		case 59:
		case 63:
		case 94:
		case 96:
		{
			result = PUNTACTION;
			break;
		}
		case -1:
		case 0:
		case 9:
		case 10:
		{
			result = CONTROL;
			break;
		}
		case 11:
		case 12:
		{
			result = SEX;
			break;
		}
		case 14:
		case 15:
		{
			result = EMOJI;
			break;
		}
		case 16:
		case 17:
		{
			result = ARROW;
			break;
		}
		case 40:
		case 41:
		case 91:
		case 93:
		case 123:
		case 125:
		{
			result = PARENTHESIS;
			break;
		}
		case 47:
		case 92:
		{
			result = SLASH;
			break;
		}
		default:
		{
			if (c >= 'A' && c <= 'Z')
				result = CONSONANT_UP;
			else if (c >= 'a' && c <= 'z')
				result = CONSONANT;
			else if (c >= '0' && c <= '9')
				result = DIGIT;
			else if ((c >= -71 && c <= -50) || (c >= -39 && c <= -33))
				result = GRAPHIC;
			else if (c >= 1 && c <= 6)
				result = EMOJI;
			else if (c >= 23 && c <= 31)
				result = EMOJI;
			else if (c >= -5 && c <= -3)
				result = DIGIT_POW;
		}
	}
	return result;
}

size_t strget(char* buffer, int max)
{
	fgets(buffer, max, stdin);
	size_t length = strlen(buffer);
	if (buffer[length - 1] == '\n')
		buffer[length - 1] = '\0';
	return length;
}

void strupc(char* string)
{
	int i;
	char c;
	for (i = 0; (c = string[i]) != '\0'; i++)
	{
		switch (chrtyp(c))
		{
			case VOWEL:
			case CONSONANT:
			{
				c -= UPC_DWC_OFF;
				break;
			}
			case VOWEL_ACCENTED:
			{

				break;
			}
			case CONSONANT_ACCENTED:
			{

				break;
			}
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c - UPC_DWC_OFF;
		}
		else
		{
			switch (string[i])
			{
				case -123:
				{
					c = -73;
					break;
				}
				case -118:
				{
					c = -44;
					break;
				}
				case -115:
				{
					c = -34;
					break;
				}
				case -107:
				{
					c = -29;
					break;
				}
				case -105:
				{
					c = -21;
					break;
				}
				case -96:
				{
					c = -75;
					break;
				}
				case -126:
				{
					c = -112;
					break;
				}
				case -95:
				{
					c = -42;
					break;
				}
				case -94:
				{
					c = -32;
					break;
				}
				case -93:
				{
					c = -23;
					break;
				}
				case -128:
				{
					c = -121;
					break;
				}
				case -127:
				{
					c = -102;
					break;
				}
				case -125:
				{
					c = -74;
					break;
				}
				case -124:
				{
					c = -114;
					break;
				}
				case -122:
				{
					c = -113;
					break;
				}
				case -120:
				{
					c = -46;
					break;
				}
				case -119:
				{
					c = -45;
					break;
				}
				case -117:
				{
					c = -40;
					break;
				}
				case -116:
				{
					c = -41;
					break;
				}
				case -111:
				{
					c = -110;
					break;
				}
				case -109:
				{
					c = -30;
					break;
				}
				case -108:
				{
					c = -103;
					break;
				}
				case -106:
				{
					c = -22;
					break;
				}
				case -101:
				{
					c = -99;
					break;
				}
				case -58:
				{
					c = -57;
					break;
				}
				case -20:
				{
					c = -19;
					break;
				}
				default:
				{
					c = (char)NULL;
				}
			}
		}
		if (c)
		{
			string[i] = c;
		}
	}
}

const char* chrdes(char_type c)
{
	const char* result;
	switch (c)
	{
		case VOWEL:
		{
			result = "vocale minuscola";
			break;
		}
		case VOWEL_UP:
		{
			result = "vocale maiuscola";
			break;
		}
		case VOWEL_ACCENTED:
		{
			result = "vocale minuscola accentata o speciale";
			break;
		}
		case VOWEL_ACCENTED_UP:
		{
			result = "vocale maiuscola accentata o speciale";
			break;
		}
		case CONSONANT:
		{
			result = "consonante minuscola";
			break;
		}
		case CONSONANT_UP:
		{
			result = "consonante maiuscola";
			break;
		}
		case CONSONANT_ACCENTED:
		{
			result = "consonante minuscola accentata o speciale";
			break;
		}
		case CONSONANT_ACCENTED_UP:
		{
			result = "consonante maiuscola accentata o speciale";
			break;
		}
		case DIGIT:
		{
			result = "cifra";
			break;
		}
		case DIGIT_FACT:
		{
			result = "frazione";
			break;
		}
		case DIGIT_POW:
		{
			result = "potenza";
			break;
		}
		case MONEY:
		{
			result = "valuta";
			break;
		}
		case PARENTHESIS:
		{
			result = "parentesi";
			break;
		}
		case PUNTACTION:
		{
			result = "punteggiatura";
			break;
		}
		case SEX:
		{
			result = "sesso";
			break;
		}
		case SLASH:
		{
			result = "barra";
			break;
		}
		case MATH:
		{
			result = "simbolo matemetico";
			break;
		}
		case GRAPHIC:
		{
			result = "carattere grafico";
			break;
		}
		case EMOJI:
		{
			result = "emoji";
			break;
		}
		case ARROW:
		{
			result = "indicatore";
			break;
		}
		case CONTROL:
		{
			result = "carattere di controllo";
			break;
		}
		default:
		{
			result = "carattere non classificato";
		}
	}
	return result;
}