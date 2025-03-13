/*

 Building the TCP server:
1. Include the Library. 
2. Create & wrap io context in a try catch.
3. Create an acceptor object that will listen to incoming connections.
4. Create a socket ,to save the connection,in an infinite,while, loop.
5. Inform the client that they are connected.
6. Complete the Catch phrase by passing the exeption.

*/


#include <boost/asio/basic_socket_acceptor.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/detail/error_code.hpp>
#include <exception>
#include <iostream>
#include <string>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void startServer(){

    try {
        boost::asio::io_context ioc;
        tcp::acceptor acceptor(ioc,tcp::endpoint(tcp::v4(),1313));

        while (1){
            std::cout << "Accepting connections on port: 1313." << std::endl;

            tcp::socket socket(ioc);
            acceptor.accept(socket);
            
            std::cout << "Client conected successfully." << std::endl;
            
            std::string acceptMsg = "Hello client";
            boost::system::error_code error;
            boost::asio::write(socket, boost::asio::buffer(acceptMsg),error);
        }
    } catch(std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


int main(){

    startServer();

    return 0 ;
}