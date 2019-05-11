set(COMMON_NAME common)
set(COMMON_NAME ${COMMON_NAME} PARENT_SCOPE)

set(QT_LIBS
        Qt5::Core
        Qt5::Widgets
)

add_compile_definitions(BUILDING_COMMON_DLL)
set(COMMON_SOURCES
        LabPluginBase.h
        LabRootWidget.h
        LabRootWidget.cpp
        LabModel.cpp
        LabModel.h
        symbols_export.h
)

add_library(${COMMON_NAME} SHARED ${COMMON_SOURCES})
target_link_libraries(${COMMON_NAME} PRIVATE ${QT_LIBS})
