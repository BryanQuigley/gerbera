/*MT*
    
    MediaTomb - http://www.mediatomb.cc/
    
    js_layout.h - this file is part of MediaTomb.
    
    Copyright (C) 2005 Gena Batyan <bgeradz@mediatomb.cc>,
                       Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>
    
    Copyright (C) 2006-2010 Gena Batyan <bgeradz@mediatomb.cc>,
                            Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>,
                            Leonhard Wimmer <leo@mediatomb.cc>
    
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2
    as published by the Free Software Foundation.
    
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    version 2 along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
    
    $Id$
*/

/// \file js_layout.h

#ifndef __JS_LAYOUT_H__
#define __JS_LAYOUT_H__

#include <memory>

#include "layout.h"

// forward declaration
class Config;
class ContentManager;
class ImportScript;
class Runtime;
class Database;

class JSLayout : public Layout {
protected:
    std::shared_ptr<Config> config;
    std::shared_ptr<Runtime> runtime;

    std::unique_ptr<ImportScript> import_script;

public:
    JSLayout(const std::shared_ptr<Config>& config,
        const std::shared_ptr<Database>& database,
        const std::shared_ptr<ContentManager>& content,
        const std::shared_ptr<Runtime>& runtime);
    ~JSLayout() override;
    void processCdsObject(std::shared_ptr<CdsObject> obj, fs::path rootpath) override;
};

#endif // __JS_LAYOUT_H__
