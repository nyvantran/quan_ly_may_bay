#pragma once
struct Ve
{
	char cmnd[225];
	char vitri1[2];
	int vitri2;
};
enum Trang_Thai {
	HUY_CHUYEN,
	CON_VE,
	HET_VE,
	HOAN_TAT,
};
struct NgayGio
{
	int gio;
	int ngay;
	int thang;
	int nam;
};
struct ChuyenBay
{
	char ma_cb[15];
	NgayGio ngay_gio_kh;
	char san_bay_den[40];//hoi thay c[40] c[15]
	Trang_Thai trang_thai_cb;
	Ve* ds_ve;
	ChuyenBay();
};