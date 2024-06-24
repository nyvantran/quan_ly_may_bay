#include<iostream>
#include<thread>
#include <stdint.h>
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
	napFileKhachHang(goc_khach_hang, DLKHACHHANG);
	
	//duyetLNR(goc_khach_hang);
	/*while (dau_chuyen_bay != NULL) {
		cout << dau_chuyen_bay->cb.sh_Mb << endl;
		cout << dau_chuyen_bay->cb.trang_thai_cb << endl;
		cout << endl;
		dau_chuyen_bay = dau_chuyen_bay->next;
	}*/
	///////////////////////////////////////////
	KhoiDong();
	chayDoHoa(ds_may_bay,dau_chuyen_bay,goc_khach_hang);
	//////////////
	KetThuc();
	ds_may_bay.ghiFile(DLMAYBAY);
	ghiFileChuyenBay(DLCHUYENBAY,dau_chuyen_bay,ds_may_bay);	
	ghiFileKhangHang(goc_khach_hang, DLKHACHHANG);
	ds_may_bay.xoa();
	xoahetChuyenBay(dau_chuyen_bay);
	xoaHetKhachHang(goc_khach_hang);
	///////////////////
	KetThuc();
	/*NgayGio t1, t2;
	t1.datNgayGio(8, 0, 23, 4, 2023);
	t2.datNgayGio(8, 0, 23, 4, 2023);
	cout << truNgayGio(t1, t2);*/
}


