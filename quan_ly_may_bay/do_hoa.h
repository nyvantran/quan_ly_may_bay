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
void chayDoHoa(DSMayBay ds_may_bay, PTRChuyenBay dau_chuyen_bay, PTRKhachhang goc_khach_hang);
void DHThemMB(DSMayBay ds_may_bay, int*, int*);
int mouseThemMb(int x, int y);
void xoachu(char* n, int x, int y);
void hienDS(int* x, int* y);
void KetThuc();
void KhoiDong();



