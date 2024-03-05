#include<iostream>
#include"khai_bao.h"
#include"do_hoa.h"
#define DLMAYBAY "dlmaybay.dat"
#define DLCHUYENBAY "dlchuyenbay.dat"
using namespace std;
int main() {
	DSMayBay ds_may_bay;
	PTRChuyenBay dau_chuyen_bay = NULL;


	ds_may_bay.napFile(DLMAYBAY);
	for (int i = 0; i < ds_may_bay.so_MB; i++) {
		cout << ds_may_bay.maybay[i]->sh_Mb << " ";
	}cout << endl;
	MayBay* sua = TimSoHieu(const_cast<char*>("n15"), ds_may_bay);
	char smb[23]; smb[0] = '\0';
	char loai[40]; strcpy_s(loai, 40, "mmmmm");
	HieuChinhMB(sua, smb, loai, -1, -1);
	for (int i = 0; i < ds_may_bay.so_MB; i++) {
		cout << ds_may_bay.maybay[i]->sh_Mb << " ";
	}cout << endl;

	/*PTRKhachhang goc_khach_hang;*/


}


