; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPassDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client_lv.h"

ClassCount=8
Class1=CClient_lvApp
Class2=CClient_lvDlg

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDD_LOGIN_DLG
Resource3=IDD_PRIOR_DLG
Resource4=IDD_INPUT_DLG
Resource5=IDD_FIND_DLG
Resource6=IDD_MODIFY_DLG
Resource7=IDD_PASS_DLG
Class3=CLoginDlg
Class4=CPriorDlg
Class5=CInputDlg
Class6=CModifyDlg
Class7=CFindDlg
Class8=CPassDlg
Resource8=IDD_WORK_DIALOG

[CLS:CClient_lvApp]
Type=0
HeaderFile=Client_lv.h
ImplementationFile=Client_lv.cpp
Filter=N

[CLS:CClient_lvDlg]
Type=0
HeaderFile=Client_lvDlg.h
ImplementationFile=Client_lvDlg.cpp
Filter=D
LastObject=CClient_lvDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_FIND_DLG]
Type=1
Class=CFindDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDC_CHECK_NUMB,button,1342242819
Control3=IDC_NUMB,edit,1350631552
Control4=IDC_CHECK_NAME,button,1342242819
Control5=IDC_NAME,edit,1350631552
Control6=IDC_CHECK_DATE,button,1342242819
Control7=IDC_DATES,SysDateTimePick32,1342242848
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DATEN,SysDateTimePick32,1342242848
Control10=IDC_CHECK_SEX,button,1342242819
Control11=IDC_SEX,button,1342308361
Control12=IDC_RADIO2,button,1342177289
Control13=IDC_CHECK_EDUC,button,1342242819
Control14=IDC_EDUC,combobox,1344340226
Control15=IDC_CHECK_LANG,button,1342242819
Control16=IDC_ENGL,button,1342242819
Control17=IDC_JAPN,button,1342242819
Control18=IDC_KREA,button,1342242819
Control19=IDC_RUSS,button,1342242819
Control20=IDC_LIST,SysListView32,1350631425

[DLG:IDD_INPUT_DLG]
Type=1
Class=CInputDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NUMB,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SALA,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_DATE,SysDateTimePick32,1342242848
Control11=IDC_STATIC,button,1342177287
Control12=IDC_SEX,button,1342308361
Control13=IDC_RADIO2,button,1342177289
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDUC,combobox,1344339971
Control16=IDC_STATIC,button,1342177287
Control17=IDC_ENGL,button,1342242819
Control18=IDC_JAPN,button,1342242819
Control19=IDC_KREA,button,1342242819
Control20=IDC_RUSS,button,1342242819

[DLG:IDD_LOGIN_DLG]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASS,edit,1350631584
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[DLG:IDD_MODIFY_DLG]
Type=1
Class=CModifyDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NUMB,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SALA,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_DATE,SysDateTimePick32,1342242848
Control11=IDC_STATIC,button,1342177287
Control12=IDC_SEX,button,1342308361
Control13=IDC_RADIO2,button,1342177289
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDUC,combobox,1344339971
Control16=IDC_STATIC,button,1342177287
Control17=IDC_ENGL,button,1342242819
Control18=IDC_JAPN,button,1342242819
Control19=IDC_KREA,button,1342242819
Control20=IDC_RUSS,button,1342242819

[DLG:IDD_PASS_DLG]
Type=1
Class=CPassDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_OLD,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NEW,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CONF,edit,1350631584
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[DLG:IDD_PRIOR_DLG]
Type=1
Class=CPriorDlg
ControlCount=10
Control1=IDC_LIST,SysListView32,1350631433
Control2=IDC_ADD,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PASS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PRIOR,combobox,1344339971
Control9=IDC_DEL,button,1342242816
Control10=IDC_MOD,button,1342242816

[DLG:IDD_WORK_DIALOG]
Type=1
Class=?
ControlCount=7
Control1=IDC_ADD,button,1342242816
Control2=IDC_DEL,button,1342242816
Control3=IDC_MOD,button,1342242816
Control4=IDC_LIST,SysListView32,1350664201
Control5=IDC_PROIR,button,1342242816
Control6=IDC_PASSWD,button,1342242816
Control7=IDC_FIND,button,1342242816

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

[CLS:CPriorDlg]
Type=0
HeaderFile=PriorDlg.h
ImplementationFile=PriorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PRIOR
VirtualFilter=dWC

[CLS:CInputDlg]
Type=0
HeaderFile=InputDlg.h
ImplementationFile=InputDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CInputDlg

[CLS:CModifyDlg]
Type=0
HeaderFile=ModifyDlg.h
ImplementationFile=ModifyDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CFindDlg]
Type=0
HeaderFile=FindDlg.h
ImplementationFile=FindDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CPassDlg]
Type=0
HeaderFile=PassDlg.h
ImplementationFile=PassDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPassDlg
VirtualFilter=dWC

