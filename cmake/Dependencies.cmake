include_guard(GLOBAL)

include(FetchContent)

function(gbmu_configure_tooling)
        if(NOT MSVC)
                include(ccache)
        endif()
endfunction()

function(gbmu_configure_dependencies target)
        include(FetchIfMissing)

        find_package(Threads REQUIRED)
        target_link_libraries(${target} PRIVATE Threads::Threads)

        if(WIN32)
                FetchIfMissing(
                        WINEDITLINE
                        GIT_REPOSITORY "https://github.com/NicolasIRAGNE/wineditline"
                        GIT_TAG WinEditLine-2.207-Patch
                )

                FetchContent_MakeAvailable(WINEDITLINE)
                target_link_libraries(${target} PRIVATE edit_static)
        else()
                target_compile_definitions(${target} PUBLIC USE_READLINE_STATIC=1 READLINE_LIBRARY=1)
                find_package(Readline REQUIRED)
                target_include_directories(${target} PRIVATE ${Readline_INCLUDE_DIR})
                target_link_libraries(${target} PRIVATE ${Readline_LIBRARY})
                target_include_directories(${target} PUBLIC ${Readline_INCLUDE_DIR})
        endif()
endfunction()
