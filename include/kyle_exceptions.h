// File Name: after_the_end_exception.h
//
// Authors: Kyle Seidenthal
//
// Date: 24-11-2019
//
// Description: An exception indicating that a cursor has gone beyond the end
// 		of the data structure  

#include <exception>

#ifndef AFTER_THE_END_EXCEPTION_INCLUDE
#define AFTER_THE_END_EXCEPTION_INCLUDE

/// @brief Contains definitions of various data structures
namespace KyleCStructs{
	
	/// @brief Contains useful exceptions for data structures
	namespace KyleCExceptions{

		/// @brief An exception indicating that a cursor has gone beyond the end of
		///  	   the data structure
		/// @author Kyle Seidenthal
		class AfterTheEndException : public std::exception{
			
                        /// @brief Constructor for the exception
                        ///
                        /// @param char const* const message: The message
                        ///
                        /// @return A new exception object
			AfterTheEndException(char const* const message) throw();

			/// @brief Tells the user what happened
			///
			/// @return A string telling what caused the exception
			///
			/// @details Throw this when a datastructure has a capacity and the cursor
			/// 	     could go after the end.
			virtual char const* what() const throw();
		};
	}
}

#endif // AFTER_THE_END_EXCEPTION_INCLUDE
