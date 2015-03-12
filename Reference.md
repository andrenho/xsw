﻿#summary Reference for xsw language
#labels Featured,Phase-Support




---


# xsw Reference #

```
# This is a comment
#
image_path: "myimages/photos"

template: NAME
  - [commands...]
  - CUSTOM_COMMAND: [text_parameters]

slide: [template]
  - "my string" [text_parameters]
  - text: "my string" [text_parameters]
  - image: "image_path.jpg" [image_parameters]
  - background: "image_path.jpg" [background_parameters]
  - [CUSTOM_COMMAND]: "my string"
```

Every minus sign (-) is a new command to be executed. A plus sign (+) in a text command means the parameters will be copied from the previous command - this can be used to write multiple lines of text.

A source file must be written using UTF-8 encoding.

# Commands and Parameters #

## comments ##

Everything that starts with a "#" is considered a comment and is ignored by the program. Comments can start in the middle of the line.

## image\_path ##
Gives xsw a image path, where it'll look for images. For example,

```
image_path: "~/myimages"
slide:
  - image: "test.jpg"
```

will look for `test.jpg` in the current directory. If not found, it'll look in `~/myimages`.

## text (or nothing) ##

The text command writes a text on the screen. The parameters are:

|x|the horizontal position (`0~100`, default: `4`)|
|:|:----------------------------------------------|
|y |the vertical position (`0~75`, default: `3`)|
|h |vertical space between lines (default: one line, defined by the font)|
|size|font size (default: `36`)|
|font|font face, must be one of: `sans`, `serif` or `mono` (default: `sans`)|
|style|font style, must be one of: `nostyle`, `italic` (default: `nostyle`)|
|align|alignment of the x position, must be one of: `left`, `center`, `right` (default: `left`)|
|color|the [color](Colors.md) of the text. Default: `white`.|
|border|the border [color](Colors.md) of the text. Can be a [color](Colors.md) or `none` for no border. Default: `black`.|

The keyword "text" is not necessary.

## image (or img) ##

The image command pastes a image on the screen. The parameters are:

|x|the horizontal position (`0~100`, default: `4`). Negative values can be used.|
|:|:----------------------------------------------------------------------------|
|y |the vertical position (`0~75`, default: `3`)|
|scale|the image zoom, `1` being 100% (default: `1`). Values higher than 1 make the image grow, values less than 1 make the image shrink (ex: `0.4`)|

## background (or bg) ##

Similar to the image command, but automatically scale the image to the screen size. The parameters are:

|x|the horizontal position (`0~100`, default: `0`). It can be used to move the background image. Negative values can be used.|
|:|:-------------------------------------------------------------------------------------------------------------------------|
|y |the vertical position (`0~75`, default: `0`)|
|expand|this parameters defines what happens when the aspect ration of the image is not the same as the screen. If `horizontal` is chosen, the left and right sides of the image will be anchored with the left and right side of the screen. (default: `vertical`)|

The background can also be used to display a color, such as `background: pink`. The default background is black. In this case, the following parameters can be used:

|gradient|a color to display a vertical gradient. The default is the same color as the background (that is - no gradient).|
|:-------|:---------------------------------------------------------------------------------------------------------------|

See [Colors](Colors.md) for more information.

# Templates #

Templates can be used to write a slide layout that is used by many slides in
the presentation. It's similar to what !MS PowerPoint calls "master slide".

Example:

```
template: mytemplate
  - background: "mylogo.jpg"

slide: mytemplate
  - text: "Title"
```

In this case, the slide will be created with the mylogo.jpg background. Any
number of templates can be created and used on any number of slides.

A template can also contain a custom command. This can be used to create a text
that'll have the same properties in all slides. Example:

```
template: mytemplate
  - title: x:50 y:10 align:center

slide: mytemplate
  - title: "My Title"
```

In this case, a "title" command is created containing some parameters (but not
a text). The text is referenced in the first slide.

A template can also be referenced from another slide, such as this:

```
template: mycompany
  - background: "logo.png"

template: cover mycompany
  - title: x:50 y:10 align:center

slide: cover
  - title: "My Company"
```

# Running the program #

The program can be run as:

`$ xsw mypresentation.xsw`

A `-l` option opens the presentation in the last slide. This can be used to
speed up development, as usually the user is editing the last slide.

The following keys can be used during the presentation:

|RIGHT / PAGE DOWN|go to the next slide|
|:----------------|:-------------------|
|LEFT / PAGE UP|go to the previous slide|
|HOME|go to the first slide|
|END|go to the last slide|
|F |fullscreen|
|Ctrl+D|developer mode|
|Q |quits presentation|

# Generating a PDF #

A PDF of the presentation can be generated like this:

`$ xsw2pdf mypresentation.xsw`

The `xsw2jpeg` and `xsw2png` tools can be used to generate jpeg and png images from the presentation.