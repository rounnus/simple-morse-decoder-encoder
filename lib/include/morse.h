#ifndef SIMPLE_MORSE_DECODER_ENCODER_MORSE_H 
#define SIMPLE_MORSE_DECODER_ENCODER_MORSE_H

#include <string.h>
#include <stdio.h>

// Morse,
struct morse_code {
	char *m_text;
	char *m_code;
};

// Define all the morse texts and codes.
#define MORSE_CODES_LEN 37
// Real 53

static const struct morse_code morse_codes[MORSE_CODES_LEN] =
{
		{.m_text = "A", .m_code = ".-"   },
		{.m_text = "B", .m_code = "-..." },
		{.m_text = "C", .m_code = "-.-." },
		{.m_text = "D", .m_code = "-.."  },
		{.m_text = "E", .m_code = "."	 },
		{.m_text = "F", .m_code = "..-." },
		{.m_text = "G", .m_code = "--."  },
		{.m_text = "H", .m_code = "...." },
		{.m_text = "I", .m_code = ".."   },
		{.m_text = "J", .m_code = ".---" },
		{.m_text = "K", .m_code = "-.-"  },
		{.m_text = "L", .m_code = ".-.." },
		{.m_text = "M", .m_code = "--"   },
		{.m_text = "N", .m_code = "-."   },
		{.m_text = "O", .m_code = "---"  },
		{.m_text = "P", .m_code = ".--." },
		{.m_text = "Q", .m_code = "--.-" },
		{.m_text = "R", .m_code = ".-."  },
		{.m_text = "S", .m_code = "..."  },
		{.m_text = "T", .m_code = "-"	 },
		{.m_text = "U", .m_code = "..-"  },
		{.m_text = "V", .m_code = "...-" },
		{.m_text = "W", .m_code = ".--"  },
		{.m_text = "X", .m_code = "-..-" },
		{.m_text = "Y", .m_code = "-.--" },
		{.m_text = "Z", .m_code = "--.." },
		{.m_text = "0", .m_code = "-----"},
		{.m_text = "1", .m_code = ".----"},
		{.m_text = "2", .m_code = "..---"},
		{.m_text = "3", .m_code = "...--"},
		{.m_text = "4", .m_code = "....-"},
		{.m_text = "5", .m_code = "....."},
		{.m_text = "6", .m_code = "-...."},
		{.m_text = "7", .m_code = "--..."},
		{.m_text = "8", .m_code = "---.."},
		{.m_text = "9", .m_code = "----."},
		{.m_code = "/", .m_code = "-..-."},
		// TODO - All the numbers and special characters.
};

/**
 *	Search for the morse sequence or for the character
 *	that represent by a sequence.
 *	@param search The morse sequence or the text.
 *	@param is_decode Choice if the operation is decode or encode.
 *	@return A pointer to the coresponded morse code struct witch
 *	cointains the informations about the current morse sequence
 *	and the character that is equal to.
 */
static inline struct morse_code *get_morse_code(const char *search,
												int is_decode)
{
	for (int code = 0; code < MORSE_CODES_LEN; code++)
	{
		if (is_decode)
		{
			if (!strcmp(morse_codes[code].m_code, search))
				return (struct morse_code *) &morse_codes[code];
		}
		else 
		{
			if (!strcmp(morse_codes[code].m_text, search))
				return (struct morse_code *) &morse_codes[code];
		}
	}

	return NULL;
}


#endif
