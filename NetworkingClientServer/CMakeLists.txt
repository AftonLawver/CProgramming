cmake_minimum_required(VERSION 3.23)
project(NetworkingClientServer C)

set(CMAKE_C_STANDARD 17)

add_executable(NetworkingClientServer tcpClient.c tcpServer.c)
