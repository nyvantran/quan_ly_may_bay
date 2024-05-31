#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include <cstdlib>
#include <time.h>
#define MAX_MB 300
#define DLMAYBAY "dlmaybay.dat"
#define DLCHUYENBAY "dlchuyenbay.dat"
#define DLKHACHHANG "dlkhachhang.dat"
//////////struct may bay
struct MayBay
{
	char sh_Mb[15]{};
	char loai_may_bay[40]{};
	int so_day, so_dong;
};
struct DSMayBay {
	int so_MB = 0;
	MayBay* maybay[MAX_MB]{};
	/*function*/;
	void napFile(const char file[]) ;
	void ghiFile(const char file[]) const;
	void xoa();
};
//========thao tac voi danh sach may bay=====
void ThemMayBay(MayBay, DSMayBay&);
void HieuChinhMB(DSMayBay& DSMayBay ,MayBay* maybay, char sohieu[], char loai[], int soday, int sodong);
void XoaMayBay(DSMayBay& , char[]);
MayBay *TimSoHieu(char[], DSMayBay);
//////
///////////struct chuyen bay
struct Ve
{
	char cmnd[13]{};
	char vitri[5]{};
	void DatVe(char cmnd[], char vt[]);
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
	bool checkNgayGio() const;
};
double truNgayGio(NgayGio x, NgayGio y);
struct ChuyenBay
{
	char ma_cb[15]{};
	NgayGio ngay_gio_kh;
	char san_bay_den[100]{};
	char sh_Mb[15]{};
	TrangThai trang_thai_cb;
	int so_ve = 0;
	Ve* ds_ve = NULL;
	void datChuyenBay(char macb[], NgayGio ngay, char sanbay[], char somb[], TrangThai trangthai, DSMayBay ds);
	Ve* timVe(char cmnd[]) const;
	bool huyVe(char cmnd[]);
	////
	void DatVe(char cmnd[], char vtd[]);
	Ve* timVe1(char vtd[]);
	//ChuyenBay();
};
struct NodeChuyenBay
{
	ChuyenBay cb;
	NodeChuyenBay* next = NULL;
	void capnhap(DSMayBay ds);
	void capNhapVe(DSMayBay ds, char shmb[], char shmbcu[], bool);
};
typedef NodeChuyenBay* PTRChuyenBay;
///chuyen bay function 
void napFileChuyenBay(const char file[], PTRChuyenBay& fist, DSMayBay ds);
void ghiFileChuyenBay(const char file[], PTRChuyenBay fist, DSMayBay ds);
bool themChuyenBay(PTRChuyenBay&, ChuyenBay);
void xoahetChuyenBay(PTRChuyenBay&);
bool xoaChuyenBay(PTRChuyenBay&, PTRChuyenBay);
/*xoa nodechuyenbay*/
bool xoadauNodeChuyenBay(PTRChuyenBay& fist);
bool xoasauNodeChuyenBay(PTRChuyenBay p);
//////////////
PTRChuyenBay timChuyenBay(PTRChuyenBay fist, char x[]);
int timCBtheoSHMB(PTRChuyenBay fist, char x[], int& m);
void chinhsuaChuyenBay(PTRChuyenBay& p, NgayGio time, char sbd[], char shmb[]);
/*void KhoiDauCB(PTRChuyenBay& fist);*/
PTRChuyenBay KhoiTaoCB();
void ThemDauCB(PTRChuyenBay& fist, ChuyenBay x);
void ThemSauCB(PTRChuyenBay p, ChuyenBay x);
TrangThai capNhapTT(NgayGio);
///////////
/////struct khanh hang
struct KhachHang
{
	char cmnd[13]{};
	char ho[40]{};
	char ten[10]{};
	bool phai = 0;
	void datKhachHang(char cmnd[], char ho[], char ten[], bool phai);
};
struct NodeKhachHang
{
	KhachHang info;
	int bf=0;
	NodeKhachHang* left = NULL, * right = NULL;
};
typedef NodeKhachHang* PTRKhachhang;
/*function khach hang*/
void napFileKhachHang(PTRKhachhang& goc, const char file[]);
void ghiFileKhangHang(PTRKhachhang goc, const char file[]);
PTRKhachhang latTraiKhachHang(PTRKhachhang goc);
PTRKhachhang latPhaiKhachHang(PTRKhachhang goc);
void duyetLNR(PTRKhachhang);
void xoaHetKhachHang(PTRKhachhang& goc);
PTRKhachhang timKhachHang(PTRKhachhang goc, char[]);
void themKhachHang(PTRKhachhang&, KhachHang);
//////////////////////////////////////////////////////////
//////cccd sinh ngau nhien
void CCCDNN(char cccd[10]);
//ve sinh theo so day va so dong 
void SapVe(char[], int, int );
//chuan hoa ngay
void SuaNgay(Ngay&);
// chuan hoa ten
void SuaTen(char[]);
// nguoc ve
void SapVeNguoc(char[], int&, int&);
// so sanh ngay thang
int SSNgayThang(NgayGio t1, NgayGio t2);
//check ngay gio
bool checkNgayGio(NgayGio t1, NgayGio t2);
//  in chuyen bay hoan tat
void demChuyenBayHT(PTRChuyenBay);
// Bublesort
void Bublesort(PTRChuyenBay, DSMayBay&);
