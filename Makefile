CC = g++

CXXFLAGS = -Iinclude -Wall -Wextra


FOO_OBJ = foo.o

# TODO: Create directory to store object files
# TOOD: Create a bin directory

# TODO: This does not work, gets undefined reference errors
test_foo: test_foo.o libfoo.so
	$(CC) -o test_foo test_foo.o -L$(CURDIR)/bin -lfoo -Wl,-rpath,$(CURDIR)/bin

test_foo.o: test/test_foo.cc
	$(CC) -c $(CXXFLAGS) test/test_foo.cc -o $@

libfoo.so: $(FOO_OBJ)
	$(CC) $(FOO_OBJ) -shared -o bin/$@

foo.o: src/foo.cc include/foo.h
	$(CC) -c -fPIC $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf test_foo



