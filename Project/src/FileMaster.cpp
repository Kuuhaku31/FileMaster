
#include "FileMaster.hpp"

bool getPath(std::string &path)
{
	char path_ch[4096];

	BROWSEINFO bInfo = {0};
	bInfo.hwndOwner = GetForegroundWindow(); // 父窗口
	bInfo.lpszTitle = TEXT("Browse File Folder");
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI /*包含一个编辑框 用户可以手动填写路径 对话框可以调整大小之类的..*/ |
					BIF_UAHINT /*带TIPS提示*/;
	LPITEMIDLIST lpDlist;
	lpDlist = SHBrowseForFolder(&bInfo);
	if (lpDlist != NULL)
	{
		SHGetPathFromIDList(lpDlist, path_ch);
		path = std::string(path_ch);
		return true;
	}
	else
	{
		return false;
	}
}