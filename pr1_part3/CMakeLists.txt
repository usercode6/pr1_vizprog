cmake_minimum_required(VERSION 3.16)

project(VideoPlayerQml VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.11 REQUIRED COMPONENTS
    Quick
    QuickControls2
    Multimedia
    Widgets
)

qt_standard_project_setup(REQUIRES 6.11)

qt_add_executable(appVideoPlayerQml
    main.cpp
)

qt_add_qml_module(appVideoPlayerQml
    URI VideoPlayerQml
    VERSION 1.0

    QML_FILES
        Main.qml
        PlayerButton.qml

    RESOURCES
        images/conus.png
        images/rastyanut.png
        images/ecvalaizer.png
        images/list.png
        images/repeat.png
        images/shuffle.png
        images/Photoroom.png
        video/video.mp4
)

target_link_libraries(appVideoPlayerQml PRIVATE
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Multimedia
    Qt6::Widgets
)

set_target_properties(appVideoPlayerQml PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)