#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int source, dest;
	char buffer;
	char filename[200];

	if (argc < 2 )
	{
		write(STDERR_FILENO, "Error! No files given, please insert filename! \n", 49);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{	
		source = open(argv[i], O_RDONLY);
	
		if (source == -1)
		{
			write(STDERR_FILENO, "Error! File ", 13);
		    write(STDERR_FILENO, argv[i], strlen(argv[i]));
			write(STDERR_FILENO, " not found!\n", 13);	
		}
		else
		{
			strcpy(filename, argv[i]);
			strcat(filename, ".copia");
			dest = open(filename, O_CREAT | O_TRUNC | O_WRONLY | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			while(read(source, &buffer, 1))
			{
				write(dest, &buffer, 1);
			}

			write(STDOUT_FILENO, "File ", 5);
			write(STDOUT_FILENO, argv[i], strlen(argv[i]));
			write(STDOUT_FILENO, " copied successfully!\n", 22);
			close(source);
			close(dest);
		}
	}


	return 0;
}
