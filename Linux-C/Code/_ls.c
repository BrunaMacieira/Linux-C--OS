#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd;
    DIR *dir;
	struct dirent *dent;
    char ftype[50];

	if (argc < 2)
	{
        dir = opendir("./");
		while ((dent = readdir(dir)) != NULL)
        {   
            switch (dent->d_type)
            {
            case DT_BLK:
                strcpy(ftype, "Block Device");
                break;
            case DT_CHR:
                strcpy(ftype, "Character Device");
                break;
            case DT_DIR:
                strcpy(ftype, "Directory");
                break;
            case DT_FIFO:
                strcpy(ftype, "FIFO/pipe");
                break;
            case DT_LNK:
                strcpy(ftype, "Symlink");
                break;
            case DT_REG:
                strcpy(ftype, "Regular File");
                break;
            case DT_SOCK:
                strcpy(ftype, "Socket");
                break;
            default:
                strcpy(ftype, "Unknown Type");
                break;
            }
            printf("%-30s%30s\n", dent->d_name, ftype);
        
            
		}	closedir(dir);
	}
	
	for (int i = 1; i < argc; i++)
	{
		dir = opendir(argv[i]);
		printf("\n%s:\n", argv[i]);
		if (dir == NULL)
		{
            printf("Error! Path %s not found!\n", argv[i]);
            break; // Break to not execute closedir(dir); because there's not any open dir and it could cause segmentation fault
		}
		else
		{	
			while ((dent = readdir(dir)) != NULL)
            {   
                switch (dent->d_type)
                {
                case DT_BLK:
                    strcpy(ftype, "Block Device");
                    break;
                case DT_CHR:
                    strcpy(ftype, "Character Device");
                    break;
                case DT_DIR:
                    strcpy(ftype, "Directory");
                    break;
                case DT_FIFO:
                    strcpy(ftype, "FIFO/pipe");
                    break;
                case DT_LNK:
                    strcpy(ftype, "Symlink");
                    break;
                case DT_REG:
                    strcpy(ftype, "Regular File");
                    break;
                case DT_SOCK:
                    strcpy(ftype, "Socket");
                    break;
                default:
                    strcpy(ftype, "Unknown Type");
                    break;
                }
                printf("%-70s%20s\n", dent->d_name, ftype);
            }
            
		}	closedir(dir);
	}

    return 0;
}
