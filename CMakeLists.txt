cmake_minimum_required(VERSION 3.5)

# ===========================================================================
# Project Config
# ===========================================================================

set(CMAKE_CXX_STANDARD 11)

# Specify Project Stuff
project(kyle_structs VERSION 0.1.0 DESCRIPTION "C++ Data Structures.")

# Need this for install
include(GNUInstallDirs)

# Use -DCMAKE_BUILD_TYPE=WHATEVER to switch 
IF(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -DDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# Export the symbols on windows so we can make a .lib file
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# ============================================================================
# Library Targets
# ============================================================================

# Generate the shared library
add_library(kyle_structs SHARED src/foo.cc)

# Set the version, soversion, and public api files
set_target_properties(kyle_structs PROPERTIES 
	VERSION ${PROJECT_VERSION} 
	SOVERSION 1
	PUBLIC_HEADER "include/foo.h")

# Configure a pc file 
configure_file(kyle_structs.pc.in kyle_structs.pc @ONLY)

# Tell it where the include files are
target_include_directories(kyle_structs PUBLIC ${PROJECT_SOURCE_DIR}/include)

# ===============================================================================
# Installation Config
# ===============================================================================

# Tell it where the library and header files go
install(TARGETS kyle_structs LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# set up the pkgconfig files for install
install(FILES ${CMAKE_BINARY_DIR}/kyle_structs.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Allow Install of Man Pages
if (UNIX)
	install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/man/man3/ DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man3)
endif ()

# ==========================================================================================
# Documentation
# ==========================================================================================

# Build documentation in release mode only
if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
	
	# Make sure we can use Doxygen
	find_package(Doxygen)
	
	if (${DOXYGEN_FOUND})
		
		# Build the documentation with make
		set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
		set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

		configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)


		add_custom_target(doc ALL
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "Generating API documentation with Doxygen"
			VERBATIM
		)
	else (DOXYGEN_FOUND)
		message("Doxygen must be installed to generate documentation.")
	endif()
endif()


#===============================================================================
# Tests
#==============================================================================

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)



enable_testing()


# Create a test executable
add_executable(foo_test test/test_foo.cc test/gtest_main.cc)

# Link the library
target_link_libraries(foo_test PUBLIC gtest_main PRIVATE kyle_structs)

add_test(NAME test_foo COMMAND foo_test)

