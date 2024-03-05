#include<iostream>
#include"khai_bao.h"
#include"do_hoa.h"
#define DLMAYBAY "dlmaybay.dat"
#define DLCHUYENBAY "dlchuyenbay.dat"
using namespace std;
int main() {
	DSMayBay ds_may_bay;
	PTRChuyenBay dau_chuyen_bay = NULL;
	KhoiDong();
	void* tam = Menu();
	putimage(0, 0, tam, 0);
	KetThuc();
	/*PTRKhachhang goc_khach_hang;*/
	//////////////////

}


