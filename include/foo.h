// File Name: foo.h
//
// Authors: {% <AUTHORS> %}
//
// Date: 16-11-2019
//
// Description: {% <DESCRIPTION> %}  

#ifndef FOO_H
#define FOO_H

/// @brief Contains various data structures
namespace KyleCStructs {
	
	/// @brief Class representing a Foo
	/// @author me
	class Foo{
		private:
			int m_a;

		public:
                        /// @brief Make a foo
                        ///
                        /// @param a Input param
                        ///
                        /// @return A foo
			///
			/// @details some details
			///
			/// Example:
			/// @code
			///	foo;
			/// @endcode
			Foo(int a);

			void printSomething();
	};

}


#endif // FOO_H
