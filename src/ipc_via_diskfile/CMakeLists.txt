

set(ipc_via_diskfile_SRC_FILES 
        "producer.cpp"    
    )

add_executable(ipc_via_diskfile "${ipc_via_diskfile_SRC_FILES}")
target_link_libraries(ipc_via_diskfile PRIVATE pthread stdc++fs)