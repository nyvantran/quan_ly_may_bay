#pragma once
#define MAX_MB 300
///////////struct chuyen bay
struct Ve
{
	char cmnd[225];
	char vitri1[2];
	int vitri2;
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
	int giay;
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
	char san_bay_den[40];//hoi thay c[40] c[15]
	TrangThai trang_thai_cb;
	Ve* ds_ve;
	ChuyenBay();
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
//////////struct may bay
struct MayBay
{
	char sh_Mb[15];
	char loai_may_bay[40];
	int so_day, so_dong, so_cho;
};
typedef struct DSMayBay {
	int so_MB;
	MayBay* maybay[MAX_MB];
};
//////
/////struct khanh hang
//////