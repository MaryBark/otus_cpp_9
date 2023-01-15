#cmake_minimum_required(VERSION 3.5)

#project(Otus_cpp9 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(Otus_cpp9 main.cpp rai_concept.h rai_concept.cpp)


cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(Otus_cpp9 VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

add_executable(Otus_cpp9 main.cpp rai_concept.h rai_concept.cpp)
#add_library(Otus_cpp9 rai_concept.h rai_concept.cpp)

set_target_properties(Otus_cpp9 Otus_cpp9 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )

find_package(Boost REQUIRED)

target_include_directories(Otus_cpp9
    PRIVATE "${CMAKE_BINARY_DIR}"
)

#target_link_libraries(Otus_cpp9 PRIVATE
#    allocator
#)



install(TARGETS Otus_cpp9 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)
include(CPack)
