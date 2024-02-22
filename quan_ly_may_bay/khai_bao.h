#pragma once
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
struct Ds_Chuyen_Bay
{

};