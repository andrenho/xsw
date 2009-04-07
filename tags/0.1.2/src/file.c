#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "file.h"

int file_exists(const char* filename)
{
	int fd;
	struct stat file_info;
	int exists = 1;

	fd = open(filename, O_RDONLY);

	fstat(fd, &file_info);

	if(!S_ISREG(file_info.st_mode))
		exists = 0;

	close(fd);
	return exists;
}
