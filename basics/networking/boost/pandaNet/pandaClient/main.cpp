/*

Building the TCP client:
1. Include the library.
2. Wrap io context in a try catch.
3. Create a resolver.
4. Create a socket to save the connection.
5. Create an infinte ,while, loop.
6. Buffer to recieve.
7. If there is an error. 

// The resolver resolves hostnames for establishing connections but does not connect itself... the socket does that.

 */


 #include <boost/system/detail/error_code.hpp>
#include <exception>
 #include <iostream>
 #include <boost/asio.hpp>
 #include <string>

using boost::asio::ip::tcp;

void startClient() {
    try{
        boost::asio::io_context ioc;
        tcp::resolver resolver{ioc};
        auto endpoints = resolver.resolve("127.0.0.1","1313");
        tcp::socket socket{ioc};
        
        boost::asio::connect(socket,endpoints);
        while (1){
            // Listen for messages
            std::array <char,128> buf{};
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf),error);
        
        if (error == boost::asio::error::eof){
            // Clean connection cut off
            break;
        } else if (error){
            throw boost::system::system_error(error) ;
         }
         std::cout.write(buf.data(),len);
        }
    } catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

 int main(){

    startClient();

    return 0;
 }