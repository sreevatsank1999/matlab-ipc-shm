

set(ipc_shm_SRC_FILES 
        "shm_create.cpp"    
    )

add_executable(ipc_shm "${ipc_shm_SRC_FILES}")
target_link_libraries(ipc_shm PRIVATE Boost::interprocess rt)