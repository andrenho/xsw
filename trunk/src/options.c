#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"

static void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: presenter [options] FILE\n");
	fprintf(stream, "Start a presentation.\n");
	exit(exit_code);
}

void options_get(Presentation* presentation, int argc, char* argv[])
{
	int next_option;

	const char* const short_options = "h";
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ NULL, 0, NULL, 0 }
	};
	
	do 
	{
		next_option = getopt_long(argc, argv, short_options, 
				long_options, NULL);
		switch(next_option)
		{
			case 'h':
				print_usage(stdout, 0);
				break;
			case '?':
				print_usage(stderr, 1);
				break;
			case -1: // done
				break;
			default:
				abort();
		}
	} while (next_option != -1);

	if(argc > optind)
		presentation->filename = argv[optind];
	else
		print_usage(stderr, 1);
}
