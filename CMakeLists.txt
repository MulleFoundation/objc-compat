cmake_minimum_required( VERSION 3.15)

project( objc-compat VERSION 0.20.6 LANGUAGES C)



### mulle-sde environment

# add cmake module paths to search path
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake/share")
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake/reflect")
list( INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include( Environment)

include( Files)

### Library

if( HEADERS_PHASE)
   install( FILES ${INSTALL_PUBLIC_HEADERS}  DESTINATION "include/objc-compat")
   install( FILES ${INSTALL_PRIVATE_HEADERS} DESTINATION "include/objc-compat")
   install( FILES ${INSTALL_CMAKE_INCLUDES}          DESTINATION "include/objc-compat/cmake")

   # short cut out
   if( NOT COMPILE_PHASE AND NOT LINK_PHASE)
      return()
   endif()
endif()

include( FinalOutput OPTIONAL)
