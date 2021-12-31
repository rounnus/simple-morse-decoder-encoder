#ifndef SIMPLE_MORSE_DECODER_ENCODER_MORSE_H 
#define SIMPLE_MORSE_DECODER_ENCODER_MORSE_H

#include <string.h>

// Morse,
struct morse_code {
	char *m_text;
	char *m_code;
};

// Define all the morse texts and codes.
#define MORSE_CODES_LEN 28
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
		{.m_text = "0", .m_code = ".----"},
		{.m_text = "1", .m_code = "..---"}
		// TODO - All the numbers and special characters.
};

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
