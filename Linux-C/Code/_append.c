#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int source, dest;
	char buffer;
	char filename[200];

	if ((argc < 3) && ((argc-1) % 2 != 0))
	{
		write(STDERR_FILENO, "Error! You should give at least 2 filenames or an even number of filenames!\n", 76);
		return 0;
	}

	for (int i = 1; i < argc; i = i + 2)
	{
		source = open(argv[i], O_RDONLY);
		dest = open(argv[i + 1], O_WRONLY | O_APPEND);
		if (source == -1)
		{
			write(STDERR_FILENO, "Error! File ", 13);
			write(STDERR_FILENO, argv[i], strlen(argv[i]));
			write(STDERR_FILENO, " not found!\n", 13);
			close(source);
			continue;
		} 
		if (dest == -1)
		{
			write(STDERR_FILENO, "Error! File ", 13);
			write(STDERR_FILENO, argv[i + 1], strlen(argv[i + 1]));
			write(STDERR_FILENO, " not found!\n", 13);
			close(dest);
			continue;
		}

		while(read(source, &buffer, 1))
		{
			write(dest, &buffer, 1);
		}

		write(STDOUT_FILENO, "File ", 5);
		write(STDOUT_FILENO, argv[i + 1], strlen(argv[i + 1]));
		write(STDOUT_FILENO, " modified successfully!\n", 24);
		close(source);
		close(dest);
	}

	return 0;
}

