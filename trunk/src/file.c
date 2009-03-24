#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "file.h"

char* file_read(const char* filename)
{
	int fd;
	char* buffer;
	struct stat file_info;
	size_t length;

	fd = open(filename, O_RDONLY);

	fstat(fd, &file_info);
	length = file_info.st_size + 1;

	if(!S_ISREG(file_info.st_mode))
	{
		close(fd);
		fprintf(stderr, "%s: File not found.\n", filename);
		exit(1);
	}

	buffer = (char*)malloc(length);
	read(fd, buffer, length);

	close(fd);

	buffer[length] = '\0';
	return buffer;
}
