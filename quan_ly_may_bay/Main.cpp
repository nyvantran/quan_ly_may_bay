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
	/*Ve tam;
	for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next) {
		if (p->cb.so_ve != 0) {
			for (int i = 0; i < p->cb.so_ve; i++) {
				for (int j = i; j < p->cb.so_ve; j++) {
					if (strcmp(p->cb.ds_ve[i].vitri, p->cb.ds_ve[j].vitri) == 1) {
						tam = p->cb.ds_ve[i];
						p->cb.ds_ve[i] = p->cb.ds_ve[j];
						p->cb.ds_ve[j] = tam;
					}
				}
			}
		}
	}*/
	ds_may_bay.ghiFile(DLMAYBAY);
	ghiFileChuyenBay(DLCHUYENBAY,dau_chuyen_bay,ds_may_bay);	
	ghiFileKhangHang(goc_khach_hang, DLKHACHHANG);
	ds_may_bay.xoa();
	xoahetChuyenBay(dau_chuyen_bay);
	xoaHetKhachHang(goc_khach_hang);
	///////////////////
}


