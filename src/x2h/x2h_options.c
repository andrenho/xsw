/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "x2h_options.h"

static void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: xsw2html [options] XSW_FILE\n");
	fprintf(stream, "Start a presentation.\n");
	fprintf(stream, "\n");
	fprintf(stream, "Options:\n");
	fprintf(stream, "  -h, --help              see this help\n");
	fprintf(stream, "  -v, --version           show version\n");
	fprintf(stream, "  -t, --template [FILE]   choose HTML template\n");
	exit(exit_code);
}

static void print_version(FILE* stream, int exit_code)
{
	fprintf(stream, "xsw2html " VERSION ", a program that converts xsw presentations to HTML.\n");
	fprintf(stream, "xsw2html is free software.\n");
	fprintf(stream, "Copyleft (C) 2009 André Wagner <andre.nho@gmail.com> - all wrongs reserved\n");
	exit(exit_code);
}

Options* options_get(Presentation* p, int argc, char* argv[])
{
	int next_opt;
	Options* opt = malloc(sizeof(Options));
	if (opt == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	opt->html_template = NULL;

	const char* const short_options = "t:hv";
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "version", 0, NULL, 'v' },
		{ "template", 1, NULL, 't' },
		{ NULL, 0, NULL, 0 }
	};

	do 
	{
		next_opt = getopt_long(argc, argv, short_options, 
				long_options, NULL);
		switch(next_opt)
		{
			case 'h':
				print_usage(stdout, 0);
				break;
			case 'v':
				print_version(stdout, 0);
				break;
			case 't':
				opt->html_template = optarg;
				break;
			case '?':
				print_usage(stderr, 1);
				break;
			case -1: 
				// done
				break;
			default:
				abort();
		}
	} while (next_opt != -1);

	if(!p->filename)
	{
		if(argc > optind)
			p->filename = argv[optind];
		else
			print_usage(stderr, 1);
	}

	return opt;
}
