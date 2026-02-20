cmake_minimum_required(VERSION 3.19)
project(chess LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network Multimedia)

qt_standard_project_setup()

qt_add_executable(chess
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    chess/chesspiece.h chess/chesspiece.cpp
    chess/chessboard.h chess/chessboard.cpp
    player/aiplayer.h player/aiplayer.cpp
    player/peopleplayer.h player/peopleplayer.cpp
    global/globaldata.h global/globaldata.cpp
    gameentity.h gameentity.cpp
    utils/utils.h utils/utils.cpp
    player/player.h player/player.cpp
    network/chesslocal.h network/chesslocal.cpp
    network/chessinternet.h network/chessinternet.cpp

)

target_link_libraries(chess
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
        Qt::Multimedia
)
target_link_libraries(chess PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS chess
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET chess
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
