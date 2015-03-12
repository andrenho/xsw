# Installation Instructions #

## Requirements ##

  * [SDL](http://www.libdsl.org/)
  * [SDL\_ttf](http://www.libdsl.org/projects/SDL_ttf/)
  * [SDL\_image](http://www.libdsl.org/projects/SDL_image/)
  * [SDL\_gfx](http://www.ferzkopp.net/Software/SDL_gfx-2.0/)

[ImageMagick](http://www.imagemagick.org/) is also required for creating PDFs, more specificly the program [convert](http://www.imagemagick.org/script/convert.php). It is not, however, required for compilation.

## Instalation instructions ##

Once you have all requirements installed, you can just type the basic installation commands of the Unix world:

```
$ ./configure
$ make
$ su -
# make install
```


## Installing vim support ##

To install vim support, copy the `doc/xsd.vim` file to your `~/.vim/syntax` directory. Then edit your `~/.vimrc` (or `~/.gvimrc`) and add:

```
au BufNewFile,BufRead *.xsw source ~/.vim/syntax/xsw.vim
```