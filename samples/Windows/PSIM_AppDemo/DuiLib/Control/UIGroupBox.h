#ifndef __UIGROUPBOX_H__
#define __UIGROUPBOX_H__

#pragma once

#define  GROUPBOX_TEXT_OFFSET		20		//����GroupBox�е�Text�������ߵ�ƫ��

namespace DuiLib
{

	class UILIB_API CGroupBoxUI : public CControlUI
	{
		DECLARE_DUICONTROL(CGroupBoxUI)
	public:
		CGroupBoxUI();
		~CGroupBoxUI();
		 LPCTSTR GetClass() const;
		 LPVOID GetInterface(LPCTSTR pstrName);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void PaintText(HDC hDC);
		void PaintBorder(HDC hDC);
		void SetTextColor(DWORD dwTextColor);
		void SetFont(int iFont);
		void SetShowHtml(bool bShowHtml);

	private:
		DWORD	m_dwTextColor;		///������ɫ
		int		m_iFont;			///����ţ���С
		bool	m_bShowHtml;		///�Ƿ���ʾHTML����
		int		m_iTextWidth;		///Text���ֿ�
		int		m_iTextHeigh;		///Text���ָ�
	};
}
#endif // __UIGROUPBOX_H__