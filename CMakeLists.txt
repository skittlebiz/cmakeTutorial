cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 33.0)

option(USE_MYMATH "Use tutorial provided math impl" ON)

#list(APPEND EXTRA_LIBS SubExe)
#list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/SubExe")

if(USE_MYMATH)
   add_subdirectory(MathFunctions)
#   list(APPEND EXTRA_LIBS MathFunctions SubExe)
   list(APPEND EXTRA_LIBS MathFunctions)
   list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MathFunctions ${PROJECT_SOURCE_DIR}/SubExe)
endif()

add_executable(Tutorial tutorial.cpp)
add_subdirectory(SubExe)

        message(STATUS "EXTRA_INCLUDES=${${EXTRA_INCLUDES}}")

    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
	
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})


configure_file(TutorialConfig.h.in TutorialConfig.h)
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

