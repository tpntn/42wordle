#include <stdio.h>
#include <string.h>


int	wcontains(char *word, char letter, int *w_location)
{
	int i = 0;

	while (word[i])
	{
		if (*w_location == i)
		{
			w_location++;
			i++;
		}
		else if (word[i] == letter)
			return (1);
		else
			i++;
	}
	return (0);
}	

int exclude_char(char *cha, char *word)
{
	int i = 0;
	int c;
	while (word[i])
	{
		c = 0;
		while (cha[c])
		{
			if(word[i] == cha[c])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}

int	main()
{
	FILE	*file;
	char	*word;
	size_t	linecap = 5;
	ssize_t	line_len;
	file = fopen("wlist", "r");
	int e[] = {1,2,3};
	int r[] = {2,4};
	char *exc = "unmsaibc";

	while ((line_len = getline(&word, &linecap, file)) > 0)
	{
		if (exclude_char(exc, word) && word[1] == 'r' &&  word[0] == 't' && wcontains(word,'e',e) && wcontains(word,'r',r))
			printf("%s", word);
	}

	return (0);
}
