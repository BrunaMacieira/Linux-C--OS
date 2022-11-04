#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd, len;
	char buffer;
	

	if (argc < 2)
	{
		write(STDERR_FILENO, "Error! No files given, please insert a filename!\n", 49);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(STDERR_FILENO, "Error! File ", 13);
		    write(STDERR_FILENO, argv[i], strlen(argv[i]));
			write(STDERR_FILENO, " not found!\n", 13);	
		}
		else
		{	
			write(STDOUT_FILENO, argv[i], strlen(argv[i]));
			write(STDOUT_FILENO, ":\n", 2);
			while(read(fd, &buffer, 1))
			{
				write(STDOUT_FILENO, &buffer, 1);
			}
			write(STDOUT_FILENO, "\n", 1);
		}
	}	close(fd);
	return 0;
}
