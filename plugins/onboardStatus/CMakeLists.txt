add_library(dronecore_onboardStatus SHARED
    onboardStatus.cpp
    onboardStatus_impl.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/core
    SYSTEM ${CMAKE_SOURCE_DIR}/third_party/mavlink/include
)

target_link_libraries(dronecore_onboardStatus
    dronecore
)

install(FILES
    onboardStatus.h
    DESTINATION ${dronecore_install_include_dir}
)

install(TARGETS dronecore_onboardStatus
    #EXPORT dronecore-targets
    DESTINATION ${dronecore_install_lib_dir}
)
