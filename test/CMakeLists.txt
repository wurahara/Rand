ENABLE_TESTING()

FILE(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
ADD_EXECUTABLE(
        Rand_Test
        ${TEST_FILES}
)

TARGET_LINK_LIBRARIES(
        Rand_Test
        PRIVATE GTest::gtest_main
        PRIVATE Rand
)

INCLUDE(GoogleTest)
GTEST_DISCOVER_TESTS(Rand_Test)