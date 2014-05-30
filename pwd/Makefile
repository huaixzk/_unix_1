all: lib_getpw.so getpw1 test_user
lib_getpw.so: _getpw.c 
	gcc -shared -fPIC $^ -o $@
getpw1: getpw1.c _getpw.h
	gcc $< -L. -l_getpw -o $@
test_user: test_user.c _getpw.h
	# add -std=c99 for(int i = 0 ;;)
	gcc -std=c99 $< -L. -l_getpw -o $@ 
clean:
	rm -rf lib_getpw.so getpw1 test_user
