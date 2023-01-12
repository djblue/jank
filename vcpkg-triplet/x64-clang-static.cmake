set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE static)
# folly uses debug deps in debug builds, so we can't set this.
#set(VCPKG_BUILD_TYPE release)

set(VCPKG_CMAKE_SYSTEM_NAME ${CMAKE_HOST_SYSTEM_NAME})
#set(VCPKG_CXX_FLAGS "${VCPKG_CXX_FLAGS} -stdlib=libc++")
set(VCPKG_CXX_FLAGS "${VCPKG_CXX_FLAGS}")
set(VCPKG_C_FLAGS "${VCPKG_C_FLAGS}")
