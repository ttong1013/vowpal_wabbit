add_executable(vw-slim-test ut_main.cc ut_explore.cc ut_opts.cc ut_vw.cc ut_util.h)

find_package(GTest REQUIRED)
find_package(Boost)
if (Boost_FOUND)
  target_compile_definitions(vw-slim-test PUBLIC BOOST_FOUND)
  target_include_directories(vw-slim-test PUBLIC ${Boost_INCLUDE_DIRS})
endif()
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/Delay_Margin_AudioNetworkPCR_all_cb_FF8.model ${CMAKE_CURRENT_BINARY_DIR}/data/Delay_Margin_AudioNetworkPCR_all_cb_FF8.model COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/cold_start.model ${CMAKE_CURRENT_BINARY_DIR}/data/cold_start.model COPYONLY)
target_link_libraries(vw-slim-test vwslim GTest::GTest GTest::Main gmock)
add_test(NAME vw_unit_test COMMAND vw-slim-test)
