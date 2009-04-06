" xsw sytax file <http://xsw.googlecode.com/>
" Maintainer:	André Wagner <andre.nho@gmail.com>
" Last Change:	2009 Apr 05


if version < 600
	syntax clear
elseif exists("b:current_syntax")
	finish
endif

syn region 	xswComment 		start="#" end="\n"
syn region 	xswComment 		start="/\*" end="\*/" extend
syn region  xswString     start="\"" end="\""
syn region  xswString     start="\'" end="\'"
syn match   xswNumber     "-\=\<\d*\.\=[0-9_]\>"
syn keyword xswStatement	slide template
syn keyword xswCommand		text image background
syn keyword xswParameter	x y w h size scale font style align expand
syn keyword xswConstant		right center italic horizontal sans serif

hi def link xswComment 		Comment
hi def link xswStatement 	Statement
hi def link xswCommand		Identifier
hi def link xswParameter 	Type
hi def link xswString     String
hi def link xswNumber     String
hi def link xswConstant		Constant

let b:current_syntax = "xsw"
