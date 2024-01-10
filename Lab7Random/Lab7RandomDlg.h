
// Lab7RandomDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLab7RandomDlg
class CLab7RandomDlg : public CDialogEx
{
// Создание
public:
	CLab7RandomDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB7RANDOM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedGenerate();
	afx_msg void OnEnChangeEdit1();
	// Ввыводим число суммы меньших или наибольиш
	CString EDIT_VALUE;
	afx_msg void OnClickedBtnBig();
	afx_msg void OnClickedBtnSmall();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedSort();
};
