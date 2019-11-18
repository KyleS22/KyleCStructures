#include <foo.h>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

namespace{
	TEST(FooTest, TheTest){
		EXPECT_EQ(1, 1);
		EXPECT_EQ(1, 0);
	}
}

//int main(){
//
//	cout << "Hello World!\n";
//
//	KyleCStructs::Foo test(10);
//
//	test.printSomething();
//}
