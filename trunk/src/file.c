/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://gplv3.fsf.org/> */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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

char* file_path(const char* filename)
{
	int ct = strlen(filename)-1; // last character
	char sl = '/'; // TODO - define '\' in win32

	while(filename[ct] != sl)
	{
		ct--;
		if(ct == 0) // not found
			return ".";
	}

	char* s = malloc(ct+1);
	strncpy(s, filename, ct);
	s[ct+1] = '\0';

	return s;
}
