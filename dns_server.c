#include <stdio.h>
// from getaddrinfo man pages
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Performing DNS Lookup ...\n");

	// DNS Lookup logic
	// using getaddrinfo()

	int sfd, s;


	struct addrinfo *result, *rp;
	const char *node = "www.google.com";
	const char *service = "http";
	struct addrinfo hints;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;	/* Allow IPv4 or IPv6 */
	//hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints.ai_socktype = 0;
	hints.ai_flags = AI_PASSIVE;	/* For wildcard IP address */
	hints.ai_protocol = 0;		/* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	s = getaddrinfo(node, service, &hints, &result);
	
	// Sneaky way to suppress unused variable
	// (void)result;
	// or print it
	// printf("%d", result);
	
	if(s != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	 * Try each address until we successfully bind(2).
	 * If socket(2) (or bind(2)) fails, we (close the socket
	 * and) try the next address. 
	 * */

	/*Print dns lookup results */
	for (rp = result; rp != NULL; rp = rp->ai_next) {

	}

	freeaddrinfo(result); /* No longer needed */

	return 0;
}
