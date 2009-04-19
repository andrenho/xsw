/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"

static void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: xsw [options] FILE\n");
	fprintf(stream, "Start a presentation.\n");
	fprintf(stream, "\n");
	fprintf(stream, "Basic options:\n");
	fprintf(stream, "  -I, --intro         display a introduction about what xsw is and how it works\n");
	fprintf(stream, "  -h, --help          see this help\n");
	fprintf(stream, "  -v, --version       show version\n");
	fprintf(stream, "\n");
	fprintf(stream, "User options:\n");
	fprintf(stream, "  -f, --fullscreen    start presentation in fullscreen\n");
	fprintf(stream, "\n");
	fprintf(stream, "Developer options:\n");
	fprintf(stream, "  -d, --developer     developer mode\n");
	fprintf(stream, "  -l, --last          start at the last slide\n");
	exit(exit_code);
}

static void print_version(FILE* stream, int exit_code)
{
	fprintf(stream, "xsw " VERSION ", a slideshow presentation tool.\n");
	fprintf(stream, "xsw is free software.\n");
	fprintf(stream, "Copyleft (C) 2009 André Wagner <andre.nho@gmail.com> - all wrongs reserved\n");
	exit(exit_code);
}

Options* options_get(Presentation* presentation, int argc, char* argv[])
{
	int next_option;

	Options* options = malloc(sizeof(Options));
	options->last = 0;
	options->developer = 0;
	options->fullscreen = 0;

	const char* const short_options = "hldvIf";
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "version", 0, NULL, 'v' },
		{ "last", 0, NULL, 'l' },
		{ "developer", 0, NULL, 'd' },
		{ "intro", 0, NULL, 'I' },
		{ "fullscreen", 0, NULL, 'f' },
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
			case 'v':
				print_version(stdout, 0);
				break;
			case '?':
				print_usage(stderr, 1);
				break;
			case 'I':
				presentation->filename = DATADIR "intro/xsw.xsw";
				break;
			case 'f':
				options->fullscreen = 1;
				break;
			case -1: // done
				break;
			default:
				abort();
		}
	} while (next_option != -1);

	if(!presentation->filename)
	{
		if(argc > optind)
			presentation->filename = argv[optind];
		else
			print_usage(stderr, 1);
	}

	return options;
}
