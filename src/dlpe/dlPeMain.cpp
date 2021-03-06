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
#include "dlPeMain.h"
#include "CmdSwitch.h"
#include "CmdFiles.h"
#include "Utils.h"
#include "ObjSection.h"
#include "ObjMemory.h"
#include "ObjIeee.h"
#include "ObjExpression.h"
#include "ObjSymbol.h"
#include "ObjFile.h"
#include "ObjFactory.h"
#include "PEObject.h"
#include "MZHeader.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

#ifdef MICROSOFT
#define system(x) winsystem(x)
extern "C" int winsystem(const char *);
#endif

CmdSwitchParser dlPeMain::SwitchParser;
CmdSwitchString dlPeMain::stubSwitch(SwitchParser, 's');
CmdSwitchString dlPeMain::modeSwitch(SwitchParser, 'm');
CmdSwitchString dlPeMain::outputFileSwitch(SwitchParser, 'o');
CmdSwitchString dlPeMain::DebugFile(SwitchParser, 'v');

int dlPeMain::osMajor = 5;
int dlPeMain::osMinor = 1;
int dlPeMain::userMajor = 0;
int dlPeMain::userMinor = 0;
int dlPeMain::subsysMajor = 5;
int dlPeMain::subsysMinor = 1;

int dlPeMain::dllFlags = 0;//0x8140; 

unsigned char dlPeMain::defaultStubData[] =
{
    0x4D,0x5A,0x6C,0x00,0x01,0x00,0x00,0x00,
    0x04,0x00,0x11,0x00,0xFF,0xFF,0x03,0x00,

    0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
    0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,

    0x0E,0x1F,0xBA,0x0E,0x00,0xB4,0x09,0xCD,
    0x21,0xB8,0x00,0x4C,0xCD,0x21,0x54,0x68,

    0x69,0x73,0x20,0x70,0x72,0x6F,0x67,0x72,
    0x61,0x6D,0x20,0x72,0x65,0x71,0x75,0x69,

    0x72,0x65,0x73,0x20,0x57,0x69,0x6E,0x33,
    0x32,0x0D,0x0A,0x24,0x00,0x00,0x00,0x00
} ;	
int dlPeMain::defaultStubSize = sizeof(defaultStubData);

char *dlPeMain::usageText = "[options] relfile\n"
            "\n"
            "/mxxx  Set output file type\n"
            "/oxxx  Set output file name\n"
            "/sxxx  Set stub file name\n"
            "\n"
            "Available output file types:\n"
            "   CON - Windows console (default)\n"
            "   GUI - Windows GUI\n"
            "   DLL - Windows DLL\n"
            "\nTime: " __TIME__ "  Date: " __DATE__;
            

int main(int argc, char **argv)
{
    dlPeMain downloader;
    return downloader.Run(argc, argv);
}
dlPeMain::~dlPeMain()
{
    for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        PEObject *p = (*it);
        delete p;
    }
    delete stubData;
    delete factory;
}
void dlPeMain::ParseOutResourceFiles(int *argc, char **argv)
{
    for (int i = 0; i < *argc; i++)
    {
        int npos = std::string(argv[i]).find_last_of(".");
        if (npos != std::string::npos)
        {
            if (!stricmp(argv[i]+npos, ".res"))
            {
                resources.AddFile(argv[i]);
                memcpy(argv + i , argv+ i + 1, sizeof(argv[0]) * *argc - i - 1);
                (*argc)--, i--;
            }
        }
    }
}
bool dlPeMain::ParseOutDefFile(int *argc, char **argv)
{
    int n = 0;
    for (int i = 0; i < *argc; i++)
    {
        int npos = std::string(argv[i]).find_last_of(".");
        if (npos != std::string::npos)
        {
            if (!stricmp(argv[i]+npos, ".def"))
            {
                defFile = argv[i];
                memcpy(argv+i, argv+i+1, sizeof(argv[0]) * *argc - i - 1);
                (*argc)--, i--;
                n++;
            }
        }
    }
    return n <= 1;
}
bool dlPeMain::GetMode()
{
    mode = UNKNOWN;
    const std::string &val = modeSwitch.GetValue();
    if (val.size() == 0)
    {
        mode = CONSOLE;
    }
    else
    {
        if (val == "CON")
            mode = CONSOLE;
        else if (val == "GUI")
            mode = GUI;
        else if (val == "DLL")
            mode = DLL;
    }
    return mode != UNKNOWN;
}
void dlPeMain::ReadValues()
{
    for (ObjFile::SymbolIterator it = file->DefinitionBegin(); it != file->DefinitionEnd(); it++)
    {
        ObjDefinitionSymbol *p = (ObjDefinitionSymbol *)(*it);
        if (p->GetName() == "FILEALIGN")
        {
            fileAlign = p->GetValue();
        }
        else if (p->GetName() == "IMAGEBASE")
        {
            imageBase = p->GetValue();
        }
        else if (p->GetName() == "IMPORTTHUNKS")
        {
            importThunkVA = p->GetValue();
        }
        else if (p->GetName() == "OBJECTALIGN")
        {
            objectAlign = p->GetValue();
        }
        else if (p->GetName() == "HEAPCOMMIT")
        {
            heapCommit = p->GetValue();
        }
        else if (p->GetName() == "HEAPSIZE")
        {
            heapSize = p->GetValue();
        }
        else if (p->GetName() == "STACKCOMMIT")
        {
            stackCommit = p->GetValue();
        }
        else if (p->GetName() == "STACKSIZE")
        {
            stackSize = p->GetValue();
        }
    }
}
bool dlPeMain::LoadImports(ObjFile *file)
{
    ObjInt base;
    ObjInt offs;
    std::set<std::string> names;
    for (ObjFile::SymbolIterator it = file->ImportBegin(); it != file->ImportEnd(); ++it)
    {
        names.insert((*it)->GetName());
    }
    // every external better have an import declaration... otherwise it is a malformed file
    for (ObjFile::SymbolIterator it = file->ExternalBegin(); it != file->ExternalEnd(); ++it)
    {
        if (names.find((*it)->GetName()) == names.end())
            return false;
        // point to its thunk...
//		(*it)->SetOffset(new ObjExpression(importThunkVA + 6 * (*it)->GetIndex()));
    }
    return true;
}
bool dlPeMain::ReadSections(const std::string &path)
{
    ObjIeeeIndexManager iml;
    factory = new ObjFactory(&iml);
    ObjIeee ieee("");
    FILE *in = fopen(path.c_str(), "rb");
    if (!in)
       Utils::fatal("Cannot open input file");
    file = ieee.Read(in, ObjIeee::eAll, factory);
    fclose(in);
    if (!ieee.GetAbsolute())
    {
        delete file;
        Utils::fatal("Input file is in relative format");
    }
    if (ieee.GetStartAddress() == NULL)
    {
        delete file;
        Utils::fatal("No start address specified");
    }
    startAddress = ieee.GetStartAddress()->Eval(0);
    if (file != NULL)
    {
        ReadValues();
        if (LoadImports(file))
        {
            PEObject::SetFile(file);
            for (ObjFile::SectionIterator it = file->SectionBegin(); it != file->SectionEnd(); ++it)
            {
                PEDataObject *p = new PEDataObject(file, *it);
                objects.push_back(p);
                (*it)->ResolveSymbols(factory);
            }
            if (file->ImportBegin() != file->ImportEnd())
                objects.push_back(new PEImportObject(objects));
            if (file->ExportBegin() != file->ExportEnd())
                objects.push_back(new PEExportObject(outputName));
            objects.push_back(new PEFixupObject());
            if (resources.size())
                objects.push_back(new PEResourceObject(resources));
            if (DebugFile.GetValue().size())
                objects.push_back(new PEDebugObject(DebugFile.GetValue(), imageBase));
            return true;
        }
        else
        {
            delete file;
            Utils::fatal("Input file internal error in import list");
        }
    }
	else
	{
		std:: cout << "Invalid rel file format " << ieee.GetErrorQualifier().c_str() << std::endl;
	}
    return false;
}
std::string dlPeMain::GetOutputName(char *infile) const
{
    std::string name;
    if (outputFileSwitch.GetValue().size() != 0)
    {
        name = outputFileSwitch.GetValue();
        const char *p = strrchr(name.c_str(), '.');
        if (p  && p[-1] != '.' && p[1] != '\\')
            return name;
    }
    else
    { 
        name = infile;
    }
    if (mode == DLL)
        name = Utils::QualifiedFile(name.c_str(), ".dll");
    else
        name = Utils::QualifiedFile(name.c_str(), ".exe");
    return name;
}			
void dlPeMain::InitHeader(unsigned headerSize, ObjInt endVa)
{
    memset(&header, 0, sizeof(header));
    header.signature = PESIG ;
    header.magic = PE_MAGICNUM ;
    header.cpu_type = PE_INTEL386 ;
    /* store time/date of creation */
    header.time=(unsigned)time(NULL);
    header.nt_hdr_size = PE_OPTIONAL_HEADER_SIZE ;

    header.flags = PE_FILE_EXECUTABLE | PE_FILE_32BIT | PE_FILE_REVERSE_BITS_HIGH |
                PE_FILE_REVERSE_BITS_LOW | PE_FILE_LOCAL_SYMBOLS_STRIPPED | PE_FILE_LINE_NUMBERS_STRIPPED  ;
    if (mode == DLL)
    {
        header.flags |= PE_FILE_LIBRARY;
    }
    header.dll_flags = dllFlags;
    
    header.image_base = imageBase ;
    header.file_align = fileAlign ;
    header.object_align = objectAlign ;

    header.os_major_version = osMajor ;
    header.os_minor_version = osMinor ;
    header.user_major_version = userMajor ;
    header.user_minor_version = userMinor ;
    header.subsys_major_version = subsysMajor ;
    header.subsys_minor_version = subsysMinor ;
    
    header.subsystem = mode == GUI ? PE_SUBSYS_WINDOWS : PE_SUBSYS_CONSOLE ;

    header.num_rvas = PE_NUM_VAS ;
    header.header_size = headerSize;
    header.heap_size = heapSize ;
    header.heap_commit = heapCommit ;
    if (mode != DLL)
    {
        header.stack_size = stackSize ;
        header.stack_commit = stackCommit ;
    }
    else
    {
          /* flag that entry point should always be called */
        header.dll_flags = 0 ;
    }
    header.num_objects = objects.size() ;
    header.entry_point = startAddress - imageBase ;

    
    header.image_size = endVa;
    for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        if ((*it)->GetName() == ".text")
        {
            header.code_base = (*it)->GetAddr();
            header.code_size = ObjectAlign(objectAlign, (*it)->GetSize());
        }
        else if ((*it)->GetName() == ".data")
        {
            header.data_base = (*it)->GetAddr();
            header.data_size = ObjectAlign(objectAlign, (*it)->GetSize());
            header.bss_size = 0;
        }
        else if ((*it)->GetName() == ".idata")
        {
            header.import_rva = (*it)->GetAddr();
            header.import_size = (*it)->GetRawSize();
        }
        else if ((*it)->GetName() == ".edata")
        {
            header.export_rva = (*it)->GetAddr();
            header.export_size = (*it)->GetRawSize();
        }
        else if ((*it)->GetName() == ".reloc")
        {
            header.fixup_rva  = (*it)->GetAddr();
            header.fixup_size  = (*it)->GetRawSize();
        }
        else if ((*it)->GetName() == ".rsrc")
        {
            header.resource_rva = (*it)->GetAddr();
            header.resource_size = (*it)->GetRawSize();
        }
        else if ((*it)->GetName() == ".debug")
        {
            header.debug_rva = (*it)->GetAddr();
            header.debug_size = (*it)->GetRawSize();
        }
    }
}
bool dlPeMain::LoadStub(const std::string &exeName)
{
    std::string val = stubSwitch.GetValue();
    if (val.size() == NULL)
        val = "dfstb32.exe";
    // look in current directory
    std::fstream *file = new std::fstream(val.c_str(), std::ios::in | std::ios::binary);
    if (!file || !file->is_open())
    {
        if (file)
        {
            delete file;
            file = NULL;
        }
        // look in lib directory if not there
        int npos = exeName.find_last_of(CmdFiles::DIR_SEP);
        if (npos != std::string::npos)
        {
            std::string val1 = exeName.substr(0, npos + 1) + "..\\lib\\" + val;
            file = new std::fstream(val1.c_str(), std::ios::in | std::ios::binary);
        }
        // look in bin directory if not there
        if (!file || !file->is_open())
        {
            if (file)
            {
                delete file;
                file = NULL;
            }
            // look in lib directory if not there
            int npos = exeName.find_last_of(CmdFiles::DIR_SEP);
            if (npos != std::string::npos)
            {
                std::string val1 = exeName.substr(0, npos + 1) + "..\\bin\\" + val;
                file = new std::fstream(val1.c_str(), std::ios::in | std::ios::binary);
            }
        }
    }
    if (!file || !file->is_open())
    {
        if (file)
        {
            delete file;
            file = NULL;
        }
        if (stubSwitch.GetValue().size() == 0)
        {
            stubData = new char[defaultStubSize];
            memcpy(stubData, defaultStubData, defaultStubSize);
            stubSize = defaultStubSize;
        }
        else
        {
            return false;
        }
    }
    else
    {
        MZHeader mzHead;
        file->read((char *)&mzHead, sizeof(mzHead));
        int bodySize = mzHead.image_length_MOD_512 + mzHead.image_length_DIV_512 * 512;
        int oldReloc = mzHead.offset_to_relocation_table;
        int oldHeader = mzHead.n_header_paragraphs * 16;
        if (bodySize & 511)
            bodySize -= 512;
        bodySize -= oldHeader;
        int relocSize = mzHead.n_relocation_items * 4;
        int preHeader = 0x40;
        int totalHeader = (preHeader + relocSize + 15) & ~15;
        stubSize = (totalHeader + bodySize + 15) & ~15;
        stubData = new char [stubSize];
        memset(stubData, 0, stubSize);
        int newSize = bodySize + totalHeader;
        if (newSize & 511)
            newSize += 512;
        mzHead.image_length_MOD_512 = newSize % 512;
        mzHead.image_length_DIV_512 = newSize / 512;
        mzHead.offset_to_relocation_table = 0x40;
        mzHead.n_header_paragraphs = totalHeader/ 16;
        memcpy(stubData, &mzHead, sizeof(mzHead));
        *(unsigned *)(stubData + 0x3c) = stubSize;
        if (relocSize)
        {
            file->seekg(oldReloc, std::ios::beg);
            file->read(stubData + 0x40, relocSize);
        }
        file->seekg(oldHeader, std::ios::beg);
        file->read(stubData + totalHeader, bodySize);
        if (!file->eof() && file->fail())
        {
            delete file;
            return false;
        }
        delete file;
    }
    return true;
}
void dlPeMain::WriteStub(std::fstream &out)
{
    out.write((char *)stubData, stubSize);
    out.flush();
}
void dlPeMain::PadHeader(std::fstream &out)
{
    int n = out.tellg();
    n = ObjectAlign(fileAlign, n) - n + fileAlign; // for secondary header
    char buf[512];
    memset(buf, 0, sizeof(buf));
    while (n)
    {
        int s = 512;
        if (n < s)
            s = n;
        out.write(buf, s);
        n -= s;
    }
    out.flush();
}
int dlPeMain::Run(int argc, char **argv)
{
    Utils::banner(argv[0]);
    char *modName = Utils::GetModuleName();
    CmdSwitchFile internalConfig(SwitchParser);
    std::string configName = Utils::QualifiedFile(argv[0], ".cfg");
    std::fstream configTest(configName.c_str(), std::ios::in);
    if (!configTest.fail())
    {
        configTest.close();
        if (!internalConfig.Parse(configName.c_str()))
            Utils::fatal("Corrupt configuration file");
    }
    if (!SwitchParser.Parse(&argc, argv) || argc < 2)
    {
        Utils::usage(argv[0], usageText);
    }
    ParseOutResourceFiles(&argc, argv);
    if (!ParseOutDefFile(&argc, argv))
    {
        Utils::usage(argv[0], usageText);
    }
    if (argc != 2)		
    {
        Utils::usage(argv[0], usageText);
    }
    if (!GetMode())
    {
        Utils::usage(argv[0], usageText);
    }
    if (!LoadStub(argv[0]))
        Utils::fatal("Missing or invalid stub file");
        
    outputName = GetOutputName(argv[1]);
    if (!ReadSections(std::string(argv[1])))
        Utils::fatal("Invalid .rel file");
    
    ObjInt endPhys = sizeof(PEHeader)+objects.size() * PEObject::HeaderSize + stubSize ;
    endPhys = ObjectAlign(fileAlign, endPhys + fileAlign); // extra space for optional PE header
    ObjInt headerSize = endPhys;
    ObjInt endVa = objects[0]->GetAddr();
    if (endVa < endPhys)
        Utils::fatal("ObjectAlign too small");
    for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        (*it)->Setup(endVa, endPhys);
    }
    for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        (*it)->Fill();
    }
    InitHeader(headerSize, endVa);
    std::fstream out(outputName.c_str(), std::ios::out | std::ios::binary);
    if (!out.fail())
    {
        WriteStub(out);
        out.write((char *)&header, sizeof(header));
        for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
        {
            (*it)->WriteHeader(out);
        }
        PadHeader(out);
        out.flush();
        for (std::deque<PEObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
        {
            (*it)->Write(out);
            out.flush();
        }		
        out.flush();
        out.close();
        if (!out.fail())
        {
            if (mode == DLL)
            {
                std::string path = modName;
                int n = path.find_last_of(CmdFiles::DIR_SEP[0]);
                if (n == std::string::npos)
                    path = "";
                else
                    path.erase(n+1);
                std::string implibName = Utils::QualifiedFile(outputName.c_str(), ".l");
                std::string cmd = std::string("\"") + path + "oimplib" + "\" " + implibName + " " + outputName;
                return system(cmd.c_str());
            }
            return 0;
        }
        return 1;
    }
    else
    {
        return 1;
    }
}
