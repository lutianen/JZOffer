/**
 * @copyright Copyright (c) 2023
 * FOR STUDY AND RESEARCH SUPPORT ONLY
 *
 * @file epoll_unit.cc
 * @brief 同时处理 TCP 和 UDP 请求的回射服务器
 * @author https://github.com/lutianen
 */

#include <arpa/inet.h>  // sockaddr_in
#include <fcntl.h>
#include <sys/epoll.h>  // epoll_create epoll_ctl epoll_wait
#include <unistd.h>     // close send recv

#include <cassert>
#include <cstring>
#include <iostream>

#define kMAX_EVENT_NUMBER 1024
#define kTCP_BUFFER_SIZE 512
#define kUDP_BUFFER_SIZE 1024

int setNonBlocking(int fd) {
    int old_opt = ::fcntl(fd, F_GETFL);
    int new_opt = old_opt | O_NONBLOCK;
    ::fcntl(fd, F_SETFL, new_opt);
    return old_opt;
}

void addfd(int epollfd, int fd) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    ::epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setNonBlocking(fd);
}

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        std::cout << "Usage: " << ::basename(argv[0])
                  << " ip_address port_number\n";
        return 1;
    }

    const char* ip = argv[1];
    int port = std::atoi(argv[2]);

    int rc = 0;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    ::inet_pton(AF_INET, ip, &addr.sin_addr);
    // Create TCP socket and bind it to port
    int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd != -1);

    rc = ::bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
    assert(rc != -1);

    rc = ::listen(listenfd, 5);
    assert(rc != -1);

    // Create UDP socket and bind it port
    ::bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    ::inet_pton(AF_INET, ip, &addr.sin_addr);
    int udpfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    assert(udpfd >= 0);
    rc = ::bind(udpfd, (struct sockaddr*)&addr, sizeof(addr));
    assert(rc != -1);

    epoll_event events[kMAX_EVENT_NUMBER];
    int epollfd = ::epoll_create(5);
    assert(epollfd != -1);

    // Register TCP socket and UDP socket
    addfd(epollfd, listenfd);
    addfd(epollfd, udpfd);

    while (true) {
        int cnt = ::epoll_wait(epollfd, events, kMAX_EVENT_NUMBER, -1);
        if (cnt < 0) {
            std::cerr << "Epoll failure\n";
            break;
        }

        for (int i = 0; i < cnt; ++i) {
            int sockfd = events[i].data.fd;

            if (sockfd == listenfd) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int connfd = ::accept(listenfd, (struct sockaddr*)&client_addr,
                                      &client_addr_len);
                addfd(epollfd, connfd);
            } else if (sockfd == udpfd) {
                char buf[kUDP_BUFFER_SIZE];
                std::memset(buf, 0, kUDP_BUFFER_SIZE);
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr_len);

                rc = ::recvfrom(sockfd, buf, kUDP_BUFFER_SIZE - 1, 0,
                                (struct sockaddr*)&client_addr,
                                &client_addr_len);
                if (rc > 0) {
                    std::cout << "UDP: " << buf << std::endl;
                    rc = ::sendto(sockfd, buf, kUDP_BUFFER_SIZE - 1, 0,
                                  (struct sockaddr*)&client_addr,
                                  client_addr_len);
                }
            } else if (events[i].events & EPOLLIN) {
                char buf[kTCP_BUFFER_SIZE];
                while (true) {
                    std::memset(buf, 0, kTCP_BUFFER_SIZE);
                    rc = ::recv(sockfd, buf, kTCP_BUFFER_SIZE - 1, 0);
                    if (rc < 0) {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) break;
                        ::close(sockfd);
                        break;
                    } else if (rc == 0)
                        ::close(sockfd);
                    else {
                        std::cout << "TCP: " << buf << std::endl;
                        ::send(sockfd, buf, kTCP_BUFFER_SIZE, 0);
                    }
                }
            } else {
                std::cout << "Something else happend \n";
            }
        }
    }

    ::close(listenfd);
    return 0;
}