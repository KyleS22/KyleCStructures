#include <iostream>
#include "foo.h"

using namespace std;

KyleCStructs::Foo::Foo(int a){
	this->m_a = a;
}

void KyleCStructs::Foo::printSomething(){
	cout << "This is a normal print";
}
