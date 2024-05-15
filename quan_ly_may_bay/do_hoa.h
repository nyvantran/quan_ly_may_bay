#pragma once
#include<iostream>
#include<cctype>
#include<thread>
#include<Windows.h>
#include"khai_bao.h"
#include"graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
void* Menu();
void* nhanhMenu1();
void* nhanhMenu2();
void mouse(int *x, int *y);
int checkMouse1(int old, int x, int y);
int checkMouse21(int x, int y);
int checkMouse22(int x, int y);
void chayDoHoa(DSMayBay& ds_may_bay, PTRChuyenBay& dau_chuyen_bay, PTRKhachhang& goc_khach_hang);
///=========================them may bay===========================================///
void DHThemMB(DSMayBay& ds_may_bay, int* x, int* y, int* ii);
void DHxoaMB(DSMayBay& ds_may_bay, PTRChuyenBay fist, int* x, int* y, int* ii, char* loc, int& cd);
void DHhieuchinhMB(DSMayBay& ds_may_bay, MayBay*& ht, PTRChuyenBay& fist, int* x, int* y, int* ii, char* loc);
void hienDSMb0(int* x, int* y, int* ii, DSMayBay& ds_may_bay);
void hienDSMb1(int* x, int* y, int* ii, DSMayBay& ds_may_bay, char* loc, int& cd);
void hienDSMb2(int* x, int* y, int* ii, MayBay*& ht, DSMayBay& ds_may_bay, char* loc);
int mouseThemMb(int x, int y);
int mouseXoaMb(int x, int y);
int mouseHieuChinhMb(int x, int y, int old);
int mouseLocHieuChinhMB(int x, int y);
int mouseLocXoaMB(int x, int y);
///===========================them chuyen bay=======================================///
void DHThemCB(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int*, int*, int* ii, int* ip);
void hienDSCB0(int* x, int* y, int* ii, int* ip, PTRChuyenBay& dau_chuyen_bay, DSMayBay ds_may_bay);
int mouseThemCB(int x, int y);
void DHHuyChuyen(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int*, int*,int*);
void hienDSCB1(int* x, int* y, int* ii, PTRChuyenBay& dau_chuyen_bay,DSMayBay& ds_may_bay);
int mouseHuyCB(int x, int y);
void DHHieuChinhCB(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay& ht, DSMayBay ds_may_bay, int* x, int* y, int* ii, char* loc);
void hienDSCB2(int* x, int* y, int* ii, PTRChuyenBay& ht, PTRChuyenBay& dau_chuyen_bay, DSMayBay ds_may_bay, char* loc);
int mouseHieuChinhCB(int old, int x, int y);
int mouseLocHieuChinhCB(int x, int y);
///===========================khach hang==============================================///
void DHdatVe(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y);
void chonChuyenBay(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay& ht, int* x, int* y, int* ii, int option, PTRChuyenBay chay[],int &cd);
void hienDSCB3(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int* x, int* y, int* ii, int option, PTRChuyenBay chay[],int &cd);
int mouseChonCB(int x, int y);
int mouseDatVe(int x, int y);
void DHhuyVe(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y);
void DHInVeCb(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y);
void hienDSCB4(int* x, int* y, PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay);
int mouseHienDSCB(int x, int y);
///===================================================================================///
void xoachu(char* n, int x, int y);
void KhoiDong();
void KetThuc();
void dongho(int xi, int yi, int* x, int* y);
//==================================================================================
void xuatSoCBHT(int*,int*,PTRChuyenBay,DSMayBay);