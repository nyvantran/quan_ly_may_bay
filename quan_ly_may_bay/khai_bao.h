#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#define MAX_MB 300
//////////struct may bay
struct MayBay
{
	char sh_Mb[15];
	char loai_may_bay[40];
	int so_day, so_dong;
};
struct DSMayBay {
	int so_MB = 0;
	MayBay* maybay[MAX_MB];
	/*function*/;
	void napFile(const char file[]) ;
	void ghiFile(const char file[]) const;
	void xoa() const;
};
//////
///////////struct chuyen bay
struct Ve
{
	char cmnd[225];
	char vitri[5];
};
enum TrangThai {
	HUY_CHUYEN,
	CON_VE,
	HET_VE,
	HOAN_TAT,
};
struct Ngay {
	int ngay = -1;
	int thang = -1;
	int nam = -1;
};

struct Gio {
	int gio = -1;
	int phut = -1;
};
struct NgayGio
{
	Ngay ngay_kh;
	Gio gio_kh;
	void datNgayGio(int gio, int phut, int ngay, int thang, int nam);
};
struct ChuyenBay
{
	char ma_cb[15];
	NgayGio ngay_gio_kh;
	char san_bay_den[100];
	char sh_Mb[15];
	TrangThai trang_thai_cb;
	Ve* ds_ve = NULL;
	ChuyenBay();
};
struct NodeChuyenBay
{
	ChuyenBay cb;
	NodeChuyenBay* next = NULL;
};
typedef NodeChuyenBay* PTRChuyenBay;
///chuyen bay function 
void napFileChuyenBay(const char file[],PTRChuyenBay &fist);
void ghiFileChuyenBay(const char file[],PTRChuyenBay fist);
bool themChuyenBay(PTRChuyenBay&, ChuyenBay);
void xoahetChuyenBay(PTRChuyenBay&);
bool xoaChuyenBay(PTRChuyenBay&, PTRChuyenBay);
/*xoa nodechuyenbay*/
bool xoadauNodeChuyenBay(PTRChuyenBay& fist);
bool xoasauNodeChuyenBay(PTRChuyenBay p);
//////////////
PTRChuyenBay timChuyenBay(PTRChuyenBay fist, char x[]);
void chinhsuaChuyenBay(PTRChuyenBay& p, NgayGio time, char sbd[], char shmb[]);
/*void KhoiDauCB(PTRChuyenBay& fist);*/
PTRChuyenBay KhoiTaoCB();
void ThemDauCB(PTRChuyenBay& fist, ChuyenBay x);
void ThemSauCB(PTRChuyenBay p, ChuyenBay x);
///////////
/////struct khanh hang
struct KhachHang
{
	char cmnd[20];
	char ho[100];
	char ten[10];
	bool phai;
};
struct NodeKhachHang
{
	KhachHang info;
	int bf;
	NodeKhachHang* left, * right;
};
typedef NodeKhachHang* PTRKhachhang;
//////
