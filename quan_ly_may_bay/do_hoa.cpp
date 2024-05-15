#include"do_hoa.h"
#include<thread>
void* Menu()
{
	void* q = malloc(imagesize(0, 0, getmaxx(), getmaxy()));
	//line(getmaxx() / 2 - 300, 0, getmaxx() / 2 - 300, getmaxy());
	setfillstyle(1, 4);
	bar(getmaxx() - 50, 0, getmaxx(), 50);
	settextstyle(9, HORIZ_DIR, 11);
	setfillstyle(1, 1);
	setbkcolor(1);
	int xg = 10, yg = 50;
	bar(xg, yg, xg + 225, yg + 70);
	rectangle(xg, yg, xg + 225, yg + 70);
	void* p = malloc(imagesize(xg, yg, xg + 225, yg + 70));
	getimage(xg, yg, xg + 225, yg + 70, p);
	for (int i = 0; i <= 7; i++) {
		putimage(xg, yg + 70 * i + 18 * i, p, COPY_PUT);
	}
	free(p);
	char a[8][225]{};
	strcpy_s(a[0], 225, "Cap nhap ds may bay");
	strcpy_s(a[1], 225, "Cap nhap chuyen bay");
	strcpy_s(a[2], 225, "Dat ve may bay");
	strcpy_s(a[3], 225, "Huy ve");
	strcpy_s(a[4], 225, "In DS ve cua chuyen bay");
	strcpy_s(a[5], 225, "In DS chuyen bay theo ngay");
	strcpy_s(a[6], 225, "DS ve trong cua chuyen bay");
	strcpy_s(a[7], 225, "TK so lan bay cua may bay");
	for (int i = 0; i < 8; i++) {
		outtextxy(xg + 112 - textwidth(a[i]) / 2, yg + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	getimage(0, 0, getmaxx(), getmaxy(), q);
	putimage(0, 0, q, XOR_PUT);
	setbkcolor(0);
	return q;
}

void* nhanhMenu1()
{
	settextstyle(9, HORIZ_DIR, 11);
	setfillstyle(1, 1);
	setbkcolor(1);
	char a[3][225]{};
	strcpy_s(a[0], 225, "Them MB");
	strcpy_s(a[1], 225, "Xoa MB");
	strcpy_s(a[2], 225, "Hieu Chinh MB");
	int x = 555, y = 50;
	bar(x, y, x + 130, y + 70);
	rectangle(x, y, x + 130, y + 70);
	void* p = malloc(imagesize(x, y, x + 130, y + 70));
	getimage(x, y, x + 130, y + 70, p);
	for (int i = 0; i < 3; i++) {
		//line(x - 50, y + 35, x, y + (70 + 18) * i + 35);
		putpixel(x - 50, y + 35, 7);
		putimage(x, y + (70 + 18) * i, p, COPY_PUT);
		outtextxy(x + 65 - textwidth(a[i]) / 2, y + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	free(p);
	void* q = malloc(imagesize(x - 50, y, x + 130, y + (70 + 18) * 2 + 70));
	getimage(x - 50, y, x + 130, y + (70 + 18) * 2 + 70, q);
	putimage(x - 50, y, q, 1);
	return q;
}

void* nhanhMenu2()
{
	settextstyle(9, HORIZ_DIR, 11);
	setfillstyle(1, 1);
	setbkcolor(1);
	char a[3][225]{};
	strcpy_s(a[0], 225, "Them CB");
	strcpy_s(a[1], 225, "Huy CB");
	strcpy_s(a[2], 225, "Hieu Chinh CB");
	int x = 555, y = 50;
	bar(x, y, x + 130, y + 70);
	rectangle(x, y, x + 130, y + 70);
	void* p = malloc(imagesize(x, y, x + 130, y + 70));
	getimage(x, y, x + 130, y + 70, p);
	for (int i = 0; i < 3; i++) {
		//line(x - 50, y + 35, x, y + (70 + 18) * i + 35);
		putpixel(x - 50, y + 35, 7);
		putimage(x, y + (70 + 18) * i, p, COPY_PUT);
		outtextxy(x + 65 - textwidth(a[i]) / 2, y + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	void* q = malloc(imagesize(x - 50, y, x + 130, y + (70 + 18) * 2 + 70));
	getimage(x - 50, y, x + 130, y + (70 + 18) * 2 + 70, q);
	putimage(x - 50, y, q, 1);
	return q;
}
/*======================mouse=====================*/
int checkMouse1(int old, int x, int y)
{
	int xg = 10, yg = 50;
	if ((x > xg) && (x < xg + 225)) {
		int n = (y - yg) / 88;
		if ((88 * n + 50 < y) && (88 * n + 50 + 70)) {
			return n;
		}
	}
	return old;
}

int checkMouse21(int x, int y)
{
	int xg = 0, yg = 50;
	int n = (y - yg) / 88;
	if ((xg + 240 + 50 <= x) && (x <= xg + 240 + 50 + 120)) {
		if ((yg + 88 * n <= y) && (y <= yg + 88 * n + 70)) {
			return n;
		}
	}
	return -1;
}

int checkMouse22(int x, int y)
{
	int xg = 0, yg = 138;
	int n = (y - yg) / 88;
	if ((xg + 240 + 50 <= x) && (x <= xg + 240 + 50 + 120)) {
		if ((yg + 88 * n <= y) && (y <= yg + 88 * n + 70)) {
			return n;
		}
	}
	return -1;
}

void mouse(int* x, int* y)
{
	int xg = 55, yg = 50, i = 0;
	char tb[220]{ "NHAN PHIM BAT KY DE THOAT" };
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN) == 1) {
			getmouseclick(WM_LBUTTONDOWN, *x, *y);
		}
		if ((*x >= getmaxx() - 50) && (*y >= 0) && (*x <= getmaxx()) && (*y <= 50)) {
			*x = -10;
			*y = -10;
			//closegraph();
			setfillstyle(1, 8);
			setbkcolor(8);
			Sleep(100);
			bar(getmaxx() / 2 -150 ,getmaxy() / 2 - 50, getmaxx() / 2 + 150, getmaxy() / 2 + 50);
			outtextxy(getmaxx() / 2 - textwidth(tb) / 2, getmaxy() / 2 - textheight(tb) / 2, tb);
			return;
		}
	}
}
///===================================================================================
void chayDoHoa(DSMayBay& ds_may_bay, PTRChuyenBay& dau_chuyen_bay, PTRKhachhang& goc_khach_hang)
{
	int xg = 0, yg = 50;
	void* p1 = Menu();
	void* p2 = nhanhMenu1();
	void* p3 = nhanhMenu2();
	putimage(0, 0, p1, 0);
	int x = 0, y = 0;
	int n = -1, tam;
	char noi[100]{};
	MayBay tam1{};
	thread nhanh1(mouse, &x, &y);
	while (1) {
		tam = n;
		n = checkMouse1(n, x, y);
		switch (n)
		{
		case 0: {
			if (n != tam) {
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				putimage(xg + 240, yg + 88 * n, p2, 0);
			}
			switch (checkMouse21(x,y))
			{
			case 0: {
				int ii = 0;
				MayBay* ht = NULL;
				thread nhanh(DHThemMB, ref(ds_may_bay), &x, &y, &ii);
				hienDSMb0(&x, &y, &ii, ds_may_bay);
				nhanh.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			case 1: {
				int ii = 0, cd = ds_may_bay.so_MB;
				thread nhanh1(DHxoaMB, ref(ds_may_bay), dau_chuyen_bay, &x, &y, &ii, noi, ref(cd));
				hienDSMb1(&x, &y, &ii, ds_may_bay, noi, ref(cd));
				nhanh1.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			case 2: {
				int ii = 0;
				MayBay* ht = NULL;
				thread nhanh1(DHhieuchinhMB, ref(ds_may_bay), ref(ht), ref(dau_chuyen_bay), &x, &y, &ii, noi);
				hienDSMb2(&x, &y, &ii, ht, ds_may_bay, noi);
				nhanh1.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 1: {
			if (n != tam) {
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
				putimage(xg + 240, yg + 88 * n, p3, 0);				
			}
			switch (checkMouse22(x,y))
			{
			case 0: {
				int ii = 0, ip = 0;
				thread nhanh(DHThemCB, ref(dau_chuyen_bay), ref(ds_may_bay), &x, &y, &ii, &ip);
				hienDSCB0(&x, &y, &ii, &ip, dau_chuyen_bay, ds_may_bay);
				nhanh.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			case 1: {
				int ii = 0;
				thread nhanh1(hienDSCB1, &x, &y, &ii, ref(dau_chuyen_bay),ref(ds_may_bay));
				DHHuyChuyen(dau_chuyen_bay, ds_may_bay, &x, &y,&ii);
				nhanh1.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			case 2: {
				int ii = 0;
				PTRChuyenBay ht = NULL;
				thread nhanh2(DHHieuChinhCB, ref(dau_chuyen_bay), ref(ht), ref(ds_may_bay), &x, &y, &ii, noi);
				hienDSCB2(&x, &y, &ii, ht, dau_chuyen_bay, ds_may_bay,noi);
				nhanh2.join();
				ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay, ds_may_bay);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2: {
			if (n != tam) {
				//settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			DHdatVe(dau_chuyen_bay, ds_may_bay, goc_khach_hang, &x, &y);
			ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay,ds_may_bay);
			ghiFileKhangHang(goc_khach_hang, DLKHACHHANG);
			n = -1;
			break;
		}
		case 3: 
		{
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			DHhuyVe(dau_chuyen_bay, ds_may_bay, goc_khach_hang, &x, &y);
			ghiFileChuyenBay(DLCHUYENBAY, dau_chuyen_bay,ds_may_bay);
			n = -1;
			break;
		}
		case 4: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			DHInVeCb(dau_chuyen_bay, ds_may_bay, goc_khach_hang, &x, &y);
			n = -1;
			break;
		}
		case 5: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			hienDSCB4(&x, &y, dau_chuyen_bay, ds_may_bay);
			n = -1;
			break;
		}
		case 6: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			thread nhanh6(locVeMB,&x,&y,dau_chuyen_bay,ds_may_bay);
			xuatSoVeTrong(&x, &y, dau_chuyen_bay, ds_may_bay);
			nhanh6.join();
			n = -1;
			break;
		}
		case 7: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}			
			xuatSoCBHT(&x,&y,dau_chuyen_bay,ds_may_bay);
			n = -1;
			break;
		}
		default:
			break;
		}
		if (x == -10 && y == -10) {
			break;
		}
	}
	nhanh1.join();
	free(p1);
	free(p2);
	free(p3);
}

void DHThemMB(DSMayBay& ds_may_bay, int* x, int* y, int* ii)
{
	int xg = 50, yg = 10;
	char text[4][40]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	void* p1 = malloc(imagesize(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200));
	rectangle(xg + getmaxx() / 2 - 320, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200);
	setbkcolor(0);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30, text[0]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 30 - textheight(text[0]) / 2,
		xg+textwidth(text[0]) + getmaxx() / 2, yg + 45 + 30 + 40 - textheight(text[0]) / 2);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30 + 50, text[1]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 80 - textheight(text[1]) / 2,
		xg+textwidth(text[0]) + getmaxx() / 2 + 300, yg + 45 + 80 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30 + 100, text[2]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 130 - textheight(text[1]) / 2,
		xg+textwidth(text[0]) + getmaxx() / 2 - 250, yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 + 150 - 310, yg + 45 + 30 + 100, text[3]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 310, yg + 45 + 130 - textheight(text[1]) / 2,
		xg+textwidth(text[0]) + getmaxx() / 2 + 100 + 60 + textwidth(text[3]) - 250, yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 130 - textheight(text[1]) / 2 + 50,
		const_cast<char*>("nhap esc de thoat       nhap enter de xac nhan"));
	
	char nhap;
	char shmb[15]{}, lmb[40]{}, soday[3]{}, sodong[3]{}; 
	/*shmb[0] = '\0'; lmb[0] = '\0'; soday[0] = '\0'; sodong[0] = '\0';*/
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0;
	setbkcolor(1);
	while (1) {
		if (((int)(nhap = getch()) != 13) && ((int)nhap != 27) && (int)nhap != 0) {
			if (mouseThemMb(*x, *y) == 0) {
				if (i0 < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					shmb[i0 + 1] = shmb[i0];
					shmb[i0] = nhap; i0++;
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
					
				}
				if ((int)nhap == 8) {
					xoachu(shmb, xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10);
					if (i0 > 0) {
						shmb[i0 - 1] = shmb[i0--];
					}
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
				}
			}
			if ( mouseThemMb(*x, *y) == 1) {
				if (i1 < 40-1) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					lmb[i1 + 1] = lmb[i1];
					lmb[i1] = nhap; i1++;
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 -300, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
				if ((int)nhap == 8) {
					xoachu(lmb, xg+textwidth(text[0]) + getmaxx() / 2 -300, yg + 45 + 80 - textheight(text[1]) / 2 + 10);
					if (i1 > 0) {
						lmb[i1 - 1] = lmb[i1--];
					}
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
			}
			if (mouseThemMb(*x, *y) == 2) {
				if (i2 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					soday[i2 + 1] = soday[i2];
					soday[i2] = nhap; i2++;
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
				if ((int)nhap == 8) {
					xoachu(soday,xg+ textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i2 > 0) {
						soday[i2 - 1] = soday[i2--];
					}
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
			}
			if (mouseThemMb(*x, *y) == 3) {
				if (i3 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					sodong[i3 + 1] = sodong[i3];
					sodong[i3] = nhap; i3++;
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) -300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
				if ((int)nhap == 8) {
					xoachu(sodong,xg+ textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) -300, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i3 > 0) {
						sodong[i3 - 1] = sodong[i3--];
					}
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) -300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
			}
		}
		if ((int)nhap == 13) {
			if ((shmb[0] == '\0') || (lmb[0] == '\0')
				|| (soday[0] == '\0') || (sodong[0] == '\0'))
			{
				int mt = getbkcolor();
				setbkcolor(0);
				outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 50, yg + 45 + 90 - textheight(text[1]) / 2 + 90,
					const_cast<char*>("khong de thong tin trong, NHAN PHIM BAT KY DE TIEP TUC"));
				getch();
				xoachu(const_cast<char*>("khong de thong tin trong, NHAN PHIM BAT KY DE TIEP TUC"),
					xg + textwidth(text[0]) + getmaxx() / 2 + 50, yg + 45 + 90 - textheight(text[1]) / 2 + 90);
				setbkcolor(mt);
			}
			else {
				if (atoi(soday) * atoi(sodong) < 20) {
					int mt = getbkcolor();
					setbkcolor(0);
					outtextxy(xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90,
						const_cast<char*>("( so day * so dong >= 20 ), NHAN PHIM BAT KY DE TIEP TUC"));
					getch();
					xoachu(const_cast<char*>("( so day * so dong >= 20 ), NHAN PHIM BAT KY DE TIEP TUC"),
						xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90);
					setbkcolor(mt);
				}
				else
					if (TimSoHieu(shmb, ds_may_bay) == NULL) {
						MayBay tam{};
						strcpy_s(tam.sh_Mb, 15, shmb);
						strcpy_s(tam.loai_may_bay, 40, lmb);
						tam.so_day = atoi(soday);
						tam.so_dong = atoi(sodong);
						ThemMayBay(tam, ds_may_bay);
						int mt = getbkcolor();
						setbkcolor(0);
						outtextxy(xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90,
							const_cast<char*>("Da them may bay, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("Da them may bay, NHAN PHIM BAT KY DE TIEP TUC"),
							xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90);
						setbkcolor(mt);
						/*getimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
						putimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
						free(p1);
						*x = -1; *y = -1;
						break;*/
					}
					else {
						int mt = getbkcolor();
						setbkcolor(0);
						outtextxy(xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90,
							const_cast<char*>("so hieu may bay da trung, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("so hieu may bay da trung, NHAN PHIM BAT KY DE TIEP TUC"),
							xg + textwidth(text[0]) + 50 + getmaxx() / 2, yg + 45 + 90 - textheight(text[1]) / 2 + 90);
						setbkcolor(mt);
					}
			}
		}
		else if ((int)nhap == 27 || (*x == -10 && *y == -10)) {
			getimage(xg+getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
			putimage(xg+getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
			free(p1);
			if (*x == -10 && *y == -10) {}
			else {
				*x = -1; *y = -1;
			}			
			return;
		}
		else if ((int)nhap == 0) {
			nhap = getch();
			int k;
			if ((int)nhap == 77) {
				if (*ii * 10 - ds_may_bay.so_MB < 0) {
					k = *ii;
					k++;
					*ii = k;
				}
			}
			if ((int)nhap == 75) {
				if (*ii > 0) {
					k = *ii;
					k--;
					*ii = k;
				}
			}
		}
	}
}
///==============================xoa chu============================================///
void xoachu(char* n, int x, int y) {
	/*int tam = getcolor();
	setcolor(getbkcolor());
	outtextxy(x, y, n);
	setcolor(tam);*/
	fillsettingstype tam{};
	getfillsettings(&tam);
	int t1 = tam.color;
	setfillstyle(1, getbkcolor());
	bar(x, y, x + textwidth(n), y + textheight(n));
	setfillstyle(1, t1);
}
void hienDSMb1(int* x, int* y, int* ii, DSMayBay& ds_may_bay, char* loc, int& cd)
{
	Sleep(50);
	int xg = 460, yg = 100;
	char text[6][225]{};
	void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
	/*============================================================*/
	strcpy_s(text[0], 40, " so hieu may bay: ");
	strcpy_s(text[1], 40, " loai may bay: ");
	strcpy_s(text[2], 40, " so day: ");
	strcpy_s(text[3], 40, " so dong: ");
	strcpy_s(text[4], 40, " Loc so hieu may bay: ");
	setfillstyle(1, 1);
	char tam[25]{};
	char nhap;
	int n = 0, k = 0, i0 = 0;
	bar(xg + 400, yg - 75, xg + 400 + 150 + 315, yg - 75 + 30);
	rectangle(xg + 400, yg - 75, xg + 400 + 150 + 315, yg - 75 + 30);
	outtextxy(xg + 405, yg - 70, text[4]);
	bar(xg + 870, yg - 75, xg + 870 + 30, yg - 75 + 30);
	outtextxy(xg + 875, yg - 70, const_cast<char*>("loc"));
	while (1) {		
		if ((int)(nhap = getch()) == 0 &&
			(mouseXoaMb(*x, *y) < 0 || (mouseXoaMb(*x, *y) >= 0 && *ii * 10 + mouseXoaMb(*x, *y) < ds_may_bay.so_MB))) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii * 10 - ds_may_bay.so_MB < 0) {
					k = *ii;
					k++;
					*ii = k;
					//bar(xg, yg, getmaxx(), getmaxy());
				}
			}
			if ((int)nhap == 75) {
				if (*ii > 0) {
					k = *ii;
					k--;
					*ii = k;
					/*bar(xg, yg, getmaxx(), getmaxy());*/
				}
			}
		}
		if ((int)nhap != 0 && (int)nhap != 13 && (int)nhap != 27) {
			if (mouseLocXoaMB(*x, *y) == 1) {
				if (i0 < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					loc[i0 + 1] = loc[i0];
					loc[i0] = nhap; i0++;
					outtextxy(xg + 560, yg - 70, loc);
				}
				if ((int)nhap == 8) {
					xoachu(loc, xg + 560, yg - 70);
					if (i0 > 0) {
						loc[i0 - 1] = loc[i0--];
					}
					outtextxy(xg + 560, yg - 70, loc);
				}
			}
		}
		if ((int)nhap == 27) {
			*x = -1;
			*y = -1;
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
		if (*x == -10 && *y == -10) {
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}
}
void hienDSMb2(int* x, int* y, int* ii, MayBay*& ht, DSMayBay& ds_may_bay, char* loc)
{
	Sleep(50);
	int xg = 460, yg = 275;
	char text[6][225]{};
	void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
	/*============================================================*/
	strcpy_s(text[0], 40, " so hieu may bay: ");
	strcpy_s(text[1], 40, " loai may bay: ");
	strcpy_s(text[2], 40, " so day: ");
	strcpy_s(text[3], 40, " so dong: ");
	setfillstyle(1, 1);
	char tam[25];
	int n = -1, cd;
	int old = -1;
	MayBay* hto = NULL;
	MayBay* hienthi[MAX_MB]{};
	for (int i = 0; i < ds_may_bay.so_MB; i++) {
		hienthi[i] = ds_may_bay.maybay[i];
	}
	cd = ds_may_bay.so_MB;
	while (1) {
		if (old != mouseHieuChinhMb(*x, *y, old) && *ii * 7 + mouseHieuChinhMb(*x, *y, old) < cd && mouseHieuChinhMb(*x, *y, old) >= 0) {
			old = mouseHieuChinhMb(*x, *y, old);
			if (0 <= *ii * 6 + old && *ii * 6 + old < cd)
			ht = hienthi[*ii * 7 + old];
			if (hto != ht) {
				bar(609 + 491, 225, 609 + 491 + 300, 225 + 25);
				bar(609, 75, 919, 115);
				bar(609, 125, 1219, 165);
				bar(609, 175, 669, 215);
				bar(823, 175, 893, 215);
				outtextxy(609 + 491, 225, ht->sh_Mb);
				outtextxy(619, 85, ht->sh_Mb);
				outtextxy(619, 135, ht->loai_may_bay);
				_itoa_s(ht->so_day, tam, 3, 10);
				outtextxy(619, 185, tam);
				_itoa_s(ht->so_dong, tam, 3, 10);
				outtextxy(833, 185, tam);
				hto = ht;
			}
		}
		if (n != *ii ) {
			*x = 0; *y = 0;
			old = -1;
			bar(xg, yg, getmaxx(), getmaxy());
			for (int i = 0; i < 7; i++) {
				if (*ii * 7 + i < cd) {
					setbkcolor(1);
					outtextxy(xg + 10, yg + 5 + 60 * i, text[0]);
					outtextxy(xg + 10 + textwidth(text[0]), yg + 5 + 60 * i, hienthi[*ii * 7 + i]->sh_Mb);
					outtextxy(xg + 235 + textwidth(text[0]), yg + 5 + 60 * i, text[1]);
					outtextxy(xg + 235 + textwidth(text[0]) + textwidth(text[1]), yg + 5 + 60 * i, hienthi[*ii * 7 + i]->loai_may_bay);
					_itoa_s(hienthi[*ii * 7 + i]->so_day, tam, 10);
					outtextxy(xg + 10, yg + 30 + 60 * i, text[2]);
					outtextxy(xg + 10 + textwidth(text[2]), yg + 30 + 60 * i, tam);
					_itoa_s(hienthi[*ii * 7 + i]->so_dong, tam, 10);
					outtextxy(xg + 210 + textwidth(text[2]), yg + 30 + 60 * i, text[3]);
					outtextxy(xg + 210 + textwidth(text[2]) + textwidth(text[3]), yg + 30 + 60 * i, tam);
					outtextxy(xg + 350 + textwidth(text[2]), yg + 30 + 60 * i, const_cast<char*>("hieuchinh"));
					rectangle(xg + 345 + textwidth(text[2]), yg + 30 + 60 * i,
						xg + 380 + textwidth(text[2]) + 50, yg + 50 + 60 * i);
				}
				n = *ii;
			}
			_itoa_s(*ii + 1, tam, 10);
			outtextxy(xg, getmaxy() - 60, tam);
			outtextxy(xg, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		if (mouseLocHieuChinhMB(*x, *y) == 2) {
			cd = 0;
			for (int i = 0; i < ds_may_bay.so_MB; i++) {
				if (strncmp(ds_may_bay.maybay[i]->sh_Mb, loc, strlen(loc))==0) {
					hienthi[cd++] = ds_may_bay.maybay[i];
				}
			}
			n = -1;
		}
		if ((*x == -2 && *y == -2) || (*x == -10 && *y == -10)) {
			void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}
}
void DHxoaMB(DSMayBay& ds_may_bay, PTRChuyenBay fist, int* x, int* y, int* ii, char* loc, int& cd)
{
	int xg = 460, yg = 20;
	char text[11][100]{};
	settextstyle(3, HORIZ_DIR, 1);
	strcpy_s(text[0], 25, "you co xac nhan xoa ko ");
	strcpy_s(text[1], 25, "xac nhan");
	strcpy_s(text[2], 25, "ko");
	strcpy_s(text[3], 40, " so hieu may bay: ");
	strcpy_s(text[4], 40, " loai may bay: ");
	strcpy_s(text[5], 40, " so day: ");
	strcpy_s(text[6], 40, " so dong: ");
	void* p = malloc(imagesize(xg, yg, xg + 900, yg + 60));
	setbkcolor(1);
	int n, t1, t2, io = -1;
	char tam[100]{};
	setbkcolor(1);
	while (1) {
		if (io != *ii) {
			bar(xg, yg + 80, getmaxx(), getmaxy());
			for (int i = 0; i < 10; i++) {
				if (*ii * 10 + i < ds_may_bay.so_MB) {
					outtextxy(xg + 10, yg + 5 + 80 + 60 * i, text[3]);
					outtextxy(xg + 10 + textwidth(text[3]), yg + 5 + 80 + 60 * i, ds_may_bay.maybay[*ii * 10 + i]->sh_Mb);
					outtextxy(xg + 235 + textwidth(text[3]), yg + 5 + 80 + 60 * i, text[4]);
					outtextxy(xg + 235 + textwidth(text[3]) + textwidth(text[4]), yg + 5 + 80 + 60 * i, ds_may_bay.maybay[*ii * 10 + i]->loai_may_bay);
					_itoa_s(ds_may_bay.maybay[*ii * 10 + i]->so_day, tam, 10);
					outtextxy(xg + 10, yg + 30 + 80 + 60 * i, text[5]);
					outtextxy(xg + 10 + textwidth(text[5]), yg + 30 + 80 + 60 * i, tam);
					_itoa_s(ds_may_bay.maybay[*ii * 10 + i]->so_dong, tam, 10);
					outtextxy(xg + 210 + textwidth(text[5]), yg + 30 + 80 + 60 * i, text[6]);
					outtextxy(xg + 210 + textwidth(text[5]) + textwidth(text[6]), yg + 30 + 80 + 60 * i, tam);
					outtextxy(xg + 350 + textwidth(text[5]), yg + 30 + 80 + 60 * i, const_cast<char*>("xoa"));
					rectangle(xg + 345 + textwidth(text[5]), yg + 30 + 80 + 60 * i,
						xg + 380 + textwidth(text[5]), yg + 50 + 80 + 60 * i);
				}
			}
			io = *ii;
			_itoa_s(*ii + 1, tam, 10);
			outtextxy(xg + 10, getmaxy() - 60, tam);
			outtextxy(xg + 10, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		n = mouseXoaMb(*x, *y);
		if (*ii * 10 + n < ds_may_bay.so_MB) {
			if (n >= 0 && (timCBtheoSHMB(fist, ds_may_bay.maybay[*ii * 10 + n]->sh_Mb, t2) != 0)) {
				/*outtextxy(xg + 25, yg - textheight(text[0]) / 2 + 25, ds_may_bay.maybay[n + *ii * 10]->sh_Mb);
				outtextxy(xg + 25, yg + 25 - textheight(text[0]) / 2 + 25, const_cast<char*>("da su dung"));
				Sleep(1500);
				*x = 0; *y = 0;
				getimage(xg, yg, xg + 400, yg + 60, p);
				putimage(xg, yg, p, 1);*/
			}else
			if (n >= 0 && (timCBtheoSHMB(fist, ds_may_bay.maybay[*ii * 10 + n]->sh_Mb, t2) == 0)) {
				bar(xg, yg, xg + 400, yg + 60);
				outtextxy(xg + 5, yg + 25 - textheight(text[0]) / 2, text[0]);
				outtextxy(xg + 25, yg + 25 - textheight(text[0]) / 2 + 25, ds_may_bay.maybay[n + *ii * 10]->sh_Mb);
				outtextxy(xg + 50 + textwidth(text[0]), yg + 25 - textheight(text[0]) / 2, text[1]);
				rectangle(xg + 45 + textwidth(text[0]), yg + 25 - textheight(text[0]) / 2,
					xg + 45 + textwidth(text[0]) + 75, yg + 25 - textheight(text[0]) / 2 + 20);
				outtextxy(xg + 100 + textwidth(text[0]) + textwidth(text[1]), yg + 25 - textheight(text[0]) / 2, text[2]);
				rectangle(xg + 95 + textwidth(text[0]) + textwidth(text[1]), yg + 25 - textheight(text[0]) / 2,
					xg + 95 + textwidth(text[0]) + textwidth(text[1]) + 70, yg + 25 - textheight(text[0]) / 2 + 20);
				///==========================///
				while (1) {
					if (mouseXoaMb(*x, *y) == -1) {
						t1 = *ii;
						if (timCBtheoSHMB(fist, ds_may_bay.maybay[t1 * 10 + n]->sh_Mb, t2) == 0) {
							*x = 0;
							*y = 0;
							strcpy_s(text[3], 41, ds_may_bay.maybay[t1 * 10 + n]->sh_Mb);
							XoaMayBay(ds_may_bay, text[3]);
						}
						getimage(xg, yg, xg + 450, yg + 60, p);
						putimage(xg, yg, p, 1);
						break;

					}
					else if (mouseXoaMb(*x, *y) == -2) {
						getimage(xg, yg, xg + 400, yg + 60, p);
						putimage(xg, yg, p, 1);
						break;
					}
					if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
						getimage(xg, yg, xg + 900, yg + 60, p);
						putimage(xg, yg, p, 1);
						break;
					}
					if (*x == -1 && *y == -1) {
						break;
					}
				}
			}
			
			
			
		}		
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg, yg, xg + 900, yg + 60, p);
			putimage(xg, yg, p, 1);
			break;
		}
		
	}
	free(p);
}
void DHhieuchinhMB(DSMayBay& ds_may_bay, MayBay*& ht, PTRChuyenBay& fist, int* x, int* y, int* ii, char* loc)
{
	int xg = 50, yg = 10;
	char text[5][40]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	strcpy_s(text[4], 40, "Loc so hieu may bay:");
	///=====================///
	void* p1 = malloc(imagesize(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200));
	void* p2 = malloc(imagesize(xg + 400, yg, xg + 925 + 40, yg + 40));
	rectangle(xg + getmaxx() / 2 - 320, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200);
	setbkcolor(0);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30, text[0]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 30 - textheight(text[0]) / 2,
		xg + textwidth(text[0]) + getmaxx() / 2, yg + 45 + 30 + 40 - textheight(text[0]) / 2);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30 + 50, text[1]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 80 - textheight(text[1]) / 2,
		xg + textwidth(text[0]) + getmaxx() / 2 + 300, yg + 45 + 80 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 45 + 30 + 100, text[2]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 130 - textheight(text[1]) / 2,
		xg + textwidth(text[0]) + getmaxx() / 2 - 250, yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 150 - 310, yg + 45 + 30 + 100, text[3]);
	bar(xg + textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 310, yg + 45 + 130 - textheight(text[1]) / 2,
		xg + textwidth(text[0]) + getmaxx() / 2 + 100 + 60 + textwidth(text[3]) - 250, yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 310, yg + 45 + 130 - textheight(text[1]) / 2 + 50,
		const_cast<char*>("nhap esc de thoat;nhap enter de xac nhan           dang hieu chinh MB: "));
	///============================================================================///
	outtextxy(xg + getmaxx() / 2 - 310, yg + 10, text[4]);
	outtextxy(xg + 930, yg + 10, const_cast<char*>("Loc"));
	bar(xg + 585, yg, xg + 585 + 315, yg + 40);
	rectangle(xg + 925, yg, xg + 925 + 40, yg + 40);
	///============================================================================///
	char nhap;
	int k;
	char shmb[16]{}, shmbcu[16]{}, lmb[41]{}, soday[3]{}, sodong[3]{};
	shmb[0] = '\0'; lmb[0] = '\0'; soday[0] = '\0'; sodong[0] = '\0';
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, old1 = -1;
	MayBay* hto = NULL;
	while (1) {	
		if (ht != hto) {
			hto = ht;
			strcpy_s(shmb, 15, ht->sh_Mb);
			strcpy_s(lmb, 15, ht->loai_may_bay);
			_itoa_s(ht->so_day, soday, 3, 10);
			_itoa_s(ht->so_dong, sodong, 3, 10);
			i0 = strlen(shmb);
			i1 = strlen(lmb);
			i2 = strlen(soday);
			i3 = strlen(sodong);
		}
		nhap = getch();	
		if (ht != hto) {
			hto = ht;
			strcpy_s(shmb, 15, ht->sh_Mb);
			strcpy_s(lmb, 15, ht->loai_may_bay);
			_itoa_s(ht->so_day, soday, 3, 10);
			_itoa_s(ht->so_dong, sodong, 3, 10);
			i0 = strlen(shmb);
			i1 = strlen(lmb);
			i2 = strlen(soday);
			i3 = strlen(sodong);
		}
		old1 = mouseHieuChinhMb(*x, *y, old1);
		if ((int)nhap != 13 && (int)nhap != 27) {
			if (mouseThemMb(*x, *y) == 0) {
				if (i0 < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {					
					nhap = toupper(nhap);
					shmb[i0 + 1] = shmb[i0];
					shmb[i0] = nhap; i0++;
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
				}
				if ((int)nhap == 8) {
					xoachu(shmb, xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10);
					if (i0 > 0) {
						shmb[i0 - 1] = shmb[i0--];
					}
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
				}
			}
			if (mouseThemMb(*x, *y) == 1) {
				if (i1 < 40-1) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					lmb[i1 + 1] = lmb[i1];
					lmb[i1] = nhap; i1++;
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
				if ((int)nhap == 8) {
					xoachu(lmb, xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 80 - textheight(text[1]) / 2 + 10);
					if (i1 > 0) {
						lmb[i1 - 1] = lmb[i1--];
					}
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
			}
			if (mouseThemMb(*x, *y) == 2) {
				if (i2 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					soday[i2 + 1] = soday[i2];
					soday[i2] = nhap; i2++;
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
				if ((int)nhap == 8) {
					xoachu(soday, xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i2 > 0) {
						soday[i2 - 1] = soday[i2--];
					}
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
			}
			if (mouseThemMb(*x, *y) == 3) {
				if (i3 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					sodong[i3 + 1] = sodong[i3];
					sodong[i3] = nhap; i3++;
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
				if ((int)nhap == 8) {
					xoachu(sodong, xg + textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i3 > 0) {
						sodong[i3 - 1] = sodong[i3--];
					}
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 300, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
			}
			if (mouseLocHieuChinhMB(*x, *y) == 1) {
				if (i4 < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					loc[i4 + 1] = loc[i4];
					loc[i4] = nhap; i4++;
					outtextxy(xg + 590, yg + 10, loc);
				}
				if ((int)nhap == 8) {
					xoachu(loc, xg + 590, yg + 10);
					if (i4 > 0) {
						loc[i4 - 1] = loc[i4--];
					}
					outtextxy(xg + 590, yg + 10, loc);
				}
			}
		}
		if ((int)nhap == 13 && *x != -10 && *y != -10) {
			if (ht != NULL) {
				int t1 = ht->so_day, t2 = ht->so_dong;
				if (soday[0] != '\0')t1 = atoi(soday);
				if (sodong[0] != '\0')	t2 = atoi(sodong); 
				int t = 0;
				strcpy_s(shmbcu, 15, ht->sh_Mb);
				if ((t1 >= ht->so_day && t2 >= ht->so_dong) && timCBtheoSHMB(fist, ht->sh_Mb, t) != 0) {
					if (shmb[0] != '\0') {
						if (strcmp(shmb, ht->sh_Mb) == 0 || TimSoHieu(shmb, ds_may_bay) == NULL) {
							HieuChinhMB(ds_may_bay, ht, shmb, lmb, t1, t2);
							if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
							bool d = 1;
							if (t1 * t2 == ht->so_day * ht->so_dong) {
								d = 0;
							}
							for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
								p1->capNhapVe(ds_may_bay, shmb, shmbcu, d);
							}
							outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
								const_cast<char*>("hieu chinh thanh cong"));
							Sleep(1000);
							bar(1019, 200, 1019 + textwidth(const_cast<char*>("hieu chinh thanh cong")), 200 + textheight(const_cast<char*>("hieu chinh thanh cong")));
						}
						else {
							outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
								const_cast<char*>("so hieu may bay trung, nhan phim bat ki de tiep tuc"));
							getch();
							bar(1019, 200, 1019 + textwidth(const_cast<char*>("so hieu may bay trung, nhan phim bat ki de tiep tuc")), 200 + textheight(const_cast<char*>("so hieu may bay trung")));
						}
					}
					else {
						HieuChinhMB(ds_may_bay, ht, shmb, lmb, t1, t2);
						if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
						bool d = 1;
						if (t1 * t2 == ht->so_day * ht->so_dong) {
							d = 0;
						}
						for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
							p1->capNhapVe(ds_may_bay, shmb, shmbcu, d);
						}
						outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
							const_cast<char*>("hieu chinh thanh cong"));
						Sleep(1000);
						bar(1019, 200, 1019 + textwidth(const_cast<char*>("hieu chinh thanh cong")), 200 + textheight(const_cast<char*>("hieu chinh thanh cong")));
					}
				}
				else if ((t1 < ht->so_day || t2 < ht->so_dong) && timCBtheoSHMB(fist, ht->sh_Mb, t) != 0) {
					outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
						const_cast<char*>("so ve ko duoc giam nhan, phim bat ki de tiep tuc"));
					getch();
					bar(1019, 200, 1019 + textwidth(const_cast<char*>("so ve ko duoc giam nhan, phim bat ki de tiep tuc")), 200 + textheight(const_cast<char*>("so ve ko duoc giam")));
				}
				if (timCBtheoSHMB(fist, ht->sh_Mb, t) == 0 && t1 * t2 >= 20) {
					if (shmb[0] != '\0') {
						if (strcmp(shmb, ht->sh_Mb) == 0 || TimSoHieu(shmb, ds_may_bay) == NULL) {
							HieuChinhMB(ds_may_bay, ht, shmb, lmb, t1, t2);
							if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
							/*bool d = 1;
							if (t1 * t2 == ht->so_day * ht->so_dong) {
								d = 0;
							}
							for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
								p1->capNhapVe(ds_may_bay, shmb, shmbcu, d);
							}*/
							outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
								const_cast<char*>("hieu chinh thanh cong"));
							Sleep(1000);
							bar(1019, 200, 1019 + textwidth(const_cast<char*>("hieu chinh thanh cong")), 200 + textheight(const_cast<char*>("hieu chinh thanh cong")));
						}
						else {
							outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
								const_cast<char*>("so hieu may bay trung, nhan phim bat ki de tiep tuc"));
							getch();
							bar(1019, 200, 1019 + textwidth(const_cast<char*>("so hieu may bay trung, nhan phim bat ki de tiep tuc")), 200 + textheight(const_cast<char*>("so hieu may bay trung")));
						}
					}
					else {
						HieuChinhMB(ds_may_bay, ht, shmb, lmb, t1, t2);
						if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
						/*bool d = 1;
						if (t1 * t2 == ht->so_day * ht->so_dong) {
							d = 0;
						}
						for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
							p1->capNhapVe(ds_may_bay, shmb, shmbcu, d);
						}*/
						outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
							const_cast<char*>("hieu chinh thanh cong"));
						Sleep(1000);
						bar(1019, 200, 1019 + textwidth(const_cast<char*>("hieu chinh thanh cong")), 200 + textheight(const_cast<char*>("hieu chinh thanh cong")));
					}
				}
			}
			else {
				outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
					const_cast<char*>("vui long chon may bay de hieu chinh"));
				Sleep(1000);
				bar(1019, 200, 1019 + textwidth(const_cast<char*>("vui klong chon may bay de hieu chinh")), 200 + textheight(const_cast<char*>("so hieu may bay trung")));
			}
		}
		if ((int)nhap == 27) {
			getimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
			putimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
			free(p1);
			getimage(xg + 400, yg, xg + 925 + 40, yg + 40, p2);
			putimage(xg + 400, yg, p2,1);
			free(p2);
			*x = -2; *y = -2;
			return;
		}
		if (*x == -10 && *y == -10) {
			getimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
			putimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
			free(p1);
			getimage(xg + 400, yg, xg + 925 + 40, yg + 40, p2);
			putimage(xg + 400, yg, p2, 1);
			free(p2);
			return;
		}
		if ((int)nhap == 0) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii * 10 - ds_may_bay.so_MB < 0) {
					k = *ii;
					k++;
					*ii = k;
				}
			}
			if ((int)nhap == 75) {
				if (*ii > 0) {
					k = *ii;
					k--;
					*ii = k;
				}
			}

		}
	}

}
void hienDSMb0(int* x, int* y, int* ii, DSMayBay& ds_may_bay)
{
	Sleep(50);
	int xg = 460, yg = 275;
	char text[6][225]{};
	void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
	/*============================================================*/
	strcpy_s(text[0], 40, " so hieu may bay: ");
	strcpy_s(text[1], 40, " loai may bay: ");
	strcpy_s(text[2], 40, " so day: ");
	strcpy_s(text[3], 40, " so dong: ");
	setfillstyle(1, 1);
	char tam[25];
	int n = -1;
	int old = -1;
	MayBay* hto = NULL;
	while (1) {
		if (n != *ii) {
			/**x = 0; *y = 0; */
			old = -1;
			bar(xg, yg, getmaxx(), getmaxy());
			for (int i = 0; i < 7; i++) {
				if (*ii * 7 + i < ds_may_bay.so_MB) {
					setbkcolor(1);
					outtextxy(xg + 10, yg + 5 + 60 * i, text[0]);
					outtextxy(xg + 10 + textwidth(text[0]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 7 + i]->sh_Mb);
					outtextxy(xg + 235 + textwidth(text[0]), yg + 5 + 60 * i, text[1]);
					outtextxy(xg + 235 + textwidth(text[0]) + textwidth(text[1]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 7 + i]->loai_may_bay);
					_itoa_s(ds_may_bay.maybay[*ii * 7 + i]->so_day, tam, 10);
					outtextxy(xg + 10, yg + 30 + 60 * i, text[2]);
					outtextxy(xg + 10 + textwidth(text[2]), yg + 30 + 60 * i, tam);
					_itoa_s(ds_may_bay.maybay[*ii * 7 + i]->so_dong, tam, 10);
					outtextxy(xg + 210 + textwidth(text[2]), yg + 30 + 60 * i, text[3]);
					outtextxy(xg + 210 + textwidth(text[2]) + textwidth(text[3]), yg + 30 + 60 * i, tam);
					/*outtextxy(xg + 350 + textwidth(text[2]), yg + 30 + 60 * i, const_cast<char*>("hieuchinh"));
					rectangle(xg + 345 + textwidth(text[2]), yg + 30 + 60 * i,
						xg + 380 + textwidth(text[2]) + 50, yg + 50 + 60 * i);*/
				}
				n = *ii;
			}
			_itoa_s(*ii + 1, tam, 10);
			outtextxy(xg + 10, getmaxy() - 60, tam);
			outtextxy(xg + 10, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}
}
int mouseThemMb(int x, int y)
{
	int xg = 50, yg = 10;
	char text[4][40]{};
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	///=============///
	if ((xg+textwidth(text[0]) + getmaxx() / 2 - 310 <= x) && (x <= xg+textwidth(text[0]) + getmaxx() / 2)) {
		if ((yg + 45 + 30 - textheight(text[0]) / 2 <= y) && (y <= yg + 45 + 30 + 40 - textheight(text[0]) / 2)) {
			return 0;
		}
	}
	if ((xg+textwidth(text[0]) + getmaxx() / 2 - 310 <= x) && (x <= xg+textwidth(text[0]) + getmaxx() / 2 + 300)) {
		if ((yg + 45 + 80 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 80 + 40 - textheight(text[1]) / 2)) {
			return 1;
		}
	}
	if ((xg+textwidth(text[0]) + getmaxx() / 2 -310<= x) && (x <= xg+textwidth(text[0]) + getmaxx() / 2 -250)) {
		if ((yg + 45 + 130 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 130 + 40 - textheight(text[1]) / 2)) {
			return 2;
		}
	}
	if ((xg+textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) - 310 <= x)
		&& (x <= xg+textwidth(text[0]) + getmaxx() / 2 + 100 + 60 + textwidth(text[3]) - 250)) {
		if ((yg + 45 + 130 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 130 + 40 - textheight(text[1]) / 2)) {
			return 3;
		}
	}
	return -1;
}
int mouseXoaMb(int x, int y)
{
	int xg = 460, yg = 100, yg1 = 20;
	if (868 <= x && x <= 898) {
		int n = (y - yg - 30) / 60;
		if (y < yg + 50 + 60 * n && n <= 9) {
			return n;
		}
	}
	if (yg1 + 15 <= y && y <= yg1 + 35) {
		if (xg + 213 <= x && x <= xg + 288) {
			return -1;
		}
		if (xg + 327 <= x && x <= xg + 397) {
			return -2;
		}
	}
	return -5;
}
int mouseHieuChinhMb(int x, int y, int old)
{
	int xg = 460, yg = 275;
	if (xg + 403 <= x && x <= xg + 488) {
		int n = (y - yg - 30) / 60;
		if (y < yg + 50 + 60 * n && n <= 7) {
			return n;
		}
	}
	return old;
}
int mouseLocHieuChinhMB(int x, int y)
{
	int xg = 50, yg = 10;
	if (yg <= y && y <= yg + 40) {
		if (xg + 585 <= x && x <= xg + 585 + 315) {
			return 1;
		}
		if (xg + 925 <= x && x <= xg + 925 + 40) {
			return 2;
		}
	}
	return 0;
}
int mouseLocXoaMB(int x, int y)
{
	int xg = 460, yg = 100;
	if (yg - 75 <= y && y <= yg - 75 + 30) {
		if (xg + 400 <= x && x <= xg + 400 + 150 + 315) {
			return 1;
		}
		if (xg + 870 <= x && x <= xg + 870 + 30) {
			return 2;
		}
	}
	return 0;
}
///============================================chuyen bay===============================///
void DHThemCB(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int* x, int* y, int* ii, int* ip)
{
	int xg = 500, yg = 55;
	char text[7][225]{};
	void* p = malloc(imagesize(xg, yg, xg + 975, yg + 150));
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(0);
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:     00 : 00        00   /  00   /   00");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "nhan enter de xac nhan ; esc de thoat");
	strcpy_s(text[6],100,"trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	rectangle(xg, yg, xg + 975, yg + 150);
	///=======================///
	outtextxy(xg + 10, yg + 10, text[0]);
	outtextxy(xg + 10 + 225 + 50+textwidth(text[0]), yg + 10, text[1]);
	outtextxy(xg + 10, yg + 50 + 10, text[2]);
	outtextxy(xg + 335 + 170, yg + 60, text[4]);
	outtextxy(xg + 10, yg + 120, text[5]);
	///=======================///
	bar(xg + 5 + textwidth(text[0]), yg + 5, xg + 10 + textwidth(text[0]) + 230, yg + 10 + 25);
	bar(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 5
		, xg + 10 + 225 + 50 + textwidth(text[0]) + 550, yg + 10 + 25);
	bar(xg + 10 + 100, yg + 50 + 5, xg + 10 + 30 + 100, yg + 50 + 10 + 25);///gio
	bar(xg + 50 + 100, yg + 50 + 5, xg + 50 + 30 + 100, yg + 50 + 10 + 25);///phut
	bar(xg + 95 + 100, yg + 50 + 5, xg + 95 + 30 + 100, yg + 50 + 10 + 25);///ngay
	bar(xg + 140 + 100, yg + 50 + 5, xg + 140 + 30 + 100, yg + 50 + 10 + 25);///thang
	bar(xg + 180 + 100, yg + 50 + 5, xg + 180 + 50 + 100, yg + 50 + 10 + 25);///nam
	bar(xg + 120 + 475, yg + 55, xg + 225 + 120 + 475, yg + 60 + 25);
	///=======================///
	char nhap;
	int i[10]{}, n, tam = 0;
	char mcb[16]{}, sbd[101]{}, gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[5]{}, tt[2]{}, shmb[16]{};
	for (int k = 0; k < 10; k++) {
		i[k] = 0;
	}
	int k = 0, cd = 0;
	for (PTRChuyenBay q = dau_chuyen_bay; q != NULL; q = q->next)cd++;
	setbkcolor(1);
	while (1) {
		if (((int)(nhap = getch()) != 13) && ((int)nhap != 27)) {
			n = mouseThemCB(*x, *y);
			switch (n)
			{
			case 1: {
				if (i[n] < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					mcb[i[n] + 1] = mcb[i[n]];
					mcb[i[n]] = nhap; i[n]++;
					outtextxy(xg + 5 + textwidth(text[0]), yg + 10, mcb);
				}
				if ((int)nhap == 8) {
					xoachu(mcb, xg + 5 + textwidth(text[0]), yg + 10);
					if (i[n] > 0) {
						mcb[i[n] - 1] = mcb[i[n]--];
					}
					outtextxy(xg + 5 + textwidth(text[0]), yg + 10, mcb);
				}
				break;
			}
			case 2: {
				if (i[n] < 100) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9')) || (int)nhap == 32) {
					sbd[i[n] + 1] = sbd[i[n]];
					sbd[i[n]++] = nhap;
					if ((int)nhap != 32 && i[n] != 0) {
						SuaTen(sbd);
						i[n] = strlen(sbd);
					}
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10, sbd);
					
				}
				if ((int)nhap == 8) {
					xoachu(sbd, xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10);
					if (i[n] > 0) {
						sbd[i[n] - 1] = sbd[i[n]--];
					}
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10, sbd);
				}
				break;
			}
			case 3: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					gio[i[n] + 1] = gio[i[n]];
					gio[i[n]] = nhap; i[n]++;
					tam = atoi(gio);
					if (tam >= 24) {
						gio[i[n] - 1] = gio[i[n]--];
					}
					outtextxy(xg + 10 + 100, yg + 50 + 10, gio);
				}
				if ((int)nhap == 8) {
					xoachu(gio, xg + 10 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						gio[i[n] - 1] = gio[i[n]--];
					}
					outtextxy(xg + 10 + 100, yg + 50 + 10, gio);
				}
				break;
			}
			case 4: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					phut[i[n] + 1] = phut[i[n]];
					phut[i[n]] = nhap; i[n]++;
					tam = atoi(phut);
					if (tam >= 60) {
						phut[i[n] - 1] = phut[i[n]--];
					}
					outtextxy(xg + 50 + 100, yg + 50 + 10, phut);
				}
				if ((int)nhap == 8) {
					xoachu(phut, xg + 50 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						phut[i[n] - 1] = phut[i[n]--];
					}
					outtextxy(xg + 50 + 100, yg + 50 + 10, phut);
				}
				break;
			}
			case 5: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {					
						ngay[i[n] + 1] = ngay[i[n]];
						ngay[i[n]] = nhap; i[n]++;
						tam = atoi(ngay);
						if (tam >= 32) {
							ngay[i[n] - 1] = ngay[i[n]--];
						}
						outtextxy(xg + 95 + 100, yg + 50 + 10, ngay);
				}
				if ((int)nhap == 8) {
					xoachu(ngay, xg + 95 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 95 + 100, yg + 50 + 10, ngay);
				}
				break;
			}
			case 6: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					thang[i[n] + 1] = thang[i[n]];
					thang[i[n]] = nhap; i[n]++;
					tam = atoi(thang);
					if (tam > 12) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 140 + 100, yg + 50 + 10, thang);
				}
				if ((int)nhap == 8) {
					xoachu(thang, xg + 140 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 140 + 100, yg + 50 + 10, thang);
				}
				break;
			}
			case 7: {
				if (i[n] < 4)if (('0' <= nhap) && (nhap <= '9')) {
					nam[i[n] + 1] = nam[i[n]];
					nam[i[n]] = nhap; i[n]++;
					tam = atoi(nam);
					outtextxy(xg + 180 + 100, yg + 50 + 10, nam);
				}
				if ((int)nhap == 8) {
					xoachu(nam, xg + 180 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						nam[i[n] - 1] = nam[i[n]--];
					}
					outtextxy(xg + 180 + 100, yg + 50 + 10, nam);
				}
				break;
			}
			case 9: {
				if (i[n] < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					shmb[i[n] + 1] = shmb[i[n]];
					shmb[i[n]] = nhap; i[n]++;
					outtextxy(xg + 120 + 475, yg + 60, shmb);
				}
				if ((int)nhap == 8) {
					xoachu(shmb, xg + 120 + 475, yg + 60);
					if (i[n] > 0) {
						shmb[i[n] - 1] = shmb[i[n]--];
					}
					outtextxy(xg + 120 + 475, yg + 60, shmb);
				}
				break;
			}
			default:
				break;
			}
		}
		if ((int)nhap == 13) {
			if ((shmb[0] == '\0') || (mcb[0] == '\0') || (ngay[0] == '\0') || (thang[0] == '\0')
				|| (nam[0] == '\0') || (gio[0] == '\0') || (phut[0] == '\0') || (sbd[0] == '\0'))
			{
				int mt = getbkcolor();
				setbkcolor(0);
				outtextxy(xg + 200, yg + 90, const_cast<char*>("khong de thong tin trong, nhan phim bat ki de tiep tuc"));
				getch();
				xoachu(const_cast<char*>("khong de thong tin trong, nhan phim bat ki de tiep tuc"), xg + 200, yg + 90);
				setbkcolor(mt);
			}
			else {
				if (timChuyenBay(dau_chuyen_bay, mcb) == NULL && TimSoHieu(shmb, ds_may_bay) != NULL) {
					ChuyenBay tam1;
					NgayGio tam2;
					bool d = 0;
					tam2.datNgayGio(atoi(gio), atoi(phut), atoi(ngay), atoi(thang), atoi(nam));
					tam1.datChuyenBay(mcb, tam2, sbd, shmb, capNhapTT(tam2), ds_may_bay);
					for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next) {
						if (strcmp(p->cb.sh_Mb, shmb) == 0 && checkNgayGio(p->cb.ngay_gio_kh, tam2) == 1) {
							d = 1;
							break;
						}
					}
					if (capNhapTT(tam2) == HOAN_TAT || tam2.checkNgayGio() == 0) {
						if (tam2.checkNgayGio() == 0) {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 200, yg + 90, const_cast<char*>("thoi gian nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("thoi gian nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
							setbkcolor(mt);
						}else
						if (capNhapTT(tam2) == HOAN_TAT) {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 200, yg + 90, const_cast<char*>("thoi gian chuyen bay da troi qua, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("thoi gian chuyen bay da troi qua, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
							setbkcolor(mt);
						}
					}
					else
						if (d == 1) {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 200, yg + 90, const_cast<char*>("thoi gian chuyen bay xung voi chuyen bay khac, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("thoi gian chuyen bay xung voi chuyen bay khac, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
							setbkcolor(mt);
						}
						else {
							themChuyenBay(dau_chuyen_bay, tam1);
							/*getimage(xg, yg, xg + 975, yg + 150, p);
							putimage(xg, yg, p, 1);
							free(p);
							return;*/
							cd++;
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 200, yg + 90, const_cast<char*>("them chuyen bay thanh cong, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("them chuyen bay thanh cong, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
							setbkcolor(mt);
						}
				}
				else {
					int mt = getbkcolor();
					setbkcolor(0);
					outtextxy(xg + 200, yg + 90, const_cast<char*>("ma chuyen bay bi trung hoac ko co so hieu may bay nay, NHAN PHIM BAT KY DE TIEP TUC"));
					getch();
					xoachu(const_cast<char*>("ma chuyen bay bi trung hoac ko co so hieu may bay nay, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
					setbkcolor(mt);
				}
			}
		}
		else if ((int)nhap == 27) {
			getimage(xg, yg, xg + 975, yg + 150, p);
			putimage(xg, yg, p, 1);
			free(p);
			*x = -1; *y = -1;
			return;
		}
		else if ((int)nhap == 0) {
			nhap = getch();
			n = mouseThemCB(*x, *y);
			if (n == -1) {
				if ((int)nhap == 77) {
					if (*ii * 8 - cd < 0) {
						k = *ii;
						k++;
						*ii = k;
					}
				}
				if ((int)nhap == 75) {
					if (*ii > 0) {
						k = *ii;
						k--;
						*ii = k;
					}
				}
			}
			if (n == -2) {
				if ((int)nhap == 77) {
					if (*ip * 8 - ds_may_bay.so_MB < 0) {
						k = *ip;
						k++;
						*ip = k;
					}
				}
				if ((int)nhap == 75) {
					if (*ip > 0) {
						k = *ip;
						k--;
						*ip = k;
					}
				}
			}
		}
		if (*x == -10 && *y == -10) {
			getimage(xg, yg, xg + 975, yg + 150, p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}

}
void hienDSCB0(int* x, int* y, int* ii, int* ip, PTRChuyenBay& dau_chuyen_bay, DSMayBay ds_may_bay)
{
	Sleep(50);
	setbkcolor(1);
	int xg = 500, yg = 220, kc = 60;
	char text[7][225]{};
	void* p = malloc(imagesize(xg, yg, xg + getmaxx(), yg + getmaxy()));
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	/*setbkcolor(0);*/
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:        :                /       /     ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	///==================================================================================///
	PTRChuyenBay q;
	int i1 = 0, cd = 0, ii1 = -1, ip1 = -1, j = 0;
	char tam[225], nhap = 0;

	q = dau_chuyen_bay;
	while (1) {
		if (ii1 != *ii) {
			//i1 = 0; *x = 0; *y = 0;
			bar(xg, yg, xg + 600, getmaxy());
			j = 0;
			for (q = dau_chuyen_bay; q != NULL && j < *ii * 8; q = q->next) {
				j++;
			}
			for (int i = 0; i < 8; i++) {
				if (q != NULL) {
					outtextxy(xg + 10, yg + 5 + kc * i, text[0]);
					//outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10 + kc * i, text[1]);
					outtextxy(xg + 10, yg + 35 + kc * i, text[2]);
					outtextxy(xg + 300, yg + 35 + kc * i, text[4]);
					///===========================================///
					outtextxy(xg + 10 + textwidth(text[0]) + 5, yg + 5 + kc * i, q->cb.ma_cb);
					_itoa_s(q->cb.ngay_gio_kh.gio_kh.gio, tam, 225, 10);
					outtextxy(xg + 15 + 100, yg + 35 + kc * i, tam);///gio
					_itoa_s(q->cb.ngay_gio_kh.gio_kh.phut, tam, 225, 10);
					outtextxy(xg + 40 + 100, yg + 35 + kc * i, tam);///phut
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.ngay, tam, 225, 10);
					outtextxy(xg + 80 + 100, yg + 35 + kc * i, tam);///ngay
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.thang, tam, 225, 10);
					outtextxy(xg + 110 + 100, yg + 35 + kc * i, tam);///thang
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.nam, tam, 225, 10);
					outtextxy(xg + 140 + 100, yg + 35 + kc * i, tam);///nam
					outtextxy(xg + 300 + 100, yg + 35 + kc * i, q->cb.sh_Mb);
					line(xg, yg + 60 + kc * i, xg + 599, yg + 60 + kc * i);
					q = q->next;
				}
			}
			ii1 = *ii;
			_itoa_s(ii1 + 1, tam, 225, 10);
			outtextxy(xg + 10, getmaxy() - 50, tam);
			outtextxy(xg + 5, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		if (ip1 != *ip) {
			//i1 = 0; *x = 0; *y = 0;
			bar(xg + 625, yg, getmaxx(), getmaxy());
			for (int i = 0; i < 8; i++) {
				if (i + *ip * 8 < ds_may_bay.so_MB) {
					outtextxy(xg + 635, yg + 5 + kc * i, text[4]);
					outtextxy(xg + 635, yg + 35 + kc * i, const_cast<char*>("So day: "));
					outtextxy(xg + 800, yg + 35 + kc * i, const_cast<char*>("So dong: "));
					///=============================================///
					outtextxy(xg + 725, yg + 5 + kc * i, ds_may_bay.maybay[i + *ip * 8]->sh_Mb);
					_itoa_s(ds_may_bay.maybay[i + *ip * 8]->so_day, tam, 200, 10);
					outtextxy(xg + 700, yg + 35 + kc * i, tam);
					_itoa_s(ds_may_bay.maybay[i + *ip * 8]->so_dong, tam, 200, 10);
					outtextxy(xg + 870, yg + 35 + kc * i, tam);
					line(xg + 625, yg + 60 + kc * i, getmaxx(), yg + 60 + kc * i);
				}
			}
			ip1 = *ip;
			_itoa_s(ip1 + 1, tam, 225, 10);
			outtextxy(xg + 625 + 10, getmaxy() - 50, tam);
			outtextxy(xg + 625 + 5, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		};
	}
}
int mouseThemCB(int x, int y)
{
	int xg = 500, yg = 55;
	if (yg + 5 <= y && y <= yg + 35) {
		if (xg + 119 <= x && x <= xg + 354) {
			return 1;
		}
		else if (xg + 494 <= x && x <= xg + 949) {
			return 2;
		}
	}
	if (yg + 50 <= y && y <= yg + 50 + 10 + 25) {
		if (xg + 10 + 100 <= x && x <= xg + 10 + 100 + 30) {
			return 3;///gio
		}
		else if (xg + 50 + 100 <= x && x <= xg + 50 + 100 + 30) {
			return 4;///phut
		}
		else if (xg + 95 + 100 <= x && x <= xg + 95 + 100 + 30) {
			return 5;///ngay
		}
		else if (xg + 140 + 100 <= x && x <= xg + 140 + 100 + 30) {
			return 6;///thang
		}
		else if (xg + 180 + 100 <= x && x <= xg + 180 + 100 + 50) {
			return 7;///nam
		}
		else if (xg + 120 + 475 <= x && x <= xg + 225 + 120 + 475) {
			return 9;
		}
	}
	if (165 + yg <= y && y <= getmaxy()) {
		if (xg <= x && x <= xg + 600) {
			return -1;
		}
		if (xg + 625 <= x && x <= getmaxx()) {
			return -2;
		}
	}
	return 0;
}
void DHHuyChuyen(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int* x, int* y,int *ii)
{
	int xg = 500, yg = 10, kc = 65;
	char text[5][225]{};
	strcpy_s(text[0], 100, "you huy chuyen bay nay:  ");
	strcpy_s(text[1], 100, " xac nhan");
	strcpy_s(text[2], 100, " huy bo");
	PTRChuyenBay p; int n, cd = 0;
	for (p = dau_chuyen_bay; p != NULL; p = p->next) {
		cd++;
	}
	void* q = malloc(imagesize(xg, yg, xg + 550, yg + 50));
	while (1) {
		n = mouseHuyCB(*x, *y);
		if (*ii * 10 + n < cd)
			if (n >= 0) {
				int i = 0;
				for (p = dau_chuyen_bay; p != NULL && i < *ii * 10 + n; p = p->next) {
					i++;
				}
				if (p != NULL && p->cb.trang_thai_cb != HOAN_TAT && p->cb.trang_thai_cb != HUY_CHUYEN) {
					bar(xg, yg, xg + 550, yg + 50);
					outtextxy(xg + 10, yg + 5, text[0]);
					outtextxy(xg + 50 + textwidth(text[0]), yg + 5, text[1]);
					outtextxy(xg + 150 + textwidth(text[0]) + textwidth(text[1]), yg + 5, text[2]);
					outtextxy(xg + 10, yg + 25, p->cb.ma_cb);
					///=======================================///
					rectangle(xg + 60 + 170, yg + 5, xg + 60 + 260, yg + 30);
					rectangle(xg + 60 + 330, yg + 5, xg + 60 + 400, yg + 30);
					while (1) {
						if (mouseHuyCB(*x, *y) == -1) {
							getimage(xg, yg, xg + 550, yg + 50, q);
							putimage(xg, yg, q, 1);
							p->cb.trang_thai_cb = HUY_CHUYEN;
							break;
						}
						else if (mouseHuyCB(*x, *y) == -2) {
							getimage(xg, yg, xg + 550, yg + 50, q);
							putimage(xg, yg, q, 1);
							break;
						}
						else if (*x == -1 && *y == -1) {
							getimage(xg, yg, xg + 550, yg + 50, q);
							putimage(xg, yg, q, 1);
							free(q);
							return;
						}
					}
				}
				else if (p != NULL) {
					if (p->cb.trang_thai_cb == HOAN_TAT) {
						strcpy_s(text[3], 25, p->cb.ma_cb);
						strcat_s(text[3], 25, " da hoan tat");
						outtextxy(xg + 10, yg + 25, text[3]);
						*x = 0; *y = 0;
						Sleep(1000);
						getimage(xg, yg, xg + 550, yg + 50, q);
						putimage(xg, yg, q, 1);
					}
					else if (p->cb.trang_thai_cb == HUY_CHUYEN) {
						strcpy_s(text[3], 25, p->cb.ma_cb);
						strcat_s(text[3], 25, " da huy chuyen");
						outtextxy(xg + 10, yg + 25, text[3]);
						*x = 0; *y = 0;
						Sleep(1000);
						getimage(xg, yg, xg + 550, yg + 50, q);
						putimage(xg, yg, q, 1);
					}
				}
			}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg, yg, xg + 550, yg + 50, q);
			putimage(xg, yg, q, 1);
			free(q);
			return;
		}
	}
}
void hienDSCB1(int* x, int* y, int* ii, PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay)
{
	int xg = 500, yg = 70, kc = 65;
	char text[7][225]{};
	void* p = malloc(imagesize(xg, yg, xg + getmaxx(), yg + getmaxy()));
	settextstyle(3, HORIZ_DIR, 1);
	setbkcolor(1);
	setfillstyle(1, 1);
	/*setbkcolor(0);*/
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:        :                /       /     ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	///==================================================================================///
	PTRChuyenBay q;
	int i1 = 0, k, cd = 0, iio = -1;
	char tam[225], nhap = 0;
	MayBay* tm = nullptr;
	for (PTRChuyenBay p1 = dau_chuyen_bay; p1 != NULL; p1 = p1->next)cd++;
	PTRChuyenBay* tcb = new PTRChuyenBay[cd]{};
	q = dau_chuyen_bay;
	for (int i = 0; i < cd; i++) {
		tcb[i] = q;
		q = q->next;
	}
	while (1) {
		if (iio != *ii) {
			bar(xg, yg, xg + getmaxx(), yg + getmaxy());
			for (int i = 0; i < 10; i++) {
				if (tcb[*ii * 10 + i] != NULL && *ii * 10 + i < cd) {
					outtextxy(xg + 10, yg + 10 + kc * i, text[0]);
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10 + kc * i, text[1]);
					outtextxy(xg + 10, yg + 40 + kc * i, text[2]);
					outtextxy(xg + 10 + textwidth(text[2]) + 30, yg + 40 + kc * i, text[3]);
					outtextxy(xg + 320 + 170, yg + 40 + kc * i, text[4]);
					outtextxy(xg + 550 + 170, yg + 40 + kc * i, text[5]);
					///===========================================///
					outtextxy(xg + 10 + textwidth(text[0]) + 5, yg + 10 + kc * i, tcb[*ii * 10 + i]->cb.ma_cb);
					outtextxy(xg + 10 + 225 + 50 + 120 + textwidth(text[1]), yg + 10 + kc * i, tcb[*ii * 10 + i]->cb.san_bay_den);
					_itoa_s(tcb[*ii * 10 + i]->cb.ngay_gio_kh.gio_kh.gio, tam, 225, 10);
					outtextxy(xg + 15 + 100, yg + 40 + kc * i, tam);///gio
					_itoa_s(tcb[*ii * 10 + i]->cb.ngay_gio_kh.gio_kh.phut, tam, 225, 10);
					outtextxy(xg + 40 + 100, yg + 40 + kc * i, tam);///phut
					_itoa_s(tcb[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.ngay, tam, 225, 10);
					outtextxy(xg + 80 + 100, yg + 40 + kc * i, tam);///ngay
					_itoa_s(tcb[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.thang, tam, 225, 10);
					outtextxy(xg + 110 + 100, yg + 40 + kc * i, tam);///thang
					_itoa_s(tcb[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.nam, tam, 225, 10);
					outtextxy(xg + 140 + 100, yg + 40 + kc * i, tam);///nam
					switch (tcb[*ii * 10 + i]->cb.trang_thai_cb)
					{
					case HUY_CHUYEN: {
						strcpy_s(tam, 225, "huy chuyen");
						break;
					}
					case CON_VE: {
						strcpy_s(tam, 225, "con ve");
						break;
					}
					case HET_VE: {
						strcpy_s(tam, 225, "het ve");
						break;
					}
					case HOAN_TAT: {
						strcpy_s(tam, 225, "hoan tat");
						break;
					}
					default:
						break;
					}
					outtextxy(xg + 295 + 100, yg + 40 + kc * i, tam);
					outtextxy(xg + 485 + 100, yg + 40 + kc * i, tcb[*ii * 10 + i]->cb.sh_Mb);
					tm = TimSoHieu(tcb[*ii * 10 + i]->cb.sh_Mb, ds_may_bay);
					_itoa_s(tm->so_day * tm->so_dong - tcb[*ii * 10 + i]->cb.so_ve, tam, 100, 10);
					outtextxy(xg + 720 + 100, yg + 40 + kc * i, tam);
					outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("HUY CHUYEN"));
					rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 880 + 100, yg + 60 + kc * i);
					line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
				}
			}
			iio = *ii;
			_itoa_s(iio + 1, tam, 225, 10);
			outtextxy(xg + 10, getmaxy() - 35, tam);
			outtextxy(xg + 30, getmaxy() - 35, const_cast<char*>("nhan esc de thoat"));
		}		
		nhap = getch();
		if (mouseChonCB(*x, *y) == -1) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			delete[]tcb;
			*x = -1; *y = -1;
			return;
		}
		if ((int)nhap == 0)
			if (!(*ii * 10 + mouseChonCB(*x, *y) < cd && mouseChonCB(*x, *y) >= 0)) {
				*x = -2; *y = -2;
				nhap = getch();
				if ((int)nhap == 77) {
					if (*ii * 10 - cd < 0) {
						k = *ii;
						k++;
						*ii = k;
						bar(xg, yg, getmaxx(), getmaxy());
					}
				}
				if ((int)nhap == 75) {
					if (*ii > 0) {
						k = *ii;
						k--;
						*ii = k;
						bar(xg, yg, getmaxx(), getmaxy());
					}
				}
			}
		if ((int)nhap == 27) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			delete[] tcb;
			*x = -1; *y = -1;
			return;
		}
		if (*x == -10 && *y == -10) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			delete[] tcb;
			return;
		}
	}
}
int mouseHuyCB(int x, int y)
{
	int xg = 500, yg = 70, kc = 65;
	int n = (y - yg - 40) / kc;
	if (xg + 765 + 100 <= x && x <= xg + 880 + 100) {
		if (yg + 40 + kc * n <= y && y <= yg + 60 + kc * n) {
			return n;
		}
	}
	if (yg - 60 + 5 <= y && y <= yg - 60 + 30) {
		if (xg + 60 + 170 <= x && x <= xg + 60 + 260) {
			return -1;
		}
		if (xg + 60 + 330 <= x && x <= xg + 60 + 400) {
			return -2;
		}
	}
	return -5;
}
void DHHieuChinhCB(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay& ht, DSMayBay ds_may_bay, int* x, int* y, int* ii, char* loc)
{
	int xg = 500, yg = 55;
	char text[7][225]{};
	void* p = malloc(imagesize(xg, yg, xg + 975, yg + 150));
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(0);
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:     00 : 00        00   /  00   /   00");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "nhan enter de xac nhan ; esc de thoat");
	strcpy_s(text[6], 100, "Loc theo ma chuyen bay: ");
	rectangle(xg, yg, xg + 975, yg + 150);
	///=======================///
	outtextxy(xg + 10, yg + 10, text[0]);
	outtextxy(xg + 10, yg - 40, text[6]);//loc
	outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10, text[1]);
	outtextxy(xg + 10, yg + 50 + 10, text[2]);
	outtextxy(xg + 335 + 170, yg + 60, text[4]);
	outtextxy(xg + 10, yg + 120, text[5]);
	rectangle(xg + 450, yg - 45, xg + 450 + 40, yg - 45 + 30);//nut xac nhan loc
	outtextxy(xg + 460, yg - 40, const_cast<char*>("loc"));
	///=======================///
	bar(xg + 5 + textwidth(text[0]), yg + 5, xg + 10 + textwidth(text[0]) + 230, yg + 10 + 25);
	bar(xg + 5 + textwidth(text[6]), yg - 45, xg + 10 + textwidth(text[6]) + 230, yg - 45 + 30);//loc	
	bar(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 5
		, xg + 10 + 225 + 50 + textwidth(text[0]) + 550, yg + 10 + 25);
	bar(xg + 10 + 100, yg + 50 + 5, xg + 10 + 30 + 100, yg + 50 + 10 + 25);///gio
	bar(xg + 50 + 100, yg + 50 + 5, xg + 50 + 30 + 100, yg + 50 + 10 + 25);///phut
	bar(xg + 95 + 100, yg + 50 + 5, xg + 95 + 30 + 100, yg + 50 + 10 + 25);///ngay
	bar(xg + 140 + 100, yg + 50 + 5, xg + 140 + 30 + 100, yg + 50 + 10 + 25);///thang
	bar(xg + 180 + 100, yg + 50 + 5, xg + 180 + 50 + 100, yg + 50 + 10 + 25);///nam
	bar(xg + 120 + 475, yg + 55, xg + 225 + 120 + 475, yg + 60 + 25);
	///=======================///
	int cd = 0, k = 0;
	for (PTRChuyenBay p1 = dau_chuyen_bay; p1 != NULL; p1 = p1->next)cd++;
	char nhap;
	int i[10]{}, n, tam = 0;
	char mcb[16]{}, sbd[101]{}, gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[5]{}, tt[2]{}, shmb[16]{};
	for (int k = 0; k < 10; k++) {
			i[k] = 0;
	}
	PTRChuyenBay hto = NULL;
	loc[0] = '\0';
	setbkcolor(1);
	while (1) {
		if (ht != hto) {
			hto = ht;
			strcpy_s(sbd, 100, ht->cb.san_bay_den);
			_itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, gio, 3, 10);
			_itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, phut, 3, 10);
			_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, ngay, 3, 10);
			_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, thang, 3, 10);
			_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, nam, 5, 10);
			strcpy_s(shmb, 15, ht->cb.sh_Mb);
			i[2] = strlen(sbd);
			i[3] = strlen(gio);
			i[4] = strlen(phut);
			i[5] = strlen(ngay);
			i[6] = strlen(thang);
			i[7] = strlen(nam);
			i[9] = strlen(shmb);
		}
		if (((int)(nhap = getch()) != 13) && ((int)nhap != 27)) {
			if (ht != hto) {
				hto = ht;
				strcpy_s(sbd, 100, ht->cb.san_bay_den);
				_itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, gio, 3, 10);
				_itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, phut, 3, 10);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, ngay, 3, 10);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, thang, 3, 10);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, nam, 5, 10);
				strcpy_s(shmb, 15, ht->cb.sh_Mb);
				i[2] = strlen(sbd);
				i[3] = strlen(gio);
				i[4] = strlen(phut);
				i[5] = strlen(ngay);
				i[6] = strlen(thang);
				i[7] = strlen(nam);
				i[9] = strlen(shmb);
			}
			n = mouseThemCB(*x, *y);
			switch (n)
			{
			case 2: {
				if (i[n] < 100) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9')) || (int)nhap == 32){
					sbd[i[n] + 1] = sbd[i[n]];
					sbd[i[n]++] = nhap;
					if ((int)nhap != 32 && i[n] != 0) {
						SuaTen(sbd);
						i[n] = strlen(sbd);
					}
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10, sbd);
				}
				if ((int)nhap == 8) {
					xoachu(sbd, xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10);
					if (i[n] > 0) {
						sbd[i[n] - 1] = sbd[i[n]--];
					}
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 10, sbd);
				}
				break;
			}
			case 3: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					gio[i[n] + 1] = gio[i[n]];
					gio[i[n]] = nhap; i[n]++;
					tam = atoi(gio);
					if (tam >= 24) {
						gio[i[n] - 1] = gio[i[n]--];
					}
					outtextxy(xg + 10 + 100, yg + 50 + 10, gio);
				}
				if ((int)nhap == 8) {
					xoachu(gio, xg + 10 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						gio[i[n] - 1] = gio[i[n]--];
					}
					outtextxy(xg + 10 + 100, yg + 50 + 10, gio);
				}
				break;
			}
			case 4: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					phut[i[n] + 1] = phut[i[n]];
					phut[i[n]] = nhap; i[n]++;
					tam = atoi(phut);
					if (tam >= 60) {
						phut[i[n] - 1] = phut[i[n]--];
					}
					outtextxy(xg + 50 + 100, yg + 50 + 10, phut);
				}
				if ((int)nhap == 8) {
					xoachu(phut, xg + 50 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						phut[i[n] - 1] = phut[i[n]--];
					}
					outtextxy(xg + 50 + 100, yg + 50 + 10, phut);
				}
				break;
			}
			case 5: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					ngay[i[n] + 1] = ngay[i[n]];
					ngay[i[n]] = nhap; i[n]++;
					tam = atoi(ngay);
					if (tam >= 32) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 95 + 100, yg + 50 + 10, ngay);
				}
				if ((int)nhap == 8) {
					xoachu(ngay, xg + 95 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 95 + 100, yg + 50 + 10, ngay);
				}
				break;
			}
			case 6: {
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
					thang[i[n] + 1] = thang[i[n]];
					thang[i[n]] = nhap; i[n]++;
					tam = atoi(thang);
					if (tam > 12) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 140 + 100, yg + 50 + 10, thang);
				}
				if ((int)nhap == 8) {
					xoachu(thang, xg + 140 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 140 + 100, yg + 50 + 10, thang);
				}
				break;
			}
			case 7: {
				if (i[n] < 4)if (('0' <= nhap) && (nhap <= '9')) {
					nam[i[n] + 1] = nam[i[n]];
					nam[i[n]] = nhap; i[n]++;
					tam = atoi(nam);
					outtextxy(xg + 180 + 100, yg + 50 + 10, nam);
				}
				if ((int)nhap == 8) {
					xoachu(nam, xg + 180 + 100, yg + 50 + 10);
					if (i[n] > 0) {
						nam[i[n] - 1] = nam[i[n]--];
					}
					outtextxy(xg + 180 + 100, yg + 50 + 10, nam);
				}
				break;
			}
			case 9: {
				if (i[n] < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					shmb[i[n] + 1] = shmb[i[n]];
					shmb[i[n]] = nhap; i[n]++;
					outtextxy(xg + 120 + 475, yg + 60, shmb);
				}
				if ((int)nhap == 8) {
					xoachu(shmb, xg + 120 + 475, yg + 60);
					if (i[n] > 0) {
						shmb[i[n] - 1] = shmb[i[n]--];
					}
					outtextxy(xg + 120 + 475, yg + 60, shmb);
				}
				break;
			}
			default:
				break;
			}
			if (mouseLocHieuChinhCB(*x, *y) == 1) {
				if (i[1] < 14) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					loc[i[1] + 1] = loc[i[1]];
					loc[i[1]++] = nhap;					
					outtextxy(xg + 5 + textwidth(text[6]), yg - 40, loc);
				}
				if ((int)nhap == 8) {
					xoachu(loc, xg + 5 + textwidth(text[6]), yg - 40);
					if (i[1] > 0) {
						loc[i[1] - 1] = loc[i[1]--];
					}
					outtextxy(xg + 5 + textwidth(text[6]), yg - 40, loc);
				}
			}
		}
		if ((int)nhap == 0) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii * 10 - cd < 0) {
					k = *ii;
					k++;
					*ii = k;

				}
			}
			if ((int)nhap == 75) {
				if (*ii > 0) {
					k = *ii;
					k--;
					*ii = k;
				}
			}
		}
		if ((int)nhap == 13) {
			if (ht != NULL) {
				NgayGio tam1;
				bool d = 0;
				int gi = ht->cb.ngay_gio_kh.gio_kh.gio, ph = ht->cb.ngay_gio_kh.gio_kh.phut;
				int ng = ht->cb.ngay_gio_kh.ngay_kh.ngay, th = ht->cb.ngay_gio_kh.ngay_kh.thang, na = ht->cb.ngay_gio_kh.ngay_kh.nam;
				if (gio[0] != '\0') {
					gi = atoi(gio);
				}
				if (phut[0] != '\0') {
					ph = atoi(phut);
				}
				if (ngay[0] != '\0') {
					ng = atoi(ngay);
				}
				if (thang[0] != '\0') {
					th = atoi(thang);
				}
				if (nam[0] != '\0') {
					na = atoi(nam);
				}
				if (shmb[0] == '\0') strcpy_s(shmb, 15, ht->cb.sh_Mb);
				tam1.datNgayGio(gi, ph, ng, th, na);
				for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next) {
					if (p != ht && strcmp(p->cb.sh_Mb, shmb) == 0 && checkNgayGio(p->cb.ngay_gio_kh, tam1) == 1) {
						d = 1;
						break;
					}
				}
				if (capNhapTT(tam1) == HOAN_TAT || tam1.checkNgayGio() == 0) {
					if (tam1.checkNgayGio() == 0) {
						int mt = getbkcolor();
						setbkcolor(0);
						outtextxy(xg + 200, yg + 90, const_cast<char*>("thoi gian nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("thoi gian nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
						setbkcolor(mt);
					}
					else
						if (capNhapTT(tam1) == HOAN_TAT) {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 200, yg + 90, const_cast<char*>("thoi gian chuyen bay da troi qua, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("thoi gian chuyen bay da troi qua, NHAN PHIM BAT KY DE TIEP TUC"), xg + 200, yg + 90);
							setbkcolor(mt);
						}
				}
				else
					if (d == 1) {
						int mt = getbkcolor();
						setbkcolor(0);
						outtextxy(xg + 100, yg + 100, const_cast<char*>("thoi gian chuyen bay xung dot voi chuyen bay khac, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("thoi gian chuyen bay xung dot voi chuyen bay khac, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
						setbkcolor(mt);
					}
					else {
						if (shmb[0] != '\0' && strcmp(shmb, ht->cb.sh_Mb) != 0 && ht->cb.ds_ve[0].cmnd[0] != '\0') {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 100, yg + 100, const_cast<char*>("chuyen bay da dat ve ko thay doi SHMB, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("chuyen bay da dat ve ko thay doi SHMB, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
							setbkcolor(mt);
						}
						else if (shmb[0] != '\0' && TimSoHieu(shmb, ds_may_bay) == NULL) {
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 100, yg + 100, const_cast<char*>("khong tim thay SHMB, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("khong tim thay SHMB, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
							setbkcolor(mt);
						}
						else {
							chinhsuaChuyenBay(ht, tam1, sbd, shmb);
							ht->capnhap(ds_may_bay);
							int mt = getbkcolor();
							setbkcolor(0);
							outtextxy(xg + 100, yg + 100, const_cast<char*>("hieu chinh thanh cong, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("hieu chinh thanh cong, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
							setbkcolor(mt);
						}
					}
			}
			else {
				int mt = getbkcolor();
				setbkcolor(0);
				outtextxy(xg + 100, yg + 100, const_cast<char*>("vui long chon CB, NHAN PHIM BAT KY DE TIEP TUC"));
				getch();
				xoachu(const_cast<char*>("vui long chon CB, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
				setbkcolor(mt);
			}

		}
		if ((int)nhap == 27) {
				getimage(xg, yg, xg + 975, yg + 150, p);
				putimage(xg, yg, p, 1);
				*x = -1; *y = -1;
				return;
		}
		if (*x == -10 && *y == -10) {
			getimage(xg, yg, xg + 975, yg + 150, p);
			putimage(xg, yg, p, 1);
			return;
		}
	}
}
void hienDSCB2(int* x, int* y, int* ii, PTRChuyenBay& ht, PTRChuyenBay& dau_chuyen_bay, DSMayBay ds_may_bay, char* loc)
{
	Sleep(50);
	setbkcolor(1);
	int xg = 500, yg = 220, kc = 65;
	char text[7][225]{};
	void* p = malloc(imagesize(xg, yg, xg + getmaxx(), yg + getmaxy()));
	void* p1 = malloc(imagesize(xg + 10, yg - 215, xg + 10 + 500, yg -215 + 35));
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:        :                /       /     ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	///==================================================================================///
	PTRChuyenBay q ;
	int i1 = 0, cd = 0, ii1 = 1, old = -1;
	char tam[225], nhap = 0;
	MayBay* tm=NULL;
	for (PTRChuyenBay p1 = dau_chuyen_bay; p1 != NULL; p1 = p1->next)cd++;
	PTRChuyenBay* tcb = new PTRChuyenBay[cd]{};
	q = dau_chuyen_bay;
	for (int i = 0; i < cd; i++) {
		tcb[i] = q;
		q = q->next;
	}
	while (1) {
		if (old != mouseHieuChinhCB(old, *x, *y) && *ii * 8 + mouseHieuChinhCB(old, *x, *y) < cd && mouseHieuChinhCB(old, *x, *y) >= 0)
		{
			old = mouseHieuChinhCB(old, *x, *y);
			i1 = 0;
			if (tcb[*ii * 8 + mouseHieuChinhCB(old, *x, *y)]->cb.trang_thai_cb != HOAN_TAT && tcb[*ii * 8 + mouseHieuChinhCB(old, *x, *y)]->cb.trang_thai_cb != HUY_CHUYEN) {
				ht = tcb[*ii * 8 + mouseHieuChinhCB(old, *x, *y)];
			}
			if (ht != NULL) {
				bar(619, 60, 854, 90);///ma chuyeb bay
				outtextxy(xg + 120, yg - 155, ht->cb.ma_cb);
				bar(994, 60, 1449, 90);//san bay den
				outtextxy(994, 65, ht->cb.san_bay_den);
				bar(610, 110, 640, 140);
				_itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, tam, 3, 10);
				outtextxy(610, 115, tam);
				bar(650, 110, 680, 140);
				_itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, tam, 3, 10);
				outtextxy(650, 115, tam);
				bar(695, 110, 725, 140);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, tam, 3, 10);
				outtextxy(695, 115, tam);
				bar(740, 110, 770, 140);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, tam, 3, 10);
				outtextxy(740, 115, tam);
				bar(780, 110, 830, 140);
				_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, tam, 5, 10);
				outtextxy(780, 115, tam);
				bar(1095, 110, 1320, 140);
				outtextxy(1095, 115, ht->cb.sh_Mb);
			}
		}
		if (ii1 != *ii) {
			i1 = 0; old = -1; *x = 0; *y = 0;
			bar(xg, yg, xg + getmaxx(), yg + getmaxy());
			for (int i = 0; i < 8; i++) {
				if (tcb[*ii * 8 + i] != NULL&& *ii * 8 + i < cd) {
					q = tcb[*ii * 8 + i];
					outtextxy(xg + 10, yg + 10 + kc * i, text[0]);
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10 + kc * i, text[1]);
					outtextxy(xg + 10, yg + 40 + kc * i, text[2]);
					outtextxy(xg + 10 + textwidth(text[2]) + 30, yg + 40 + kc * i, text[3]);
					outtextxy(xg + 335 + 170, yg + 40 + kc * i, text[4]);
					outtextxy(xg + 550 + 170, yg + 40 + kc * i, text[5]);
					///===========================================///
					outtextxy(xg + 10 + textwidth(text[0]) + 5, yg + 10 + kc * i, q->cb.ma_cb);
					outtextxy(xg + 10 + 225 + 50 + 120 + textwidth(text[1]), yg + 10 + kc * i, q->cb.san_bay_den);
					_itoa_s(q->cb.ngay_gio_kh.gio_kh.gio, tam, 225, 10);
					outtextxy(xg + 15 + 100, yg + 40 + kc * i, tam);///gio
					_itoa_s(q->cb.ngay_gio_kh.gio_kh.phut, tam, 225, 10);
					outtextxy(xg + 40 + 100, yg + 40 + kc * i, tam);///phut
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.ngay, tam, 225, 10);
					outtextxy(xg + 80 + 100, yg + 40 + kc * i, tam);///ngay
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.thang, tam, 225, 10);
					outtextxy(xg + 110 + 100, yg + 40 + kc * i, tam);///thang
					_itoa_s(q->cb.ngay_gio_kh.ngay_kh.nam, tam, 225, 10);
					outtextxy(xg + 140 + 100, yg + 40 + kc * i, tam);///nam
					switch (q->cb.trang_thai_cb)
					{
					case HUY_CHUYEN: {
						strcpy_s(tam, 225, "huy chuyen");
						break;
					}
					case CON_VE: {
						strcpy_s(tam, 225, "con ve");
						break;
					}
					case HET_VE: {
						strcpy_s(tam, 225, "het ve");
						break;
					}
					case HOAN_TAT: {
						strcpy_s(tam, 225, "hoan tat");
						break;
					}
					default:
						break;
					}
					outtextxy(xg + 295 + 100, yg + 40 + kc * i, tam);
					outtextxy(xg + 500 + 100, yg + 40 + kc * i, q->cb.sh_Mb);
					tm = TimSoHieu(q->cb.sh_Mb, ds_may_bay);
					_itoa_s(tm->so_day * tm->so_dong - q->cb.so_ve, tam, 100, 10);
					outtextxy(xg + 720 + 100, yg + 40 + kc * i, tam);
					if (q->cb.trang_thai_cb != HUY_CHUYEN && q->cb.trang_thai_cb != HOAN_TAT) {
						outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("HIEU CHINH"));
						rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 870 + 100, yg + 60 + kc * i);
					}					
					line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
					q = q->next;
				}
			}
			ii1 = *ii;
			_itoa_s(ii1 + 1, tam, 225, 10);
			outtextxy(xg + 10, getmaxy() - 30, tam);
			outtextxy(xg + 30, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			getimage(xg + 10, yg - 215, xg + 10 + 500, yg - 215 + 35, p1);
			putimage(xg + 10, yg - 215, p1, 1);
			free(p1);
			delete[]tcb;
			return;
		}
		if (mouseLocHieuChinhCB(*x, *y) == 2) {
			cd = 0;
			for (PTRChuyenBay chay = dau_chuyen_bay; chay != NULL; chay = chay->next) {
				if (strncmp(chay->cb.ma_cb, loc, strlen(loc)) == 0) {
					tcb[cd++] = chay;
				}
			}
			ii1 = -1;			
		}		
	}

}
int mouseHieuChinhCB(int old, int x, int y)
{
	int xg = 500, yg = 220, kc = 65;
	int n = (y - yg - 40) / kc;
	if (xg + 765 + 100 <= x && x <= xg + 870 + 100) {
		if (yg + 40 + kc * n <= y && y <= yg + 60 + kc * n) {
			return n;
		}
	}
	return old;
}
int mouseLocHieuChinhCB(int x, int y)
{
	int xg = 500, yg = 55;
	if (yg - 45 <= y && y <= yg - 45 + 30) {
		if (685 <= x && x <= 920) {
			return 1;
		}
		if (950 <= x && x <= 990) {
			return 2;
		}
	}
	return 0;
}
///====================khach hang==================================================================///
void DHdatVe(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y)
{
	int xg = 500, yg = 10, kc = 65;
	int ii = 0, cd = 0;
	PTRChuyenBay ht=NULL;
	for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next)
		if (p->cb.trang_thai_cb == CON_VE) {
			cd++;
		}
	PTRChuyenBay* chay = new PTRChuyenBay[cd];
	thread nhanh(chonChuyenBay, ref(dau_chuyen_bay), ref(ht), x, y, &ii, 0, chay, ref(cd));
	hienDSCB3(dau_chuyen_bay, ds_may_bay, x, y, &ii, 0, chay, cd);
	nhanh.join();
	delete[]chay;
	setbkcolor(0);
	char text[15][100]{};
	strcpy_s(text[0], 25, "Cmnd: ");
	strcpy_s(text[1], 25, "Ho: ");
	strcpy_s(text[2], 25, "Ten: ");
	strcpy_s(text[3], 25, "Phai: ");
	strcpy_s(text[4], 25,"Vi tri dat: ");
	strcpy_s(text[5], 25, "Thong tin nguoi dat ve: ");
	strcpy_s(text[6], 25, "Ma chuyen bay: ");
	strcpy_s(text[7], 100, "Ngay gio KH:         :                 /        /      ");
	strcpy_s(text[8], 25, "San bay den: ");
	strcpy_s(text[9], 50, "(1 la nam, 0 la nu)");
	///========///
	char nhap, ho[41]{}, ten[11]{}, cmnd[13]{}, phai[2]{}, vitri[10]{}, vtd[10]{}, so[5]{};
	int n[5]{ 0, 0,0,0,0 }, n1 = 0, id = 0, in = 0, ido = -1, ino = -1;
	if (ht != NULL) {
		ht->capnhap(ds_may_bay);
		if (ht->cb.trang_thai_cb != HUY_CHUYEN && ht->cb.trang_thai_cb != HOAN_TAT) {
			rectangle(xg, yg, xg + 610, yg + 90);
			outtextxy(xg + 15, yg + 15, text[1]);
			outtextxy(xg + 520, yg + 15, text[3]);
			outtextxy(xg + 15, yg + 55, text[2]);
			outtextxy(xg + 240, yg + 55, text[0]);
			outtextxy(xg + 700, yg + 55, text[4]);
			outtextxy(xg - 165, yg + 15, text[5]);
			outtextxy(xg - 165, yg + 95, text[6]);
			outtextxy(xg - 50, yg + 95, ht->cb.ma_cb);
			outtextxy(xg + 170, yg + 95, text[7]); _itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, so, 4, 10);
			outtextxy(xg + 275, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, so, 4, 10);
			outtextxy(xg + 305, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, so, 4, 10);
			outtextxy(xg + 345, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, so, 4, 10);
			outtextxy(xg + 380, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, so, 5, 10);
			outtextxy(xg + 415, yg + 95, so);
			outtextxy(xg + 460, yg + 95, text[8]);
			outtextxy(xg + 560, yg + 95, ht->cb.san_bay_den);
			outtextxy(xg + 620, yg + 15, text[9]);
			///======///
			rectangle(xg + 45, yg + 10, xg + 45 + 460, yg + 10 + 30);
			rectangle(xg + 560, yg + 10, xg + 560 + 40, yg + 10 + 30);
			rectangle(xg + 50, yg + 50, xg + 50 + 160, yg + 50 + 30);
			rectangle(xg + 300, yg + 50, xg + 300 + 160, yg + 50 + 30);
			rectangle(xg + 770, yg + 50, xg + 770 + 70, yg + 50 + 30);
			///=====///
			MayBay* mb = TimSoHieu(ht->cb.sh_Mb, ds_may_bay);
			setfillstyle(1, 0);
			PTRKhachhang kh = NULL;
			thread nhanh1(dongho, xg + 740, yg, x, y);
			Sleep(100);
			while (1) {
				if (in != ino || id != ido) {
					ino = in; ido = id;
					bar(xg - 130, yg + 140, getmaxx(), getmaxy());
					rectangle(xg - 130, yg + 140, getmaxx(), getmaxy());
					for (int i = 1; i <= 15; i++) {
						for (int j = 1; j <= 20; j++) {
							if (j + in * 20 <= mb->so_day && i + id * 15 <= mb->so_dong) {
								SapVe(vitri, j + in * 20, i + id * 15);
								for (int i = 0; i < ht->cb.so_ve; i++) {
									if (strcmp(ht->cb.ds_ve[i].vitri, vitri) == 0) {
										setbkcolor(4);
										break;
									}
								}
								outtextxy(xg + 55 * j - 170, yg + 130 + i * 40 - 20, vitri);
								setbkcolor(0);
							}
						}
					}
				}
				if ((int)(nhap = getch()) != 13 && (int)nhap != 0 && (int)nhap != 27) {
					n1 = mouseDatVe(*x, *y);
					switch (n1)
					{
					case 0: {
						if (('a' <= nhap && nhap <= 'z') || ('A' <= nhap && nhap <= 'Z') || (int)nhap == 32) {
							if (n[n1] < 40) {
								ho[n[n1] + 1] = ho[n[n1]];
								ho[n[n1]++] = nhap;
								if ((int)nhap != 32 && n[n1] != 0) {
									SuaTen(ho);
									n[n1] = strlen(ho);
								}
								outtextxy(xg + 50, yg + 15, ho);
							}
						}
						if ((int)nhap == 8) {
							xoachu(ho, xg + 50, yg + 15);
							if (n[n1] > 0) {
								ho[n[n1] - 1] = ho[n[n1]--];
							}
							outtextxy(xg + 50, yg + 15, ho);
						}
						break;
					}
					case 1: {
						if (nhap == '1' || nhap == '0') {
							if (n[n1] < 1) {
								phai[n[n1] + 1] = phai[n[n1]];
								phai[n[n1]++] = nhap;
								outtextxy(xg + 565, yg + 15, phai);
							}
						}
						if ((int)nhap == 8) {
							xoachu(phai, xg + 565, yg + 15);
							if (n[n1] > 0) {
								phai[n[n1] - 1] = phai[n[n1]--];
							}
							outtextxy(xg + 565, yg + 15, phai);
						}
						break;
					}
					case 2: {
						if (('a' <= nhap && nhap <= 'z') || ('A' <= nhap && nhap <= 'Z') || (int)nhap == 32) {
							if (n[n1] < 10) {
								ten[n[n1] + 1] = ten[n[n1]];
								ten[n[n1]++] = nhap;
								if ((int)nhap != 32 && n[n1] != 0) {
									SuaTen(ten);
									n[n1] = strlen(ten);
								}
								outtextxy(xg + 55, yg + 55, ten);
							}
						}
						if ((int)nhap == 8) {
							xoachu(ten, xg + 55, yg + 55);
							if (n[n1] > 0) {
								ten[n[n1] - 1] = ten[n[n1]--];
							}
							outtextxy(xg + 55, yg + 55, ten);
						}
						break;
					}
					case 3: {
						if ('0' <= nhap && nhap <= '9') {
							if (n[n1] < 12) {
								cmnd[n[n1] + 1] = cmnd[n[n1]];
								cmnd[n[n1]++] = nhap;
								outtextxy(xg + 305, yg + 55, cmnd);
							}
						}
						if ((int)nhap == 8) {
							xoachu(cmnd, xg + 305, yg + 55);
							if (n[n1] > 0) {
								cmnd[n[n1] - 1] = cmnd[n[n1]--];
							}
							outtextxy(xg + 305, yg + 55, cmnd);
						}
						break;
					}
					case 4: {
						if (('a' <= nhap && nhap <= 'z') || ('A' <= nhap && nhap <= 'Z') || ('0' <= nhap && nhap <= '9')) {
							if (n[n1] < 4) {
								nhap = toupper(nhap);
								vtd[n[n1] + 1] = vtd[n[n1]];
								vtd[n[n1]++] = nhap;
								outtextxy(xg + 775, yg + 55, vtd);
							}
						}
						if ((int)nhap == 8) {
							xoachu(vtd, xg + 775, yg + 55);
							if (n[n1] > 0) {
								vtd[n[n1] - 1] = vtd[n[n1]--];
							}
							outtextxy(xg + 775, yg + 55, vtd);
						}
						break;

					}
					default:
						break;
					}
				}
				if ((int)nhap == 0) {
					nhap = getch();
					switch ((int)nhap)
					{
					case 75: {//trai
						if (in > 0)in--;
						break;
					}
					case 72: {//len
						if (id > 0)id--;
						break;
					}case 77: {//phai
						if (in * 20 - mb->so_day < -10)
							in++;
						break;
					}case 80: {//xuong
						if (id * 15 - mb->so_dong < -10)
							id++;
						break;
					}
					default:
						break;
					}
				}
				if ((int)nhap == 13) {
					if (cmnd[0] != '\0' && ho[0] == '\0' && ten[0] == '\0' && phai[0] == '\0') {
						kh = timKhachHang(goc_khach_hang, cmnd);
						if (kh != NULL) {
							strcpy_s(ho, 40, kh->info.ho); n[0] = strlen(ho);
							strcpy_s(ten, 10, kh->info.ten); n[2] = strlen(ten);
							_itoa_s((int)kh->info.phai, phai, 2, 10); n[1] = 1; n[3] = strlen(kh->info.cmnd);
							outtextxy(xg + 50, yg + 15, ho);
							outtextxy(xg + 565, yg + 15, phai);
							outtextxy(xg + 55, yg + 55, ten);
							if (vtd[0] != '\0' && capNhapTT(ht->cb.ngay_gio_kh) != HOAN_TAT) {
								int x, y;
								SapVeNguoc(vtd, x, y);
								if (0 < x && x <= mb->so_day && 0 < y && y <= mb->so_dong) {
									bool d = 1, a = 0, b = 0;
									for (int i = 0; i < ht->cb.so_ve; i++) {
										if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0 || strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
											if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0) {
												a = 1;
											}
											if (strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
												b = 1;
											}
											d = 0; break;
										}
									}
									if (d == 1) {
										ht->cb.ds_ve[ht->cb.so_ve++].DatVe(cmnd, vtd);
										ido = -1;
										ino = -1;
										outtextxy(xg, yg + 120, const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"));
										getch();
										xoachu(const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
										if (ht->cb.so_ve >= mb->so_day * mb->so_dong) {
											outtextxy(xg, yg + 120, const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"));
											getch();
											xoachu(const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
										}
									}
									else {
										if (a == 1 && b == 1) {
											outtextxy(xg, yg + 120, const_cast<char*>("khach hang da dat ve chuyen bay nay va vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"));
											getch();
											xoachu(const_cast<char*>("khach hang da dat ve chuyen bay nay va vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
										}
										else
											if (a == 1 && b == 0) {
												outtextxy(xg, yg + 120, const_cast<char*>("khach hang da dat ve chuyen bay nay, NHAN PHIM BAT KY DE TIEP TUC"));
												getch();
												xoachu(const_cast<char*>("khach hang da dat ve chuyen bay nay, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											}
											else
												if (a == 0 && b == 1) {
													outtextxy(xg, yg + 120, const_cast<char*>("vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"));
													getch();
													xoachu(const_cast<char*>("vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
												}
									}
								}
								else {
									outtextxy(xg, yg + 120, const_cast<char*>("vi tri khong hop le, NHAN PHIM BAT KY DE TIEP TUC"));
									getch();
									xoachu(const_cast<char*>("vi tri khong hop le, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
								}
							}
							else {
								if (capNhapTT(ht->cb.ngay_gio_kh) == HOAN_TAT) {
									outtextxy(xg, yg + 120, const_cast<char*>("da qua thoi gian dat ve, NHAN PHIM BAT KY DE TIEP TUC"));
									getch();
									xoachu(const_cast<char*>("da qua thoi gian dat ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
								}
							}
						}
						else {
							outtextxy(xg, yg + 120, const_cast<char*>("ko tim thay khach hang nay, nhan phim bat ki de tiep tuc"));
							getch();
							xoachu(const_cast<char*>("ko tim thay khach hanh nay, nhan phim bat ki de tiep tuc"), xg, yg + 120);
						}
					}
					else
						if (cmnd[0] != '\0' && ho[0] != '\0' && ten[0] != '\0' && phai[0] != '\0') {
							kh = timKhachHang(goc_khach_hang, cmnd);
							if (kh != NULL && (strcmp(kh->info.ho, ho) != 0
								|| strcmp(kh->info.ten, ten) != 0 || atoi(phai) != (int)kh->info.phai)) {
								outtextxy(xg, yg + 120, const_cast<char*>("thong tin khong khop voi cmnd, nhan phim bat ki de tiep tuc"));
								getch();
								xoachu(const_cast<char*>("thong tin khong khop voi cmnd, nhan phim bat ki de tiep tuc"), xg, yg + 120);
							}
							else if (kh == NULL) {
								KhachHang tam;
								tam.datKhachHang(cmnd, ho, ten, (bool)atoi(phai));
								if (vtd[0] != '\0' && capNhapTT(ht->cb.ngay_gio_kh) != HOAN_TAT) {
									int x, y;
									SapVeNguoc(vtd, x, y);
									if (0 < x && x <= mb->so_day && 0 < y && y <= mb->so_dong) {
										bool d = 1;
										for (int i = 0; i < ht->cb.so_ve; i++) {
											if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0 || strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
												d = 0; break;
											}
										}
										if (d == 1) {
											ht->cb.ds_ve[ht->cb.so_ve++].DatVe(cmnd, vtd);
											ido = -1;
											ino = -1;
											outtextxy(xg, yg + 120, const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"));
											getch();
											xoachu(const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											if (ht->cb.so_ve >= mb->so_day * mb->so_dong) {
												outtextxy(xg, yg + 120, const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"));
												getch();
												xoachu(const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											}
										}
										else {
											outtextxy(xg, yg + 120, const_cast<char*>("khach hang da dat ve chuyen bay nay hoac vi tri da dc dat, nhan phim bat ky de tiep tuc"));
											getch();
											xoachu(const_cast<char*>("khach hang da dat ve chuyen bay nay hoac vi tri da dc dat, nhan phim bat ky de tiep tuc"), xg, yg + 120);
										}
									}
									else {
										outtextxy(xg, yg + 120, const_cast<char*>("vi tri khong hop le"));
										Sleep(1500);
										xoachu(const_cast<char*>("vi tri khong hop le"), xg, yg + 120);
									}
								}
								else {
									if (capNhapTT(ht->cb.ngay_gio_kh) == HOAN_TAT) {
										outtextxy(xg, yg + 120, const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"));
										getch();
										xoachu(const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
									}
								}
								themKhachHang(goc_khach_hang, tam);
								outtextxy(xg, yg + 120, const_cast<char*>("da them vao ds khach hang"));
								Sleep(1500);
								xoachu(const_cast<char*>("da them vao ds khach hang"), xg, yg + 120);
							}
							else if (kh != NULL) {
								if (vtd[0] != '\0' && capNhapTT(ht->cb.ngay_gio_kh) != HOAN_TAT) {
									int x, y;
									SapVeNguoc(vtd, x, y);
									if (0 < x && x <= mb->so_day && 0 < y && y <= mb->so_dong) {
										bool d = 1, a = 0, b = 0;
										for (int i = 0; i < ht->cb.so_ve; i++) {
											if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0 || strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
												d = 0;
												if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0) {
													a = 1;
												}
												if (strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
													b = 1;
												}
												break;
											}
										}
										if (d == 1) {
											ht->cb.ds_ve[ht->cb.so_ve++].DatVe(cmnd, vtd);
											ido = -1;
											ino = -1;
											outtextxy(xg, yg + 120, const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"));
											getch();
											xoachu(const_cast<char*>("dat ve thanh cong, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											if (ht->cb.so_ve >= mb->so_day * mb->so_dong) {
												outtextxy(xg, yg + 120, const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"));
												getch();
												xoachu(const_cast<char*>("chuyen bay da het ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											}
										}
										else {
											if (a == 1 && b == 1) {
												outtextxy(xg, yg + 120, const_cast<char*>("khach hang da dat ve chuyen bay nay va vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"));
												getch();
												xoachu(const_cast<char*>("khach hang da dat ve chuyen bay nay va vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
											}
											else
												if (a == 1 && b == 0) {
													outtextxy(xg, yg + 120, const_cast<char*>("khach hang da dat ve chuyen bay nay, NHAN PHIM BAT KY DE TIEP TUC"));
													getch();
													xoachu(const_cast<char*>("khach hang da dat ve chuyen bay nay, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
												}
												else
													if (a == 0 && b == 1) {
														outtextxy(xg, yg + 120, const_cast<char*>("vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"));
														getch();
														xoachu(const_cast<char*>("vi tri da dc dat, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
													}
										}
									}
									else {
										outtextxy(xg, yg + 120, const_cast<char*>("vi tri khong hop le"));
										Sleep(1500);
										xoachu(const_cast<char*>("vi tri khong hop le"), xg, yg + 120);
									}
								}
								else {
									if (capNhapTT(ht->cb.ngay_gio_kh) == HOAN_TAT) {
										outtextxy(xg, yg + 120, const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"));
										getch();
										xoachu(const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
									}
								}
							}
						}
					if (cmnd[0] == '\0') {
						outtextxy(xg, yg + 120, const_cast<char*>("CMND khong dc de trong, nhan phim bat ky de tiep tuc"));
						getch();
						xoachu(const_cast<char*>("CMND khong dc de trong, nhan phim bat ky de tiep tuc"), xg, yg + 120);
					}
				}
				if ((int)nhap == 27 || (*x == -10 && *y == -10)) {
					bar(xg - 165, yg, xg + 850, yg + 101);
					bar(xg - 170, yg + 100, getmaxx(), getmaxy());
					if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
					setbkcolor(0);
					break;
				}
			}
			nhanh1.join();
		}
		else {
			outtextxy(xg, yg, const_cast<char*>("CHUYEN BAY DA HOAN TAT HOAC DA HUY CHUYEN"));
			Sleep(1500);
			xoachu(const_cast<char*>("CHUYEN BAY DA HOAN TAT HOAC DA HUY CHUYEN"), xg, yg);
		}
	}
}
void chonChuyenBay(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay& ht, int* x, int* y, int* ii, int option, PTRChuyenBay chay[], int& cd)
{
	int xg = 250, yg = 70, kc = 65;
	settextstyle(3, HORIZ_DIR, 1);
	char text[5][225]{};
	strcpy_s(text[0], 100, "you con muon chon ");
	strcpy_s(text[1], 100, "chuyen bay nay: ");
	strcpy_s(text[2], 100, " xac nhan");
	strcpy_s(text[3], 100, " huy bo");
	PTRChuyenBay p; 
	int n;
	void* q = malloc(imagesize(xg, yg, xg + 240, yg + 120));
	while (1) {
		n = mouseChonCB(*x, *y);
		if (*ii * 10 + n < cd && n >= 0)
		{
			int i = 0;			
			p = chay[*ii * 10 + n];
			if (p != NULL) {
				rectangle(xg, yg, xg + 240, yg + 120);
				outtextxy(xg + 10, yg + 5, text[0]);
				outtextxy(xg + 10, yg + 5 + 20, text[1]);
				outtextxy(xg + 10, yg + 50, p->cb.ma_cb);
				outtextxy(xg + 10, yg + 80, text[2]);
				outtextxy(xg + 10 + 150, yg + 80, text[3]);
				///=======================================///
				rectangle(xg + 10, yg + 80, xg + 10 + 75, yg + 80 + 25);
				rectangle(xg + 10 + 150, yg + 80, xg + 10 + 150 + 65, yg + 80 + 25);
				while (1) {
					if (mouseChonCB(*x,*y) == -1) {
						getimage(xg, yg, xg + 240, yg + 120, q);
						putimage(xg, yg, q, 1);
						ht = p;
						free(q);
						*x = -1; *y = -1;
						outtextxy(xg + 300, getmaxy() - 35, const_cast<char*>("nhap phim tuy y de tiep tuc"));
						return;
					}
					else if (mouseChonCB(*x, *y) == -2) {
						getimage(xg, yg, xg + 240, yg + 120, q);
						putimage(xg, yg, q, 1);
						break;
					}
					else if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
						getimage(xg, yg, xg + 240, yg + 120, q);
						putimage(xg, yg, q, 1);
						free(q);
						return;
					}
				}
			}
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg, yg, xg + 240, yg + 120, q);
			putimage(xg, yg, q, 1);
			free(q);
			return;
		}
	}
}
void hienDSCB3(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int* x, int* y, int* ii, int option, PTRChuyenBay chay[], int& cd)
{
	int xg = 500, yg = 70, kc = 65;
	char text[7][225]{};
	void* p = malloc(imagesize(xg - 1, yg - 1, xg + getmaxx(), yg + getmaxy()));
	void* p1 = malloc(imagesize(xg + 5, yg + 5 - 55, xg + 10 + 300 + 50 + 550, yg + 10 + 25 - 55));
	settextstyle(3, HORIZ_DIR, 1);
	setbkcolor(1);
	setfillstyle(1, 0);
	rectangle(xg-1, yg-1, xg + getmaxx(), yg + getmaxy());
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:        :                /       /     ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	///==================================================================================///
	char text1[7][225]{};
	setbkcolor(0);
	strcpy_s(text1[0], 40, "Ma chuyen bay: ");
	strcpy_s(text1[1], 40, "San bay den:");
	strcpy_s(text1[2], 225, "Ngay gio KH:                      /          /       ");
	strcpy_s(text1[3], 40, "Trang thai CB: ");
	strcpy_s(text1[4], 40, "So hieu MB: ");
	strcpy_s(text1[5], 100, "So ve con lai: ");
	///
	outtextxy(xg + 10, yg + 10 - 55, text1[2]);
	rectangle(xg + 55 + 100, yg + 5 - 55, xg + 55 + 30 + 100, yg + 10 + 25 - 55);///ngay
	rectangle(xg + 100 + 100, yg + 5 - 55, xg + 100 + 30 + 100, yg + 10 + 25 - 55);///thang
	rectangle(xg + 140 + 100, yg + 5 - 55, xg + 140 + 50 + 100, yg + 10 + 25 - 55);///nam
	///
	outtextxy(xg + 10 + 300 + 50, yg + 10 - 55, text[1]);
	rectangle(xg + 10 + 300 + 50 + 95, yg + 5 - 55, xg + 10 + 300 + 50 + 550, yg + 10 + 25 - 55);
	///===================================================================================///
	PTRChuyenBay q;
	int i1 = 0, k, i[5]{ 0,0,0,0,0 };
	char tam[225], nhap = 0;
	MayBay* tm = nullptr;
	q = dau_chuyen_bay;
	for (q = dau_chuyen_bay; q != NULL; q = q->next) {
		switch (option)
		{
		case 0: {
			if (q->cb.trang_thai_cb == CON_VE) {
				chay[i1++] = q;
			}
			break;
		}
		case 1: {
			if (q->cb.trang_thai_cb != HOAN_TAT && q->cb.trang_thai_cb != HUY_CHUYEN) {
				chay[i1++] = q;
			}
			break;
		}
		case 2: {
			chay[i1++] = q;
			break;
		}
		default:
			break;
		}
		
	}
	i1 = 0;
	int io = -1, n = -1, tam1;
	char ngay[3]{}, thang[3]{}, nam[5]{}, sbd[100]{};
	while (1) {
		if (io != *ii) {
			io = *ii;
			bar(xg, yg, xg + getmaxx(), yg + getmaxy());
			for (int i = 0; i < 10; i++) {
				if (chay[*ii * 10 + i] != NULL && *ii * 10 + i < cd) {
					outtextxy(xg + 10, yg + 10 + kc * i, text[0]);
					outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10 + kc * i, text[1]);
					outtextxy(xg + 10, yg + 40 + kc * i, text[2]);
					outtextxy(xg + 10 + textwidth(text[2]) + 30, yg + 40 + kc * i, text[3]);
					outtextxy(xg + 320 + 170, yg + 40 + kc * i, text[4]);
					outtextxy(xg + 550 + 170, yg + 40 + kc * i, text[5]);
					///===========================================///
					outtextxy(xg + 10 + textwidth(text[0]) + 5, yg + 10 + kc * i, chay[*ii * 10 + i]->cb.ma_cb);
					outtextxy(xg + 10 + 225 + 50 + 120 + textwidth(text[1]), yg + 10 + kc * i, chay[*ii * 10 + i]->cb.san_bay_den);
					_itoa_s(chay[*ii * 10 + i]->cb.ngay_gio_kh.gio_kh.gio, tam, 225, 10);
					outtextxy(xg + 15 + 100, yg + 40 + kc * i, tam);///gio
					_itoa_s(chay[*ii * 10 + i]->cb.ngay_gio_kh.gio_kh.phut, tam, 225, 10);
					outtextxy(xg + 40 + 100, yg + 40 + kc * i, tam);///phut
					_itoa_s(chay[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.ngay, tam, 225, 10);
					outtextxy(xg + 80 + 100, yg + 40 + kc * i, tam);///ngay
					_itoa_s(chay[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.thang, tam, 225, 10);
					outtextxy(xg + 110 + 100, yg + 40 + kc * i, tam);///thang
					_itoa_s(chay[*ii * 10 + i]->cb.ngay_gio_kh.ngay_kh.nam, tam, 225, 10);
					outtextxy(xg + 140 + 100, yg + 40 + kc * i, tam);///nam
					switch (chay[*ii * 10 + i]->cb.trang_thai_cb)
					{
					case HUY_CHUYEN: {
						strcpy_s(tam, 225, "huy chuyen");
						break;
					}
					case CON_VE: {
						strcpy_s(tam, 225, "con ve");
						break;
					}
					case HET_VE: {
						strcpy_s(tam, 225, "het ve");
						break;
					}
					case HOAN_TAT: {
						strcpy_s(tam, 225, "hoan tat");
						break;
					}
					default:
						break;
					}
					outtextxy(xg + 295 + 100, yg + 40 + kc * i, tam);
					outtextxy(xg + 485 + 100, yg + 40 + kc * i, chay[*ii * 10 + i]->cb.sh_Mb);
					tm = TimSoHieu(chay[*ii * 10 + i]->cb.sh_Mb, ds_may_bay);
					_itoa_s(tm->so_day * tm->so_dong - chay[*ii * 10 + i]->cb.so_ve, tam, 100, 10);
					outtextxy(xg + 720 + 100, yg + 40 + kc * i, tam);
					outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("XAC NHAN"));
					rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 880 + 100, yg + 60 + kc * i);
					line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
				}
			}
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			getimage(xg - 1, yg - 1, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg - 1, yg - 1, p, 1);
			getimage(xg + 5, yg + 5 - 55, xg + 10 + 300 + 50 + 550, yg + 10 + 25 - 55, p1);
			putimage(xg + 5, yg + 5 - 55, p1, 1);
			free(p1);
			free(p);
			return;
		}
		if ((int)(nhap = getch()) != 13 && (int)nhap != 0 && (int)nhap != 27) {
			n = mouseHienDSCB(*x, *y);
			switch (n)
			{
			case 0: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 2) {
					ngay[i[n] + 1] = ngay[i[n]];
					ngay[i[n]++] = nhap;
					tam1 = atoi(ngay);
					if (tam1 >= 32) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 60 + 100, yg + 10 - 55, ngay);
				}
				if ((int)nhap == 8) {
					xoachu(ngay, xg + 60 + 100, yg + 10 - 55);
					if (i[n] > 0) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 60 + 100, yg + 10 - 55, ngay);
				}
				break;
			}
			case 1: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 2) {
					thang[i[n] + 1] = thang[i[n]];
					thang[i[n]++] = nhap;
					tam1 = atoi(thang);
					if (tam1 >= 13) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 105 + 100, yg + 10 - 55, thang);
				}
				if ((int)nhap == 8) {
					xoachu(thang, xg + 105 + 100, yg + 10 - 55);
					if (i[n] > 0) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 105 + 100, yg + 10 - 55, thang);
				}
				break;
			}
			case 2: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 4) {
					nam[i[n] + 1] = nam[i[n]];
					nam[i[n]++] = nhap;
					outtextxy(xg + 145 + 100, yg + 10 - 55, nam);
				}
				if ((int)nhap == 8) {
					xoachu(nam, xg + 145 + 100, yg + 10 - 55);
					if (i[n] > 0) {
						nam[i[n] - 1] = nam[i[n]--];
					}
					outtextxy(xg + 145 + 100, yg + 10 - 55, nam);
				}
				break;
			}
			case 3: {
				if (i[n] < 100) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9')) || (int)nhap == 32) {
					sbd[i[n] + 1] = sbd[i[n]];
					sbd[i[n]++] = nhap;
					if ((int)nhap != 32 && i[n] != 0) {
						SuaTen(sbd);
						i[n] = strlen(sbd);
					}
					outtextxy(xg + 15 + 300 + 50 + 95, yg + 10 - 55, sbd);
				}
				if ((int)nhap == 8) {
					xoachu(sbd, xg + 15 + 300 + 50 + 95, yg + 10 - 55);
					if (i[n] > 0) {
						sbd[i[n] - 1] = sbd[i[n]--];
					}
					outtextxy(xg + 15 + 300 + 50 + 95, yg + 10 - 55, sbd);
				}
				break;
			}
			default:
				break;
			}
		}
		if ((int)nhap == 13) {
			if (ngay[0] != '\0' || thang[0] != '\0' || nam[0] != '\0') {
				if (ngay[0] != '\0' && thang[0] != '\0' && nam[0] != '\0') {
					NgayGio test;
					test.datNgayGio(0, 0, atoi(ngay), atoi(thang), atoi(nam));
					if (test.checkNgayGio() == 0) {
						setbkcolor(1);
						outtextxy(xg + 100, yg + 100, const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
						setbkcolor(0);
					}
				}
				if (ngay[0] != '\0' && thang[0] != '\0' && nam[0] == '\0') {
					NgayGio test;
					test.datNgayGio(0, 0, atoi(ngay), atoi(thang), 2004);
					if (test.checkNgayGio() == 0) {
						setbkcolor(1);
						outtextxy(xg + 100, yg + 100, const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						xoachu(const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg + 100, yg + 100);
						setbkcolor(0);
					}
				}
			}
			cd = 0;
			for (q = dau_chuyen_bay; q != NULL; q = q->next) {					
				switch (option)
				{
				case 0: {
					if (q->cb.trang_thai_cb == CON_VE) {
						if ((ngay[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.ngay == atoi(ngay)) && (thang[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.thang == atoi(thang))
							&& (nam[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.nam == atoi(nam)) && (sbd[0] == '\0' || strcmp(sbd, q->cb.san_bay_den) == 0)) {
							chay[cd++] = q;
						}
					}
					break;
				}
				case 1: {
					if (q->cb.trang_thai_cb != HOAN_TAT && q->cb.trang_thai_cb != HUY_CHUYEN) {
						if ((ngay[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.ngay == atoi(ngay)) && (thang[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.thang == atoi(thang))
							&& (nam[0] == '\0' || q->cb.ngay_gio_kh.ngay_kh.nam == atoi(nam)) && (sbd[0] == '\0' || strcmp(sbd, q->cb.san_bay_den) == 0)) {
							chay[cd++] = q;
						};
					}
					break;
				}
				case 2: {
					chay[i1++] = q;
					break;
				}
				default:
					break;
				}
			}
			io = -1;
		}
		if ((int)nhap == 0)	if (!(*ii * 10 + mouseChonCB(*x, *y) < cd && mouseChonCB(*x, *y) >= 0)) {
			*x = -2; *y = -2;
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii * 10 - cd < 0) {
					k = *ii;
					k++;
					*ii = k;
					bar(xg, yg, getmaxx(), getmaxy());
				}
			}
			if ((int)nhap == 75) {
				if (*ii > 0) {
					k = *ii;
					k--;
					*ii = k;
					bar(xg, yg, getmaxx(), getmaxy());
				}
			}
		}
		if ((int)nhap == 27) {
			getimage(xg - 1, yg - 1, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg - 1, yg - 1, p, 1);
			getimage(xg + 5, yg + 5 - 55, xg + 10 + 300 + 50 + 550, yg + 10 + 25 - 55, p1);
			putimage(xg + 5, yg + 5 - 55, p1, 1);
			free(p1);
			free(p);
			*x = -1; *y = -1;
			return;
		}			
	}
}
int mouseChonCB(int x, int y)
{
	int xg = 500, yg = 70, kc = 65;
	if (xg + 765 + 100 <= x && x <= xg + 880 + 100) {
		int n = (y - yg - 40) / kc;
		if (yg + 40 + kc * n <= y && y <= yg + 60 + kc * n) {
			return n;
		}
	}
	if (150 <= y && y <= 175) {
		if ( 260 <= x && x <=  335) {
			return -1;
		}
		if (410 <= x && x <= 475) {
			return -2;
		}
	}
	return -5;
}
int mouseDatVe(int x, int y)
{
	int xg = 500, yg = 10, kc = 65;
	if (yg + 10 <= y && y <= yg + 10 + 30) {
		if (xg + 45 <= x && x <= xg + 45 + 460) {
			return 0;
		}
		if (xg + 560 <= x && x <= xg + 560 + 40) {
			return 1;
		}
	}
	if (yg + 50 <= y && y <= yg + 50 + 30) {
		if (xg + 50 <= x && x <= xg + 50 + 160) {
			return 2;
		}
		if (xg + 300 <= x && x <= xg + 300 + 160) {
			return 3;
		}
		if (xg + 770 <= x && x <= xg + 770 + 70) {
			return 4;
		}
	}
	return -1;
}
void DHhuyVe(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y)
{
	int xg = 500, yg = 10, kc = 65;
	int ii = 0, cd = 0;
	PTRChuyenBay ht = NULL;
	for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next)
		if (p->cb.trang_thai_cb != HOAN_TAT && p->cb.trang_thai_cb != HUY_CHUYEN) {
			cd++;
		}
	PTRChuyenBay* chay = new PTRChuyenBay[cd];
	thread nhanh(chonChuyenBay, ref(dau_chuyen_bay), ref(ht), x, y, &ii, 1, chay, ref(cd));
	hienDSCB3(dau_chuyen_bay, ds_may_bay, x, y, &ii, 1, chay, cd);
	nhanh.join();
	delete[]chay;
	setbkcolor(0);
	setfillstyle(1, 0);
	char text[11][100]{};
	strcpy_s(text[0], 25, "Cmnd: ");
	strcpy_s(text[1], 25, "Ho: ");
	strcpy_s(text[2], 25, "Ten: ");
	strcpy_s(text[3], 25, "Phai: ");
	strcpy_s(text[4], 25, "Vi tri huy: ");
	strcpy_s(text[5], 25, "Thong tin nguoi huy ve: ");
	strcpy_s(text[6], 100, "You that su huy ve:            nhan enter de huy ve;          nhan phim khac de ko huy ve;   ");
	strcpy_s(text[7], 25, "Ma chuyen bay: ");
	strcpy_s(text[8], 100, "Ngay gio KH:         :                 /        /      ");
	strcpy_s(text[9], 25, "San bay den: ");
	strcpy_s(text[10], 50, "(1 la nam, 0 la nu)");
	///========///
	char nhap, ho[41]{}, ten[11]{}, cmnd[13]{}, phai[2]{}, vitri[10]{}, vtd[10]{}, so[5]{};
	int n[5]{ 0, 0,0,0,0 }, n1 = 0, id = 0, in = 0, ido = -1, ino = -1;
	PTRKhachhang kh;	
	if (ht != NULL) {
		ht->capnhap(ds_may_bay);
		if (ht->cb.trang_thai_cb != HOAN_TAT && ht->cb.trang_thai_cb != HUY_CHUYEN) {
			rectangle(xg, yg, xg + 610, yg + 90);
			outtextxy(xg + 15, yg + 15, text[1]);
			outtextxy(xg + 520, yg + 15, text[3]);
			outtextxy(xg + 15, yg + 55, text[2]);
			outtextxy(xg + 240, yg + 55, text[0]);
			outtextxy(xg + 700, yg + 55, text[4]);
			outtextxy(xg - 175, yg + 15, text[5]);
			outtextxy(xg - 165, yg + 95, text[7]);
			outtextxy(xg - 50, yg + 95, ht->cb.ma_cb);
			outtextxy(xg + 170, yg + 95, text[8]); _itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, so, 4, 10);
			outtextxy(xg + 275, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, so, 4, 10);
			outtextxy(xg + 305, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, so, 4, 10);
			outtextxy(xg + 345, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, so, 4, 10);
			outtextxy(xg + 380, yg + 95, so); _itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, so, 5, 10);
			outtextxy(xg + 415, yg + 95, so);
			outtextxy(xg + 460, yg + 95, text[9]);
			outtextxy(xg + 560, yg + 95, ht->cb.san_bay_den);
			outtextxy(xg + 620, yg + 15, text[10]);
			///======///
			rectangle(xg + 45, yg + 10, xg + 45 + 460, yg + 10 + 30);
			rectangle(xg + 560, yg + 10, xg + 560 + 40, yg + 10 + 30);
			rectangle(xg + 50, yg + 50, xg + 50 + 160, yg + 50 + 30);
			rectangle(xg + 300, yg + 50, xg + 300 + 160, yg + 50 + 30);
			rectangle(xg + 770, yg + 50, xg + 770 + 70, yg + 50 + 30);
			///=====///
			thread nhanh1(dongho, xg + 740, yg, x, y);
			Sleep(100);
			MayBay* mb = TimSoHieu(ht->cb.sh_Mb, ds_may_bay);
			while (1) {
				if (in != ino || id != ido) {
					ino = in; ido = id;
					bar(xg - 170, yg + 120, getmaxx(), getmaxy());
					rectangle(xg - 130, yg + 140, getmaxx(), getmaxy());
					for (int i = 1; i <= 15; i++) {
						for (int j = 1; j <= 20; j++) {
							if (j + in * 20 <= mb->so_day && i + id * 15 <= mb->so_dong) {
								SapVe(vitri, j + in * 20, i + id * 15);
								for (int i = 0; i < ht->cb.so_ve; i++) {
									if (strcmp(ht->cb.ds_ve[i].vitri, vitri) == 0) {
										setbkcolor(4);
										break;
									}
								}
								outtextxy(xg + 55 * j - 170, yg + 130 + i * 40 - 20, vitri);
								setbkcolor(0);
							}
						}
					}
				}
				if ((int)(nhap = getch()) != 13 && (int)nhap != 0 && (int)nhap != 27) {
					n1 = mouseDatVe(*x, *y);
					switch (n1)
					{
					case 3: {
						if ('0' <= nhap && nhap <= '9') {
							if (n[n1] < 12) {
								cmnd[n[n1] + 1] = cmnd[n[n1]];
								cmnd[n[n1]++] = nhap;
								outtextxy(xg + 305, yg + 55, cmnd);
							}
						}
						if ((int)nhap == 8) {
							xoachu(cmnd, xg + 305, yg + 55);
							if (n[n1] > 0) {
								cmnd[n[n1] - 1] = cmnd[n[n1]--];
							}
							outtextxy(xg + 305, yg + 55, cmnd);
						}
						break;
					}
					case 4: {
						if (('a' <= nhap && nhap <= 'z') || ('A' <= nhap && nhap <= 'Z') || ('0' <= nhap && nhap <= '9')) {
							if (n[n1] < 4) {
								nhap = toupper(nhap);
								vtd[n[n1] + 1] = vtd[n[n1]];
								vtd[n[n1]++] = nhap;
								outtextxy(xg + 775, yg + 55, vtd);
							}
						}
						if ((int)nhap == 8) {
							xoachu(vtd, xg + 775, yg + 55);
							if (n[n1] > 0) {
								vtd[n[n1] - 1] = vtd[n[n1]--];
							}
							outtextxy(xg + 775, yg + 55, vtd);
						}
						break;

					}
					default:
						break;
					}
				}
				if ((int)nhap == 0) {
					nhap = getch();
					switch ((int)nhap)
					{
					case 75: {//trai
						if (in > 0)in--;
						break;
					}
					case 72: {//len
						if (id > 0)id--;
						break;
					}case 77: {//phai
						if (in * 20 - mb->so_day < -10)
							in++;
						break;
					}case 80: {//xuong
						if (id * 15 - mb->so_dong < -10)
							id++;
						break;
					}
					default:
						break;
					}
				}
				if ((int)nhap == 13) {
					if (cmnd[0] != '\0' && vtd[0] == '\0') {
						kh = timKhachHang(goc_khach_hang, cmnd);
						if (capNhapTT(ht->cb.ngay_gio_kh) == HOAN_TAT) {
							outtextxy(xg, yg + 120, const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);							
						}else
						if (kh == NULL) {
							outtextxy(xg, yg + 120, const_cast<char*>("ko co khach hang nay tren chuyen bay, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("ko co khach hang nay tren chuyen bay, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
						}
						else {
							for (int i = 0; i < ht->cb.so_ve; i++) {
								if (strcmp(ht->cb.ds_ve[i].cmnd, cmnd) == 0) {
									outtextxy(xg + 50, yg + 15, kh->info.ho);
									_itoa_s((int)kh->info.phai, phai, 2, 10);
									outtextxy(xg + 565, yg + 15, phai);
									outtextxy(xg + 55, yg + 55, kh->info.ten);
									outtextxy(xg + 775, yg + 55, ht->cb.ds_ve[i].vitri);
									outtextxy(xg, yg + 120, text[6]);
									if ((int)(nhap = getch()) == 13) {
										for (int j = i; j < ht->cb.so_ve; j++) {
											ht->cb.ds_ve[j] = ht->cb.ds_ve[j + 1];
										}
										ht->cb.so_ve--;
									}
									ino = -1;
									ido = -1;
									xoachu(text[6], xg, yg + 120);
									xoachu(kh->info.ho, xg + 50, yg + 15);
									xoachu(phai, xg + 565, yg + 15);
									xoachu(kh->info.ten, xg + 55, yg + 55);
									xoachu(ht->cb.ds_ve[i].vitri, xg + 775, yg + 55);
									break;
								}
							}
							if (ino != -1) {
								outtextxy(xg, yg + 120, const_cast<char*>("khach hang nay ko dat ve tren chuyen bay, NHAN PHIM BAT KY DE TIEP TUC"));
								getch();
								xoachu(const_cast<char*>("khach hang nay ko dat ve tren chuyen bay, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
							}
						}
					}
					else if (cmnd[0] == '\0' && vtd[0] != '\0') {
						int n, m;
						if (capNhapTT(ht->cb.ngay_gio_kh) != HOAN_TAT) {
							SapVeNguoc(vtd, n, m);
							if (0 < n && n <= mb->so_day && 0 < m && m <= mb->so_dong) {
								SapVe(vtd, n, m);
								for (int i = 0; i < ht->cb.so_ve; i++) {
									if (strcmp(ht->cb.ds_ve[i].vitri, vtd) == 0) {
										kh = timKhachHang(goc_khach_hang, ht->cb.ds_ve[i].cmnd);
										outtextxy(xg + 50, yg + 15, kh->info.ho);
										_itoa_s((int)kh->info.phai, phai, 2, 10);
										outtextxy(xg + 565, yg + 15, phai);
										outtextxy(xg + 55, yg + 55, kh->info.ten);
										outtextxy(xg + 305, yg + 55, kh->info.cmnd);
										outtextxy(xg, yg + 120, text[6]);
										if ((int)(nhap = getch()) == 13) {
											for (int j = i; j < ht->cb.so_ve; j++) {
												ht->cb.ds_ve[j] = ht->cb.ds_ve[j + 1];
											}
											ht->cb.so_ve--;
										}
										ino = -1;
										ido = -1;
										xoachu(text[6], xg, yg + 120);
										xoachu(kh->info.ho, xg + 50, yg + 15);
										xoachu(phai, xg + 565, yg + 15);
										xoachu(kh->info.ten, xg + 55, yg + 55);
										xoachu(kh->info.cmnd, xg + 305, yg + 55);
										break;
									}
								}
								if (ino != -1) {
									outtextxy(xg, yg + 120, const_cast<char*>("vi tri nay chua duoc dat, NHAN PHIM BAT KY DE TIEP TUC"));
									getch();
									xoachu(const_cast<char*>("vi tri nay chua duoc dat, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
								}
							}
							else {
								outtextxy(xg, yg + 120, const_cast<char*>("vi tri ko hop le, NHAN PHIM BAT KY DE TIEP TUC"));
								getch();
								xoachu(const_cast<char*>("vi tri ko hop le, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
							}
						}
						else {
							outtextxy(xg, yg + 120, const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("da qua thoi gian huy ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);						
						}
					}
					else {
						if (cmnd[0] != '\0' && vtd[0] != '\0') {
							outtextxy(xg, yg + 120, const_cast<char*>("chi huy ve dua vao 1 trg 2 thong tin, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("chi huy ve dua vao 1 trg 2 thong tin, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
						}
						if (cmnd[0] == '\0' && vtd[0] == '\0') {
							outtextxy(xg, yg + 120, const_cast<char*>("huy ve bang thong tin CMND hoac vi tri ve, NHAN PHIM BAT KY DE TIEP TUC"));
							getch();
							xoachu(const_cast<char*>("huy ve bang thong tin CMND hoac vi tri ve, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 120);
						}
					}
				}
				if ((int)nhap == 27 || (*x == -10 && *y == -10)) {
					bar(xg - 175, yg, xg + 850, yg + 101);
					bar(xg - 170, yg + 100, getmaxx(), getmaxy());
					setbkcolor(0);
					if (*x != -10 && *y != -10) { *x = -1; *y = -1; }
					break;
				}
			}
			nhanh1.join();
		}
		else {
			outtextxy(xg, yg, const_cast<char*>("CHUYEN BAY DA HOAN TAT HOAC DA HUY CHUYEN"));
			Sleep(500);
			xoachu(const_cast<char*>("CHUYEN BAY DA HOAN TAT HOAC DA HUY CHUYEN"), xg, yg);
		}
	}		
}
void DHInVeCb(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y)
{
	int xg = 600, yg = 10, kc = 65;
	int ii = 0, cd = 0;
	PTRChuyenBay ht = NULL;
	for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next)cd++;		
	PTRChuyenBay* chay = new PTRChuyenBay[cd];
	thread nhanh(chonChuyenBay, ref(dau_chuyen_bay), ref(ht), x, y, &ii, 2, chay, ref(cd));
	hienDSCB3(dau_chuyen_bay, ds_may_bay, x, y, &ii, 2, chay, cd);
	nhanh.join();
	delete[]chay;
	setbkcolor(0);
	char nhap = 0, text[9][400]{}, gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[5]{};
	strcpy_s(text[0], 40, "DANH SACH KHACH HANG THUOC CHUYEN BAY ");
	strcpy_s(text[1], 40, "Noi den : ");
	strcpy_s(text[2], 220, "Ngay gio khoi hanh:        /        /                        :     ");
	strcpy_s(text[3], 30, "STT");
	strcpy_s(text[4], 30, "SOVE");
	strcpy_s(text[5], 30, "SO CMND");
	strcpy_s(text[6], 30, "HO");
	strcpy_s(text[7], 30, "TEN");
	strcpy_s(text[8], 30, "PHAI");
	if (ht != NULL) {
		outtextxy(xg, yg, text[0]);
		outtextxy(xg, yg + 30, text[2]);
		outtextxy(xg + 500, yg + 30, text[1]);
		///
		_itoa_s(ht->cb.ngay_gio_kh.gio_kh.gio, gio, 3, 10);
		_itoa_s(ht->cb.ngay_gio_kh.gio_kh.phut, phut, 3, 10);
		_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.ngay, ngay, 3, 10);
		_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.thang, thang, 3, 10);
		_itoa_s(ht->cb.ngay_gio_kh.ngay_kh.nam, nam, 5, 10);
		outtextxy(xg + 390, yg, ht->cb.ma_cb);
		outtextxy(xg + 150, yg + 30, ngay);
		outtextxy(xg + 180, yg + 30, thang);
		outtextxy(xg + 215, yg + 30, nam);
		outtextxy(xg + 285, yg + 30, gio);
		outtextxy(xg + 315, yg + 30, phut);
		outtextxy(xg + 500 + textwidth(text[1]), yg + 30, ht->cb.san_bay_den);
		////
		outtextxy(xg - 200, yg + 60, text[3]);
		outtextxy(xg - 100, yg + 60, text[4]);
		outtextxy(xg, yg + 60, text[5]);
		outtextxy(xg + 150, yg + 60, text[6]);
		outtextxy(xg + 610, yg + 60, text[7]);
		outtextxy(xg + 780, yg + 60, text[8]);
		ii = 0;
		char tam[100];
		PTRKhachhang kh;
		setfillstyle(1, 0);
		while (1) {
			bar(xg - 200, yg + 80, getmaxx(), getmaxy());
			for (int i = 0; i < 18; i++) {
				if (i + ii * 18 < ht->cb.so_ve) {
					_itoa_s(i + 1 + ii * 18, tam, 90, 10);
					kh = timKhachHang(goc_khach_hang, ht->cb.ds_ve[i + ii * 18].cmnd);
					outtextxy(xg - 200, yg + 100 + 35 * i, tam);
					outtextxy(xg - 100, yg + 100 + 35 * i, ht->cb.ds_ve[i + ii * 18].vitri);
					outtextxy(xg, yg + 100 + 35 * i, kh->info.cmnd);
					outtextxy(xg + 150, yg + 100 + 35 * i, kh->info.ho);
					outtextxy(xg + 610, yg + 100 + 35 * i, kh->info.ten);
					if (kh->info.phai == 1) {
						outtextxy(xg + 780, yg + 100 + 35 * i, const_cast<char*>("NAM"));
					}
					else
					{
						outtextxy(xg + 780, yg + 100 + 35 * i, const_cast<char*>("NU"));
					}
				}

			}
			if ((int)(nhap = getch()) == 0) {
				nhap = getch();
				switch ((int)nhap)
				{
				case 75: {//trai
					if (ii > 0)ii--;
					break;
				}
				case 77: {//phai
					if (ii * 18 - ht->cb.so_ve < -18)
						ii++;
					break;
				}

				}
			}
			else if ((int)nhap == 27 ) {
				bar(xg - 200, yg + 60, getmaxx(), getmaxy());
				bar(xg, yg, xg + 800, yg + 50);
				*x = -1; *y = -1;
				return;
			}	
			if (*x == -10 && *y == -10) {
				bar(xg - 200, yg + 60, getmaxx(), getmaxy());
				bar(xg, yg, xg + 800, yg + 50);
				return;
			}
		}
	}	
}
void hienDSCB4(int* x, int* y, PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay)
{
	int xg = 500, yg = 15;
	char text[7][225]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(0);
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:"); 
	strcpy_s(text[2], 225, "Ngay gio KH:                      /          /       ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	///
	outtextxy(xg + 10, yg  + 10, text[2]);
	rectangle(xg + 55 + 100, yg + 5, xg + 55 + 30 + 100, yg + 10 + 25);///ngay
	rectangle(xg + 100 + 100, yg + 5, xg + 100 + 30 + 100, yg + 10 + 25);///thang
	rectangle(xg + 140 + 100, yg + 5, xg + 140 + 50 + 100, yg + 10 + 25);///nam
	///
	outtextxy(xg + 10 + 300 + 50, yg + 10, text[1]);
	rectangle(xg + 10 + 300 + 50 + 95, yg + 5, xg + 10 + 300 + 50 + 550, yg + 10 + 25);
	bool testngay = 0;
	int n = 0, i[5]{ 0,0,0,0,0 }, tam = 0, ii = 0, cd = 0, ht = 0, io = -1, kc = 60;
	char ngay[3]{}, thang[3]{}, nam[5]{}, sbd[101]{}, nhap, tam1[225]{};
	MayBay* tm = nullptr;
	PTRChuyenBay p = dau_chuyen_bay;
	for (p = dau_chuyen_bay; p != NULL; p = p->next)cd++;
	PTRChuyenBay* q = new PTRChuyenBay[cd];
	for (p = dau_chuyen_bay; p != NULL; p = p->next) {
		q[ht++] = p;
	}
	setfillstyle(1,BLACK);
	while (1) {
		if (io != ii) {
			io = ii;
			bar(xg, yg + 70, getmaxx(), getmaxy());
			for (int j = 0; j < 10; j++) {
				if (j + ii * 10 < ht) {
					outtextxy(xg, yg + 80 + kc * j, text[0]);
					outtextxy(xg + 225 + 130 + textwidth(text[0]), yg + 80 + kc * j, text[1]);
					outtextxy(xg, yg + 110 + kc * j, text[2]);
					outtextxy(xg + textwidth(text[2]) + 30, yg + 110 + kc * j, text[3]);
					outtextxy(xg + 325 + 170, yg + 110 + kc * j, text[4]);
					outtextxy(xg + 540 + 170, yg + 110 + kc * j, text[5]);
					///===========================================///
					outtextxy(xg + textwidth(text[0]) + 5, yg + 80 + kc * j, q[j + ii * 10]->cb.ma_cb);
					outtextxy(xg + 310 + 50 + 120 + textwidth(text[1]), yg + 80 + kc * j, q[j + ii * 10]->cb.san_bay_den);
					_itoa_s(q[j + ii * 10]->cb.ngay_gio_kh.gio_kh.gio, tam1, 225, 10);
					outtextxy(xg + 100, yg + 110 + kc * j, tam1);///gio
					_itoa_s(q[j + ii * 10]->cb.ngay_gio_kh.gio_kh.phut, tam1, 25, 10);
					outtextxy(xg + 25 + 100, yg + 110 + kc * j, tam1);///phut
					_itoa_s(q[j + ii * 10]->cb.ngay_gio_kh.ngay_kh.ngay, tam1, 25, 10);
					outtextxy(xg + 55 + 100, yg + 110 + kc * j, tam1);///ngay
					_itoa_s(q[j + ii * 10]->cb.ngay_gio_kh.ngay_kh.thang, tam1, 25, 10);
					outtextxy(xg + 95 + 100, yg + 110 + kc * j, tam1);///thang
					_itoa_s(q[j + ii * 10]->cb.ngay_gio_kh.ngay_kh.nam, tam1, 25, 10);
					outtextxy(xg + 135 + 100, yg + 110 + kc * j, tam1);///nam
					switch (q[j + ii * 10]->cb.trang_thai_cb)
					{
					case HUY_CHUYEN: {
						strcpy_s(tam1, 225, "huy chuyen");
						break;
					}
					case CON_VE: {
						strcpy_s(tam1, 225, "con ve");
						break;
					}
					case HET_VE: {
						strcpy_s(tam1, 225, "het ve");
						break;
					}
					case HOAN_TAT: {
						strcpy_s(tam1, 225, "hoan tat");
						break;
					}
					default:
						break;
					}
					outtextxy(xg + 295 + 100, yg + 110 + kc * j, tam1);
					outtextxy(xg + 485 + 100, yg + 110 + kc * j, q[j + ii * 10]->cb.sh_Mb);
					tm = TimSoHieu(q[j + ii * 10]->cb.sh_Mb, ds_may_bay);
					_itoa_s(tm->so_day * tm->so_dong - q[j + ii * 10]->cb.so_ve, tam1, 10, 10);
					outtextxy(xg + 720 + 100, yg + 110 + kc * j, tam1);
					line(xg, yg + 133 + kc * j, getmaxx(), yg + 133 + kc * j);
				}				
			}
		}
		if ((int)(nhap = getch()) != 13 && (int)nhap != 0 && (int)nhap != 27) {
			n = mouseHienDSCB(*x, *y);
			switch (n)
			{
			case 0: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 2)	{
					ngay[i[n] + 1] = ngay[i[n]];
					ngay[i[n]++] = nhap;
					tam = atoi(ngay);
					if (tam >= 32) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 60 + 100, yg + 10, ngay);
				}
				if ((int)nhap == 8) {
					xoachu(ngay, xg + 60 + 100, yg + 10);
					if (i[n] > 0) {
						ngay[i[n] - 1] = ngay[i[n]--];
					}
					outtextxy(xg + 60 + 100, yg + 10, ngay);
				}
				break;
			}
			case 1: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 2) {
					thang[i[n] + 1] = thang[i[n]];
					thang[i[n]++] = nhap;
					tam = atoi(thang);
					if (tam >= 13) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 105 + 100, yg + 10, thang);
				}
				if ((int)nhap == 8) {
					xoachu(thang, xg + 105 + 100, yg + 10);
					if (i[n] > 0) {
						thang[i[n] - 1] = thang[i[n]--];
					}
					outtextxy(xg + 105 + 100, yg + 10, thang);
				}
				break;
			}
			case 2: {
				if ('0' <= nhap && nhap <= '9' && i[n] < 4) {
					nam[i[n] + 1] = nam[i[n]];
					nam[i[n]++] = nhap;
					outtextxy(xg + 145 + 100, yg + 10, nam);
				}
				if ((int)nhap == 8) {
					xoachu(nam, xg + 145 + 100, yg + 10);
					if (i[n] > 0) {
						nam[i[n] - 1] = nam[i[n]--];
					}
					outtextxy(xg + 145 + 100, yg + 10, nam);
				}
				break;
			}
			case 3:{
				if (i[n] < 100) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9')) || (int)nhap == 32) {
					sbd[i[n] + 1] = sbd[i[n]];
					sbd[i[n]++] = nhap;
					if ((int)nhap != 32 && i[n] != 0) {
						SuaTen(sbd);
						i[n] = strlen(sbd);
					}
					outtextxy(xg + 15 + 300 + 50 + 95, yg + 10, sbd);
				}
				if ((int)nhap == 8) {
					xoachu(sbd, xg + 15 + 300 + 50 + 95, yg + 10);
					if (i[n] > 0) {
						sbd[i[n] - 1] = sbd[i[n]--];
					}
					outtextxy(xg + 15 + 300 + 50 + 95, yg + 10, sbd);
				}
				break;
			}
			default:
				break;
			}
		}
		if ((int)nhap == 13) {			
			if (ngay[0] != '\0' || thang[0] != '\0' || nam[0] != '\0') {
				if (ngay[0] != '\0' && thang[0] != '\0' && nam[0] != '\0') {
					NgayGio test;
					test.datNgayGio(0, 0, atoi(ngay), atoi(thang), atoi(nam));
					if (test.checkNgayGio() == 0) {
						outtextxy(xg, yg + 50, const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						testngay = 1;
						xoachu(const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 50);
					}
				}
				if (ngay[0] != '\0' && thang[0] != '\0' && nam[0] == '\0') {
					NgayGio test;
					test.datNgayGio(0, 0, atoi(ngay), atoi(thang), 2004);
					if (test.checkNgayGio() == 0) {
						outtextxy(xg, yg + 50, const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"));
						getch();
						testngay = 1;
						xoachu(const_cast<char*>("ngay nay khong ton tai, NHAN PHIM BAT KY DE TIEP TUC"), xg, yg + 50);
					}
				}
			}
			if (testngay == 0) {
				ht = 0;
				for (p = dau_chuyen_bay; p != NULL; p = p->next) {
					if ((ngay[0] == '\0' || p->cb.ngay_gio_kh.ngay_kh.ngay == atoi(ngay)) && (thang[0] == '\0' || p->cb.ngay_gio_kh.ngay_kh.thang == atoi(thang))
						&& (nam[0] == '\0' || p->cb.ngay_gio_kh.ngay_kh.nam == atoi(nam)) && (sbd[0] == '\0' || strcmp(sbd, p->cb.san_bay_den) == 0)) {
						q[ht++] = p;
					}
				}
				io = -1;
			}	
			testngay = 0;
		}
		if ((int)nhap == 0) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (ii * 10 - ht < -10) {
					ii++;
				}
			}
			if ((int)nhap == 75) {
				if (ii > 0) {
					ii--;
				}
			}
		}
		if ((int)nhap == 27) {
			bar(xg, yg, getmaxx() - 80, yg + 100);
			bar(xg, yg + 60, getmaxx(), getmaxy());
			*x = -1; *y = -1;
			delete[]q;
			return;
		}
		if (*x == -10 && *y == -10) {
			bar(xg, yg, getmaxx() - 80, yg + 100);
			bar(xg, yg + 60, getmaxx(), getmaxy());
			delete[]q;
			return;
		}
	}
	
}
int mouseHienDSCB(int x, int y)
{
	int xg = 500, yg = 15;
	if (yg + 5 <= y && y <= yg + 35) {
		if (xg + 55 + 100 <= x  &&x <= xg + 55 + 30 + 100)return 0;
		if (xg + 110 + 100 <= x && x <= xg + 110 + 30 + 100)return 1;
		if (xg + 140 + 100 <= x && x <= xg + 140 + 50 + 100)return 2;
		if (xg + 10 + 300 + 50 + 95 <= x && x <= xg + 10 + 300 + 50 + 550)return 3;
	}
	return -1;
}
///=====================================================================================///
void KhoiDong()
{
	initwindow(1500, 770, "quan ly chuyen bay");	
}

void KetThuc()
{
	closegraph();
}
void dongho(int xi, int yi, int* x, int* y)
{
	int ng[5];
	char text[100]{ "         :                 /        /      " };
	char ngay[5][100]{};
	*x = 0; *y = 0;
	settextstyle(3, HORIZ_DIR, 1);
	for (int i = 0; i < 5; i++) {
		ng[i] = -1;
	}
	time_t now = time(0);
	tm th;
	localtime_s(&th, &now);
	outtextxy(xi, yi, text);
	rectangle(xi + 10, yi - 3, xi + 200, yi + 20);
	while (1) {
		now = time(0);
		localtime_s(&th, &now);		
		if (th.tm_hour != ng[0] || th.tm_min != ng[1] || th.tm_mday != ng[2] || th.tm_mon + 1 != ng[3] || th.tm_year + 1900 != ng[4]) {
			ng[0] = th.tm_hour;
			ng[1] = th.tm_min;
			ng[2] = th.tm_mday;
			ng[3] = th.tm_mon + 1;
			ng[4] = th.tm_year + 1900;
			xoachu(ngay[0], xi + 15, yi);
			xoachu(ngay[1], xi + 45, yi);
			xoachu(ngay[2], xi + 85, yi);
			xoachu(ngay[3], xi + 120, yi);
			xoachu(ngay[4], xi + 155, yi);
			for (int i = 0; i < 5; i++) {
				_itoa_s(ng[i], ngay[i], 5, 10);
			}
			outtextxy(xi + 15, yi, ngay[0]);
			outtextxy(xi + 45, yi, ngay[1]);
			outtextxy(xi + 85, yi, ngay[2]);
			outtextxy(xi + 120, yi, ngay[3]);
			outtextxy(xi + 155, yi, ngay[4]);
		}
		if ((*x == -1 && *y == -1) || (*x == -10 && *y == -10)) {
			bar(xi + 10, yi - 3, xi + 201, yi + 21);
			break;
		}
	}
}
//=================================================================
void xuatSoCBHT(int* x, int* y, PTRChuyenBay chuyenBay,DSMayBay DsMayBay)
{
	int max;
	char tam[100];
	int i = 0;
	int page = 0;
	int slin = 0;
	int xg = 50, yg = 10;
	int itam = 0;
	char text[4][40]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
	settextstyle(9, 0, 2);
	outtextxy(xg + getmaxx() - 1000, yg + 50, (char*)"SO HIEU MAY BAY");
	outtextxy(getmaxx() - 470, yg + 50, (char*)"SO CHUYEN BAY HOAN TAT");
	settextstyle(4, 0, 2);
	outtextxy(xg + getmaxx() - 900, yg + 600, (char*)"SU DUNG 2 NUT TRAI PHAI DE QUA TRANG");
	settextstyle(9, 0, 2);
	line(getmaxx() - 500, 55, getmaxx() - 500,yg+70);
	line(xg +450, yg+80, xg+getmaxx() - 50, yg + 80);
	char nhap;
	Bublesort(chuyenBay, DsMayBay);
	//_itoa_s(chuyenBay->dem,tam[i], 10, 10);
	/*while (chuyenBay != NULL && i<10) {
		outtextxy(getmaxx() - 950, yg + 100, chuyenBay->cb.sh_Mb);
		_itoa_s(chuyenBay->dem, tam, 10, 10);
		outtextxy(getmaxx() - 450, yg + 100, tam);
		yg = yg + 50;
		chuyenBay = chuyenBay->next;
		i++;
	}
	*/
	
	
//========================
	while (1) {
		line(getmaxx() - 500, 55, getmaxx() - 500, yg + 70);
		line(xg + 450, yg + 80, xg + getmaxx() - 50, yg + 80);
		while (i<DsMayBay.so_MB && slin<10) {
			outtextxy(getmaxx() - 950, yg + 100, DsMayBay.maybay[i]->sh_Mb);
			timCBtheoSHMB(chuyenBay, DsMayBay.maybay[i]->sh_Mb, max);
			_itoa_s(max, tam, 10, 10);
			outtextxy(getmaxx() - 450, yg + 100, tam);
			line(getmaxx() - 500, 60, getmaxx() - 500, yg + 120);
			line(xg + 450, yg + 120, xg + getmaxx() - 50, yg + 120);
			yg = yg + 50;
			i++;
			slin++;
			Sleep(50);
		}




//===============================================================
			yg = 10;
			nhap = getch();
			if ((int)nhap == 75 && page>0) {
				i = itam;
				page--;
				slin = 0;
				bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
				itam = i-10;
				bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
				settextstyle(9, 0, 2);
				outtextxy(xg + getmaxx() - 1000, yg + 50, (char*)"SO HIEU MAY BAY");
				outtextxy(getmaxx() - 470, yg + 50, (char*)"SO CHUYEN BAY HOAN TAT");
				settextstyle(4, 0, 2);
				outtextxy(xg + getmaxx() - 900, yg + 600, (char*)"SU DUNG 2 NUT TRAI PHAI DE QUA TRANG");
				settextstyle(9, 0, 2);
			}

			if ((int)nhap == 77&& i<DsMayBay.so_MB) {
				slin = 0;
				page++;
				bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
				settextstyle(9, 0, 2);
				outtextxy(xg + getmaxx() - 1000, yg + 50, (char*)"SO HIEU MAY BAY");
				outtextxy(getmaxx() - 470, yg + 50, (char*)"SO CHUYEN BAY HOAN TAT");
				settextstyle(4, 0, 2);
				outtextxy(xg + getmaxx() - 900, yg + 600, (char*)"SU DUNG 2 NUT TRAI PHAI DE QUA TRANG");
				settextstyle(9, 0, 2);
				itam = i-10;
			}

			if ((int)nhap == 27) {
				setfillstyle(1, 0);
				bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
				*x = -1;
				*y = -1;
				return;
			}
		}
	}
	

void xuatSoVeTrong(int* x, int* y, PTRChuyenBay chuyenBay, DSMayBay DsMayBay) 
{
	char char0[] = { '0' };
	char tam[100];
	int xm=0, ym=0;
	int check = 0;
	int chay = 0;
	int page = 0;
	int demqt = 0;
	char nhap=0;
	PTRChuyenBay cbtam = chuyenBay;
	int i=0;
	while (chuyenBay != NULL) {
		i++;
		chuyenBay = chuyenBay->next;
	}
	chuyenBay = cbtam;
	bool n = false;
	int xg = 50, yg = 10;
	//bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
	setbkcolor(BLUE);
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	bar(getmaxx()-1255,yg+45,getmaxx()-1000, yg + 240);
	line(getmaxx() - 1255, yg + 45, getmaxx() - 1000, yg + 45);
	line(getmaxx() - 1255, yg + 240, getmaxx() - 1000, yg + 240);
	line(getmaxx() - 1255, yg + 45, getmaxx() - 1255, yg + 240);
//====================================
	setbkcolor(0);
	outtextxy(getmaxx() - 990, yg , (char*)"CHUYEN BAY MA: ");
	rectangle(getmaxx() - 850, yg, getmaxx() - 700,yg+20);
//=======================================
	setbkcolor(BLUE);
	outtextxy(getmaxx() - 1250, yg+50, (char*)"GIO:");
	rectangle(getmaxx() - 1210, yg+50, getmaxx() - 1135, yg + 70);
	line(getmaxx() - 1172, yg+50, getmaxx() - 1172, yg + 70);

//=======================================
	outtextxy(getmaxx() - 1250, yg + 100, (char*)"NGAY:");
	rectangle(getmaxx() - 1190, yg + 100, getmaxx() - 1030, yg + 120);
	line(getmaxx() - 1150, yg + 100, getmaxx() - 1150, yg + 120);
	line(getmaxx() - 1110, yg + 100, getmaxx() - 1110, yg + 120);
//=======================================
	outtextxy(getmaxx() - 1250, yg + 140, (char*)"TRANG THAI:");
	rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
	line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
	line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
	line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
//======================================
	setbkcolor(BLUE);
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
	line(getmaxx() - 750, 55, getmaxx() - 750, yg + 750);
	line(getmaxx() - 1000, 55, getmaxx() - 1000, yg + 750);
	line(xg + 450, yg + 45, xg + getmaxx() - 800, yg + 45);
	settextstyle(9,0,1);
	*x= -1;
	*y = -1;
	/*thread nhanh(mousexv, ref(x), ref(y));
	nhanh.join();
	n = mousexv(x, y);
	if (n) {
		cout << *x << endl << *y << endl;
	}*/
	while (1) {
		/*n = mousexv(x, y);
		if (n) {
			cout << *x << endl << *y << endl;
		}*/
		//================================
		while (chuyenBay != NULL && demqt < 8) {
			line(xg + 450, yg + 125, xg + getmaxx() - 800, yg + 125);
			outtextxy(getmaxx() - 900, yg + 50, chuyenBay->cb.sh_Mb);
			_itoa_s(chuyenBay->cb.ngay_gio_kh.ngay_kh.ngay, tam, 10, 10);
			if (chuyenBay->cb.ngay_gio_kh.ngay_kh.ngay < 10) {
				outtextxy(getmaxx() - 885, yg + 100, (char*)"0");
				outtextxy(getmaxx() - 870, yg + 100, tam);
			}
			else {
				outtextxy(getmaxx() - 885, yg + 100, tam);
			}
			//outtextxy(getmaxx() - 885, yg + 100, tam);
//===================================================
			outtextxy(getmaxx() - 855, yg + 100, (char*)"/");
			_itoa_s(chuyenBay->cb.ngay_gio_kh.ngay_kh.thang, tam, 10, 10);
			if (chuyenBay->cb.ngay_gio_kh.ngay_kh.thang < 10) {
				outtextxy(getmaxx() - 847, yg + 100, (char*)"0");
				outtextxy(getmaxx() - 832, yg + 100, tam);
			}
			else {
				outtextxy(getmaxx() - 847, yg + 100, tam);
			}
			//outtextxy(getmaxx() - 847, yg + 100, tam);
//===================================================
			outtextxy(getmaxx() - 820, yg + 100, (char*)"/");
			_itoa_s(chuyenBay->cb.ngay_gio_kh.ngay_kh.nam, tam, 10, 10);
			outtextxy(getmaxx() - 810, yg + 100, tam);
			//=======================================
			_itoa_s(chuyenBay->cb.ngay_gio_kh.gio_kh.gio, tam, 10, 10);
			if (chuyenBay->cb.ngay_gio_kh.gio_kh.gio < 10) {
				outtextxy(getmaxx() - 990, yg + 100, (char*)"0");
				outtextxy(getmaxx() - 975, yg + 100, tam);
			}
			else {
				outtextxy(getmaxx() - 985, yg + 100, tam);
			}
			//================================			
			outtextxy(getmaxx() - 960, yg + 100, (char*)":");
			_itoa_s(chuyenBay->cb.ngay_gio_kh.gio_kh.phut, tam, 10, 10);
			if (chuyenBay->cb.ngay_gio_kh.gio_kh.phut < 10) {
				outtextxy(getmaxx() - 950, yg + 100, (char*)"0");
				outtextxy(getmaxx() - 935, yg + 100, tam);
			}
			else {
				outtextxy(getmaxx() - 950, yg + 100, tam);
			}


			if (chuyenBay->cb.trang_thai_cb == 0) {
				setcolor(BROWN);
				outtextxy(getmaxx() - 990, yg + 80, (char*)" HUY CHUYEN");
				setcolor(WHITE);
			}
			if (chuyenBay->cb.trang_thai_cb == 1) {
				setcolor(GREEN);
				outtextxy(getmaxx() - 990, yg + 80, (char*)" CON VE");
				setcolor(WHITE);
			}
			if (chuyenBay->cb.trang_thai_cb == 2) {
				setcolor(WHITE);
				outtextxy(getmaxx() - 990, yg + 80, (char*)" HET VE");
				setcolor(WHITE);
			}
			if (chuyenBay->cb.trang_thai_cb == 3) {
				setcolor(RED);
				outtextxy(getmaxx() - 990, yg + 80, (char*)" HOAN TAT");
				setcolor(WHITE);
			}
			//cout << chuyenBay->cb.sh_Mb << endl;
			demqt++;
			yg = yg + 80;
			chuyenBay = chuyenBay->next;
			Sleep(75);

		}
		//chuyenBay = cbtam;
//=====


//================================
		//bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
		if (*x > xg + getmaxx() / 2 - 300 && *x < getmaxx() / 2 - 25 + 800) {
			if (*y > yg + 45 && *y < yg + 750) {
				
				nhap = getch();
				cout << nhap << endl;
			}
		}
		/*else {
			nhap = '=';
		}*/
		 yg = 10;
		 if ((int)nhap == 80&& chuyenBay!=NULL) {
			 bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
			 if (check < i-1) {

			 check = check + 8;
		 }
			//cout << check;
			demqt = 0;
			page++;
			line(getmaxx() - 750, 55, getmaxx() - 750, yg + 750);
			line(getmaxx() - 1000, 55, getmaxx() - 1000, yg + 750);
			line(xg + 450, yg + 45, xg + getmaxx() - 800, yg + 45);
			nhap = 0;
		}
		if ((int)nhap == 72 && page>0) {
			bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
			line(getmaxx() - 750, 55, getmaxx() - 750, yg + 750);
			line(getmaxx() - 1000, 55, getmaxx() - 1000, yg + 750);
			line(xg + 450, yg + 45, xg + getmaxx() - 800, yg + 45);
			chuyenBay = cbtam;
			check = check - 8;
			//cout << check;
			for (int j = 0; j < check; j++) {
				chuyenBay = chuyenBay->next;
			}
			nhap = 0;
			demqt = 0;
			page--;
			
		}

//================================
		if ((int)nhap == 27) {
			setfillstyle(1, 0);
			bar(xg + getmaxx() / 2 - 300, yg + 45, getmaxx() / 2 - 25 + 800, yg + 750);
			*x = -1;
			*y = -1;
			return;
		}
	}
}

//================
bool mousexv(int *x, int *y) {
	int xg = 50, yg = 10;
		if (*x > getmaxx() - 850 && *x< getmaxx() - 700 ) {
			if (*y > yg && *y < yg + 20) {
			cout << *x << endl << *y << endl;
			return true;
			}
		}
		else {
			*x = -1;
			*y = -1;
			return false;
		}
}
//==========
void locVeMB(int* x, int* y, PTRChuyenBay chuyenBay, DSMayBay DsMayBay) {
	char gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[3]{};
	int bgio = 0, bphut = 0, bngay = 0, bthang = 0, bnam = 0;
	int n=0;
	int n1 = 0;
	int xg = 50, yg = 10;
	char nhap=0;
	int lgio = 0, lphut = 0, lngay = 0, lthang = 0, lnam = 0, ltt = -1;
	//rectangle(getmaxx() - 1210, yg + 50, getmaxx() - 1135, yg + 70);
	while (1) {
		//bar(getmaxx() - 1255, yg + 45, getmaxx() - 1000, yg + 205);
		if (*x > getmaxx() - 1255 && *x < getmaxx() - 1000) {
			if (*y > yg + 45 && *y < yg + 240) {
				nhap = getch();
				/*cout <<"y="<< * y << endl;
				cout << "x=" << *x << endl;*/
				cout << (int)nhap << endl;
			}
		}
		/*else {
			nhap = '=';
		}*/
		
		if (*x > getmaxx() - 1210 && *x < getmaxx() - 1135) {
			if (*y > yg + 50 && *y < yg + 70) {
				n = 1;
				//cout << *x << " "  << *y << endl;
			
			}
		}
		 if(*x > getmaxx() - 1190 && *x < getmaxx() - 1030) {
			if (*y > yg + 100 && *y < yg + 120) {
				n = 2;
				//cout << *x << " " << *y << endl;
			}
			//rectangle(getmaxx() - 1190, yg + 100, getmaxx() - 1030, yg + 120);
		}
		 if (*x > getmaxx() - 1140 && *x < getmaxx() - 1010) {
			if (*y > yg + 140 && *y < yg + 160) {
				n = 3;
				//cout << *x << " " << *y << endl;
			}
			//rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1030, yg + 160);
		}
	/*	cout << n;
		cout << " " << nhap << endl;*/
		 switch(n) {
		 case 1:
			 //line(getmaxx() - 1172, yg + 50, getmaxx() - 1172, yg + 70);
			 if (*x > getmaxx() - 1210 && *x < getmaxx() - 1172) {
				 n1 = 1;
				// cout << *x << endl;
			 }
			 else if (*x > getmaxx() - 1172 && *x < getmaxx() - 1135) {
				 n1 = 2;
				// cout << *x << endl;
			 }
			 else { 
				// cout << *x << endl;
				 n1 = 0; }
			// cout << nhap << endl;
			 switch (n1) {
			 case 1:
				 if (nhap >= '0' && nhap <= '9') {
					 if (bgio < 2) {
						lgio = (lgio * 10) + (int)nhap - 48;
						if (lgio < 24) {
							//cout << nhap<< endl;
							gio[bgio + 1] = gio[bgio];
							gio[bgio] = nhap;
							bgio++;
							// settextstyle(, 0,);
							//cout << tam[0] <<  endl;
							setbkcolor(BLUE);
							settextstyle(6, HORIZ_DIR, 1);
							setfillstyle(1, 1);
							outtextxy(getmaxx() - 1205, yg + 51, (char*)gio);
							
							cout << lgio << endl;
						}
						else {
							lgio = lgio / 10;
						}
						// cout << (int)nhap - 48;
					 }
				 }
				 if ((int)nhap == 8) {
					 if (bgio >0) {
						 xoachu(gio, getmaxx() - 1205, yg + 51);
						 gio[bgio - 1] = gio[bgio--];
						 outtextxy(getmaxx() - 1205, yg + 51, (char*)gio);
						 lgio = lgio / 10;
						 cout << lgio << " ";
					 }
				 }
				break;
			 case 2: 
				 if (nhap >= '0' && nhap <= '9') {
					 if (bphut < 2) {
						 //cout << nhap<< endl;
						lphut = (lphut * 10) + (int)nhap - 48;
						if (lphut < 60) {
							phut[bphut + 1] = phut[bphut];
							phut[bphut] = nhap;
							bphut++;
							// settextstyle(, 0,);
							//cout << tam[0] <<  endl;
							setbkcolor(BLUE);
							settextstyle(6, HORIZ_DIR, 1);
							setfillstyle(1, 1);
							outtextxy(getmaxx() - 1165, yg + 51, (char*)phut);
				
							cout << lphut << endl;
						
						 
						}
						else {
							lphut = lphut / 10;
						}
					 }
				 }
				 if ((int)nhap == 8) {
					 if (bphut > 0) {
						 xoachu(phut, getmaxx() - 1165, yg + 51);
						 phut[bphut - 1] = phut[bphut--];
						 outtextxy(getmaxx() - 1165, yg + 51, (char*)phut);
						 lphut = lphut / 10;
					 }
				 }
				 break;
			}
			// cout << n1 << endl;
			 break;
		
		 case 2:
			 //line(getmaxx() - 1150, yg + 100, getmaxx() - 1150, yg + 120);
			 //line(getmaxx() - 1110, yg + 100, getmaxx() - 1110, yg + 120);
			 if (*x > getmaxx() - 1190 && *x < getmaxx() - 1150) {
				 n1 = 1;
			 }
			 else if (*x > getmaxx() - 1150 && *x < getmaxx() - 1110) {
				 n1 = 2;
			 }
			 else if(*x> getmaxx() - 1110&&*x< getmaxx() - 1030) {
				 n1 = 3;
			 }
			 else { n1 = 0; }
			 switch (n1) {
			 case 1:
				 if (nhap >= '0' && nhap <= '9') {
					 if (bngay < 2) {
						 lngay = (lngay * 10) + (int)nhap - 48;
						 if (lngay < 32) {
							 //cout << nhap<< endl;
							 ngay[bngay + 1] = ngay[bngay];
							 ngay[bngay] = nhap;
							 bngay++;
							 // settextstyle(, 0,);
							 //cout << tam[0] <<  endl;
							 setbkcolor(BLUE);
							 settextstyle(6, HORIZ_DIR, 1);
							 setfillstyle(1, 1);
							 outtextxy(getmaxx() - 1185, yg + 101, (char*)ngay);
							
							 cout << lngay << endl;
						 }
						 else {
							 lngay = lngay / 10;
						 }
						// cout << (int)nhap - 48;
					 }
				 }
				 if ((int)nhap == 8&& bngay>0) {
					 xoachu(ngay, getmaxx() - 1185, yg + 101);
					 ngay[bngay - 1] = ngay[bngay--];
					 outtextxy(getmaxx() - 1185, yg + 101, (char*)ngay);
					 lngay = lngay / 10;
				 }
				 break;
			 case 2:
				 if (nhap >= '0' && nhap <= '9') {
					 if (bthang < 2) {
						 //cout << nhap<< endl;
						lthang = (lthang * 10) + (int)nhap - 48;
						if (lthang < 13) {
							thang[bthang + 1] = thang[bthang];
							thang[bthang] = nhap;
							bthang++;
							// settextstyle(, 0,);
							//cout << tam[0] <<  endl;
							setbkcolor(BLUE);
							settextstyle(6, HORIZ_DIR, 1);
							setfillstyle(1, 1);
							outtextxy(getmaxx() - 1145, yg + 101, (char*)thang);
							
							cout << lthang << endl;
						}
						else {
							lthang = lthang / 10;
						}
						 //cout << (int)nhap - 48;
					 }
				 }
				 if ((int)nhap == 8&&bthang>0) {
					 xoachu(thang, getmaxx() - 1145, yg + 101);
					 thang[bthang - 1] = thang[bthang--];
					 outtextxy(getmaxx() - 1145, yg + 101, (char*)thang);
					 lthang = lthang / 10;
				 }
				 break;
			 case 3:
				 if (nhap >= '0' && nhap <= '9') {
					 if (bnam < 4) {
						 //cout << nhap<< endl;
						 nam[bnam + 1] = nam[bnam];
						 nam[bnam] = nhap;
						 bnam++;
						 // settextstyle(, 0,);
						 //cout << tam[0] <<  endl;
						 setbkcolor(BLUE);
						 settextstyle(6, HORIZ_DIR, 1);
						 setfillstyle(1, 1);
						 outtextxy(getmaxx() - 1105, yg + 101, (char*)nam);
						 lnam = (lnam * 10) + (int)nhap - 48;
						 cout << lnam << endl;
						
						 //cout << (int)nhap - 48;
					 }
				 }
				 if ((int)nhap == 8&&bnam>0) {
					 xoachu(nam, getmaxx() - 1105, yg + 101);
					 nam[bnam - 1] = nam[bnam--];
					 outtextxy(getmaxx() - 1105, yg + 101, (char*)nam);
					 lnam = lnam / 10;
					 cout << "ltt=" << ltt;
				 }
				 break;
			 }
			 //cout << n1;
			 break;
		 case 3:
			 //rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
			 //line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
			 if (*x > getmaxx() - 1255 && *x < getmaxx() - 1000) {
				 if (*y > yg + 45 && *y < yg + 240) {

					 if (*x > getmaxx() - 1030 && *x < getmaxx() - 1005) {
						 if (*y > yg + 140 && *y < yg + 240) {
							 /**x = -1;
							 *y = -1;*/
							 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
							 outtextxy(getmaxx() - 1135, yg + 143, (char*)"CON VE");
							 outtextxy(getmaxx() - 1138, yg + 163, (char*)"HOAN TAT");
							 rectangle(getmaxx() - 1140, yg + 160, getmaxx() - 1010, yg + 180);
							 outtextxy(getmaxx() - 1138, yg + 183, (char*)"HET VE");
							 rectangle(getmaxx() - 1140, yg + 180, getmaxx() - 1010, yg + 200);
							 outtextxy(getmaxx() - 1138, yg + 203, (char*)"HUY ");
							 rectangle(getmaxx() - 1140, yg + 200, getmaxx() - 1010, yg + 240);
							 outtextxy(getmaxx() - 1138, yg + 220, (char*)"CHUYEN ");
							 //=======================================================================================


						 }
					 }
					 if (*x< getmaxx()-1140 || *x>  getmaxx() - 1010 || *y<yg + 140 || *y>yg + 240) {

						 bar(getmaxx() - 1140, yg + 140, getmaxx() - 1005, yg + 240);
						 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
						 line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
						 line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
						 line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
						 cout << "hello";
						 ltt = -1;
						 cout << ltt;
					 }
					 if (*x> getmaxx() - 1140&&*x< getmaxx() - 1030) {
						 if (*y> yg + 140&&*y< yg + 160) {
							 ltt = 1;
							 cout << ltt;
							 bar(getmaxx() - 1140, yg + 140, getmaxx() - 1005, yg + 240);
							outtextxy(getmaxx() - 1135, yg + 143, (char*)"CON VE");
							 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
							 line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
							 line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
							 line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
							
						 }
					 }
					 if (*x > getmaxx() - 1140 && *x < getmaxx() - 1010) {
						 if (*y > yg + 160 && *y < yg + 180) {
							 ltt = 3;
							 cout << ltt;
							 bar(getmaxx() - 1140, yg + 140, getmaxx() - 1005, yg + 240);
							 outtextxy(getmaxx() - 1135, yg + 143, (char*)"HOAN");
							 outtextxy(getmaxx() - 1135, yg + 160, (char*)"TAT");
							 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 180);
							 line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
							 line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
							 line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
							 line(getmaxx() - 1030, yg + 160, getmaxx() - 1010, yg + 160);
							 
						 }
					 }
					 if (*x > getmaxx() - 1140 && *x < getmaxx() - 1010) {
						 if (*y > yg + 180 && *y < yg + 200) {
							 ltt = 2;

							 cout << ltt;
							 bar(getmaxx() - 1140, yg + 140, getmaxx() - 1005, yg + 240);
							 outtextxy(getmaxx() - 1135, yg + 143, (char*)"HET VE");
							 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 160);
							 line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
							 line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
							 line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
							 
						 }
					 }
					 if (*x > getmaxx() - 1140 && *x < getmaxx() - 1010) {
						 if (*y > yg + 200 && *y < yg + 240) {
							 ltt = 0;
							 cout << ltt;
							 bar(getmaxx() - 1140, yg + 140, getmaxx() - 1005, yg + 240);
							 outtextxy(getmaxx() - 1135, yg + 143, (char*)"HUY");
							 outtextxy(getmaxx() - 1135, yg + 160, (char*)"CHUYEN");
							 rectangle(getmaxx() - 1140, yg + 140, getmaxx() - 1010, yg + 180);
							 line(getmaxx() - 1030, yg + 140, getmaxx() - 1030, yg + 160);
							 line(getmaxx() - 1020, yg + 145, getmaxx() - 1020, yg + 155);
							 line(getmaxx() - 1025, yg + 150, getmaxx() - 1015, yg + 150);
							 line(getmaxx() - 1030, yg + 160, getmaxx() - 1010, yg + 160);
							 
						 }
					 }
					 nhap = 0;
				 }
			 }
			// cout << 3;
			 break;


		 }
		 if ((int)nhap == 13) {

		}
		
	}

}
