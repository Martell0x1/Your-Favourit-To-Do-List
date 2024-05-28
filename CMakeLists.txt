cmake_minimum_required(VERSION 3.27)
project(Your-Favourit-To-Do-List)

set(CMAKE_CXX_STANDARD 20)

# Get wxWidgets compilation and linking flags using wx-config
execute_process(COMMAND wx-config --cxxflags OUTPUT_VARIABLE wxWidgets_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND wx-config --libs OUTPUT_VARIABLE wxWidgets_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${wxWidgets_LIBS}")

# Include wxWidgets module
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES
        main.cpp
        StringHandle.cpp StringHandle.h
        FileHandler.cpp FileHandler.h
        Task.cpp Task.h
        TaskManager.cpp TaskManager.h
        Libs.h
        MainGUI.cpp MainGUI.h
        AddTaskWindow.cpp AddTaskWindow.h
        wxHeaders.h
        EditTask.cpp EditTask.h
)

add_executable(To_DoList ${SOURCE_FILES})

message(STATUS "wxWidgets_CXX_FLAGS: ${wxWidgets_CXX_FLAGS}")
message(STATUS "wxWidgets_LIBS: ${wxWidgets_LIBS}")
target_link_libraries(To_DoList ${wxWidgets_LIBS})