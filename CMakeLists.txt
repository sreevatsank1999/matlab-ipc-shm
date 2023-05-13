cmake_minimum_required(VERSION 3.0)

project(IPC)

set(IPC_SRC_DIR "src")
set(IPC_LIB_DIR "lib")


add_subdirectory("${IPC_LIB_DIR}")

add_subdirectory("${IPC_SRC_DIR}")