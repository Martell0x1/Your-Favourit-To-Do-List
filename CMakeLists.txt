cmake_minimum_required(VERSION 3.27)
project(To_DoList)

execute_process(COMMAND wx-config --cxxflags OUTPUT_VARIABLE wxWidgets_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND wx-config --libs OUTPUT_VARIABLE wxWidgets_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${wxWidgets_LIBS}")

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp
        StringHandle.cpp
        StringHandle.h
        FileHandler.cpp
        FileHandler.h
        Task.cpp
        Task.h
        TaskManager.cpp
        TaskManager.h
        Libs.h
        MainGUI.cpp
        MainGUI.h
        AddTaskWindow.cpp
        AddTaskWindow.h
        wxHeaders.h
        EditTask.cpp
        EditTask.h

)

add_executable(To_DoList ${SOURCE_FILES})
message(STATUS "wxWidgets_USE_FILE: ${wxWidgets_USE_FILE}")
message(STATUS "wxWidgets_INCLUDE_DIRS: ${wxWidgets_INCLUDE_DIRS}")
message(STATUS "wxWidgets_LIBRARIES: ${wxWidgets_LIBRARIES}")
target_link_libraries(To_DoList ${wxWidgets_LIBRARIES})
