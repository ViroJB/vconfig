find_package(GTest CONFIG REQUIRED)

set(TEST_SOURCES
    main.cpp
    example_test.cpp
)

add_executable(${APP_NAME}_tests
    ${TEST_SOURCES}
)

target_link_libraries(${APP_NAME}_tests PRIVATE 
    GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)

add_test(NAME AllTests COMMAND ${APP_NAME}_tests)