#include<iostream>
#include<thread>
#include"khai_bao.h"
#include"do_hoa.h"
#define DLMAYBAY "dlmaybay.dat"
#define DLCHUYENBAY "dlchuyenbay.dat"
#define DLKHACHHANG "dlkhachhang.dat"
using namespace std;
int main() {
	DSMayBay ds_may_bay;
	PTRChuyenBay dau_chuyen_bay = NULL;
	PTRKhachhang goc_khach_hang = NULL;
	ds_may_bay.napFile(DLMAYBAY);
	napFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
	int max;

	//Bublesort(dau_chuyen_bay, ds_may_bay);
	//for (int i = 0; i < ds_may_bay.so_MB; i++) {
	//	cout << ds_may_bay.maybay[i]->sh_Mb << " ";
	//	timCBtheoSHMB(dau_chuyen_bay, ds_may_bay.maybay[i]->sh_Mb, max);
	//	cout << max << endl;
	//}
	//
	
	//PTRChuyenBay cbtam = dau_chuyen_bay;


	
	napFileKhachHang(goc_khach_hang, DLKHACHHANG);
	///////////////////////////////////////////
	KhoiDong();
	chayDoHoa(ds_may_bay,dau_chuyen_bay,goc_khach_hang);
	//////////////
	ds_may_bay.ghiFile(DLMAYBAY);
	ghiFileChuyenBay(DLCHUYENBAY,dau_chuyen_bay);	
	ghiFileKhangHang(goc_khach_hang, DLKHACHHANG);
	ds_may_bay.xoa();
	xoahetChuyenBay(dau_chuyen_bay);
	xoaHetKhachHang(goc_khach_hang);
	///////////////////
	KetThuc();
	

}


