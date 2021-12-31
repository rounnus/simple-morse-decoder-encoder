#include <stdio.h>
#include <stdlib.h>
#include <morse.h>
#include <string.h>



void encode_morse(const char *ascii_text)
{
	printf("' %s ' is equal to ' ", ascii_text);

	char tmp[2];
	memset(tmp, 0x0, 2);

	struct morse_code *curr_morse_code = NULL;
	for (int ch = 0; ch < strlen(ascii_text); ch++)
	{
		tmp[0] = ascii_text[ch];
		curr_morse_code = get_morse_code(tmp, 0x0);
		if (curr_morse_code == NULL)
		{
			printf("\nFailed to decode the input sequence.\n");
			exit(0);
		}
		// Print the morse of the current character.
		printf("%s ", curr_morse_code->m_code);
	}
	printf("'\n");
}
