
# ===================== �ⲿ����Լ��� =============================
!include "StrFunc.nsh"
!include "WordFunc.nsh"
${StrRep}
${StrStr}
!include "LogicLib.nsh"
!include "nsDialogs.nsh"
!include "common.nsh"
!include "x64.nsh"
!include "MUI.nsh"
!include "WinVer.nsh" 

!insertmacro MUI_LANGUAGE "SimpChinese"
# ===================== �������汾 =============================
VIProductVersion             		"${PRODUCT_VERSION}"
VIAddVersionKey "ProductVersion"    "${PRODUCT_VERSION}"
VIAddVersionKey "ProductName"       "${PRODUCT_NAME}"
VIAddVersionKey "CompanyName"       "${PRODUCT_PUBLISHER}"
VIAddVersionKey "FileVersion"       "${PRODUCT_VERSION}"
VIAddVersionKey "InternalName"      "${EXE_NAME}"
VIAddVersionKey "FileDescription"   "${PRODUCT_NAME}"
VIAddVersionKey "LegalCopyright"    "${PRODUCT_LEGAL}"

!define PRODUCT_WEB_SITE "www.easylive.com"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\${EXE_NAME}"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

!define INSTALL_PAGE_CONFIG 			0
;!define INSTALL_PAGE_LICENSE 			1
!define INSTALL_PAGE_PROCESSING 		1
!define INSTALL_PAGE_FINISH 			2
!define INSTALL_PAGE_UNISTCONFIG 		3
!define INSTALL_PAGE_UNISTPROCESSING 	4
!define INSTALL_PAGE_UNISTFINISH 		5

InstallDirRegKey HKLM  "Software\Microsoft\Windows\CurrentVersion\App Paths\${EXE_NAME}" ""

# �Զ���ҳ��
Page custom DUIPage

# ж�س�����ʾ����
UninstPage custom un.DUIPage

# ======================= DUILIB �Զ���ҳ�� =========================
Var hInstallDlg
Var sCmdFlag
Var sCmdSetupPath
Var sSetupPath 
Var sReserveData   #ж��ʱ�Ƿ������� 
Var InstallState   #���������л����������  
Var UnInstallValue  #ж�صĽ���  

Var temp11
Var temp12
Function DUIPage
    StrCpy $InstallState "0"	#����δ�������״̬
	InitPluginsDir   	
	SetOutPath "$PLUGINSDIR"
	File "${INSTALL_LICENCE_FILENAME}"
    File "${INSTALL_RES_PATH}"
	nsNiuniuSkin::InitSkinPage "$PLUGINSDIR\" "${INSTALL_LICENCE_FILENAME}" #ָ�����·����Э���ļ�����
    Pop $hInstallDlg
   	
	#���ÿؼ���ʾ����·�� 
	ReadRegStr $0 HKLM "Software\${PRODUCT_NAME}" "InstPath"
	${if} $0 == ""
	${else}
		 StrCpy $INSTDIR "$0" 
	${Endif}
    nsNiuniuSkin::SetDirValue "$INSTDIR"
	#�����������ı��⼰��������ʾ  
	nsNiuniuSkin::SetWindowTile "${PRODUCT_NAME}��������"
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_CONFIG}
	#nsNiuniuSkin::PrePage "wizardTab" 
    Call BindUIControls	
    nsNiuniuSkin::ShowPage	
FunctionEnd

Function un.DUIPage
FunctionEnd

#��ж�ص��¼� 
Function un.BindUnInstUIControls
	GetFunctionAddress $0 un.ExitDUISetup
    nsNiuniuSkin::BindCallBack "btnUninstalled" $0
	
	GetFunctionAddress $0 un.onUninstall
    nsNiuniuSkin::BindCallBack "btnUnInstall" $0
	
	GetFunctionAddress $0 un.ExitDUISetup
    nsNiuniuSkin::BindCallBack "btnClose" $0
FunctionEnd

#�������Ľ����¼� 
Function BindUIControls
	# Licenseҳ��
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnLicenseClose" $0

    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnLicenseMin" $0
 
	GetFunctionAddress $0 OnBtnLicenseClick
    nsNiuniuSkin::BindCallBack "btnAgreement" $0

    # Ŀ¼ѡ�� ҳ��
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnDirClose" $0

	GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnLicenseCancel" $0
    
    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnDirMin" $0
    
    GetFunctionAddress $0 OnBtnSelectDir
    nsNiuniuSkin::BindCallBack "btnSelectDir" $0
    
    GetFunctionAddress $0 OnBtnDirPre
    nsNiuniuSkin::BindCallBack "btnDirPre" $0
    
	GetFunctionAddress $0 OnBtnShowConfig
    nsNiuniuSkin::BindCallBack "btnAgree" $0
	
    GetFunctionAddress $0 OnBtnCancel
    nsNiuniuSkin::BindCallBack "btnDirCancel" $0
        
    GetFunctionAddress $0 OnBtnInstall
    nsNiuniuSkin::BindCallBack "btnInstall" $0

    # �������� ҳ��
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnDetailClose" $0

    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnDetailMin" $0
	
    # ������� ҳ��
    GetFunctionAddress $0 OnFinished
    nsNiuniuSkin::BindCallBack "btnRun" $0
    
    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnFinishedMin" $0
    
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnClose" $0
	
	GetFunctionAddress $0 OnCheckLicenseClick
    nsNiuniuSkin::BindCallBack "chkAgree" $0
	
	GetFunctionAddress $0 OnBtnShowMore
    nsNiuniuSkin::BindCallBack "btnShowMore" $0
	
	GetFunctionAddress $0 OnBtnHideMore
    nsNiuniuSkin::BindCallBack "btnHideMore" $0
FunctionEnd

#����ѡ�е���������ư�ť�Ƿ�Ҷ���ʾ 
Function OnCheckLicenseClick
	nsNiuniuSkin::GetCheckboxStatus "chkAgree"
    Pop $0
	${If} $0 == "0"        
		nsNiuniuSkin::SetControlAttribute "btnInstall" "enabled" "true"
	${Else}
		nsNiuniuSkin::SetControlAttribute "btnInstall" "enabled" "false"
    ${EndIf}
FunctionEnd

Function OnBtnLicenseClick
    ;nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_LICENSE}
	nsNiuniuSkin::SetControlAttribute "licenseshow" "visible" "true"
	nsNiuniuSkin::IsControlVisible "moreconfiginfo"
	Pop $0
	${If} $0 = 0        
		;pos="10,35,580,410"
		nsNiuniuSkin::SetControlAttribute "licenseshow" "pos" "10,35,590,410"
		nsNiuniuSkin::SetControlAttribute "editLicense" "height" "300"		
	${Else}
		nsNiuniuSkin::SetControlAttribute "licenseshow" "pos" "10,35,590,470"
		nsNiuniuSkin::SetControlAttribute "editLicense" "height" "360"
    ${EndIf}
	
FunctionEnd

# ���һ���յ�Section����ֹ����������
Section "None"
SectionEnd

# ��ʼ����
Function OnBtnInstall
    nsNiuniuSkin::GetCheckboxStatus "chkAgree"
    Pop $0
	StrCpy $0 "1"
	
	#���δͬ�⣬ֱ���˳� 
	StrCmp $0 "0" InstallAbort 0
	
	CheckExe: 
	#�˴���⵱ǰ�Ƿ��г����������У�����������У���ʾ��ж�������� 
	nsProcess::_FindProcess "${EXE_NAME}"
	Pop $R0
	${If} $R0 == 0
        nsNiuniuSkin::ShowMsgBox "��ʾ" "${PRODUCT_NAME} �������У�ȷ����������ô��" 1
		pop $0
		${If} $0 == 0
			; ȡ��������;
			goto InstallAbort
		${EndIf}

		Push "xsd.exe"
		Processwork::KillProcess

		Sleep 1000
		Goto CheckExe
    ${EndIf}		

	nsNiuniuSkin::GetDirValue
    Pop $0
    StrCmp $0 "" InstallAbort 0
	#$sCmdSetupPath��ʾ �������д���·�� �ķ�ʽ  
	StrCpy $sSetupPath "$0\"
    StrCpy $INSTDIR "$0"
	#д��ע����Ϣ 
	SetRegView 32
	WriteRegStr HKLM "Software\${PRODUCT_NAME}" "InstPath" "$sSetupPath"
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 420
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "false"
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_PROCESSING}
    nsNiuniuSkin::SetSliderRange "slrProgress" 0 100
	
    # ����Щ�ļ��ݴ浽��ʱĿ¼
    #Call BakFiles
  
    #����һ�������ȼ��ĺ�̨�߳�
    GetFunctionAddress $0 ExtractFunc
    BgWorker::CallAndWait
	
    #��ԭ�ļ�
    #Call RestoreFiles
    
	#����ģʽ�²���Ҫ������ݷ�ʽ�� 
	#Call CreateShortcut
	#Call CreateUninstall
    	
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_FINISH}
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "true"
		
	StrCpy $InstallState "1"
InstallAbort:
FunctionEnd

Function ExtractFunc
    SetOutPath $INSTDIR
    File "${INSTALL_7Z_PATH}"
    GetFunctionAddress $R9 ExtractCallback
    nsis7z::ExtractWithCallback "$INSTDIR\${INSTALL_7Z_NAME}" $R9
	Delete "$INSTDIR\${INSTALL_7Z_NAME}"
	Sleep 100
FunctionEnd

Function ExtractCallback
    Pop $1
    Pop $2
    System::Int64Op $1 * 100
    Pop $3
    System::Int64Op $3 / $2
    Pop $0
    Sleep 10
    nsNiuniuSkin::SetSliderValue "slrProgress" $0
	Sleep 10
    ${If} $1 == $2
        nsNiuniuSkin::SetSliderValue "slrProgress" 100        				
    ${EndIf}
FunctionEnd

#�����������˳���������ʾ 
Function OnExitDUISetup
	${If} $InstallState == "0"		
		nsNiuniuSkin::ShowMsgBox "��ʾ" "������δ��ɣ���ȷ���˳�ô��" 1
		pop $0
		${If} $0 == 0
			goto endfun
		${EndIf}
	${EndIf}
	nsNiuniuSkin::ExitDUISetup
endfun:    
FunctionEnd

Function OnBtnMin
    SendMessage $hInstallDlg ${WM_SYSCOMMAND} 0xF020 0
FunctionEnd

Function OnBtnCancel
	nsNiuniuSkin::ExitDUISetup
FunctionEnd

#��������
Function OnFinished	
	Exec '"$INSTDIR\${EXE_NAME}" /un'
    Call OnExitDUISetup
FunctionEnd

Function OnBtnSelectDir
    nsNiuniuSkin::SelectInstallDir
    Pop $0
FunctionEnd

Function OnBtnShowMore
	;�������ڸ߶� 
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 480
	nsNiuniuSkin::SetControlAttribute "moreconfiginfo" "visible" "true"
	nsNiuniuSkin::SetControlAttribute "btnShowMore" "visible" "false"
	nsNiuniuSkin::SetControlAttribute "btnHideMore" "visible" "true"
	
FunctionEnd

Function OnBtnHideMore
	;�������ڸ߶� 
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 420
	nsNiuniuSkin::SetControlAttribute "moreconfiginfo" "visible" "false"
	nsNiuniuSkin::SetControlAttribute "btnShowMore" "visible" "true"
	nsNiuniuSkin::SetControlAttribute "btnHideMore" "visible" "false"
FunctionEnd

Function OnBtnShowConfig
    ;nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_CONFIG}
	nsNiuniuSkin::SetControlAttribute "licenseshow" "visible" "false"
FunctionEnd

Function OnBtnDirPre
    nsNiuniuSkin::PrePage "wizardTab"
FunctionEnd


# ============================== �ص����� ====================================

# �������ԡ�.����ͷ��һ����Ϊ�ص���������.
# �������ԡ�un.����ͷ�ĺ������ᱻ������ж�س������ˣ���ͨ�������κͺ������ܵ���ж�غ�������ж�����κ�ж�غ���Ҳ���ܵ�����ͨ������

Function .onInit	
	#�˴���Ҫ���֮ǰ���������������Ѿ�����������Ŀ¼��ϢĬ��д���ַ�� 
	
FunctionEnd


# �����ɹ��Ժ�.
Function .onInstSuccess

FunctionEnd

# ������ʧ�ܺ��û������ȡ������ťʱ������.
Function .onInstFailed
    
FunctionEnd


# ÿ���û���������·����ʱ����δ��붼�ᱻ����һ��.
Function .onVerifyInstDir
;nsNiuniuSkin::SetControlAttribute "txtNeed" "text" "AAAA"
;nsNiuniuSkin::ShowMsgBox "��ʾ" "${PRODUCT_NAME} �������У����˳�������!" 0
FunctionEnd

# ж�ز�����ʼǰ.
Function un.onInit
    
FunctionEnd

# ж�سɹ��Ժ�.
Function un.onUninstSuccess

FunctionEnd

Function un.ExitDUISetup
	nsNiuniuSkin::ExitDUISetup
FunctionEnd

#ִ�о����ж�� 
Function un.onUninstall
	nsNiuniuSkin::GetCheckboxStatus "chkReserveData"
    Pop $0
	StrCpy $sReserveData $0
		
	#�˴���⵱ǰ�Ƿ��г����������У�����������У���ʾ��ж�������� 
	nsProcess::_FindProcess "${EXE_NAME}"
	Pop $R0
	
	${If} $R0 == 0
		nsNiuniuSkin::ShowMsgBox "��ʾ" "${PRODUCT_NAME} �������У����˳�������!" 0
		goto InstallAbort
    ${EndIf}
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "false"
	nsNiuniuSkin::SetControlAttribute "lblInstalling" "text" "����ж��..."
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_UNISTPROCESSING}
	nsNiuniuSkin::SetSliderRange "slrProgress" 0 100
	IntOp $UnInstallValue 0 + 1
	SetRegView 32
	;DeleteRegKey HKLM "Software\${PRODUCT_NAME}"	
	DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
	DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"

	; ɾ����ݷ�ʽ
	SetShellVarContext all
	
	Delete "$INSTDIR\${PRODUCT_NAME}.url"
	Delete "$INSTDIR\Uninst.exe"
 
	Delete "$DESKTOP\С����������.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\С����������.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\С����������.lnk"

	;RMDir "$SMPROGRAMS\$ICONS_GROUP"
	
	RMDir /r /REBOOTOK "$INSTDIR"
	
	/* Delete "$SMPROGRAMS\${PRODUCT_NAME}\${PRODUCT_NAME}.lnk"
	Delete "$SMPROGRAMS\${PRODUCT_NAME}\ж��${PRODUCT_NAME}.lnk"
	RMDir "$SMPROGRAMS\${PRODUCT_NAME}\"
	Delete "$DESKTOP\${PRODUCT_NAME}.lnk" */
	
	#ɾ����������  
    Delete "$SMSTARTUP\${PRODUCT_NAME}.lnk"
	SetShellVarContext current
	
	IntOp $UnInstallValue $UnInstallValue + 8
    
	#ɾ���ļ� 
	GetFunctionAddress $0 un.RemoveFiles
    BgWorker::CallAndWait	
	
	;SetAutoClose true
	
	InstallAbort:
FunctionEnd

#���߳���ɾ���ļ����Ա���ʾ���� 
Function un.RemoveFiles
	${Locate} "$INSTDIR" "/G=0 /M=*.*" "un.onDeleteFileFound"
	StrCpy $InstallState "1"
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "true"
	nsNiuniuSkin::SetSliderValue "slrProgress" 100
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_UNISTFINISH}
FunctionEnd


#ж�س���ʱɾ���ļ������̣��������Ҫ���˵��ļ����ڴ˺��������  
Function un.onDeleteFileFound
    ; $R9    "path\name"
    ; $R8    "path"
    ; $R7    "name"
    ; $R6    "size"  ($R6 = "" if directory, $R6 = "0" if file with /S=)
    
	
	#�Ƿ����ɾ��  
			
	Delete "$R9"
	RMDir /r "$R9"
    RMDir "$R9"
	
	IntOp $UnInstallValue $UnInstallValue + 2
	${If} $UnInstallValue > 100
		IntOp $UnInstallValue 100 + 0
		nsNiuniuSkin::SetSliderValue "slrUnInstProgress" 100
	${Else}
		nsNiuniuSkin::SetSliderValue "slrUnInstProgress" $UnInstallValue
		Sleep 20
	${EndIf}	
	undelete:
	Push "LocateNext"	
FunctionEnd