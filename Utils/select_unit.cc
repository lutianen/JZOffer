#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << ::basename(argv[0])
                  << " ip_address port_number" << std::endl;
        return 1;
    }

    const char* ip = argv[1];
    int port = ::atoi(argv[2]);

    int rc = 0;
    struct sockaddr_in addr;
    ::bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    ::inet_pton(AF_INET, ip, &addr.sin_addr);
    addr.sin_port = ::htons(port);

    int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    rc = ::bind(listenfd, (const struct sockaddr*)&addr, sizeof(addr));
    assert(rc != -1);
    rc = ::listen(listenfd, 5);
    assert(rc != -1);

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int connfd =
        ::accept(listenfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (connfd < 0) {
        std::cout << "errno is: " << errno << std::endl;
        ::close(listenfd);
    }

    char buf[1024];
    fd_set read_fds;
    fd_set exception_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&exception_fds);

    while (1) {
        std::memset(buf, '\0', sizeof(buf));
        /* 每次调用 select 前都需要重新在 read_fds 和 exception_fds
         * 中设置文件描述符 connfd，因为事件发生后，文件描述符集合将被内核修改
         */
        FD_SET(connfd, &read_fds);
        FD_SET(connfd, &exception_fds);

        rc = ::select(connfd + 1, &read_fds, nullptr, &exception_fds, nullptr);
        if (rc < 0) {
            std::cout << "select failure\n";
            break;
        }

        // 可读事件，采用普通的 recv 函数读取数据
        if (FD_ISSET(connfd, &read_fds)) {
            rc = ::recv(connfd, buf, sizeof(buf) - 1, 0);
            if (rc <= 0) break;

            std::cout << "get " << rc << " bytes of nomal data: " << buf
                      << std::endl;
        }
        // 异常事件，采用带 MSG_OOB 标志的 recv 函数读取带外数据
        else if (FD_ISSET(connfd, &exception_fds)) {
            rc = ::recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
            if (rc <= 0) break;

            std::cout << "get " << rc << " bytes of oob data: " << buf
                      << std::endl;
        }
    }

    ::close(connfd);
    ::close(listenfd);
    return 0;
}
