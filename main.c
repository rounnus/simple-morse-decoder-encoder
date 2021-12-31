#include <stdio.h>
#include <decoder.h>
#include <encoder.h>
#include <stdlib.h>
#include <string.h>

/**
 * @reference https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
 */
char *get_user_input(FILE *stream, 
					 size_t init_size)
{
	char *input = NULL;
	int curr_ch;
	size_t curr_len = 0;

	// Allocate space for init_size characters.
	input = calloc(init_size, sizeof(char));
	if (input == NULL)
		return NULL;

	while ( (curr_ch = fgetc(stream)) != EOF 
			&& curr_ch != '\n')
	{
		input[curr_len++] = curr_ch;
		if (curr_len == init_size)
		{
			input = realloc(input, sizeof(char) * (init_size += 10));
		}
	}
	input[curr_len++] = '\0';

	// Decreace the memory to the exac size of string.
	return realloc(input, sizeof(char) * curr_len);
}



int main(void) 
{
	char *input = NULL;
	int choice = 0;

	printf("Enter [1] to decode [2] to encode\n\n");
	printf("Choice[]: ");

	input = get_user_input(stdin, 2);
	if (input == NULL)
	{
		printf("Failed to read input.");
		return -1;
	}

	if (strcmp(input, "1") && strcmp(input, "2"))
	{
		printf("Wrong choice.\n");
		free(input);
		return 0;
	}

	printf("Enter: ");
	
	if (!strcmp(input, "1")) choice = 1;
	else choice = 2;

	free(input);
	input = get_user_input(stdin, 20);
	if (input == NULL)
	{
		printf("Failed to read input.");
		return -1;
	}
	
	if (choice == 1) decode_morse(input);
	else encode_morse(input);


	free(input);

	return 0;
}
