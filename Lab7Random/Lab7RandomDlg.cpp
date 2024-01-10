
// Lab7RandomDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Lab7Random.h"
#include "Lab7RandomDlg.h"
#include "afxdialogex.h"
#include <vector>
#include <algorithm>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CLab7RandomDlg



CLab7RandomDlg::CLab7RandomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB7RANDOM_DIALOG, pParent)
	, EDIT_VALUE(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab7RandomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BBOD, EDIT_VALUE);
}

BEGIN_MESSAGE_MAP(CLab7RandomDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENERATE, &CLab7RandomDlg::OnClickedGenerate)
	ON_BN_CLICKED(IDC_BTN_BIG, &CLab7RandomDlg::OnClickedBtnBig)
	ON_BN_CLICKED(IDC_BTN_SMALL, &CLab7RandomDlg::OnClickedBtnSmall)
	ON_BN_CLICKED(IDC_SORT, &CLab7RandomDlg::OnClickedSort)
END_MESSAGE_MAP()


// Обработчики сообщений CLab7RandomDlg

BOOL CLab7RandomDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLab7RandomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLab7RandomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab7RandomDlg::OnClickedGenerate()
{
	// Получите указатель на элемент управления List Box
// Получите указатель на элемент управления List Box
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST); // IDC_MY_LISTBOX - идентификатор вашего List Box



	std::vector<int> numbers;

	for (int i = 0; i < 100; i++) {
		int randomNumber = rand();
		numbers.push_back(randomNumber);
	}

	// Сортировка чисел
	std::sort(numbers.begin(), numbers.end());

	// Добавление отсортированных чисел в List Box
	for (int i = 0; i < numbers.size(); i++) {
		CString numberString;
		numberString.Format(_T("%d"), numbers[i]);
		pListBox->AddString(numberString);
	}
}


void CLab7RandomDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CLab7RandomDlg::OnClickedBtnBig()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST); 

	
	int itemCount = pListBox->GetCount();
	if (itemCount < 3)
	{
		AfxMessageBox(_T("Выберите как минимум 3 числа"));
		return;
	}

	std::vector<int> numbers;


	for (int i = 0; i < itemCount; i++)
	{
		CString numberString;
		pListBox->GetText(i, numberString);
		int number = _ttoi(numberString);
		numbers.push_back(number);
	}

	std::sort(numbers.rbegin(), numbers.rend());

	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
 {
			sum += numbers[i];
		}
	}
	CString sumString;
	sumString.Format(_T("%d"), sum);
	UpdateData(TRUE);
	EDIT_VALUE = sumString;
	UpdateData(FALSE);


	pListBox->SetSel(-1, FALSE); // Снятие выделения со всех элементов ListBox
	for (int i = 0; i < 3; i++)
	{
		CString numberString;
		numberString.Format(_T("%d"), numbers[i]);
		int index = pListBox->FindStringExact(-1, numberString);
		if (index != LB_ERR)
		{
			pListBox->SetSel(index, TRUE); // Выделение числа
		}
	}

}


void CLab7RandomDlg::OnClickedBtnSmall()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST); 


	int itemCount = pListBox->GetCount();
	if (itemCount < 3)
	{
		AfxMessageBox(_T("Выберите как минимум 3 числа"));
		return;
	}

	std::vector<int> numbers;
	for (int i = 0; i < itemCount; i++)
	{
		CString numberString;
		pListBox->GetText(i, numberString);
		int number = _ttoi(numberString);
		numbers.push_back(number);

	}

	std::sort(numbers.begin(), numbers.end());

	int sum = 0;
	for (int i = 0; i < 3; i++)
	{

		sum += numbers[i];
	}

	CString sumString;
	sumString.Format(_T("%d"), sum);
	UpdateData(TRUE);
	EDIT_VALUE = sumString;
	UpdateData(FALSE);
	// Выделение трех наименьших чисел в ListBox
	pListBox->SetSel(-1, FALSE); // Снятие выделения со всех элементов ListBox
	for (int i = 0; i < 3; i++)
	{
		CString numberString;
		numberString.Format(_T("%d"), numbers[i]);
		int index = pListBox->FindStringExact(-1, numberString);
		if (index != LB_ERR)
		{
			pListBox->SetSel(index, TRUE); // Выделение числа
		}
	}

	
}



void CLab7RandomDlg::OnClickedSort()
{
		// Получение указателя на элемент ListBox
		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST); // IDC_MY_LISTBOX - идентификатор вашего ListBox

		int itemCount = pListBox->GetCount();
		if (itemCount < 2)
		{
			AfxMessageBox(_T("Добавьте как минимум 2 числа в ListBox"));
			return;
		}

		// Сортировка чисел в ListBox в порядке убывания
		for (int i = 0; i < itemCount - 1; i++)
		{
			for (int j = i + 1; j < itemCount; j++)
			{
				CString numberString1, numberString2;
				pListBox->GetText(i, numberString1);
				pListBox->GetText(j, numberString2);
				int number1 = _ttoi(numberString1);
				int number2 = _ttoi(numberString2);
				if (number1 < number2)
				{
					pListBox->DeleteString(j);
					pListBox->InsertString(i, numberString2);
				}
			}
		}
	
}
