#pragma once
#include<iostream>
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
	int ngay;
	int thang;
	int nam;
};

struct Gio {
	int gio;
	int phut;
};
struct NgayGio
{
	Ngay ngay_kh;
	Gio gio_kh;
};
struct ChuyenBay
{
	char ma_cb[15];
	NgayGio ngay_gio_kh;
	char san_bay_den[100];
	TrangThai trang_thai_cb;
	Ve* ds_ve = NULL;
	/*ChuyenBay();*/
};
struct NodeChuyenBay
{
	ChuyenBay cb;
	NodeChuyenBay* next;
	//NodeChuyenBay();
	//~NodeChuyenBay();
};
typedef NodeChuyenBay* PTRChuyenBay;
void KhoiDauCB(PTRChuyenBay& fist);
PTRChuyenBay KhoiTaoCB();
void ThemDauCB(PTRChuyenBay& fist, NodeChuyenBay x);
void ThemSauCB(PTRChuyenBay p, NodeChuyenBay x);
PTRChuyenBay TimCB(PTRChuyenBay fist);
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