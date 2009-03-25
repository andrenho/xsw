#include <stdio.h>
#include <string.h>

#include "parser.h"

#define MAX_ID_LENGTH 4096
#define add_id() { id[i_id] = '\0'; \
		   i_id = 0; \
                   parse_id(pres, id); }

static Slide* current_slide;
static Command* current_command;
static Parameter* current_parameter;

inline static void parse_error(char* s)
{
	fprintf(stderr, "Error parsing file: %s\n", s);
	exit(1);
}

inline static char* strcpy_nc(char* origin)
{
	char* dest = (char*)malloc(strlen(origin));
	strncpy(dest, origin, strlen(origin)-1);
	dest[strlen(origin)-1] = '\0';
	return dest;
}

inline static int is_command(char* s)
{
	return (s[strlen(s)-1] == ':');
}

inline static void parse_id(Presentation* pr, char *id)
{
	// slide
	if(strcmp("slide:", id) == 0)
	{
		current_slide = presentation_add_slide(pr);
		current_command = current_parameter = NULL;
	}

	// id
	if(current_command)
	{
		if(current_command->id == '\0') // command doesn't have an id
		{
			if(!is_command(id))
				parse_error("Expected: command");
			current_command->id = strcpy_nc(id);
#ifndef DEBUG
			printf("Command: %s\n", current_command->id);
#endif
		}
		else // command already has an id
		{
			if(is_command(id))
			{
				if(current_parameter)
					parse_error("Expected: value");
				current_parameter = command_add_parameter(current_command, strcpy_nc(id));
			}
			else
			{
				if(current_parameter)
				{
					current_parameter->value = (char*)malloc(strlen(id)+1);
					strcpy(current_parameter->value, id);
#ifdef DEBUG
					printf("New value: %s\n", current_parameter->value);
#endif
					current_parameter = NULL;
				}
			}
		}
	}

	// new command
	if(strcmp("-", id) == 0)
	{
		if(current_slide == NULL)
			parse_error("Expected: slide");
		current_command = slide_add_command(current_slide);
		current_parameter = NULL;
	}


	// ...
}

inline static int is_separator(char s)
{
	return (s == ' ' || s == '\n' || s == '\t' || s == ':');
}

int parser_parse(Presentation *pres, char *sswl)
{
	int i = 0, i_id = 0;
	char id[MAX_ID_LENGTH];

	current_slide = current_command = current_parameter = NULL;

	// 
	// lexer
	//
	enum { WAITING_ID, ID, QUOTES, COMMENT } parsing;
	parsing = WAITING_ID;

	while(sswl[i] != '\0')
	{
		// check for comment
		if(parsing != QUOTES && sswl[i] == '#')
		{
			if(parsing == ID)
				add_id();
			while(sswl[i] != '\0' && sswl[i] != '\n')
				i++;
			parsing = WAITING_ID;
		}

		// do we have a separator?
		if(parsing == WAITING_ID && !is_separator(sswl[i]))
		{
			if(sswl[i] == '\"')
			{
				parsing = QUOTES;
				i++;
			}
			else
				parsing = ID;
		}

		// check for ID or quotes
		switch(parsing)
		{
		case ID:
			if(is_separator(sswl[i]))
			{
				if(sswl[i] == ':')
					id[i_id++] = ':';
				add_id();
				parsing = WAITING_ID;
			}
			else
				id[i_id++] = sswl[i];
			break;
		case QUOTES:
			if(sswl[i] == '\"')
			{
				parsing = WAITING_ID;
				add_id();
			}
			else
				id[i_id++] = sswl[i];
			break;
		case WAITING_ID:
		case COMMENT:
			break;
		default:
			printf("Invalid parsing: %d\n", parsing);
			abort();
		}
		
		i++;	
	}

	return 1;

error:
	return 0;
}
