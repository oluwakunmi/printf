#include "main.h"

/**
 * getFlags - Get flags from format string
 * @fmt: Input format string
 * @index: Pointer to current index
 * Return: Integer representing flags
 */
int getFlags(const char *fmt, int *index)
{
	int flag = 0;
	int curr_index, char_index;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_index = *index + 1; fmt[curr_index] != '\0'; curr_index++)
	{
		for (char_index = 0; FLAGS_CH[char_index] != '\0'; char_index++)
		{
			if (fmt[curr_index] == FLAGS_CH[char_index])
			{
				flag |= FLAGS_ARR[char_index];
				break;
			}
		}

		if (FLAGS_CH[char_index] == 0)
			break;
	}

	*index = curr_index - 1;

	return (flag);
}

