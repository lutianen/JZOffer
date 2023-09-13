# add_executable(ACMIO ACM_IO.cc)
# add_executable(DeadLockDemo DeadLock.cc)
# add_executable(LuxString LuxString.cc)
# add_executable(Graph Graph.cc)
# add_executable(quickPow quickPow.cc)
# add_executable(regex regex.cc)
# # add_executable(Singleton Singleton.cc)
# add_executable(Sort sortAlgorithm.cc)
add_executable(test test.cc)
# add_executable(UnionFindUnitTest UnionFind_unit.cc)
# add_executable(TypeNameTest TypeName.h Test.cc)

add_executable(thread_unit thread_unit.cc)
target_link_libraries(thread_unit pthread)

add_executable(select_unit select_unit.cc)
add_executable(select_unit_client select_unit_client.cc)

add_executable(epoll_unit epoll_unit.cc)