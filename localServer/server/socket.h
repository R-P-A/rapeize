#ifndef SOCKET
#define SOCKET

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket {
	private:
		int mSock;
		sockaddr_in mAddr;
		
	public:
		Socket();
		virtual ~Socket();

		// Server initialization
		bool create();
		bool bind (const int port);
		bool listen() const;
		bool accept (Socket&) const;

		// Client initialization
		bool connect (const string host, const int port);

		// Data Transimission
		bool send (const string) const;
		int recv (string&) const;

		void set_non_blocking (const bool);

		bool is_valid() const {
			return mSock != -1;
		}

};

#endif	// SOCKET
