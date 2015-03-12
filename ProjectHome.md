# What is it? #

**xsw** is a slide show presentation tool for all those who are frustrated with
[Microsoft PowerPoint](http://office.microsoft.com/en-us/powerpoint/default.aspx) and its [clones](http://www.openoffice.org/).

It is available for all **Unix systems (Linux, FreeBSD, etc...)** as source.

## Requirements ##

  * [SDL](http://www.libsdl.org/)
  * [SDL\_ttf](http://www.libsdl.org/projects/SDL_ttf/)
  * [SDL\_image](http://www.libsdl.org/projects/SDL_image/)
  * [SDL\_gfx](http://www.ferzkopp.net/Software/SDL_gfx-2.0/)
  * [ImageMagick](http://www.imagemagick.org/) - required only for creating PDFs, not required for compiling

This is **alpha** software! Questions? Comments? Contribuitions? Please post your message in the [xsw discussion group](http://groups.google.com/group/xsw-software). You can also contact the [project manager](mailto:andre.nho@gmail.com). Found a accidental feature (a.k.a. bug)? [Open an issue](http://code.google.com/p/xsw/issues/list)!


---


# Basics #

By using **xsw**, you create your presentation "by hand", using the xsw language
described in the [manual](Reference.md). A example of a file is:

```
slide:
  - "Hello" x:50 y:30 align:center
  + "World!"
```

The first line says we're writing a slide. The second one says: "add the text
'Hello' centered at the position 50x30 (each slide is 100x75)". The third line
says: "write 'hello' using the same parameters that the line before'. That's
what the plus (+) is for.

Let's say you save the script in a file called **test.xsw**. So, to run, just type:

`$ xsw test.xsw`

![![](http://andre.nho.googlepages.com/1-small.png)](http://andre.nho.googlepages.com/1.png)

Press **`F`** at any time to go to fullscreen and return.

While xsw has a learning curve, after you learned, you'll be able to build
presentations that look much better (and much faster) than Microsoft PowerPoint.


## Images ##

Adding images can be done the following way:

```
slide:
  - background: "bg.jpg"
  - image: "image.png" x:10 y:10
```

This will add two images: one scaled on the background, and a second one in
regular size.

![![](http://andre.nho.googlepages.com/2-small.jpg)](http://andre.nho.googlepages.com/2.jpg)

## Templates ##

If you want all your slides to look the same, you can use a template (this
would be called a "master slide" in other programs). Do so the following way:

```
template: mytemplate
  - background: "mycompanylogo.jpg"
  - title: x:50 y:10 align:center

slide: mytemplate
  - title: "My Company"
```

![![](http://andre.nho.googlepages.com/3-small.jpg)](http://andre.nho.googlepages.com/3.jpg)

## Output ##

A PDF file can be created from the presentation like this:

`$ xsw2pdf presentation.xsw`

The `xsw2png` and `xsw2jpeg` tools can also be used to generate other formats.

Please note that [ImageMagick](http://www.imagemagick.org/) must be installed for the conversion tools to work.

## Tutorial ##

A more complete tutorial presentation can be viewed by running:

`$ xsw --tutorial`

## Developing ##

When developing, use the `-l` parameter on xsw to go directly to the last slide.
The `-d` parameter shows a grid to help with the positioning. The same grid can
be show by pressing CTRL+D.

To know more about the commands and parameters you can use, read in the
[Reference](Reference.md).