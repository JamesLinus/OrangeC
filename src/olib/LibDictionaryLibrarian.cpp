/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2011, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, 
    with or without modification, are permitted provided that the following 
    conditions are met:
    
    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the
      following disclaimer.
    
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.
    
    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    contact information:
        email: TouchStone222@runbox.com <David Lindauer>
*/
#include "LibDictionary.h"
#include "LibFiles.h"
#include "ObjFile.h"
#include "ObjSymbol.h"
#include "ObjSection.h"
#include "Utils.h"
#include <ctype.h>
#include <iostream>
#include <string.h>

void LibDictionary::CreateDictionary(LibFiles &files)
{
    int total = 0;
    int symbols = 0;
    Clear();
    int i = 0;
    for (LibFiles::FileIterator it = files.FileBegin(); it != files.FileEnd(); ++it)
    {
        const LibFiles::FileDescriptor *fd = (*it);
        if (fd->data)
        {	
            for (ObjFile::SymbolIterator pi = fd->data->PublicBegin(); pi != fd->data->PublicEnd(); ++pi)
            {
                InsertInDictionary((*pi)->GetName().c_str(), i);
            }
            for (ObjFile::SymbolIterator pi = fd->data->ImportBegin(); pi != fd->data->ImportEnd(); ++pi)
            {
                InsertInDictionary((*pi)->GetName().c_str(), i);
            }
            // support for virtual sections
            for (ObjFile::SectionIterator si = fd->data->SectionBegin(); si != fd->data->SectionEnd(); ++si)
            {
                if ((*si)->GetQuals() & ObjSection::virt)
                {
                    int j;
                    std::string name = (*si)->GetName();
                    for (j=0; j < name.size(); j++)
                        if (name[j] == '@')
                            break;
                    if (j < name.size())
                    {
                        name = name.substr(j);
                        InsertInDictionary(name.c_str(), i);
                    }
                }
            }
            i++;
        }
    }
}
void LibDictionary::InsertInDictionary(const char *name, int index)
{
    char buf[2048];
    int l = strlen(name);
    int n = l + 1;
    strncpy(buf, name, 2048);
    buf[2047] = 0;
    if (!caseSensitive)
        for (int i=0; i <= l; i++)
            buf[i] = toupper(buf[i]);
    dictionary[buf] = index;
}
void LibDictionary::Write(FILE *stream)
{
    char sig[4] = { '1','0',0,0 };
    fwrite(&sig[0], 4, 1, stream);
    for (std::map<ObjString, ObjInt, DictCompare>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        short len = it->first.size();
        fwrite(&len, sizeof(len), 1, stream);
        fwrite(it->first.c_str(), len , 1, stream);
        ObjInt fileNum = it->second;
        fwrite(&fileNum, sizeof(fileNum), 1, stream);
    }
    short eof = 0;
    fwrite(&eof, sizeof(eof), 1, stream);
}
