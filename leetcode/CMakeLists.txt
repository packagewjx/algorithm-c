add_library(tree tree.c)
target_link_libraries(tree queue)



set(PROBLEMS 771 709 929 804 961 977 905 832 657 942 461 944 617 728 852 933 999 561 1002 965 700 509 922 883 559 908 811
        867 897 590 589 985 876 557 344 821 806 872 476 893 500 766 682 463 884 669 104 937 136 575 868 412 496 429 566
        1009 762 637 693 226 824)

foreach (problem ${PROBLEMS})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${problem}.cpp)
        add_executable(l${problem} ${problem}.cpp)
    elseif (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${problem}.c)
        add_executable(l${problem} ${problem}.c)
    endif ()
    target_link_libraries(l${problem} util)

endforeach ()

target_link_libraries(l897 tree)
target_link_libraries(l872 tree)
target_link_libraries(l637 tree)
target_link_libraries(l226 tree)
