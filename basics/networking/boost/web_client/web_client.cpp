#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;
namespace ssl = boost::asio::ssl;

void handle_response(boost::asio::streambuf& response) {
    std::istream response_stream(&response);
    std::string line;
    while (std::getline(response_stream, line) && !line.empty()) {
        std::cout << line << std::endl;
    }
}

int main() {
    try {
        boost::asio::io_context io_context;

        ssl::context ssl_context(ssl::context::tls_client);
        ssl_context.set_default_verify_paths(); // Load default CA certificates

        tcp::resolver resolver(io_context);
        ssl::stream<tcp::socket> socket(io_context, ssl_context);

        // Resolve the host name
        auto endpoints = resolver.resolve("google.com", "https");
        boost::asio::connect(socket.lowest_layer(), endpoints);

        // Perform SSL handshake
        socket.handshake(ssl::stream_base::client);

        // Prepare and send the request
        std::string request =
            "GET / HTTPS/1.1\r\n"
            "Host: google.com\r\n"
            "Connection: close\r\n\r\n";
        boost::asio::write(socket, boost::asio::buffer(request));

        // Read the response
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n\r\n");

        handle_response(response);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
