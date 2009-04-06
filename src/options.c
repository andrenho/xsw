#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"

static void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: xsw [options] FILE\n");
	fprintf(stream, "Start a presentation.\n");
	fprintf(stream, "\n");
	fprintf(stream, "Options:\n");
	fprintf(stream, "  -h, --help               see this help\n");
	fprintf(stream, "  -d, --developer          developer mode\n");
	fprintf(stream, "  -l, --last               start at the last slide\n");
	exit(exit_code);
}

Options* options_get(Presentation* presentation, int argc, char* argv[])
{
	int next_option;

	Options* options = malloc(sizeof(Options));
	options->last = 0;
	options->developer = 0;

	const char* const short_options = "hld";
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "last", 0, NULL, 'l' },
		{ "developer", 0, NULL, 'd' },
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
			case 'l':
				options->last = 1;
				break;
			case 'd':
				options->developer = 1;
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

	return options;
}
