#include "BoostSerialize.h"
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>
using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

void on_send_completed(boost::system::error_code ec, size_t bytes_transferred) {
    if (ec)
        std::cout << "Send failed: " << ec.message() << "\n";
    else
        std::cout << "Send succesful (" << bytes_transferred << " bytes)\n";
}

int main() {
     boost::asio::io_service io_service;
     //socket creation
     tcp::socket socket(io_service);
     //connection
     socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
     // request/message from client

        boost::asio::streambuf buf;
        uint32_t mid1;
	uint32_t leng1;
	uint32_t rid1;
	uint8_t protocol_version1;
	uint8_t interface_version1;
	uint8_t message_type1;
	uint8_t return_code1;
	int size,p;
        std::vector<int> payload1;
      cout<<"\nEnter Message ID:";
      cin>>mid1;
      cout<<"\nEnter Length:";
      cin>>leng1;
      cout<<"\nEnter Request ID:";
      cin>>rid1;
      cout<<"\nEnter Protocol_version:";
      cin>>protocol_version1;
      cout<<"\nEnter Interface_version:";
      cin>>interface_version1;
      cout<<"\nEnter Message_type:";
      cin>>message_type1;
      cout<<"\nEnter Return_code:";
      cin>>return_code1;
      cout<<"\nEnter Size of the Payload:";
      cin>>size;
      cout<<"\nEnter Payload:";
      for(int i=0;i<size;i++){
      cin>>p;
      payload1.push_back(p);
      }
     someip someip1(mid1, leng1,rid1, protocol_version1,interface_version1,message_type1,return_code1,payload1);

     std::ostream oss(&buf);

     //saving data in oss
     someip1.save(oss);

     boost::system::error_code error;
     boost::asio::async_write( socket, buf, on_send_completed);

     return 0;
}
