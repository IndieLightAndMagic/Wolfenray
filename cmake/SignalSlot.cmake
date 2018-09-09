
get_filename_component(3RD_INCLUDE ${CMAKE_SOURCE_DIR}/3rd/include ABSOLUTE)
get_filename_component(SIGNALANDSLOTS_DISTRO_INCLUDE ${ROOT_ROOT}/signalslot/dist/include ABSOLUTE)
FILE(GLOB 3RD_HEADER_INCLUDES "${SIGNALANDSLOTS_DISTRO_INCLUDE}/*.*")
FILE(COPY ${3RD_HEADER_INCLUDES} DESTINATION ${3RD_INCLUDE})
