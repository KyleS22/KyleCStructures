
# Compiler Flags
CC = g++
CXXFLAGS = -Iinclude -Wall -Wextra

DEBUG_FLAGS = -DDEBUG -g

# Directory Structure
BIN_DIR=$(CURDIR)/bin
LIB_DIR=$(CURDIR)/lib
OBJ_DIR=$(CURDIR)/obj

# Library Stuff
LIBKYLE=-L$(LIB_DIR) -lkyle -Wl,-rpath,$(LIB_DIR)

KYLE_OBJ = $(OBJ_DIR)/foo.o


# TODO: Set up unit testing
# TODO: Code Coverage?
# TODO: Generate documentation
# TODO: Set up install


#---------------------------------
# Create All
#---------------------------------
all: builddirs test_foo


#---------------------------------
# Set up Debugging
#---------------------------------
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: test_foo


#---------------------------------
# Build Directories
#---------------------------------
builddirs:
	mkdir -p $(BIN_DIR)/
	mkdir -p $(LIB_DIR)/
	mkdir -p $(OBJ_DIR)/

test_foo: builddirs test_foo.o libkyle.so
	$(CC) -o $(BIN_DIR)/test_foo $(OBJ_DIR)/test_foo.o $(LIBKYLE)

test_foo.o: test/test_foo.cc
	$(CC) -c $(CXXFLAGS) test/test_foo.cc -o $(OBJ_DIR)/$@

libkyle.so: builddirs foo.o
	$(CC) $(KYLE_OBJ) -shared -o $(LIB_DIR)/$@

foo.o: src/foo.cc include/foo.h
	$(CC)  -c -fPIC $(CXXFLAGS) $< -o $(OBJ_DIR)/$@

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(OBJ_DIR)



