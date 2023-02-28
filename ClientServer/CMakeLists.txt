cmake_minimum_required(VERSION 3.23)
project(ClientServer C)

set(CMAKE_C_STANDARD 17)

add_executable(ClientServer tcp_client.c tcp_server.c)
