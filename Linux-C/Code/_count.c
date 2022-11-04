#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd;
    int counter = 0;
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
			printf("Error! File %s not found!\n", argv[i]);
			// write(STDERR_FILENO, "Error! File ", 13);
		    // write(STDERR_FILENO, argv[i], strlen(argv[i]));
			// write(STDERR_FILENO, " not found!\n", 13);	
		}
		else
		{	
			while(read(fd, &buffer, 1))
		    {
			    if (buffer == '\n')
                    counter++;
		    }

            printf("%d line(s) counted on file: %s\n", counter, argv[i]);
			
            counter = 0;
		}
	}	close(fd);
	return 0;
}
