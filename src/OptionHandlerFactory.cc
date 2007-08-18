/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#include "OptionHandlerFactory.h"
#include "prefs.h"
#include "OptionHandlerImpl.h"

OptionHandlers OptionHandlerFactory::createOptionHandlers()
{
  OptionHandlers handlers;
  handlers.push_back(new HttpProxyOptionHandler(PREF_HTTP_PROXY));
  handlers.push_back(new DefaultOptionHandler(PREF_HTTP_USER));
  handlers.push_back(new DefaultOptionHandler(PREF_HTTP_PASSWD));
  handlers.push_back(new DefaultOptionHandler(PREF_HTTP_PROXY_USER));
  handlers.push_back(new DefaultOptionHandler(PREF_HTTP_PROXY_PASSWD));
  handlers.push_back(new ParameterOptionHandler(PREF_HTTP_AUTH_SCHEME, V_BASIC));
  handlers.push_back(new DefaultOptionHandler(PREF_REFERER));
  handlers.push_back(new NumberOptionHandler(PREF_RETRY_WAIT, 0, 60));
  handlers.push_back(new DefaultOptionHandler(PREF_FTP_USER));
  handlers.push_back(new DefaultOptionHandler(PREF_FTP_PASSWD));
  handlers.push_back(new ParameterOptionHandler(PREF_FTP_TYPE, V_BINARY, V_ASCII));
  handlers.push_back(new ParameterOptionHandler(PREF_FTP_VIA_HTTP_PROXY,
						V_GET, V_TUNNEL));
  handlers.push_back(new UnitNumberOptionHandler(PREF_MIN_SEGMENT_SIZE, 1024));
  handlers.push_back(new ParameterOptionHandler(PREF_HTTP_PROXY_METHOD,
						V_GET, V_TUNNEL));
  handlers.push_back(new NumberOptionHandler(PREF_LISTEN_PORT, 1024, UINT16_MAX));
  handlers.push_back(new BooleanOptionHandler(PREF_FOLLOW_TORRENT));
  handlers.push_back(new BooleanOptionHandler(PREF_NO_PREALLOCATION));
  handlers.push_back(new BooleanOptionHandler(PREF_DIRECT_FILE_MAPPING));
  handlers.push_back(new DefaultOptionHandler(PREF_SELECT_FILE));
  handlers.push_back(new NumberOptionHandler(PREF_SEED_TIME, 0));
  handlers.push_back(new FloatNumberOptionHandler(PREF_SEED_RATIO, 0.0));
  handlers.push_back(new UnitNumberOptionHandler(PREF_MAX_UPLOAD_LIMIT, 0));
  handlers.push_back(new DefaultOptionHandler(PREF_METALINK_VERSION));
  handlers.push_back(new DefaultOptionHandler(PREF_METALINK_LANGUAGE));
  handlers.push_back(new DefaultOptionHandler(PREF_METALINK_OS));
  handlers.push_back(new BooleanOptionHandler(PREF_FOLLOW_METALINK));
  handlers.push_back(new DefaultOptionHandler(PREF_METALINK_LOCATION));
  handlers.push_back(new UnitNumberOptionHandler(PREF_LOWEST_SPEED_LIMIT, 0));
  handlers.push_back(new UnitNumberOptionHandler(PREF_MAX_DOWNLOAD_LIMIT, 0));
  handlers.push_back(new BooleanOptionHandler(PREF_ALLOW_OVERWRITE));
  handlers.push_back(new BooleanOptionHandler(PREF_CHECK_INTEGRITY));
  handlers.push_back(new BooleanOptionHandler(PREF_REALTIME_CHUNK_CHECKSUM));
  handlers.push_back(new BooleanOptionHandler(PREF_DAEMON));
  handlers.push_back(new DefaultOptionHandler(PREF_DIR));
  handlers.push_back(new DefaultOptionHandler(PREF_OUT));
  handlers.push_back(new LogOptionHandler(PREF_LOG));
  handlers.push_back(new NumberOptionHandler(PREF_SPLIT, 1, 5));
  handlers.push_back(new NumberOptionHandler(PREF_TIMEOUT, 1, 600));
  handlers.push_back(new NumberOptionHandler(PREF_MAX_TRIES, 0));
  handlers.push_back(new BooleanOptionHandler(PREF_FTP_PASV));
  handlers.push_back(new BooleanOptionHandler(PREF_SHOW_FILES));
  handlers.push_back(new DefaultOptionHandler(PREF_TORRENT_FILE));
  handlers.push_back(new DefaultOptionHandler(PREF_METALINK_FILE));
  handlers.push_back(new NumberOptionHandler(PREF_METALINK_SERVERS, 1));
  handlers.push_back(new ParameterOptionHandler(PREF_FILE_ALLOCATION,
						V_NONE, V_PREALLOC));
  handlers.push_back(new BooleanOptionHandler(PREF_CONTINUE));
  handlers.push_back(new DefaultOptionHandler(PREF_USER_AGENT));
  handlers.push_back(new BooleanOptionHandler(PREF_NO_NETRC));
  handlers.push_back(new DefaultOptionHandler(PREF_INPUT_FILE));
  handlers.push_back(new NumberOptionHandler(PREF_MAX_CONCURRENT_DOWNLOADS, 1, 45));
  handlers.push_back(new DefaultOptionHandler(PREF_LOAD_COOKIES));
  handlers.push_back(new DefaultOptionHandler(PREF_PEER_ID_PREFIX));

  return handlers;
}
