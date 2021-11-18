cmake_minimum_required(VERSION 3.16)

project(PROJECT0)

set(CMAKE_CXX_STANDARD 14)

set(SRC_FILES
    main.cpp
    SD_var_process.cpp
    SD_button.cpp
    SD_panel.cpp
    SD_button_ball.cpp
    )

include_directories(
    C:/wxWidgets-3.1.5
    C:/wxWidgets-3.1.5/include
    C:/wxWidgets-3.1.5/lib/gcc_lib/mswud
    C:/workspace/project0/include
)

link_directories(
    C:/wxWidgets-3.1.5/lib/gcc_lib/dll
    C:/wxWidgets-3.1.5/lib/gcc_lib/mswud
)

add_compile_definitions(
    __WXMSW__
    _UNICODE
    WXUSINGDLL

)


# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --param heapsize=131072")


set(
    WX_LIBS
    wxbase315u_gcc810_x64.dll
    wxbase315u_net_gcc810_x64.dll
    wxbase315u_xml_gcc810_x64.dll
    wxbase315ud_gcc810_x64.dll
    wxbase315ud_net_gcc810_x64.dll
    wxbase315ud_xml_gcc810_x64.dll
    wxmsw315u_adv_gcc810_x64.dll
    wxmsw315u_aui_gcc810_x64.dll
    wxmsw315u_core_gcc810_x64.dll
    wxmsw315u_gl_gcc810_x64.dll
    wxmsw315u_html_gcc810_x64.dll
    wxmsw315u_media_gcc810_x64.dll
    wxmsw315u_propgrid_gcc810_x64.dll
    wxmsw315u_ribbon_gcc810_x64.dll
    wxmsw315u_richtext_gcc810_x64.dll
    wxmsw315u_stc_gcc810_x64.dll
    wxmsw315u_webview_gcc810_x64.dll
    wxmsw315u_xrc_gcc810_x64.dll
    wxmsw315ud_adv_gcc810_x64.dll
    wxmsw315ud_aui_gcc810_x64.dll
    wxmsw315ud_core_gcc810_x64.dll
    wxmsw315ud_gl_gcc810_x64.dll
    wxmsw315ud_html_gcc810_x64.dll
    wxmsw315ud_media_gcc810_x64.dll
    wxmsw315ud_propgrid_gcc810_x64.dll
    wxmsw315ud_ribbon_gcc810_x64.dll
    wxmsw315ud_richtext_gcc810_x64.dll
    wxmsw315ud_stc_gcc810_x64.dll
    wxmsw315ud_webview_gcc810_x64.dll
    wxmsw315ud_xrc_gcc810_x64.dll
)

add_executable(${PROJECT_NAME} ${SRC_FILES} )

target_link_libraries(
    ${PROJECT_NAME}
    ${WX_LIBS}
)