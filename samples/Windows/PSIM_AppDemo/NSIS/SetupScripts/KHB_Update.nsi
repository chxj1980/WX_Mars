# ====================== �Զ���� ��Ʒ��Ϣ==============================
!define PRODUCT_NAME           		"KHB"
!define EXE_NAME               		"KHB.exe"
!define PRODUCT_VERSION        		"2.1.0.0"
!define PRODUCT_PUBLISHER      		"xx���޹�˾"
!define PRODUCT_LEGAL          		"��Ȩ���У�c��2015-2016"
!define INSTALL_OUTPUT_NAME    		"../Output/KHB_Update.exe"

# ====================== �Զ���� ������Ϣ==============================
!define INSTALL_7Z_PATH 	   		"app.7z"
!define INSTALL_7Z_NAME 	   		"app.7z"
!define INSTALL_RES_PATH       		"update\skin.zip"
!define INSTALL_LICENCE_FILENAME    "license.txt"
!define INSTALL_ICO 				"Icon_Install.ico"
!define UNINSTALL_ICO 				"Icon_UnInstall.ico"

!include "KHB_Update_UI.nsh"

# ==================== NSIS���� ================================

# ���Vista��win7 ��UAC����Ȩ������.
# RequestExecutionLevel none|user|highest|admin
RequestExecutionLevel admin

#SetCompressor zlib

; ���°�����.
Name "${PRODUCT_NAME}"

# ���³����ļ���.
OutFile "${INSTALL_OUTPUT_NAME}"

; Ĭ�ϸ���Ŀ¼;
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"

# ���º�ж�س���ͼ��
Icon              "${INSTALL_ICO}"
UninstallIcon     "${UNINSTALL_ICO}"
