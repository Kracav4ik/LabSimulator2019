set(LAB_NAME Lab3)
set(QT_LIBS
        Qt5::Core
        Qt5::Widgets
        )
set(LAB_SOURCES
        Lab3Plugin.h
        Lab3Plugin.cpp
        Lab3RootWidget.cpp
        Lab3RootWidget.h
        Lab3Model.cpp
        Lab3Model.h
        Lab3View.cpp
        Lab3View.h
)

add_library(${LAB_NAME} SHARED ${LAB_SOURCES})
target_link_libraries(${LAB_NAME} PRIVATE ${QT_LIBS} ${COMMON_NAME})
