#pragma once
#include <functional>
#include "ColorConvert.h"


// CTreeCtrlEx

//ע������ͨ���Ի��������ı���ѡ����ı�����ɫ��CTreeCtrl::SetTextColor �����������ã�
//������Ȼ����ʹ�� CTreeCtrl::SetBkColor ���ñ�����ɫ

class CTreeCtrlEx : public CTreeCtrl
{
	DECLARE_DYNAMIC(CTreeCtrlEx)

public:
	CTreeCtrlEx();
	virtual ~CTreeCtrlEx();

public:
    void InsertPath(CString path, HTREEITEM hRoot);

    //�����в���һ���ļ��нṹ
    //path: �ļ��еĸ�Ŀ¼
    //hRoot: Ҫ����ĸ�Ŀ¼�����ؼ��е�λ��
    //is_path_show: һ���������������ж�һ���ļ����Ƿ���Ҫ��ʾ
    void InsertPath(CString path, HTREEITEM hRoot, std::function<bool(const CString&)> is_path_show);
    CString GetItemPath(HTREEITEM hItem);

    bool IsItemExpand(HTREEITEM hItem);
    void ExpandAll(HTREEITEM hItem);        //չ��ָ���ڵ��µ����нڵ�
    void ExpandAll();                       //չ�����нڵ�
    void IterateItems(HTREEITEM hRoot, std::function<void(HTREEITEM)> func);           //����ָ���ڵ��µ����нڵ�

    void SaveExpandState();                 //�������нڵ��չ������״̬
    void SaveItemExpandState(HTREEITEM hItem, bool expand);     //����ָ���ڵ��չ������״̬
    void RestoreExpandState();              //�ָ����нڵ��չ������״̬

protected:
    static std::map<CString, bool> m_expand_state;       //����ÿ���ڵ��չ������״̬
    ColorTable& m_theme_color;

private:
    void _InsertPath(CString path, HTREEITEM hRoot, std::function<bool(const CString&)> is_path_show = [](const CString&) {return true; });

protected:
	DECLARE_MESSAGE_MAP()
    virtual void PreSubclassWindow();
public:
    afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
};

