set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp)

add_compile_definitions(SFML_STATIC)

target_sources(
    ${PROJECT_NAME} PUBLIC
    ${SRC_DIR}/Bird.cpp
    ${SRC_DIR}/Game.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SFML_INCLUDE_PATH}
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    ${LIBS}
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(
        ${PROJECT_NAME} PUBLIC
        "/MTd"
    )
    target_link_options(
        ${PROJECT_NAME} PUBLIC
        /SUBSYSTEM:WINDOWS
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_options(
        ${PROJECT_NAME} PUBLIC
        -mwindows
    )
    target_link_options(
        ${PROJECT_NAME} PUBLIC
        -static-libgcc
        -static-libstdc++
    )
endif()

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RES_DIR} ${CMAKE_CURRENT_BINARY_DIR}/resources)
