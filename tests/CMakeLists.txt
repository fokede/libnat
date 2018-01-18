add_subdirectory(libupnp)

add_test(natpmp LIBS nat ${Boost_LIBRARIES})
add_test(upnp LIBS nat upnpc ${Boost_LIBRARIES})
