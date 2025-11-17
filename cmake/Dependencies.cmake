include_guard(GLOBAL)

set(GBMU_EXTRA_MODULES_URL "https://github.com/NicolasIRAGNE/CMakeScripts")
set(GBMU_EXTRA_MODULES_TAG "main")

function(_gbmu_fetch_extra_modules)
        if(DEFINED GBMU_EXTRA_MODULES_FETCHED AND GBMU_EXTRA_MODULES_FETCHED)
                return()
        endif()

        FetchContent_Declare(
                ExtraModules
                GIT_REPOSITORY ${GBMU_EXTRA_MODULES_URL}
                GIT_TAG ${GBMU_EXTRA_MODULES_TAG}
                BUILD_COMMAND ""
                CONFIGURE_COMMAND ""
        )

        FetchContent_MakeAvailable(ExtraModules)
        list(APPEND CMAKE_MODULE_PATH ${extramodules_SOURCE_DIR})

        set(GBMU_EXTRA_MODULES_FETCHED ON CACHE INTERNAL "Extra modules already fetched")

        if(NOT DEFINED FETCHED_TARGETS)
                set(FETCHED_TARGETS "" CACHE INTERNAL "Targets fetched via FetchIfMissing")
        endif()
endfunction()

function(gbmu_configure_tooling)
        _gbmu_fetch_extra_modules()

        if(NOT MSVC)
                include(ccache)
        endif()
endfunction()

function(gbmu_configure_dependencies target)
        _gbmu_fetch_extra_modules()
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
