all: ttyname1 lib_ttyname.so
lib_ttyname.so: _ttyname.c _ttyname.h
	gcc -g -shared -fPIC $< -o $@
ttyname1: ttyname1.c _ttyname.h lib_ttyname.so
	gcc  -g -L. -l_ttyname $< -o $@
clean:
	rm -rf ttyname1 lib_ttyname.so
