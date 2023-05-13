// #include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <random>
#include <string>
#include <thread>
#include <chrono>

using namespace std;



std::string random_string( std::size_t length )
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz" ;
    static std::default_random_engine rng( std::time(nullptr) ) ;
    static std::uniform_int_distribution<std::size_t> distribution( 0, alphabet.size() - 1 ) ;

    std::string str ;   str.reserve(length);
    while( str.size() < length ) str += alphabet[ distribution(rng) ] ;
    return str ;
}


int main(){

    experimental::filesystem::path filename = "write_file.txt";

    fstream writefile(filename, ios_base::in | ios_base::out);



    while (true){

        string message = random_string(5) + '\n';
        writefile.write(message.c_str(),message.size());

        // writefile.flush();
        this_thread::sleep_for(chrono::milliseconds(50));

    }

    return 0;
}