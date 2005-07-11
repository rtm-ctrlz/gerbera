/*  tools.h - this file is part of MediaTomb.

    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>

    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


/// \file tools.h
#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "common.h"

/// \todo genych, pishi chtoeto hernya delaet
zmm::Ref<zmm::Array<zmm::StringBase> > split_string(zmm::String str, char sep);

/// \brief Checks existance of the specified file or path.
/// \param path file or directory to be checked.
/// \param needDir true when checked item has to be a directory.
/// \return true path or file exists
/// \return false path of file not found 
bool check_path(zmm::String path, bool needDir = false);

/// \brief Checks existance of the specified file or path.
/// \param path file or directory to be checked.
/// \param needDir true when checked item has to be a directory.
///
/// More or less the same as check_path, the only difference is,
/// that this function throws an exception if a path or directory
/// was not found or was not the desired type.
void check_path_ex(zmm::String path, bool needDir = false);
    
/// \brief Checks if the string contains any data.
/// \param str String to be checked.
/// \return true if ok
/// \return false if string was either nil or empty
/// 
/// Checks if str is nil or ""
bool string_ok(zmm::String str);

/// \brief Checks if the string contains any data.
/// \param str String to be checked.
/// 
/// Checks if str is nil or "" and throws an exception if that is the case.
void string_ok_ex(zmm::String str);

/// \brief Render HTML that is doing a redirect to the given ip, port and html page.
/// \param ip IP address as string.
/// \param port Port as string.
/// \oaram page HTML document to redirect to.
/// \return string representing the desired HTML document.
zmm::String http_redirect_to(zmm::String ip, zmm::String port, zmm::String page = "");

/// \brief Encodes arbitrary data to a hex string.
/// \param data Buffer that is holding the data
/// \param len Length of the buffer.
/// \return string of the data in hex representation.
zmm::String hex_encode(void *data, int len);

/// \brief Decodes hex encoded string.
/// \param encoded hex-encoded string.
/// \return decoded string
zmm::String hex_decode_string(zmm::String encoded);


/// \brief Generates random id.
/// \return String representing the newly created id.
zmm::String generate_random_id();

/// \brief Converts a string to a URL (meaning: %20 instead of space and so on)
/// \param str String to be converted.
/// \return string that contains the url-escaped representation of the original string.
zmm::String url_escape(zmm::String str);
 
/// \brief Opposite of url_escape :) 
zmm::String url_unescape(zmm::String str);

/// \brief Convert an array of strings to a CSV list, with additional protocol information
/// \param array that needs to be converted
/// \return string containing the CSV list
zmm::String mime_types_to_CSV(zmm::Ref<zmm::Array<zmm::StringBase> > mimeTypes);

/// \todo bgeradz, ffs, comment your shit dammit
zmm::String read_text_file(zmm::String path);

typedef int (*COMPARATOR) (void *, void *);
typedef void * COMPARABLE;

int StringBaseComparatorAsc(void *, void *);

void quicksort(COMPARABLE *arr, int size, COMPARATOR comparator);

/// \brief Renders a string that can be used as the protocolInfo resource 
/// attribute: "http-get:*:mimetype:*"
/// 
/// \param mimetype the mimetype that should be inserted
zmm::String renderProtocolInfo(zmm::String mimetype);

/// \brief converts a number of seconds to H+:MM:SS representation as required by
/// the UPnP spec
zmm::String secondsToHMS(int seconds);

#endif // __TOOLS_H__

