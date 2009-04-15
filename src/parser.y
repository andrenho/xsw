%{
/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://gplv3.fsf.org/> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presentation.h"
#include "parser.h"
#include "cmd_text.h"
#include "cmd_img.h"
#include "color.h"

extern FILE *yyin;
static Presentation* pr;
static Slide* cr_slide;
static CommandText* cr_cmd_txt = 0x0;
static CommandImage* cr_cmd_img = 0x0;

extern int yylex(void);
extern int line_no;
int yyparse(void);

void yyerror(const char *s)
{
	fprintf(stderr, "parser error: %s in line %d\n", s, line_no);
	exit(1);
}

int yywrap()
{
	return 1;
}

int parser_parse(Presentation *pres, char *filename)
{
	pr = pres;
	yyin = fopen(filename, "r");
	yyparse();
	return 1;
}

%}

%token SLIDE COLON HIFEN TEXT X Y W H IMAGE SIZE SCALE TEMPLATE BACKGROUND FONT
%token STYLE ALIGN EXPAND PLUS IMAGE_PATH GRADIENT COLOR_PAR BORDER NONE
%token <dval> NUM
%token <cval> ID STRING COLOR
%token <ival> STYLE_TYPE ALIGN_TYPE EXPAND_TYPE

%union
{
	double dval;
	char* cval;
	int ival;
}

%%

presentation: presentation_options templates slides
	    | presentation_options slides;

presentation_options: 
		    | presentation_options presentation_option

presentation_option: IMAGE_PATH COLON STRING { pr->image_path = $3; }

templates: template
	 | templates template;

template: TEMPLATE COLON ID { cr_slide = pr_add_slide(pr, template_new($3)); } commands
	| TEMPLATE COLON ID ID { cr_slide = pr_add_slide_from(pr, template_new($3), $4); } commands;

slides: slide
      | slides slide;

slide: SLIDE COLON { cr_slide = pr_add_slide(pr, slide_new()); cr_cmd_txt = NULL; } commands
     | SLIDE COLON ID { cr_slide = pr_add_slide_from(pr, slide_new(), $3); cr_cmd_txt = NULL; } commands;

commands: 
	| commands command;

command: text_command
       | image_command
       | background_command
       | custom_command
       | template_command;

/* 
 * Information
 */
color: COLOR { $<cval>$ = $1; }
     | ID { $<cval>$ = color_get($1); }

/* 
 * Text command 
 */
text:
    | TEXT COLON;

text_command: HIFEN text STRING { cr_cmd_txt = (CommandText*)slide_add_command(cr_slide, T_TEXT, cmd_txt_new($3, (CommandText*)cr_cmd_txt)); } text_parameters
            | PLUS text STRING { cr_cmd_txt = (CommandText*)slide_add_command(cr_slide, T_TEXT, cmd_txt_new_plus($3, (CommandText*)cr_cmd_txt)); } text_parameters

text_parameters:
	       | text_parameters text_parameter;

text_parameter: X COLON NUM { cr_cmd_txt->x = $3; }
	      | Y COLON NUM { cr_cmd_txt->y = $3; }
              | H COLON NUM { cr_cmd_txt->h = $3; }
              | SIZE COLON NUM { cr_cmd_txt->size = $3; }
              | FONT COLON STRING { cr_cmd_txt->font = $3; }
              | FONT COLON ID { cr_cmd_txt->font = $3; }
              | STYLE COLON STYLE_TYPE { cr_cmd_txt->style = $3; }
              | ALIGN COLON ALIGN_TYPE { cr_cmd_txt->align = $3; }
	      | COLOR_PAR COLON color { memcpy(cr_cmd_txt->color, $<cval>3, 3); }
              | BORDER COLON color { memcpy(cr_cmd_txt->border, $<cval>3, 3); }
              | BORDER COLON NONE { cr_cmd_txt->has_border = 0; }

/*
 * Image command
 */
image_command: HIFEN IMAGE COLON STRING { cr_cmd_img = (CommandImage*)slide_add_command(cr_slide, T_IMAGE, cmd_img_new($4, 0)); } image_parameters;

image_parameters:
		| image_parameters image_parameter;

image_parameter: X COLON NUM { cr_cmd_img->x = $3; }
	       | Y COLON NUM { cr_cmd_img->y = $3; }
               | SCALE COLON NUM { cr_cmd_img->scale = $3; }

/*
 * Template command
 */
template_command: HIFEN ID COLON { cr_cmd_txt = (CommandText*)slide_add_command(cr_slide, T_TEXT, cmd_txt_new_template($2)); } text_parameters;

/*
 * Custom command
 */
custom_command: HIFEN ID COLON STRING { cr_cmd_txt = (CommandText*)slide_add_custom_command(cr_slide, $2, $4); } text_parameters;

/*
 * Background command
 */
background_command: HIFEN BACKGROUND COLON STRING { cr_cmd_img = (CommandImage*)slide_add_command(cr_slide, T_IMAGE, cmd_img_new($4, 1)); } background_parameters
		  | HIFEN BACKGROUND COLON color { memcpy(cr_slide->bg_color, $<cval>4, 3); memcpy(cr_slide->bg_gradient, $<cval>4, 3); } bg_color_parameters;

background_parameters:
		     | background_parameters background_parameter;

background_parameter: EXPAND COLON EXPAND_TYPE { cr_cmd_img->expand = $3; }
                    | X COLON NUM  { cr_cmd_img->x = $3; }
	            | Y COLON NUM  { cr_cmd_img->y = $3; }

bg_color_parameters: 
		   | bg_color_parameters bg_color_parameter;

bg_color_parameter: GRADIENT COLON color { memcpy(cr_slide->bg_gradient, $<cval>3, 3); }
