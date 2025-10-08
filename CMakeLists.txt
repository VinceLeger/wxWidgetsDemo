#minimum CMake
cmake_minimum_required(VERSION 3.20)
#build TestApp in C++
project(TestApp CXX)

#C++ stuff
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#pre-compile definitions
add_compile_definitions(
	_MBCS	#multi-byte character set
) 

#build wxWidgets
add_subdirectory(External/wxWidgets-3.3.1)

#build target
add_executable(TestApp WIN32 Src/main.cpp)
#link with wxWidgets Core and Base libraries
target_link_libraries(TestApp PUBLIC wx::core wx::base)

#copy DLLs 
add_custom_command(
	TARGET TestApp
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:wx::core>
            $<TARGET_FILE_DIR:TestApp>
    COMMENT "Copying wxWidget Core DLL"
)
add_custom_command(
	TARGET TestApp
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:wx::base>
            $<TARGET_FILE_DIR:TestApp>
    COMMENT "Copying wxWidget Base DLL"
)