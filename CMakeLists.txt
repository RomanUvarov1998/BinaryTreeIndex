project(binary-tree)

set(SRC_FILES
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/index.c
    ${CMAKE_CURRENT_LIST_DIR}/index.h
    ${CMAKE_CURRENT_LIST_DIR}/index_contiguous.c
    ${CMAKE_CURRENT_LIST_DIR}/index_contiguous.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_compile_options(${PROJECT_NAME}
    PRIVATE -Wall
)
