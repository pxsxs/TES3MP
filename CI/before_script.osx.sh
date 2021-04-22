#!/bin/sh -e

export CXX=clang++
export CC=clang

DEPENDENCIES_ROOT="/private/tmp/openmw-deps/openmw-deps"
QT_PATH=$(brew --prefix qt@5)
CCACHE_EXECUTABLE=$(brew --prefix ccache)/bin/ccache
mkdir build
cd build

cmake \
-D CMAKE_PREFIX_PATH="$DEPENDENCIES_ROOT;$QT_PATH" \
-D CMAKE_C_COMPILER_LAUNCHER="$CCACHE_EXECUTABLE" \
-D CMAKE_CXX_COMPILER_LAUNCHER="$CCACHE_EXECUTABLE" \
-D CMAKE_CXX_FLAGS="-stdlib=libc++" \
-D CMAKE_C_FLAGS_RELEASE="-g -O0" \
-D CMAKE_CXX_FLAGS_RELEASE="-g -O0" \
-D CMAKE_OSX_DEPLOYMENT_TARGET="10.14" \
-D CMAKE_OSX_SYSROOT="macosx10.14" \
-D CMAKE_BUILD_TYPE=RELEASE \
-D OPENMW_OSX_DEPLOYMENT=TRUE \
-D BUILD_OPENMW=TRUE \
-D BUILD_OPENCS=TRUE \
-D BUILD_ESMTOOL=TRUE \
-D BUILD_BSATOOL=TRUE \
-D BUILD_ESSIMPORTER=TRUE \
-D BUILD_NIFTEST=TRUE \
-D BULLET_USE_DOUBLES=TRUE \
-G"Unix Makefiles" \
..
