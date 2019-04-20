add_library(tree tree.c)
target_link_libraries(tree queue)

set(PROBLEMS 824 976 888 521)

foreach (problem ${PROBLEMS})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${problem}.cpp)
        add_executable(l${problem} ${problem}.cpp)
    elseif (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${problem}.c)
        add_executable(l${problem} ${problem}.c)
    endif ()
    target_link_libraries(l${problem} util)

endforeach ()



# 代码集合
add_executable(ccodes codes.c)
target_link_libraries(ccodes tree util)

add_executable(cppcodes codes.cpp)
target_link_libraries(cppcodes tree util)