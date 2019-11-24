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
	
        // {% classy comment here %}
        /// @brief {% Brief Description %}
        ///@author {% Author %}
	class Foo{
		private:
			int m_a;

		public:
                        /// @brief {% What it do %}
                        ///
                        /// @pre {% Preconditions %}
                        /// @post {% Postconditions %}
                        ///
                        /// @param int a: {% A parameter %}
                        ///
                        /// @return {% A thing %}
                        ///
                        /// @details {% Details go here %}
			Foo(int a);

			void printSomething();
	};

}


#endif // FOO_H
