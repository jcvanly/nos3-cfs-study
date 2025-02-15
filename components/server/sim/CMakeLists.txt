project(server_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(server_sim_src
    src/server_hardware_model.cpp
    src/server_42_data_provider.cpp
    src/server_data_provider.cpp
    src/server_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB server_sim_inc inc/*.hpp)

set(server_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(server_sim SHARED ${server_sim_src} ${server_sim_inc})
target_link_libraries(server_sim ${server_sim_libs})
install(TARGETS server_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
