#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdio.h>

/**
 * @brief Get the Username from uid
 * 
 * @param uid 
 * @return const char*
 */
const char *getUsername(uid_t uid)
{
	struct passwd *pw = getpwuid(uid);
	if (pw)
	{
		return pw->pw_name;
	}
	return "";
}

int main(int argc, char const *argv[])
{
    int fd;
	struct stat stats;

	if (argc < 2)
	{
		write(STDERR_FILENO, "Error! No paths given, please insert a pathname!\n", 49);
		return 0;
	}
	
	for (int i = 1; i < argc; i++)
	{
		fd = stat(argv[i], &stats);
		printf("\n%s:\n", argv[i]);
		if (fd == -1)
		{
			write(STDERR_FILENO, "Error! Path ", 13);
			write(STDERR_FILENO, argv[i], strlen(argv[i]));
			write(STDERR_FILENO, " not found!\n", 13);	
		}
		else
		{	
			printf("File type:\t\t");
			switch (stats.st_mode & S_IFMT)
			{
				case S_IFBLK:
					printf("block device\n");
					break;
				case S_IFCHR:
					printf("character device\n");
					break;
				case S_IFDIR:
					printf("directory\n");
					break;
				case S_IFIFO:
					printf("FIFO/pipe\n");
					break;
				case S_IFLNK:
					printf("symlink\n");
					break;
				case S_IFREG:
					printf("regular file\n");
					break;
				case S_IFSOCK:
					printf("socket\n");
					break;
				default:
					printf("unknown?\n");
					break;
			}

			printf("I-node number:\t\t%ld\n", (long) stats.st_ino);
			printf("Ownership: %s\t\tUID: %ld   GID: %ld\n", getUsername(stats.st_uid), (long) stats.st_uid, (long) stats.st_gid);
			printf("Last status change:\t\t%s", ctime(&stats.st_ctime));
			printf("Last file access:\t\t%s", ctime(&stats.st_atime));
			printf("Last file modification:\t\t%s", ctime(&stats.st_mtime));
		
		}	close(fd);
	}

    return 0;
}
