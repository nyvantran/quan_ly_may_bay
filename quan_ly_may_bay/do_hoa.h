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
void chayDoHoa(DSMayBay& ds_may_bay, PTRChuyenBay dau_chuyen_bay, PTRKhachhang goc_khach_hang);
///=========================them may bay===========================================///
void DHThemMB(DSMayBay& ds_may_bay, int*, int*);
void DHxoaMB(DSMayBay& ds_may_bay, int* x, int* y, int* ii);
void DHhieuchinhMB(DSMayBay& ds_may_bay, int* x, int* y, int* ii, int& ki,int&hi);
void hienDSMb1(int* x, int* y, int* ii, DSMayBay& ds_may_bay);
void hienDSMb2(int* x, int* y, int* ii, int& ki, int& hi, DSMayBay& ds_may_bay);
int mouseThemMb(int x, int y);
int mouseXoaMb(int x, int y);
int mouseHieuChinhMb(int x, int y, int old);
///===========================them chuyen bay=======================================///
void DHThemCB(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int*, int*);
int mouseThemCB(int x, int y);
void DHHuyChuyen(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int*, int*,int*);
void hienDSCB1(int* x, int* y, int* ii, PTRChuyenBay& dau_chuyen_bay);
int mouseHuyCB(int x, int y);
///=================================================================================///
void xoachu(char* n, int x, int y);
void KetThuc();
void KhoiDong();



