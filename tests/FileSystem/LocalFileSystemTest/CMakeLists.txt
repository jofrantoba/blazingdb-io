set(LocalFileSystemTest_SRCS
    ${CMAKE_SOURCE_DIR}/src/Config/Config.cpp
    LocalFileSystemTest.cpp
)

#TODO
#WARNING this test depends on all simplicity libs, this is not good we need to find a way to don't use config module in fs module
#TODO rerty delay config can be a connection arg for local file systems
configure_simplicity_test(LocalFileSystemTest "${LocalFileSystemTest_SRCS}" "${simplicity_libraries}")
