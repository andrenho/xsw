OBJECTS=pre_parser.o pre_lexer.o parser.o lexer.o xsw.o

#
# Binary 
# 
xsw: $(OBJECTS)
	gcc -g -o $@ $?

#
# Preprocessor
#
pre_lexer.o: pre_lexer.c

pre_parser.o: pre_parser.c

pre_lexer.c: pre_lexer.l
	flex -o$@ $?

pre_parser.c: pre_parser.y
	bison -d -o $@ $?

#
# Parser
#
lexer.o: lexer.c

parser.o: parser.c

lexer.c: lexer.l
	flex -o$@ $?

parser.c: parser.y
	bison -d -o $@ $?

# 
# Compile
#
.o.c:
	gcc -g -c $<

#
# Clean
#
clean:
	rm -f pre_parser.c pre_lexer.c parser.c lexer.c *.o
