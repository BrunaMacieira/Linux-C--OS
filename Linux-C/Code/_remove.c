#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd, len;
	char content[300];
	

	if (argc < 2)
	{
		write(STDERR_FILENO, "Error! No files given, please insert a filename!\n", 49);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		fd = access(argv[i], F_OK);
		if (fd == -1)
		{
			write(STDERR_FILENO, "Error! File ", 13);
		    write(STDERR_FILENO, argv[i], strlen(argv[i]));
			write(STDERR_FILENO, " not found!\n", 13);	
		}
		else
		{	
			unlink(argv[i]);
			write(STDOUT_FILENO, content, len);
            write(STDOUT_FILENO, "File ", 5);
		    write(STDOUT_FILENO, argv[i], strlen(argv[i]));
			write(STDOUT_FILENO, " removed successfully!\n", 23);
		}
	}	close(fd);

    return 0;
}
