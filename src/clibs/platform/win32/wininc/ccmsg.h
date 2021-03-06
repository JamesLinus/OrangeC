/* 
   ccmsg.h

   Base definitions

   Copyright (C) 1996 Free Software Foundation, Inc.

   This file is part of the Windows32 API Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   If you are interested in a warranty or support for this source code,
   contact Scott Christley <scottc@net-community.com> for more information.
   
   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation, 
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   -----------
   DAL 2003 - this file modified extensively for my compiler.  New
   definitionswnwn added as well.
*/ 
#define ACM_OPENA (1124)
#define ACM_OPENW (1127)
#define ACM_PLAY (1125)
#define ACM_STOP (1126)

#define CBEM_DELETEITEM CB_DELETESTRING
#define CBEM_GETCOMBOCONTROL (1030)
#define CBEM_GETEDITCONTROL (1031)
#define CBEM_GETEXSTYLE (1033)
#define CBEM_GETEXSTYLE (1033)
#define CBEM_GETEXTENDEDSTYLE (1033)
#define CBEM_GETIMAGELIST (1027)
#define CBEM_GETITEMA (1028)
#define CBEM_GETITEMW (1037)
#define CBEM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define CBEM_HASEDITCHANGED (1034)
#define CBEM_INSERTITEMA (1025)
#define CBEM_INSERTITEMW (1035)
#define CBEM_SETEXSTYLE (1032)
#define CBEM_SETEXSTYLE (1032)
#define CBEM_SETEXTENDEDSTYLE (1038)
#define CBEM_SETIMAGELIST (1026)
#define CBEM_SETITEMA (1029)
#define CBEM_SETITEMW (1036)
#define CBEM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#define CCM_GETCOLORSCHEME (8195)
#define CCM_GETDROPTARGET (8196)
#define CCM_GETUNICODEFORMAT (8198)
#define CCM_GETVERSION (8200)
#define CCM_SETBKCOLOR (8193)
#define CCM_SETCOLORSCHEME (8194)
#define CCM_SETNOTIFYWINDOW (8201)
#define CCM_SETUNICODEFORMAT (8197)
#define CCM_SETVERSION (8199)

#define DTM_GETMCCOLOR (4103)
#define DTM_GETMCFONT (4106)
#define DTM_GETMONTHCAL (4104)
#define DTM_GETRANGE (4099)
#define DTM_GETSYSTEMTIME (4097)
#define DTM_SETFORMATA (4101)
#define DTM_SETFORMATW (4146)
#define DTM_SETMCCOLOR (4102)
#define DTM_SETMCFONT (4105)
#define DTM_SETRANGE (4100)
#define DTM_SETSYSTEMTIME (4098)

#define HDM_CLEARFILTER (4632)
#define HDM_CREATEDRAGIMAGE (4624)
#define HDM_DELETEITEM (4610)
#define HDM_EDITFILTER (4631)
#define HDM_GETBITMAPMARGIN (4629)
#define HDM_GETIMAGELIST (4617)
#define HDM_GETITEMA (4611)
#define HDM_GETITEMCOUNT (4608)
#define HDM_GETITEMRECT (4615)
#define HDM_GETITEMW (4619)
#define HDM_GETORDERARRAY (4625)
#define HDM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define HDM_HITTEST (4614)
#define HDM_INSERTITEMA (4609)
#define HDM_INSERTITEMW (4618)
#define HDM_LAYOUT (4613)
#define HDM_ORDERTOINDEX (4623)
#define HDM_SETBITMAPMARGIN (4628)
#define HDM_SETFILTERCHANGETIMEOUT (4630)
#define HDM_SETHOTDIVIDER (4627)
#define HDM_SETIMAGELIST (4616)
#define HDM_SETITEMA (4612)
#define HDM_SETITEMW (4620)
#define HDM_SETORDERARRAY (4626)
#define HDM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#define HKM_GETHOTKEY (1026)
#define HKM_SETHOTKEY (1025)
#define HKM_SETRULES (1027)

#define IPM_CLEARADDRESS (1124)
#define IPM_GETADDRESS (1126)
#define IPM_ISBLANK (1129)
#define IPM_SETADDRESS (1125)
#define IPM_SETFOCUS (1128)
#define IPM_SETRANGE (1127)

#define LVM_APPROXIMATEVIEWRECT (4160)
#define LVM_ARRANGE (4118)
#define LVM_CREATEDRAGIMAGE (4129)
#define LVM_DELETEALLITEMS (4105)
#define LVM_DELETECOLUMN (4124)
#define LVM_DELETEITEM (4104)
#define LVM_EDITLABELA (4119)
#define LVM_EDITLABELW (4214)
#define LVM_ENSUREVISIBLE (4115)
#define LVM_FINDITEMA (4109)
#define LVM_FINDITEMW (4179)
#define LVM_GETBKCOLOR (4096)
#define LVM_GETBKIMAGEA (4165)
#define LVM_GETBKIMAGEW (4235)
#define LVM_GETCALLBACKMASK (4106)
#define LVM_GETCOLUMNA (4121)
#define LVM_GETCOLUMNORDERARRAY (4155)
#define LVM_GETCOLUMNW (4191)
#define LVM_GETCOLUMNWIDTH (4125)
#define LVM_GETCOUNTPERPAGE (4136)
#define LVM_GETEDITCONTROL (4120)
#define LVM_GETEXTENDEDLISTVIEWSTYLE (4151)
#define LVM_GETHEADER (4127)
#define LVM_GETHOTCURSOR (4159)
#define LVM_GETHOTITEM (4157)
#define LVM_GETHOVERTIME (4168)
#define LVM_GETIMAGELIST (4098)
#define LVM_GETISEARCHSTRINGA (4148)
#define LVM_GETISEARCHSTRINGW (4213)
#define LVM_GETITEMA (4101)
#define LVM_GETITEMCOUNT (4100)
#define LVM_GETITEMPOSITION (4112)
#define LVM_GETITEMRECT (4110)
#define LVM_GETITEMSPACING (4147)
#define LVM_GETITEMSTATE (4140)
#define LVM_GETITEMTEXTA (4141)
#define LVM_GETITEMTEXTW (4211)
#define LVM_GETITEMW (4171)
#define LVM_GETNEXTITEM (4108)
#define LVM_GETNUMBEROFWORKAREAS (4169)
#define LVM_GETORIGIN (4137)
#define LVM_GETSELECTEDCOUNT (4146)
#define LVM_GETSELECTIONMARK (4162)
#define LVM_GETSTRINGWIDTHA (4113)
#define LVM_GETSTRINGWIDTHW (4183)
#define LVM_GETSUBITEMRECT (4152)
#define LVM_GETTEXTBKCOLOR (4133)
#define LVM_GETTEXTCOLOR (4131)
#define LVM_GETTOOLTIPS (4174)
#define LVM_GETTOPINDEX (4135)
#define LVM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define LVM_GETVIEWRECT (4130)
#define LVM_GETWORKAREAS (4166)
#define LVM_HITTEST (4114)
#define LVM_INSERTCOLUMNA (4123)
#define LVM_INSERTCOLUMNW (4193)
#define LVM_INSERTITEMA (4103)
#define LVM_INSERTITEMW (4173)
#define LVM_REDRAWITEMS (4117)
#define LVM_SCROLL (4116)
#define LVM_SETBKCOLOR (4097)
#define LVM_SETBKIMAGEA (4164)
#define LVM_SETBKIMAGEW (4234)
#define LVM_SETCALLBACKMASK (4107)
#define LVM_SETCOLUMNA (4122)
#define LVM_SETCOLUMNORDERARRAY (4154)
#define LVM_SETCOLUMNW (4192)
#define LVM_SETCOLUMNWIDTH (4126)
#define LVM_SETEXTENDEDLISTVIEWSTYLE (4150)
#define LVM_SETHOTCURSOR (4158)
#define LVM_SETHOTITEM (4156)
#define LVM_SETHOVERTIME (4167)
#define LVM_SETICONSPACING (4149)
#define LVM_SETIMAGELIST (4099)
#define LVM_SETITEMA (4102)
#define LVM_SETITEMCOUNT (4143)
#define LVM_SETITEMPOSITION (4111)
#define LVM_SETITEMPOSITION32 (4145)
#define LVM_SETITEMSTATE (4139)
#define LVM_SETITEMTEXTA (4142)
#define LVM_SETITEMTEXTW (4212)
#define LVM_SETITEMW (4172)
#define LVM_SETSELECTIONMARK (4163)
#define LVM_SETTEXTBKCOLOR (4134)
#define LVM_SETTEXTCOLOR (4132)
#define LVM_SETTOOLTIPS (4170)
#define LVM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define LVM_SETWORKAREAS (4161)
#define LVM_SORTITEMS (4144)
#define LVM_SORTITEMSEX (4177)
#define LVM_SUBITEMHITTEST (4153)
#define LVM_UPDATE (4138)

#define MCM_GETCOLOR (4107)
#define MCM_GETCURSEL (4097)
#define MCM_GETFIRSTDAYOFWEEK (4112)
#define MCM_GETMAXSELCOUNT (4099)
#define MCM_GETMAXTODAYWIDTH (4117)
#define MCM_GETMINREQRECT (4105)
#define MCM_GETMONTHDELTA (4115)
#define MCM_GETMONTHRANGE (4103)
#define MCM_GETRANGE (4113)
#define MCM_GETSELRANGE (4101)
#define MCM_GETTODAY (4109)
#define MCM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define MCM_HITTEST (4110)
#define MCM_SETCOLOR (4106)
#define MCM_SETCURSEL (4098)
#define MCM_SETDAYSTATE (4104)
#define MCM_SETFIRSTDAYOFWEEK (4111)
#define MCM_SETMAXSELCOUNT (4100)
#define MCM_SETMONTHDELTA (4116)
#define MCM_SETRANGE (4114)
#define MCM_SETSELRANGE (4102)
#define MCM_SETTODAY (4108)
#define MCM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#define PBM_DELTAPOS (1027)
#define PBM_GETPOS (1032)
#define PBM_GETRANGE (1031)
#define PBM_SETBARCOLOR (1033)
#define PBM_SETBKCOLOR CCM_SETBKCOLOR
#define PBM_SETPOS (1026)
#define PBM_SETRANGE (1025)
#define PBM_SETRANGE32 (1030)
#define PBM_SETSTEP (1028)
#define PBM_STEPIT (1029)

#define PGM_FORWARDMOUSE (5123)
#define PGM_GETBKCOLOR (5125)
#define PGM_GETBORDER (5127)
#define PGM_GETBUTTONSIZE (5131)
#define PGM_GETBUTTONSTATE (5132)
#define PGM_GETDROPTARGET CCM_GETDROPTARGET
#define PGM_GETPOS (5129)
#define PGM_RECALCSIZE (5122)
#define PGM_SETBKCOLOR (5124)
#define PGM_SETBORDER (5126)
#define PGM_SETBUTTONSIZE (5130)
#define PGM_SETCHILD (5121)
#define PGM_SETPOS (5128)

#define RB_BEGINDRAG (1048)
#define RB_DELETEBAND (1026)
#define RB_DRAGMOVE (1050)
#define RB_ENDDRAG (1049)
#define RB_GETBANDBORDERS (1058)
#define RB_GETBANDCOUNT (1036)
#define RB_GETBANDINFOA (1053)
#define RB_GETBANDINFOW (1052)
#define RB_GETBARHEIGHT (1051)
#define RB_GETBARINFO (1027)
#define RB_GETBKCOLOR (1044)
#define RB_GETCOLORSCHEME CCM_GETCOLORSCHEME
#define RB_GETDROPTARGET CCM_GETDROPTARGET
#define RB_GETPALETTE (1062)
#define RB_GETRECT (1033)
#define RB_GETROWCOUNT (1037)
#define RB_GETROWHEIGHT (1038)
#define RB_GETTEXTCOLOR (1046)
#define RB_GETTOOLTIPS (1041)
#define RB_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define RB_HITTEST (1032)
#define RB_IDTOINDEX (1040)
#define RB_INSERTBANDA (1025)
#define RB_INSERTBANDW (1034)
#define RB_MAXIMIZEBAND (1055)
#define RB_MINIMIZEBAND (1054)
#define RB_MOVEBAND (1063)
#define RB_PUSHCHEVRON (1067)
#define RB_SETBANDINFOA (1030)
#define RB_SETBANDINFOW (1035)
#define RB_SETBARINFO (1028)
#define RB_SETBKCOLOR (1043)
#define RB_SETCOLORSCHEME CCM_SETCOLORSCHEME
#define RB_SETPALETTE (1061)
#define RB_SETPARENT (1031)
#define RB_SETTEXTCOLOR (1045)
#define RB_SETTOOLTIPS (1042)
#define RB_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define RB_SHOWBAND (1059)
#define RB_SIZETORECT (1047)

#define SB_GETBORDERS (1031)
#define SB_GETICON (1044)
#define SB_GETPARTS (1030)
#define SB_GETRECT (1034)
#define SB_GETTEXTA (1026)
#define SB_GETTEXTLENGTHA (1027)
#define SB_GETTEXTLENGTHW (1036)
#define SB_GETTEXTW (1037)
#define SB_GETTIPTEXTA (1042)
#define SB_GETTIPTEXTW (1043)
#define SB_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define SB_ISSIMPLE (1038)
#define SB_SETBKCOLOR CCM_SETBKCOLOR
#define SB_SETICON (1039)
#define SB_SETMINHEIGHT (1032)
#define SB_SETPARTS (1028)
#define SB_SETTEXTA (1025)
#define SB_SETTEXTW (1035)
#define SB_SETTIPTEXTA (1040)
#define SB_SETTIPTEXTW (1041)
#define SB_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define SB_SIMPLE (1033)
#define SB_SIMPLEID (255)

#define TBM_CLEARSEL (1043)
#define TBM_CLEARTICS (1033)
#define TBM_GETBUDDY (1057)
#define TBM_GETCHANNELRECT (1050)
#define TBM_GETLINESIZE (1048)
#define TBM_GETNUMTICS (1040)
#define TBM_GETPAGESIZE (1046)
#define TBM_GETPOS (1024)
#define TBM_GETPTICS (1038)
#define TBM_GETRANGEMAX (1026)
#define TBM_GETRANGEMIN (1025)
#define TBM_GETSELEND (1042)
#define TBM_GETSELSTART (1041)
#define TBM_GETTHUMBLENGTH (1052)
#define TBM_GETTHUMBRECT (1049)
#define TBM_GETTIC (1027)
#define TBM_GETTICPOS (1039)
#define TBM_GETTOOLTIPS (1054)
#define TBM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TBM_SETBUDDY (1056)
#define TBM_SETLINESIZE (1047)
#define TBM_SETPAGESIZE (1045)
#define TBM_SETPOS (1029)
#define TBM_SETRANGE (1030)
#define TBM_SETRANGEMAX (1032)
#define TBM_SETRANGEMIN (1031)
#define TBM_SETSEL (1034)
#define TBM_SETSELEND (1036)
#define TBM_SETSELSTART (1035)
#define TBM_SETTHUMBLENGTH (1051)
#define TBM_SETTIC (1028)
#define TBM_SETTICFREQ (1044)
#define TBM_SETTIPSIDE (1055)
#define TBM_SETTOOLTIPS (1053)
#define TBM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#define TB_ADDBITMAP (1043)
#define TB_ADDBUTTONSA (1044)
#define TB_ADDBUTTONSW (1092)
#define TB_ADDSTRINGA (1052)
#define TB_ADDSTRINGW (1101)
#define TB_AUTOSIZE (1057)
#define TB_BOTTOM (7)
#define TB_BUTTONCOUNT (1048)
#define TB_BUTTONSTRUCTSIZE (1054)
#define TB_CHANGEBITMAP (1067)
#define TB_CHECKBUTTON (1026)
#define TB_COMMANDTOINDEX (1049)
#define TB_CUSTOMIZE (1051)
#define TB_DELETEBUTTON (1046)
#define TB_ENABLEBUTTON (1025)
#define TB_ENDTRACK (8)
#define TB_GETANCHORHIGHLIGHT (1098)
#define TB_GETBITMAP (1068)
#define TB_GETBITMAPFLAGS (1065)
#define TB_GETBUTTON (1047)
#define TB_GETBUTTONINFOA (1089)
#define TB_GETBUTTONINFOW (1087)
#define TB_GETBUTTONSIZE (1082)
#define TB_GETBUTTONTEXTA (1069)
#define TB_GETBUTTONTEXTW (1099)
#define TB_GETCOLORSCHEME CCM_GETCOLORSCHEME
#define TB_GETDISABLEDIMAGELIST (1079)
#define TB_GETEXTENDEDSTYLE (1109)
#define TB_GETHOTIMAGELIST (1077)
#define TB_GETHOTITEM (1095)
#define TB_GETIMAGELIST (1073)
#define TB_GETINSERTMARK (1103)
#define TB_GETINSERTMARKCOLOR (1113)
#define TB_GETITEMRECT (1053)
#define TB_GETMAXSIZE (1107)
#define TB_GETOBJECT (1086)
#define TB_GETPADDING (1110)
#define TB_GETRECT (1075)
#define TB_GETROWS (1064)
#define TB_GETSTATE (1042)
#define TB_GETSTRINGA (1116)
#define TB_GETSTRINGW (1115)
#define TB_GETSTYLE (1081)
#define TB_GETTEXTROWS (1085)
#define TB_GETTOOLTIPS (1059)
#define TB_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TB_HIDEBUTTON (1028)
#define TB_HITTEST (1093)
#define TB_INDETERMINATE (1029)
#define TB_INSERTBUTTONA (1045)
#define TB_INSERTBUTTONW (1091)
#define TB_INSERTMARKHITTEST (1105)
#define TB_ISBUTTONCHECKED (1034)
#define TB_ISBUTTONENABLED (1033)
#define TB_ISBUTTONHIDDEN (1036)
#define TB_ISBUTTONHIGHLIGHTED (1038)
#define TB_ISBUTTONINDETERMINATE (1037)
#define TB_ISBUTTONPRESSED (1035)
#define TB_LINEDOWN (1)
#define TB_LINEUP (0)
#define TB_LOADIMAGES (1074)
#define TB_MAPACCELERATORA (1102)
#define TB_MAPACCELERATORW (1114)
#define TB_MARKBUTTON (1030)
#define TB_MOVEBUTTON (1106)
#define TB_PAGEDOWN (3)
#define TB_PAGEUP (2)
#define TB_PRESSBUTTON (1027)
#define TB_REPLACEBITMAP (1070)
#define TB_SAVERESTOREA (1050)
#define TB_SAVERESTOREW (1100)
#define TB_SETANCHORHIGHLIGHT (1097)
#define TB_SETBITMAPSIZE (1056)
#define TB_SETBUTTONINFOA (1090)
#define TB_SETBUTTONINFOW (1088)
#define TB_SETBUTTONSIZE (1055)
#define TB_SETBUTTONWIDTH (1083)
#define TB_SETCMDID (1066)
#define TB_SETCOLORSCHEME CCM_SETCOLORSCHEME
#define TB_SETDISABLEDIMAGELIST (1078)
#define TB_SETDRAWTEXTFLAGS (1094)
#define TB_SETEXTENDEDSTYLE (1108)
#define TB_SETHOTIMAGELIST (1076)
#define TB_SETHOTITEM (1096)
#define TB_SETIMAGELIST (1072)
#define TB_SETINDENT (1071)
#define TB_SETINSERTMARK (1104)
#define TB_SETINSERTMARKCOLOR (1112)
#define TB_SETMAXTEXTROWS (1084)
#define TB_SETPADDING (1111)
#define TB_SETPARENT (1061)
#define TB_SETROWS (1063)
#define TB_SETSTATE (1041)
#define TB_SETSTYLE (1080)
#define TB_SETTOOLTIPS (1060)
#define TB_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define TB_THUMBPOSITION (4)
#define TB_THUMBTRACK (5)
#define TB_TOP (6)

#define TCM_ADJUSTRECT (4904)
#define TCM_DELETEALLITEMS (4873)
#define TCM_DELETEITEM (4872)
#define TCM_DESELECTALL (4914)
#define TCM_GETCURFOCUS (4911)
#define TCM_GETCURSEL (4875)
#define TCM_GETEXTENDEDSTYLE (4917)
#define TCM_GETIMAGELIST (4866)
#define TCM_GETITEMA (4869)
#define TCM_GETITEMCOUNT (4868)
#define TCM_GETITEMRECT (4874)
#define TCM_GETITEMW (4924)
#define TCM_GETROWCOUNT (4908)
#define TCM_GETTOOLTIPS (4909)
#define TCM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TCM_HIGHLIGHTITEM (4915)
#define TCM_HITTEST (4877)
#define TCM_INSERTITEMA (4871)
#define TCM_INSERTITEMW (4926)
#define TCM_REMOVEIMAGE (4906)
#define TCM_SETCURFOCUS (4912)
#define TCM_SETCURSEL (4876)
#define TCM_SETEXTENDEDSTYLE (4916)
#define TCM_SETIMAGELIST (4867)
#define TCM_SETITEMA (4870)
#define TCM_SETITEMEXTRA (4878)
#define TCM_SETITEMSIZE (4905)
#define TCM_SETITEMW (4925)
#define TCM_SETMINTABWIDTH (4913)
#define TCM_SETPADDING (4907)
#define TCM_SETTOOLTIPS (4910)
#define TCM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#define TTM_ACTIVATE (1025)
#define TTM_ADDTOOLA (1028)
#define TTM_ADDTOOLW (1074)
#define TTM_ADJUSTRECT (1055)
#define TTM_DELTOOLA (1029)
#define TTM_DELTOOLW (1075)
#define TTM_ENUMTOOLSA (1038)
#define TTM_ENUMTOOLSW (1082)
#define TTM_GETBUBBLESIZE (1054)
#define TTM_GETCURRENTTOOLA (1039)
#define TTM_GETCURRENTTOOLW (1083)
#define TTM_GETDELAYTIME (1045)
#define TTM_GETMARGIN (1051)
#define TTM_GETMAXTIPWIDTH (1049)
#define TTM_GETTEXTA (1035)
#define TTM_GETTEXTW (1080)
#define TTM_GETTIPBKCOLOR (1046)
#define TTM_GETTIPTEXTCOLOR (1047)
#define TTM_GETTOOLCOUNT (1037)
#define TTM_GETTOOLINFOA (1032)
#define TTM_GETTOOLINFOW (1077)
#define TTM_HITTESTA (1034)
#define TTM_HITTESTW (1079)
#define TTM_NEWTOOLRECTA (1030)
#define TTM_NEWTOOLRECTW (1076)
#define TTM_POP (1052)
#define TTM_RELAYEVENT (1031)
#define TTM_SETDELAYTIME (1027)
#define TTM_SETMARGIN (1050)
#define TTM_SETMAXTIPWIDTH (1048)
#define TTM_SETTIPBKCOLOR (1043)
#define TTM_SETTIPTEXTCOLOR (1044)
#define TTM_SETTITLEA (1056)
#define TTM_SETTITLEW (1057)
#define TTM_SETTOOLINFOA (1033)
#define TTM_SETTOOLINFOW (1078)
#define TTM_TRACKACTIVATE (1041)
#define TTM_TRACKPOSITION (1042)
#define TTM_UPDATE (1053)
#define TTM_UPDATETIPTEXTA (1036)
#define TTM_UPDATETIPTEXTW (1081)
#define TTM_WINDOWFROMPOINT (1040)

#define TVM_CREATEDRAGIMAGE (4370)
#define TVM_DELETEITEM (4353)
#define TVM_EDITLABELA (4366)
#define TVM_EDITLABELW (4417)
#define TVM_ENDEDITLABELNOW (4374)
#define TVM_ENSUREVISIBLE (4372)
#define TVM_EXPAND (4354)
#define TVM_GETBKCOLOR (4383)
#define TVM_GETCOUNT (4357)
#define TVM_GETEDITCONTROL (4367)
#define TVM_GETIMAGELIST (4360)
#define TVM_GETINDENT (4358)
#define TVM_GETINSERTMARKCOLOR (4390)
#define TVM_GETISEARCHSTRINGA (4375)
#define TVM_GETISEARCHSTRINGW (4416)
#define TVM_GETITEMA (4364)
#define TVM_GETITEMHEIGHT (4380)
#define TVM_GETITEMRECT (4356)
#define TVM_GETITEMSTATE (4391)
#define TVM_GETITEMW (4414)
#define TVM_GETLINECOLOR (4393)
#define TVM_GETNEXTITEM (4362)
#define TVM_GETSCROLLTIME (4386)
#define TVM_GETTEXTCOLOR (4384)
#define TVM_GETTOOLTIPS (4377)
#define TVM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TVM_GETVISIBLECOUNT (4368)
#define TVM_HITTEST (4369)
#define TVM_INSERTITEMA (4352)
#define TVM_INSERTITEMW (4402)
#define TVM_SELECTITEM (4363)
#define TVM_SETBKCOLOR (4381)
#define TVM_SETIMAGELIST (4361)
#define TVM_SETINDENT (4359)
#define TVM_SETINSERTMARK (4378)
#define TVM_SETINSERTMARKCOLOR (4389)
#define TVM_SETITEMA (4365)
#define TVM_SETITEMHEIGHT (4379)
#define TVM_SETITEMW (4415)
#define TVM_SETLINECOLOR (4392)
#define TVM_SETSCROLLTIME (4385)
#define TVM_SETTEXTCOLOR (4382)
#define TVM_SETTOOLTIPS (4376)
#define TVM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define TVM_SORTCHILDREN (4371)
#define TVM_SORTCHILDRENCB (4373)

#define UDM_GETACCEL (1132)
#define UDM_GETBASE (1134)
#define UDM_GETBUDDY (1130)
#define UDM_GETPOS (1128)
#define UDM_GETPOS32 (1138)
#define UDM_GETRANGE (1126)
#define UDM_GETRANGE32 (1136)
#define UDM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define UDM_SETACCEL (1131)
#define UDM_SETBASE (1133)
#define UDM_SETBUDDY (1129)
#define UDM_SETPOS (1127)
#define UDM_SETPOS32 (1137)
#define UDM_SETRANGE (1125)
#define UDM_SETRANGE32 (1135)
#define UDM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT

#ifdef UNICODE
#define ACM_OPEN ACM_OPENW

#define CBEM_GETITEM CBEM_GETITEMW
#define CBEM_INSERTITEM CBEM_INSERTITEMW
#define CBEM_SETITEM CBEM_SETITEMW

#define DTM_SETFORMAT DTM_SETFORMATW

#define HDM_GETITEM HDM_GETITEMW
#define HDM_INSERTITEM HDM_INSERTITEMW
#define HDM_SETITEM HDM_SETITEMW

#define LVM_EDITLABEL LVM_EDITLABELW
#define LVM_FINDITEM LVM_FINDITEMW
#define LVM_GETBKIMAGE LVM_GETBKIMAGEW
#define LVM_GETCOLUMN LVM_GETCOLUMNW
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
#define LVM_GETITEM LVM_GETITEMW
#define LVM_GETITEMTEXT LVM_GETITEMTEXTW
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNW
#define LVM_INSERTITEM LVM_INSERTITEMW
#define LVM_SETBKIMAGE LVM_SETBKIMAGEW
#define LVM_SETCOLUMN LVM_SETCOLUMNW
#define LVM_SETITEM LVM_SETITEMW
#define LVM_SETITEMTEXT LVM_SETITEMTEXTW

#define RB_GETBANDINFO RB_GETBANDINFOW
#define RB_INSERTBAND RB_INSERTBANDW
#define RB_SETBANDINFO RB_SETBANDINFOW

#define SB_GETTEXT SB_GETTEXTW
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHW
#define SB_GETTIPTEXT SB_GETTIPTEXTW
#define SB_SETTEXT SB_SETTEXTW
#define SB_SETTIPTEXT SB_SETTIPTEXTW

#define TB_ADDBUTTONS TB_ADDBUTTONSW
#define TB_ADDSTRING TB_ADDSTRINGW
#define TB_GETBUTTONINFO TB_GETBUTTONINFOW
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
#define TB_GETSTRING TB_GETSTRINGW
#define TB_INSERTBUTTON TB_INSERTBUTTONW
#define TB_MAPACCELERATOR TB_MAPACCELERATORW
#define TB_SAVERESTORE TB_SAVERESTOREW
#define TB_SETBUTTONINFO TB_SETBUTTONINFOW

#define TCM_GETITEM TCM_GETITEMW
#define TCM_INSERTITEM TCM_INSERTITEMW
#define TCM_SETITEM TCM_SETITEMW

#define TTM_ADDTOOL TTM_ADDTOOLW
#define TTM_DELTOOL TTM_DELTOOLW
#define TTM_ENUMTOOLS TTM_ENUMTOOLSW
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLW
#define TTM_GETTEXT TTM_GETTEXTW
#define TTM_GETTOOLINFO TTM_GETTOOLINFOW
#define TTM_HITTEST TTM_HITTESTW
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTW
#define TTM_SETTITLE TTM_SETTITLEW
#define TTM_SETTOOLINFO TTM_SETTOOLINFOW
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTW

#define TVM_EDITLABEL TVM_EDITLABELW
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
#define TVM_GETITEM TVM_GETITEMW
#define TVM_INSERTITEM TVM_INSERTITEMW
#define TVM_SETITEM TVM_SETITEMW
#else
#define ACM_OPEN ACM_OPENA

#define CBEM_GETITEM CBEM_GETITEMA
#define CBEM_INSERTITEM CBEM_INSERTITEMA
#define CBEM_SETITEM CBEM_SETITEMA

#define DTM_SETFORMAT DTM_SETFORMATA

#define HDM_GETITEM HDM_GETITEMA
#define HDM_INSERTITEM HDM_INSERTITEMA
#define HDM_SETITEM HDM_SETITEMA

#define LVM_EDITLABEL LVM_EDITLABELA
#define LVM_FINDITEM LVM_FINDITEMA
#define LVM_GETBKIMAGE LVM_GETBKIMAGEA
#define LVM_GETCOLUMN LVM_GETCOLUMNA
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
#define LVM_GETITEM LVM_GETITEMA
#define LVM_GETITEMTEXT LVM_GETITEMTEXTA
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNA
#define LVM_INSERTITEM LVM_INSERTITEMA
#define LVM_SETBKIMAGE LVM_SETBKIMAGEA
#define LVM_SETCOLUMN LVM_SETCOLUMNA
#define LVM_SETITEM LVM_SETITEMA
#define LVM_SETITEMTEXT LVM_SETITEMTEXTA

#define RB_GETBANDINFO RB_GETBANDINFOA
#define RB_INSERTBAND RB_INSERTBANDA
#define RB_SETBANDINFO RB_SETBANDINFOA

#define SB_GETTEXT SB_GETTEXTA
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHA
#define SB_GETTIPTEXT SB_GETTIPTEXTA
#define SB_SETTEXT SB_SETTEXTA
#define SB_SETTIPTEXT SB_SETTIPTEXTA

#define TB_ADDBUTTONS TB_ADDBUTTONSA
#define TB_ADDSTRING TB_ADDSTRINGA
#define TB_GETBUTTONINFO TB_GETBUTTONINFOA
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
#define TB_GETSTRING TB_GETSTRINGA
#define TB_INSERTBUTTON TB_INSERTBUTTONA
#define TB_MAPACCELERATOR TB_MAPACCELERATORA
#define TB_SAVERESTORE TB_SAVERESTOREA
#define TB_SETBUTTONINFO TB_SETBUTTONINFOA

#define TCM_GETITEM TCM_GETITEMA
#define TCM_INSERTITEM TCM_INSERTITEMA
#define TCM_SETITEM TCM_SETITEMA

#define TTM_ADDTOOL TTM_ADDTOOLA
#define TTM_DELTOOL TTM_DELTOOLA
#define TTM_ENUMTOOLS TTM_ENUMTOOLSA
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
#define TTM_GETTEXT TTM_GETTEXTA
#define TTM_GETTOOLINFO TTM_GETTOOLINFOA
#define TTM_HITTEST TTM_HITTESTA
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTA
#define TTM_SETTITLE TTM_SETTITLEA
#define TTM_SETTOOLINFO TTM_SETTOOLINFOA
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTA

#define TVM_EDITLABEL TVM_EDITLABELA
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
#define TVM_GETITEM TVM_GETITEMA
#define TVM_INSERTITEM TVM_INSERTITEMA
#define TVM_SETITEM TVM_SETITEMA
#endif

#define CBEN_BEGINEDIT (-804)
#define CBEN_DELETEITEM (-802)
#define CBEN_DRAGBEGINA (-808)
#define CBEN_DRAGBEGINW (-809)
#define CBEN_ENDEDITA (-805)
#define CBEN_ENDEDITW (-806)
#define CBEN_GETDISPINFOA (-800)
#define CBEN_GETDISPINFOW (-807)
#define CBEN_INSERTITEM (-801)

#define DTN_CLOSEUP (-753)
#define DTN_DATETIMECHANGE (-759)
#define DTN_DROPDOWN (-754)
#define DTN_FORMATA (-756)
#define DTN_FORMATQUERYA (-755)
#define DTN_FORMATQUERYW (-742)
#define DTN_FORMATW (-743)
#define DTN_USERSTRINGA (-758)
#define DTN_USERSTRINGW (-745)
#define DTN_WMKEYDOWNA (-757)
#define DTN_WMKEYDOWNW (-744)

#define HDN_BEGINDRAG (-310)
#define HDN_BEGINTRACKA (-306)
#define HDN_BEGINTRACKW (-326)
#define HDN_DIVIDERDBLCLICKA (-305)
#define HDN_DIVIDERDBLCLICKW (-325)
#define HDN_ENDDRAG (-311)
#define HDN_ENDTRACKA (-307)
#define HDN_ENDTRACKW (-327)
#define HDN_FILTERBTNCLICK (-313)
#define HDN_FILTERCHANGE (-312)
#define HDN_GETDISPINFOA (-309)
#define HDN_GETDISPINFOW (-329)
#define HDN_ITEMCHANGEDA (-301)
#define HDN_ITEMCHANGEDW (-321)
#define HDN_ITEMCHANGINGA (-300)
#define HDN_ITEMCHANGINGW (-320)
#define HDN_ITEMCLICKA (-302)
#define HDN_ITEMCLICKW (-322)
#define HDN_ITEMDBLCLICKA (-303)
#define HDN_ITEMDBLCLICKW (-323)
#define HDN_TRACKA (-308)
#define HDN_TRACKW (-328)

#define IPN_FIELDCHANGED (-860)

#define LVN_BEGINDRAG (-109)
#define LVN_BEGINLABELEDITA (-105)
#define LVN_BEGINLABELEDITW (-175)
#define LVN_BEGINRDRAG (-111)
#define LVN_COLUMNCLICK (-108)
#define LVN_DELETEALLITEMS (-104)
#define LVN_DELETEITEM (-103)
#define LVN_ENDLABELEDITA (-106)
#define LVN_ENDLABELEDITW (-176)
#define LVN_GETDISPINFOA (-150)
#define LVN_GETDISPINFOW (-177)
#define LVN_GETINFOTIPA (-157)
#define LVN_GETINFOTIPW (-158)
#define LVN_HOTTRACK (-121)
#define LVN_INSERTITEM (-102)
#define LVN_ITEMACTIVATE (-114)
#define LVN_ITEMCHANGED (-101)
#define LVN_ITEMCHANGING (-100)
#define LVN_KEYDOWN (-155)
#define LVN_MARQUEEBEGIN (-156)
#define LVN_ODCACHEHINT (-113)
#define LVN_ODFINDITEMA (-152)
#define LVN_ODFINDITEMW (-179)
#define LVN_ODSTATECHANGED (-115)
#define LVN_SETDISPINFOA (-151)
#define LVN_SETDISPINFOW (-178)

#define MCN_GETDAYSTATE (-747)
#define MCN_SELCHANGE (-749)
#define MCN_SELECT (-746)

#define NM_CACHEHINT NMLVCACHEHINT
#define NM_CHAR (-18)
#define NM_CLICK (-2)
#define NM_CUSTOMDRAW (-12)
#define NM_DBLCLK (-3)
#define NM_FINDITEMA NMLVFINDITEMA
#define NM_FINDITEMW NMLVFINDITEMW
#define NM_HOVER (-13)
#define NM_KEYDOWN (-15)
#define NM_KILLFOCUS (-8)
#define NM_LDOWN (-20)
#define NM_LISTVIEW NMLISTVIEW
#define NM_NCHITTEST (-14)
#define NM_ODSTATECHANGE NMLVODSTATECHANGE
#define NM_OUTOFMEMORY (-1)
#define NM_RCLICK (-5)
#define NM_RDBLCLK (-6)
#define NM_RDOWN (-21)
#define NM_RELEASEDCAPTURE (-16)
#define NM_RETURN (-4)
#define NM_SETCURSOR (-17)
#define NM_SETFOCUS (-7)
#define NM_TOOLTIPSCREATED (-19)
#define NM_TREEVIEW NMTREEVIEW
#define NM_TREEVIEWA NMTREEVIEWA
#define NM_TREEVIEWW NMTREEVIEWW
#define NM_UPDOWN NMUPDOWN

#define PGN_CALCSIZE (-902)
#define PGN_SCROLL (-901)

#define RBN_AUTOSIZE (-834)
#define RBN_BEGINDRAG (-835)
#define RBN_CHEVRONPUSHED (-841)
#define RBN_CHILDSIZE (-839)
#define RBN_DELETEDBAND (-838)
#define RBN_DELETINGBAND (-837)
#define RBN_ENDDRAG (-836)
#define RBN_GETOBJECT (-832)
#define RBN_HEIGHTCHANGE (-831)
#define RBN_LAYOUTCHANGED (-833)
#define RBN_MINMAX (-852)

#define SBN_SIMPLEMODECHANGE (-880)

#define TBN_BEGINADJUST (-703)
#define TBN_BEGINDRAG (-701)
#define TBN_CUSTHELP (-709)
#define TBN_DELETINGBUTTON (-715)
#define TBN_DRAGOUT (-714)
#define TBN_DROPDOWN (-710)
#define TBN_ENDADJUST (-704)
#define TBN_ENDDRAG (-702)
#define TBN_GETBUTTONINFOA (-700)
#define TBN_GETBUTTONINFOW (-720)
#define TBN_GETDISPINFOA (-716)
#define TBN_GETDISPINFOW (-717)
#define TBN_GETINFOTIPA (-718)
#define TBN_GETINFOTIPW (-719)
#define TBN_GETOBJECT (-712)
#define TBN_HOTITEMCHANGE (-713)
#define TBN_INITCUSTOMIZE (-723)
#define TBN_QUERYDELETE (-707)
#define TBN_QUERYINSERT (-706)
#define TBN_RESET (-705)
#define TBN_RESTORE (-721)
#define TBN_SAVE (-722)
#define TBN_TOOLBARCHANGE (-708)

#define TCN_FOCUSCHANGE (-554)
#define TCN_GETOBJECT (-553)
#define TCN_KEYDOWN (-550)
#define TCN_SELCHANGE (-551)
#define TCN_SELCHANGING (-552)

#define TTN_GETDISPINFOA (-520)
#define TTN_GETDISPINFOW (-530)
#define TTN_NEEDTEXT TTN_GETDISPINFO
#define TTN_NEEDTEXTA TTN_GETDISPINFOA
#define TTN_NEEDTEXTW TTN_GETDISPINFOW
#define TTN_POP (-522)
#define TTN_SHOW (-521)

#define TVN_BEGINDRAGA (-407)
#define TVN_BEGINDRAGW (-456)
#define TVN_BEGINLABELEDITA (-410)
#define TVN_BEGINLABELEDITW (-459)
#define TVN_BEGINRDRAGA (-408)
#define TVN_BEGINRDRAGW (-457)
#define TVN_DELETEITEMA (-409)
#define TVN_DELETEITEMW (-458)
#define TVN_ENDLABELEDITA (-411)
#define TVN_ENDLABELEDITW (-460)
#define TVN_GETDISPINFOA (-403)
#define TVN_GETDISPINFOW (-452)
#define TVN_GETINFOTIPA (-413)
#define TVN_GETINFOTIPW (-414)
#define TVN_ITEMEXPANDEDA (-406)
#define TVN_ITEMEXPANDEDW (-455)
#define TVN_ITEMEXPANDINGA (-405)
#define TVN_ITEMEXPANDINGW (-454)
#define TVN_KEYDOWN (-412)
#define TVN_SELCHANGEDA (-402)
#define TVN_SELCHANGEDW (-451)
#define TVN_SELCHANGINGA (-401)
#define TVN_SELCHANGINGW (-450)
#define TVN_SETDISPINFOA (-404)
#define TVN_SETDISPINFOW (-453)
#define TVN_SINGLEEXPAND (-415)

#define UDN_DELTAPOS (-722)

#ifdef UNICODE
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
#define CBEN_ENDEDIT CBEN_ENDEDITW
#define CBEN_GETDISPINFO CBEN_GETDISPINFOW

#define DTN_FORMAT DTN_FORMATW
#define DTN_FORMATQUERY DTN_FORMATQUERYW
#define DTN_USERSTRING DTN_USERSTRINGW
#define DTN_WMKEYDOWN DTN_WMKEYDOWNW

#define HDN_BEGINTRACK HDN_BEGINTRACKW
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKW
#define HDN_ENDTRACK HDN_ENDTRACKW
#define HDN_GETDISPINFO HDN_GETDISPINFOW
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDW
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGW
#define HDN_ITEMCLICK HDN_ITEMCLICKW
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKW
#define HDN_TRACK HDN_TRACKW

#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
#define LVN_GETDISPINFO LVN_GETDISPINFOW
#define LVN_GETINFOTIP LVN_GETINFOTIPW
#define LVN_ODFINDITEM LVN_ODFINDITEMW
#define LVN_SETDISPINFO LVN_SETDISPINFOW

#define NM_FINDITEM NM_FINDITEMW

#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
#define TBN_GETDISPINFO TBN_GETDISPINFOW
#define TBN_GETINFOTIP TBN_GETINFOTIPW

#define TTN_GETDISPINFO TTN_GETDISPINFOW

#define TVN_BEGINDRAG TVN_BEGINDRAGW
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
#define TVN_BEGINRDRAG TVN_BEGINRDRAGW
#define TVN_DELETEITEM TVN_DELETEITEMW
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
#define TVN_GETDISPINFO TVN_GETDISPINFOW
#define TVN_GETINFOTIP TVN_GETINFOTIPW
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
#define TVN_SELCHANGED TVN_SELCHANGEDW
#define TVN_SELCHANGING TVN_SELCHANGINGW
#define TVN_SETDISPINFO TVN_SETDISPINFOW
#else
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
#define CBEN_ENDEDIT CBEN_ENDEDITA
#define CBEN_GETDISPINFO CBEN_GETDISPINFOA

#define DTN_FORMAT DTN_FORMATA
#define DTN_FORMATQUERY DTN_FORMATQUERYA
#define DTN_USERSTRING DTN_USERSTRINGA
#define DTN_WMKEYDOWN DTN_WMKEYDOWNA

#define HDN_BEGINTRACK HDN_BEGINTRACKA
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKA
#define HDN_ENDTRACK HDN_ENDTRACKA
#define HDN_GETDISPINFO HDN_GETDISPINFOA
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDA
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGA
#define HDN_ITEMCLICK HDN_ITEMCLICKA
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKA
#define HDN_TRACK HDN_TRACKA

#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
#define LVN_GETDISPINFO LVN_GETDISPINFOA
#define LVN_GETINFOTIP LVN_GETINFOTIPA
#define LVN_ODFINDITEM LVN_ODFINDITEMA
#define LVN_SETDISPINFO LVN_SETDISPINFOA

#define NM_FINDITEM NM_FINDITEMA

#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
#define TBN_GETDISPINFO TBN_GETDISPINFOA
#define TBN_GETINFOTIP TBN_GETINFOTIPA

#define TTN_GETDISPINFO TTN_GETDISPINFOA

#define TVN_BEGINDRAG TVN_BEGINDRAGA
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
#define TVN_BEGINRDRAG TVN_BEGINRDRAGA
#define TVN_DELETEITEM TVN_DELETEITEMA
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
#define TVN_GETDISPINFO TVN_GETDISPINFOA
#define TVN_GETINFOTIP TVN_GETINFOTIPA
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
#define TVN_SELCHANGED TVN_SELCHANGEDA
#define TVN_SELCHANGING TVN_SELCHANGINGA
#define TVN_SETDISPINFO TVN_SETDISPINFOA
#endif