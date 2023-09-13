#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << ::basename(argv[0])
                  << " server_addr server_port\n";
        return 1;
    }

    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    ::inet_pton(AF_INET, argv[1], &addr.sin_addr);
    addr.sin_port = htons(std::atoi(argv[2]));

    int rc = 0;
    rc = ::connect(sockfd, (const struct sockaddr*)&addr, sizeof(addr));
    if (rc < 0) {
        std::cerr << "Failed to connect to server\n";
        ::close(sockfd);
        return 1;
    }

    while (1) {
        int type;
        std::string oob_buf;
        std::cin >> type >> oob_buf;

        if (type == 0) {
            rc = ::send(sockfd, oob_buf.data(), oob_buf.size(), MSG_OOB);
            if (rc < 0) {
                std::cerr << "Failed to send out-of-band data\n";
            } else {
                std::cout << "Sent " << rc
                          << " bytes of out-of-band data: " << oob_buf
                          << std::endl;
            }
        } else if (type == 1) {
            rc = ::send(sockfd, oob_buf.data(), oob_buf.size(), 0);
            if (rc < 0) {
                std::cerr << "Failed to send normal data\n";
            } else {
                std::cout << "Sent " << rc
                          << " bytes of normal data: " << oob_buf << std::endl;
            }
        }
    }
    ::close(sockfd);
    return 0;
}