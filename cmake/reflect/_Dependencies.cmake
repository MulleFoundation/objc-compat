# This file will be regenerated by `mulle-sourcetree-to-cmake` via
# `mulle-sde reflect` and any edits will be lost.
#
# This file will be included by cmake/share/Files.cmake
#
# Disable generation of this file with:
#
# mulle-sde environment set MULLE_SOURCETREE_TO_CMAKE_DEPENDENCIES_FILE DISABLE
#
if( MULLE_TRACE_INCLUDE)
   message( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

#
# Generated from sourcetree: AA752614-F078-4EE6-9F21-E234626335B7;mulle-objc-compat;no-all-load,no-cmake-loader,no-cmake-searchpath,no-import,no-platform-darwin;
# Disable with : `mulle-sourcetree mark mulle-objc-compat no-link`
# Disable for this platform: `mulle-sourcetree mark mulle-objc-compat no-cmake-platform-${MULLE_UNAME}`
# Disable for a sdk: `mulle-sourcetree mark mulle-objc-compat no-cmake-sdk-<name>`
#
if( NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   if( NOT MULLE_OBJC_COMPAT_LIBRARY)
      find_library( MULLE_OBJC_COMPAT_LIBRARY NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-objc-compat${CMAKE_DEBUG_POSTFIX}${CMAKE_STATIC_LIBRARY_SUFFIX} ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-objc-compat${CMAKE_STATIC_LIBRARY_SUFFIX} mulle-objc-compat NO_CMAKE_SYSTEM_PATH NO_SYSTEM_ENVIRONMENT_PATH)
      message( STATUS "MULLE_OBJC_COMPAT_LIBRARY is ${MULLE_OBJC_COMPAT_LIBRARY}")
      #
      # The order looks ascending, but due to the way this file is read
      # it ends up being descending, which is what we need.
      #
      if( MULLE_OBJC_COMPAT_LIBRARY)
         #
         # Add MULLE_OBJC_COMPAT_LIBRARY to DEPENDENCY_LIBRARIES list.
         # Disable with: `mulle-sourcetree mark mulle-objc-compat no-cmake-add`
         #
         set( DEPENDENCY_LIBRARIES
            ${DEPENDENCY_LIBRARIES}
            ${MULLE_OBJC_COMPAT_LIBRARY}
            CACHE INTERNAL "need to cache this"
         )
         #
         # Inherit information from dependency.
         # Encompasses: no-cmake-searchpath,no-cmake-dependency,no-cmake-loader
         # Disable with: `mulle-sourcetree mark mulle-objc-compat no-cmake-inherit`
         #
         # temporarily expand CMAKE_MODULE_PATH
         get_filename_component( _TMP_MULLE_OBJC_COMPAT_ROOT "${MULLE_OBJC_COMPAT_LIBRARY}" DIRECTORY)
         get_filename_component( _TMP_MULLE_OBJC_COMPAT_ROOT "${_TMP_MULLE_OBJC_COMPAT_ROOT}" DIRECTORY)
         #
         #
         # Search for "DependenciesAndLibraries.cmake" to include.
         # Disable with: `mulle-sourcetree mark mulle-objc-compat no-cmake-dependency`
         #
         foreach( _TMP_MULLE_OBJC_COMPAT_NAME "mulle-objc-compat")
            set( _TMP_MULLE_OBJC_COMPAT_DIR "${_TMP_MULLE_OBJC_COMPAT_ROOT}/include/${_TMP_MULLE_OBJC_COMPAT_NAME}/cmake")
            # use explicit path to avoid "surprises"
            if( EXISTS "${_TMP_MULLE_OBJC_COMPAT_DIR}/DependenciesAndLibraries.cmake")
               unset( MULLE_OBJC_COMPAT_DEFINITIONS)
               list( INSERT CMAKE_MODULE_PATH 0 "${_TMP_MULLE_OBJC_COMPAT_DIR}")
               # we only want top level INHERIT_OBJC_LOADERS, so disable them
               if( NOT NO_INHERIT_OBJC_LOADERS)
                  set( NO_INHERIT_OBJC_LOADERS OFF)
               endif()
               list( APPEND _TMP_INHERIT_OBJC_LOADERS ${NO_INHERIT_OBJC_LOADERS})
               set( NO_INHERIT_OBJC_LOADERS ON)
               #
               include( "${_TMP_MULLE_OBJC_COMPAT_DIR}/DependenciesAndLibraries.cmake")
               #
               list( GET _TMP_INHERIT_OBJC_LOADERS -1 NO_INHERIT_OBJC_LOADERS)
               list( REMOVE_AT _TMP_INHERIT_OBJC_LOADERS -1)
               #
               list( REMOVE_ITEM CMAKE_MODULE_PATH "${_TMP_MULLE_OBJC_COMPAT_DIR}")
               set( INHERITED_DEFINITIONS
                  ${INHERITED_DEFINITIONS}
                  ${MULLE_OBJC_COMPAT_DEFINITIONS}
                  CACHE INTERNAL "need to cache this"
               )
               break()
            else()
               message( STATUS "${_TMP_MULLE_OBJC_COMPAT_DIR}/DependenciesAndLibraries.cmake not found")
            endif()
         endforeach()
      else()
         # Disable with: `mulle-sourcetree mark mulle-objc-compat no-require-link`
         message( FATAL_ERROR "MULLE_OBJC_COMPAT_LIBRARY was not found")
      endif()
   endif()
   endif()
