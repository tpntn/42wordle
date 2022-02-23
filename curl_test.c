#include <stdio.h>
#include <string.h>


int	wcontains(char *word, char letter)
{
	while (*word)
	{
		if (*word == letter)
			return (1);
		word++;
	}
	return (0);
}

int	main()
{
	FILE	*file;
	char	*word;
	size_t	linecap = 5;
	ssize_t	line_len;
	file = fopen("wlist", "r");

	while ((line_len = getline(&word, &linecap, file)) > 0)
	{
		if (word[0] == 't' && wcontains(word,'e') && wcontains(word,'r'))
			printf("%s", word);
	}

	return (0);
}
