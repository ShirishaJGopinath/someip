

#compile server with

g++ someip_server.cpp BoostSerialize.cpp -o server -lboost_serialization -lboost_system

#compile client with

g++ someip_client.cpp BoostSerialize.cpp -o client -lboost_serialization -lboost_system

./server

./client
