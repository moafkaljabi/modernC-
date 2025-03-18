
/*

We will have three main dirs;
1.Networking; comon.
2. TCP server.
3. TCP client.

Each wih its CMakeLists.txt. 



 Building the TCP server:
1. Include the Library. 
2. Create & wrap io context in a try catch.
3. Create an acceptor object that will listen to incoming connections.
4. Create a socket ,to save the connection,in an infinite,while, loop.
5. Inform the client that they are connected.
6. Complete the Catch phrase by passing the exeption.


Building the TCP client:
1. Include the library.
2. Wrap io context in a try catch.
3. Create a resolver.
4. Create a socket to save the connection.
5. Create an infinte ,while, loop.
6. Buffer to recieve.
7. If there is an error. 
 


*/


#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <iostream>
#include <string>


using boost::asio::ip::tcp;

namespace ssl = boost::asio::ssl;


void handle_response();
void perform_http_request();


void handle_response(){

}


void perform_http_request(){
    try {
        
        
        // Resolve the hostname.

        // Perform SSL handshake.

        // Prepare and send the request.

        // Read the response.



    } catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}




int main(){

perform_http_request();
    return 0;
}