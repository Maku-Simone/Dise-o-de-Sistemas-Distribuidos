paquet: datagramPaquet.cpp datagramPaquet.h
	g++ datagramPaquet.cpp -c
socket: datagramSocket.cpp datagramSocket.h datagramPaquet.o
	g++ -c datagramSocket.cpp datagramPaquet.o
OOPclient: OOPclient.cpp datagramPaquet.o datagramSocket.o
	g++ OOPclient.cpp datagramPaquet.o datagramSocket.o -o OOPclient