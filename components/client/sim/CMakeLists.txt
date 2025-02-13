project(client_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(client_sim_src
    src/client_hardware_model.cpp
    src/client_42_data_provider.cpp
    src/client_data_provider.cpp
    src/client_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB client_sim_inc inc/*.hpp)

set(client_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(client_sim SHARED ${client_sim_src} ${client_sim_inc})
target_link_libraries(client_sim ${client_sim_libs})
install(TARGETS client_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
