set(FileFilterTest_SRCS
    WildcardFilterTest.cpp
)

configure_simplicity_test(FileFilterTest "${FileFilterTest_SRCS}" SimplicityFileSystem SimplicityUtil_StandardCppOnly)
