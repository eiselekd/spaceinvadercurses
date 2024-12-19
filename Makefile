all:
	make lib
	make main

lib:
	gcc -c g.cpp -o g.o
	ar rcs g.a g.o

main:
	gcc m.cpp g.a -o m.exe -lncurses -ltinfo -lstdc++

tar:
	tar czvf p.tar.gz g.cpp g.h m.cpp libncurses.a libtinfo.a Makefile
