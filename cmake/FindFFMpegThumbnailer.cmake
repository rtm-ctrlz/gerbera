# - Try to find ffmpegthumbnailer
# Once done this will define
#
#  FFMPEGTHUMBNAILER_FOUND - system has FFMpegThumbnailer
#  FFMPEGTHUMBNAILER_INCLUDE_DIRS - the FFMpegThumbnailer include directory
#  FFMPEGTHUMBNAILER_LIBRARIES - Link these to use FFMpegThumbnailer
#

FIND_PACKAGE(PkgConfig QUIET)
PKG_CHECK_MODULES(PC_FFTHUMB QUIET libffmpegthumbnailer)

FIND_PATH(FFMPEGTHUMBNAILER_INCLUDE_DIRS videothumbnailerc.h
    HINTS ${PC_FFTHUMB_INCLUDEDIR} ${PC_FFTHUMB_INCLUDE_DIRS}
    PATH_SUFFIXES ffmpegthumbnailer libffmpegthumbnailer)

FIND_LIBRARY(FFMPEGTHUMBNAILER_LIBRARIES
    NAMES libffmpegthumbnailer ffmpegthumbnailer
    HINTS ${PC_FFTHUMB_LIBDIR} ${PC_FFTHUMB_LIBRARY_DIRS})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FFMpegThumbnailer
    REQUIRED_VARS FFMPEGTHUMBNAILER_LIBRARIES FFMPEGTHUMBNAILER_INCLUDE_DIRS)

MARK_AS_ADVANCED(
    FFMPEGTHUMBNAILER_INCLUDE_DIR
    FFMPEGTHUMBNAILER_LIBRARY
)
