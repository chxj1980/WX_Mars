# ====================== �Զ���� ��Ʒ��Ϣ==============================
!define PRODUCT_NAME           		"KHB"
!define EXE_NAME               		"KHB.exe"
!define PRODUCT_VERSION        		"2.1.0.0"
!define PRODUCT_PUBLISHER      		"xx���޹�˾"
!define PRODUCT_LEGAL          		"��Ȩ���У�c��2015-2016"
!define INSTALL_OUTPUT_NAME    		"../Output/KHB_Setup.exe"

# ====================== �Զ���� ��װ��Ϣ==============================
!define INSTALL_7Z_PATH 	   		"app.7z"
!define INSTALL_7Z_NAME 	   		"app.7z"
!define INSTALL_RES_PATH       		"install\skin.zip"
!define INSTALL_LICENCE_FILENAME    "license.txt"
!define INSTALL_ICO 				"Icon_Install.ico"
!define UNINSTALL_ICO 				"Icon_UnInstall.ico"

!include "KHB_Install_UI.nsh"

# ==================== NSIS���� ================================

# ���Vista��win7 ��UAC����Ȩ������.
# RequestExecutionLevel none|user|highest|admin
RequestExecutionLevel admin

#SetCompressor zlib

; ��װ������
Name "${PRODUCT_NAME}"

# ��װ�����ļ���.
OutFile "${INSTALL_OUTPUT_NAME}"

; Ĭ�ϰ�װĿ¼;
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"

# ��װ��ж�س���ͼ��
Icon              "${INSTALL_ICO}"
UninstallIcon     "${UNINSTALL_ICO}"
