set(LAB_NAME Lab6)
set(QT_LIBS
        Qt5::Core
        Qt5::Widgets
        )
set(LAB_SOURCES
        Lab6Plugin.h
        Lab6Plugin.cpp
)

add_library(${LAB_NAME} SHARED ${LAB_SOURCES})
target_link_libraries(${LAB_NAME} PRIVATE ${QT_LIBS})
