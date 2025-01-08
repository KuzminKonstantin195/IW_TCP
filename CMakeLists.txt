cmake_minimum_required(VERSION 3.16)

project(IW_TCPClient LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(IW_TCPClient
  main.cpp
  iw_tcp_client.h iw_tcp_client.cpp
  headers.h
  tcp_client_parent.h tcp_client_parent.cpp
  tcp_client_bytes.h tcp_client_bytes.cpp
)
target_link_libraries(IW_TCPClient  Qt${QT_VERSION_MAJOR}::Core
                                    Qt${QT_VERSION_MAJOR}::Network)

include(GNUInstallDirs)
install(TARGETS IW_TCPClient
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
