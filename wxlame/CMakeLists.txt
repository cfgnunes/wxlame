cmake_minimum_required(VERSION 3.5)
project(wxlame)

# Find dependencies
find_package(wxWidgets REQUIRED)
find_program(EXE_MSGFMT msgfmt)

include(${wxWidgets_USE_FILE})

# Compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Sources
set(SOURCE_FILES
        src/Application.cpp
        src/Application.h
        src/ConfigBase.cpp
        src/ConfigBase.h
        src/Constants.h
        src/DndFile.cpp
        src/DndFile.h
        src/FileInfo.cpp
        src/FileInfo.h
        src/FileListManager.cpp
        src/FileListManager.h
        src/Gui.cpp
        src/Gui.h
        src/GuiMain.cpp
        src/GuiMain.h
        src/GuiProgress.cpp
        src/GuiProgress.h
        src/GuiSettings.cpp
        src/GuiSettings.h)

set(SOURCES_LANG
        cs
        de
        es
        pt_BR
        ru)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Compile language files
if(EXE_MSGFMT)
        set(MO_FILES)
        foreach(LANG ${SOURCES_LANG})
                set(PO msg/${LANG}.po)
                set(MO ${CMAKE_CURRENT_BINARY_DIR}/resource/msg/${LANG}/${PROJECT_NAME}.mo)
                file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/resource/msg/${LANG}")
                set(MO_FILES ${MO_FILES} ${MO})
                add_custom_command(
                        OUTPUT ${MO}
                        COMMAND ${EXE_MSGFMT} ${PO} -o ${MO}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        DEPENDS ${PO})
        endforeach()
        add_custom_target(create-mo ALL DEPENDS ${MO_FILES})
else()
        message("-- msgfmt not found, translations not generatied")
endif()

if (UNIX)
        set(CMAKE_INSTALL_PREFIX /home/cristiano/Downloads)

        # Install main files
        install(TARGETS ${PROJECT_NAME} DESTINATION bin)
        install(DIRECTORY resource DESTINATION share/${PROJECT_NAME})

        # Install icon files
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/icon32x32.png"           DESTINATION "share/icons/hicolor/32x32/apps"     RENAME "${PROJECT_NAME}.png"     )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/icon48x48.png"           DESTINATION "share/icons/hicolor/48x48/apps"     RENAME "${PROJECT_NAME}.png"     )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/icon64x64.png"           DESTINATION "share/icons/hicolor/64x64/apps"     RENAME "${PROJECT_NAME}.png"     )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/icon128x128.png"         DESTINATION "share/icons/hicolor/128x128/apps"   RENAME "${PROJECT_NAME}.png"     )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/icon.xpm"                DESTINATION "share/pixmaps"                      RENAME "${PROJECT_NAME}.xpm"     )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/${PROJECT_NAME}"         DESTINATION "share/menu"                         RENAME "${PROJECT_NAME}"         )
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/debian/menu/${PROJECT_NAME}.desktop" DESTINATION "share/applications"                 RENAME "${PROJECT_NAME}.desktop" )
endif (UNIX)
