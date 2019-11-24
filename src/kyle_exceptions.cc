// File Name: after_the_end_exception.cc
//
// Authors: Kyle Seidenthal
//
// Date: 24-11-2019
//
// Description: Implementation of the AfterTheEndException  

#include <exception>

#include "kyle_exceptions.h"

using namespace KyleCStructs::KyleCExceptions;

// Constructor for AfterTheEndException
AfterTheEndException::AfterTheEndException(char const* const message) throw()
{
// TODO: figure out what I am missing here
}

// Return a descriptive message
char const* AfterTheEndException::what() const throw(){
	return "The cursor has gone past the end of the structure!";
}


// TODO: BeforeTheStartException
// TODO: ContainerException
// TODO: ContainerEmptyException
// TODO: ContainerFullException
// TODO: DuplicateItemException
// TODO: InvalidArgumentException
// TODO: InvalidStateException
// TODO: ItemNotFoundException
// TODO: IteratorException
// TODO: NoCurrentItemException
