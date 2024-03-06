#pragma once
#include<iostream>
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
int checkMouse2(int old, int x, int y);
void chayDoHoa(DSMayBay ds_may_bay, PTRChuyenBay dau_chuyen_bay, PTRKhachhang goc_khach_hang);
void KetThuc();
void KhoiDong();



