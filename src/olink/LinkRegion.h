/*
    Software License Agreement (BSD License)
    

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
#ifndef LINKREGION_H
#define LINKREGION_H

#include <vector>
#include <vector>
#include <map>
#include <set>
#include "LinkAttribs.h"

class LinkOverlay;
class ObjFile;
class ObjSection;
class LinkExpression;
class LinkTokenizer;
class CmdFiles;
class LinkRegionFileSpecContainer;
class LinkManager;

class LinkRegion
{
    
    public:
        struct OneSection
        {
            OneSection() : file(NULL), section(NULL) { }
            OneSection(ObjFile *File, ObjSection *Section) : file(File), section(Section) { }
            ObjFile *file;
            ObjSection *section;
        };
        typedef std::vector<OneSection>::iterator OneSectionIterator;
        struct NamedSection
        {
            std::string name;
            std::vector<OneSection> sections;
        };
        struct nslt {
            bool operator ()(const NamedSection *left, const NamedSection *right)
            {
                return strcmp(left->name.c_str(), right->name.c_str()) < 0;
            }
        };
        typedef std::vector<ObjString *> SourceFile;
        typedef std::vector<NamedSection *> SectionData;
        LinkRegion(LinkOverlay *Parent) : name(""), common(false), maxSize(-1), 
                                         parent(Parent), overlayed(false) {}
        ~LinkRegion();

        ObjString &GetName() { return name; }
        void SetName(const ObjString &Name) { name = Name; }
        ObjString QualifiedRegionName() ;		

        LinkOverlay *GetParent() { return parent; }
        void SetParent(LinkOverlay *Parent) { parent = Parent; }

        void SetAttribs(const LinkAttribs &Attribs) { attribs = Attribs; }
        LinkAttribs &GetAttribs() { return attribs; }
        
        typedef SourceFile::iterator SourceFileIterator;
        
        SourceFileIterator SourceFileBegin() { return sourceFiles.begin(); }
        SourceFileIterator SourceFileEnd() { return sourceFiles.end(); }
        
        typedef SectionData::iterator SectionDataIterator;
        typedef std::set<NamedSection *,nslt> LookasideBuf;
        
        SectionDataIterator NowDataBegin() { return nowData.begin(); }
        SectionDataIterator NowDataEnd() { return nowData.end(); }
        SectionDataIterator NormalDataBegin() { return normalData.begin(); }
        SectionDataIterator NormalDataEnd() { return normalData.end(); }
        SectionDataIterator PostponeDataBegin() { return postponeData.begin(); }
        SectionDataIterator PostponeDataEnd() { return postponeData.end(); }
        
        void AddSourceFile(CmdFiles &files, const ObjString &spec);
        void AddSection(LinkManager *manager);
        
        bool ParseRegionSpec(LinkManager *manager, CmdFiles &files, LinkTokenizer &spec);
        
        ObjInt PlaceRegion(LinkManager *manager, LinkAttribs &partitionAttribs, ObjInt base);
        
        void AddNowData(ObjFile *file, ObjSection *section) { AddData(nowData, nowLookaside, file, section); }
        void AddNormalData(ObjFile *file, ObjSection *section) { AddData(normalData, normalLookaside, file, section); }
        void AddPostponeData(ObjFile *file, ObjSection *section) { AddData(postponeData, postponeLookaside, file, section); }
    protected:
        void AddData(SectionData &data, LookasideBuf &lookaside, ObjFile *file, ObjSection *section);
    private:
        std::map<std::string, int> equalSections;
        ObjInt ArrangeOverlayed(LinkManager *manager, SectionDataIterator it, ObjInt address);
        void AddFile(ObjFile *file);
        bool ParseFiles(CmdFiles &files, LinkTokenizer &spec);
        bool ParseName(LinkTokenizer &spec);
        bool ParseAttributes( LinkTokenizer &spec);
        bool ParseValue(LinkTokenizer &spec, LinkExpression **rv);
        bool HoldsFile(const ObjString &fileName);
        void CheckAttributes();
        bool Matches(const ObjString &name, const ObjString &spec);
        LinkRegionFileSpecContainer &Split(ObjString &spec);
        ObjInt ArrangeSections(LinkManager *manager);
        ObjString name;
        bool common ;
        bool overlayed;
        SourceFile sourceFiles;
        SectionData nowData;
        SectionData normalData;
        SectionData postponeData;
        LookasideBuf nowLookaside;
        LookasideBuf normalLookaside;
        LookasideBuf postponeLookaside;
        LinkAttribs attribs;
        LinkOverlay *parent;
        ObjInt maxSize;
};
#endif
