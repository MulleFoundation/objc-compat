cmake_minimum_required( VERSION 3.1)

project( objc-compat C)


### mulle-sde environment

# add cmake module paths to search path
list( INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake/share")
list( INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake/reflect")
list( INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake")

include( Environment)

include( Files)

### Library

if( HEADERS_PHASE)
   install( FILES ${INSTALL_PUBLIC_HEADERS}  DESTINATION "include/objc-compat")
   install( FILES ${INSTALL_PRIVATE_HEADERS} DESTINATION "include/objc-compat/private")
   install( FILES ${CMAKE_INCLUDES}          DESTINATION "include/objc-compat/cmake")

   # short cut out
   if( NOT COMPILE_PHASE AND NOT LINK_PHASE)
      return()
   endif()
endif()

include( FinalOutput OPTIONAL)
