#include <wand/MagickWand.h>
#include "images.h"

int images_process(Presentation* p)
{
	MagickWand *mw;
	int status = 1;
	int i, j;

	MagickWandGenesis();
	mw = NewMagickWand();

	for(i=0; i<p->n_slides; i++)
	{
		Slide* slide = p->slides[i];
		for(j=0; j<slide->n_commands; j++)
		{
			Command* cmd = slide->commands[j];
			if(cmd->type == T_IMAGE)
			{
				CommandImage* img = &cmd->command.image;
				int status = MagickReadImage(mw, img->path);
				if(status == MagickFalse)
				{
					fprintf(stderr, "Error reading image %s.\n", img->path);
					status = 0;
					continue;
				}
				int width = MagickGetImageWidth(mw);
				int height = MagickGetImageHeight(mw);
				printf("=== %0.2f", img->scale);
				MagickResizeImage(mw, (float)width * img->scale, (float)height * img->scale, LanczosFilter, 1.0);
				MagickSetFormat(mw, "png");
				img->data = MagickGetImageBlob(mw, &img->data_length);
			}
		}
	}

	mw = DestroyMagickWand(mw);
	MagickWandTerminus();

	return status;
}
