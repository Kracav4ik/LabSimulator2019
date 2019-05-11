# QTDIR must point to c:/Qt/5.7/mingw53_32/ or similar
message("qtdir is set to '$ENV{QTDIR}' (must be 'c:/Qt/5.7/mingw53_32/' or similar)")
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the QtWidgets library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(EXE_NAME LabSimulator2019)
set(QT_LIBS
        Qt5::Core
        Qt5::Widgets
)

set(EXE_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        LabContainer.cpp
        LabContainer.h
)

add_subdirectory(common)
add_subdirectory(labs)

qt5_add_resources(EXE_RESOURCES main.qrc)

add_executable(${EXE_NAME} ${EXE_SOURCES} ${EXE_RESOURCES})
target_link_libraries(${EXE_NAME} ${QT_LIBS} ${COMMON_NAME})
