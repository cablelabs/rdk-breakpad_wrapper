/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2017 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#include "breakpad_wrapper.h"
#include "client/linux/handler/exception_handler.h"
#include <stdio.h>

static bool breakpadDumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                                                                void* context,
                                                                bool succeeded)
{
        /* Do the desired exit process here*/
        printf("breakpad Call back ..................................................");
        printf("Print descriptor path: %s\n", descriptor.path());
        return succeeded;
}


void breakpad_ExceptionHandler()

{

        printf("\t\t\t\t ********ENTER breakpad_ExceptionHandler****************** \n");
	static google_breakpad::ExceptionHandler* excHandler = NULL;
       if (excHandler)
       {
           printf("Handler exist \n");
           return ;
       }
	excHandler = new google_breakpad::ExceptionHandler(google_breakpad::MinidumpDescriptor("/minidumps"), NULL, breakpadDumpCallback, NULL, true, -1);
        printf("\t\t\t\t ******** breakpad_ExceptionHandler EXIT****************** \n");
}

