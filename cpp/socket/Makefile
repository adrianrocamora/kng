all:
	g++ async_udp_echo_server_multithread.cpp -std=c++14 -lboost_system -lboost_thread-mt -o bserver
	g++ blocking_udp_echo_client.cpp -std=c++14 -lboost_system -lboost_thread-mt -o bclient
