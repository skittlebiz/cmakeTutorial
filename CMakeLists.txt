cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 33.0)

option(USE_MYMATH "Use tutorial provided math impl" ON)

if(USE_MYMATH)
   add_subdirectory(MathFunctions)
   list(APPEND EXTRA_LIBS MathFunctions)
   list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MathFunctions"")
endif()

add_executable(Tutorial tutorial.cpp)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})


configure_file(TutorialConfig.h.in TutorialConfig.h)
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

