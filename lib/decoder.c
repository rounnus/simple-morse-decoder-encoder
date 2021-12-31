#include <morse.h>
#include <decoder.h>
#include <stdlib.h>




void decode_morse(const char *morse_seq)
{
	printf("'%s' is equal to '", morse_seq);
	// Don't change the source char *.
	char tmp[strlen(morse_seq)];
	strcpy(tmp, morse_seq);

	// Get each morse sequence.
	char *curr_morse_seq = strtok(tmp, " ");	
	struct morse_code *curr_morse_code = NULL;

	while (curr_morse_seq)
	{
		curr_morse_code = get_morse_code(curr_morse_seq, 1);
		if (curr_morse_code == NULL)
		{
			printf("Failed to decode the input sequence.");
			exit(0);
		}
		// Print the decoded character.
		printf("%s", curr_morse_code->m_text);

		curr_morse_seq = strtok(NULL, " ");	
	}

	printf("'\n");
}
