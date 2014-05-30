all: lib_strcat.so strcat1 strcat2
lib_strcat.so: _strcat.c _strcat.h
	gcc -shared -fPIC $< -o $@
strcat1: strcat1.c _strcat.h lib_strcat.so
	gcc -g $< -L. -l_strcat -o $@
strcat2: strcat2.c _strcat.h lib_strcat.so
	gcc -g $< -L. -l_strcat -o $@
clean:
	rm -rf *.so strcat1  strcat2
