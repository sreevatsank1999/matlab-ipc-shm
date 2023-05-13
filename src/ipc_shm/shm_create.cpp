#include <iostream>
#include <string>

#include "boost/interprocess/shared_memory_object.hpp"
#include "boost/interprocess/mapped_region.hpp"

// using boost::interprocess;

#define PAGESIZE 4096

int main(int argc, char* argv[]){
    
    if (argc < 2) {
        std::cout << "Missing arguemnt 1 <name> of Shared Memory file \n";
        std::cout << "Usage: ipc_shm <shm_name> \n";
        std::cout << "\n";
    }

    boost::interprocess::shared_memory_object shm_obj(boost::interprocess::create_only, argv[1], boost::interprocess::read_write);

    constexpr uint32_t N = 1024*256;
    constexpr uint32_t shm_size = N*PAGESIZE;
    
    shm_obj.truncate(shm_size);

    boost::interprocess::mapped_region region(shm_obj,boost::interprocess::read_write,0,shm_size);


    uint32_t shm_indx = 0;

    while (shm_indx<shm_size){

        std::string user_input;
        std::cin >> user_input;
        std::memcpy(region.get_address()+shm_indx,(void*)user_input.data(),user_input.size());

        shm_indx += user_input.size();
    }

    return 0;
}