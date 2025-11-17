include_guard(GLOBAL)

include(FetchContent)
include(CMakeParseArguments)

# Declare a FetchContent block only when a dependency is not already available.
function(FetchIfMissing name)
    set(options)
    set(oneValueArgs GIT_REPOSITORY GIT_TAG URL URL_HASH)
    set(multiValueArgs CMAKE_ARGS PATCH_COMMAND)
    cmake_parse_arguments(FIM "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Short-circuit if the dependency already exists as a target or through find_package.
    if(TARGET ${name} OR TARGET ${name}::${name} OR (DEFINED ${name}_FOUND AND ${name}_FOUND))
        return()
    endif()

    if(NOT FIM_URL AND NOT FIM_GIT_REPOSITORY)
        message(FATAL_ERROR "FetchIfMissing(${name}) requires URL or GIT_REPOSITORY")
    endif()

    FetchContent_Declare(
        ${name}
        GIT_REPOSITORY ${FIM_GIT_REPOSITORY}
        GIT_TAG ${FIM_GIT_TAG}
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        URL ${FIM_URL}
        URL_HASH ${FIM_URL_HASH}
        PATCH_COMMAND ${FIM_PATCH_COMMAND}
        CMAKE_ARGS ${FIM_CMAKE_ARGS}
    )

    list(APPEND FETCHED_TARGETS ${name})
    set(FETCHED_TARGETS "${FETCHED_TARGETS}" PARENT_SCOPE)
endfunction()
