#include<iostream>
#include<thread>
#include"khai_bao.h"
#include"do_hoa.h"
#define DLMAYBAY "dlmaybay.dat"
#define DLCHUYENBAY "dlchuyenbay.dat"
using namespace std;
int main() {
	DSMayBay ds_may_bay;
	PTRChuyenBay dau_chuyen_bay = NULL;
	PTRKhachhang goc_khach_hang = NULL;
	ds_may_bay.napFile(DLMAYBAY);
	napFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
	KhoiDong();
	chayDoHoa(ds_may_bay,dau_chuyen_bay,goc_khach_hang);
	ds_may_bay.ghiFile(DLMAYBAY);
	ghiFileChuyenBay(DLCHUYENBAY,dau_chuyen_bay);
	KetThuc();
}


