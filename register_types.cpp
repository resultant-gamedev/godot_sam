/*************************************************************************/
/*  register_types.cpp                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#include "register_types.h"
#include "object_type_db.h"
#include "SuperAnimNode.h"
#include "SuperAnimResource.h"

SuperAnimDataFormatLoader *resource_loader_sam = NULL;
SuperAnimDataFormatSaver *resource_saver_sam = NULL;

void register_superanim_types() {
    MYPRINT("+Registring the SuperAnim\n");
    ObjectTypeDB::register_type<SuperAnimNode>();
    ObjectTypeDB::register_type<SuperAnimData>();

    resource_loader_sam = memnew( SuperAnimDataFormatLoader );
	ResourceLoader::add_resource_format_loader(resource_loader_sam);

//    resource_saver_sam = memnew( SuperAnimDataFormatSaver );
//    ResourceSaver::add_resource_format_saver(resource_saver_sam);
    MYPRINT("-Registring the SuperAnim\n");
}



void unregister_superanim_types() {
    
    if(resource_loader_sam){
        memdelete(resource_loader_sam);
        resource_loader_sam = NULL;
    }

    if(resource_saver_sam){
        memdelete(resource_saver_sam);
        resource_saver_sam = NULL;
    }
}
