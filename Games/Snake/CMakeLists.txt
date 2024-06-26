project(arcade_snake
        VERSION 0.1.0
        DESCRIPTION "Snake library for the arcade project"
        LANGUAGES C CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/Snake.cpp
        ${SRC_DIR}/gameLoop.cpp
        ${SRC_DIR}/event.cpp
        ${SRC_DIR}/move.cpp
        ${SRC_DIR}/food.cpp
        ${SRC_DIR}/load.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE arcade_abstractions)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)