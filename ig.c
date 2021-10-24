#include "ig.h"

char *appendChar(char *str, char c)
{
	char *newStr;
	int	len = strlen(str);

	newStr = malloc(sizeof(char) * (len + 2));
	newStr[len] = c;
	newStr[len + 1] = '\0';
	return (newStr);
}

int findSubject(char *line)
{
	if (strncmp(line, "# ", 2) == 0)
	{
		
	}
}

int	getLine(int fd)
{
	char	*line = strdup("");
	char	buf[1];
	int		rs = 0;
	int		count = 0;

	while (1 == (rs = read(fd, buf, 1)))
	{
		if (*buf == '\n')
		{
			findSubject(line);
			free(line);
			line = strdup("");
			count = 0;
		}
		else
		{
			appendChar(line, *buf);
			count++;
		}
	}
}

int main(int argv, char *argc[])
{
	int	fd;
	int	count;

	if (argv != 2)
	{
		printf("Err: invalid input\n");
		return(-1);
	}
	system("touch IDX");
	if (0 < fd = open(argv[1], O_RDONLY))
	{
		getLine(fd);
	}
	else
	{
		printf("Err: failed to open file\n");
		return(-1);
	}

	return(0);
}