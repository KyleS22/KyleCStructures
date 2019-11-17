cmake_minimum_required(VERSION 3.5)

# Specify Project Stuff
project(kyle_structs VERSION 1.0.0 DESCRIPTION "C++ Data Structures.")

# Need this for install
include(GNUInstallDirs)

# Use -DCMAKE_BUILD_TYPE=WHATEVER to switch 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")


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

# Tell it where the library and header files go
install(TARGETS kyle_structs LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# set up the pkgconfig files for install
install(FILES ${CMAKE_BINARY_DIR}/kyle_structs.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)



# Create a test executable
add_executable(test_foo test/test_foo.cc)

# Link the library
target_link_libraries(test_foo PRIVATE kyle_structs)


