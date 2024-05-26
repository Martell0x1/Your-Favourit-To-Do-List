cmake_minimum_required(VERSION 3.27)
project(To_DoList)

set(CMAKE_CXX_STANDARD 20)
set(wxWidgets_ROOT_DIR "/usr/local")  # Set this to the root directory of wxWidgets
set(wxWidgets_CONFIGURATION gtk3)     # Use the correct configuration for your wxWidgets installation
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

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
message(STATUS "wxWidgets_INCLUDE_DIRS: ${wxWidgets_INCLUDE_DIRS}")
message(STATUS "wxWidgets_LIBRARIES: ${wxWidgets_LIBRARIES}")
target_link_libraries(To_DoList ${wxWidgets_LIBRARIES})
