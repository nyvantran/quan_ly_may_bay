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
	strcpy_s(a[6], 225, "In DS ve cua chuyen bay");
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
	int xg = 55, yg = 50;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN) == 1) {
			getmouseclick(WM_LBUTTONDOWN, *x, *y);
		}
		if ((*x >= getmaxx() - 50) && (*y >= 0) && (*x <= getmaxx()) && (*y <= 50)) {
			*x = -10;
			*y = -10;
			break;
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
	int x=0, y=0;
	int n = -1, tam;
	MayBay tam1{};
	thread nhanh1(mouse, &x, &y);
	while (1) {
		tam = n;
		n = checkMouse1(n, x, y);
		switch (n)
		{
		case 0: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				putimage(xg + 240, yg + 88 * n, p2, 0);
			}
			switch (checkMouse21(x,y))
			{
			case 0: {
				thread nhanh(DHThemMB, ref(ds_may_bay), &x, &y);
				nhanh.join();
				break;
			}
			case 1: {
				int ii = 0;
				thread nhanh1(DHxoaMB, ref(ds_may_bay),dau_chuyen_bay, &x, &y, &ii);
				hienDSMb1(&x, &y, &ii, ds_may_bay);
				nhanh1.join();
				break;
			}
			case 2: {
				int ii = 0;
				MayBay* ht;
				thread nhanh1(DHhieuchinhMB, ref(ds_may_bay), ref(ht), ref(dau_chuyen_bay), &x, &y, &ii);
				hienDSMb2(&x, &y, &ii, ht, ds_may_bay);
				nhanh1.join();
				//bat loi hieu chinh day dong chi tang so cho va ham cb.capnhap
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
				DHThemCB(dau_chuyen_bay,ds_may_bay, &x, &y);
				break;
			}
			case 1: {
				int ii = 0;
				thread nhanh1(hienDSCB1, &x, &y, &ii, ref(dau_chuyen_bay),ref(ds_may_bay));
				DHHuyChuyen(dau_chuyen_bay, ds_may_bay, &x, &y,&ii);
				nhanh1.join();
				break;
			}
			case 2: {
				int ii = 0;
				PTRChuyenBay ht;
				thread nhanh2(DHHieuChinhCB, ref(dau_chuyen_bay),ref(ht), &x, &y, &ii);
				hienDSCB2(&x, &y, &ii, ht, dau_chuyen_bay, ds_may_bay);
				nhanh2.join();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2: {
			if (n != tam) {
				settextstyle(3, HORIZ_DIR, 1);
				if (getpixel(xg + 240, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 1, p3, 1);
				}
				if (getpixel(xg + 240, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 240, yg + 88 * 0, p2, 1);
				}
			}
			DHdatVe(dau_chuyen_bay, ds_may_bay, goc_khach_hang, &x, &y);
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

void DHThemMB(DSMayBay& ds_may_bay, int* x, int* y)
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
	char shmb[16]{}, lmb[41]{}, soday[3]{}, sodong[3]{}; 
	shmb[0] = '\0'; lmb[0] = '\0'; soday[0] = '\0'; sodong[0] = '\0';
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0;
	setbkcolor(1);
	while (1) {
		if (((int)(nhap = getch()) != 13) && ((int)nhap != 27)) {
			if (mouseThemMb(*x, *y) == 0) {
				if (i0 < 15) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
				if (i1 < 40) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
				|| (soday[0] == '\0') || (sodong[0] == '\0') || (atoi(soday) * atoi(sodong) < 20))
			{
				int mt = getbkcolor();
				setbkcolor(0);
				outtextxy(xg+textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90,
					const_cast<char*>("khong de thong tin trong"));
				Sleep(500);
				xoachu(const_cast<char*>("khong de thong tin trong"), 
					xg+textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90);
				setbkcolor(mt);
			}
			else {
				if (TimSoHieu(shmb, ds_may_bay) == NULL) {
					MayBay tam{};
					strcpy_s(tam.sh_Mb, 15, shmb);
					strcpy_s(tam.loai_may_bay, 40, lmb);
					tam.so_day = atoi(soday);
					tam.so_dong = atoi(sodong);
					ThemMayBay(tam, ds_may_bay);
					getimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
					putimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
					free(p1);
					*x = -1; *y = -1;
					break;
				}
				else {
					int mt = getbkcolor();
					setbkcolor(0);
					outtextxy(xg+textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90,
						const_cast<char*>("so hieu may bay da trung"));
					Sleep(500);
					xoachu(const_cast<char*>("so hieu may bay da trung"),
						xg+textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90);
					setbkcolor(mt);
				}
			}
		}
		else if ((int)nhap == 27) {
			getimage(xg+getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
			putimage(xg+getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
			free(p1);
			*x = -1; *y = -1;
			return;
		}
	}
}
///==============================xoa chu============================================///
void xoachu(char* n, int x, int y) {
	int tam = getcolor();
	setcolor(getbkcolor());
	outtextxy(x, y, n);
	setcolor(tam);
}
///==================================================================================///
void hienDSMb1(int* x, int* y, int* ii, DSMayBay& ds_may_bay)
{
	int xg = 460, yg = 100;
	char text[6][225]{};
	void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
	/*============================================================*/
	strcpy_s(text[0], 40, " so hieu may bay: ");
	strcpy_s(text[1], 40, " loai may bay: ");
	strcpy_s(text[2], 40, " so day: ");
	strcpy_s(text[3], 40, " so dong: ");
	setfillstyle(1, 1);
	bar(xg, yg, getmaxx(), getmaxy());
	char tam[25];
	char nhap;
	int n = 0;
	int k = 0;
	while (1) {
		for (int i = 0; i < 10; i++) {
			if (*ii * 10 + i < ds_may_bay.so_MB) {
				outtextxy(xg, yg + 5 + 60 * i, text[0]);
				outtextxy(xg + textwidth(text[0]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 10 + i]->sh_Mb);
				outtextxy(xg + 225 + textwidth(text[0]), yg + 5 + 60 * i, text[1]);
				outtextxy(xg + 225 + textwidth(text[0]) + textwidth(text[1]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 10 + i]->loai_may_bay);
				_itoa_s(ds_may_bay.maybay[*ii * 10 + i]->so_day, tam, 10);
				outtextxy(xg, yg + 30 + 60 * i, text[2]);
				outtextxy(xg + textwidth(text[2]), yg + 30 + 60 * i, tam);
				_itoa_s(ds_may_bay.maybay[*ii * 10 + i]->so_dong, tam, 10);
				outtextxy(xg + 200 + textwidth(text[2]), yg + 30 + 60 * i, text[3]);
				outtextxy(xg + 200 + textwidth(text[2]) + textwidth(text[3]), yg + 30 + 60 * i, tam);
				outtextxy(xg + 350 + textwidth(text[2]), yg + 30 + 60 * i, const_cast<char*>("xoa"));
				rectangle(xg + 345 + textwidth(text[2]), yg + 30 + 60 * i,
					xg + 380 + textwidth(text[2]), yg + 50 + 60 * i);
			}			
		}
		_itoa_s(*ii+1, tam, 10);
		outtextxy(xg, getmaxy() - 60, tam);
		outtextxy(xg, getmaxy() - 30, const_cast<char*>("nhan esc de thoat"));
		if ((int)(nhap = getch()) == 0 && mouseXoaMb(*x, *y) < 0) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii * 10 - ds_may_bay.so_MB < 0) {
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
		else if ((int)nhap == 27) {
			*x = -1;
			*y = -1;
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}
}
void hienDSMb2(int* x, int* y, int* ii, MayBay*& ht, DSMayBay& ds_may_bay)
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
	while (1) {
		if (old != mouseHieuChinhMb(*x, *y, old) && *ii * 6 + mouseHieuChinhMb(*x, *y, old) < ds_may_bay.so_MB) {
			bar(609 + 491, 225, 609 + 491 + 300, 225 + 25);
			old = mouseHieuChinhMb(*x, *y, old);
			if (0 <= *ii * 6 + old && *ii * 6 + old < ds_may_bay.so_MB)
			ht = ds_may_bay.maybay[*ii * 7 + old];
			outtextxy(609 + 491, 225, ht->sh_Mb);
		}
		if (n != *ii) {
			*x = 0; *y = 0; old = -1;
			bar(xg, yg, getmaxx(), getmaxy());
			for (int i = 0; i < 7; i++) {
				if (*ii * 7 + i < ds_may_bay.so_MB) {
					setbkcolor(1);
					outtextxy(xg, yg + 5 + 60 * i, text[0]);
					outtextxy(xg + textwidth(text[0]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 7 + i]->sh_Mb);
					outtextxy(xg + 225 + textwidth(text[0]), yg + 5 + 60 * i, text[1]);
					outtextxy(xg + 225 + textwidth(text[0]) + textwidth(text[1]), yg + 5 + 60 * i, ds_may_bay.maybay[*ii * 7 + i]->loai_may_bay);
					_itoa_s(ds_may_bay.maybay[*ii * 7 + i]->so_day, tam, 10);
					outtextxy(xg, yg + 30 + 60 * i, text[2]);
					outtextxy(xg + textwidth(text[2]), yg + 30 + 60 * i, tam);
					_itoa_s(ds_may_bay.maybay[*ii * 7 + i]->so_dong, tam, 10);
					outtextxy(xg + 200 + textwidth(text[2]), yg + 30 + 60 * i, text[3]);
					outtextxy(xg + 200 + textwidth(text[2]) + textwidth(text[3]), yg + 30 + 60 * i, tam);
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
		if (*x == -1 && *y == -1) {
			void* p = malloc(imagesize(xg, yg, getmaxx(), getmaxy()));
			getimage(xg, yg, getmaxx(), getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
		}
	}
}
///=========== do hoa xoa ds ============================///
void DHxoaMB(DSMayBay& ds_may_bay,PTRChuyenBay fist, int* x, int* y, int* ii)
{
	int xg = 460, yg = 20;
	char text[11][100]{};
	strcpy_s(text[0], 25, "you co xac nhan xoa ko ");
	strcpy_s(text[1], 25, "xac nhan");
	strcpy_s(text[2], 25, "ko");
	void* p = malloc(imagesize(xg, yg, xg + 400, yg + 60));
	int n, t1,t2;
	while (1) {
		if (mouseXoaMb(*x, *y) >= 0 && *ii * 10 + mouseXoaMb(*x, *y)<ds_may_bay.so_MB) {
			n = mouseXoaMb(*x, *y);
			bar(xg, yg, xg + 400, yg + 60);
			outtextxy(xg + 5, yg + 25 - textheight(text[0]) / 2, text[0]);
			outtextxy(xg + 25, yg + 25 - textheight(text[0]) / 2 + 25, ds_may_bay.maybay[n + *ii * 10]->sh_Mb);
			outtextxy(xg + 50 + textwidth(text[0]), yg + 25 - textheight(text[0]) / 2, text[1]);
			rectangle(xg + 45 + textwidth(text[0]), yg + 25 - textheight(text[0]) / 2,
				xg + 45 + textwidth(text[0]) + 75, yg + 25 - textheight(text[0]) / 2 + 20);
			outtextxy(xg + 100 + textwidth(text[0]) + textwidth(text[1]), yg + 25 - textheight(text[0]) / 2,
				text[2]);
			rectangle(xg + 95 + textwidth(text[0]) + textwidth(text[1]), yg + 25 - textheight(text[0]) / 2,
				xg + 95 + textwidth(text[0]) + textwidth(text[1]) + 70, yg + 25 - textheight(text[0]) / 2 + 20);
		///==========================///
			while (1) {
				if (mouseXoaMb(*x, *y) == -1 ) {
					t1 = *ii;
					if (timCBtheoSHMB(fist, ds_may_bay.maybay[t1 * 10 + n]->sh_Mb,t2) == 0) {
						*x = 0;
						*y = 0;
						strcpy_s(text[3], 41, ds_may_bay.maybay[t1 * 10 + n]->sh_Mb);
						XoaMayBay(ds_may_bay, text[3]);
					}
					else {
						outtextxy(xg + 25, yg + 25 - textheight(text[0]) / 2 + 25,const_cast<char*>("co chuyen bay su dung"));
						Sleep(350);
					}
					getimage(xg, yg, xg + 400, yg + 60, p);
					putimage(xg, yg, p, 1);
					break;
					
				}
				else if (mouseXoaMb(*x, *y) == -2) {
					getimage(xg, yg, xg + 400, yg + 60, p);
					putimage(xg, yg, p, 1);
					break;
				}
				if (*x == -1 && *y == -1) {
					break;
				}
			}
		}
		if (*x == -1 && *y == -1) {
			getimage(xg, yg, xg + 400, yg + 60, p);
			putimage(xg, yg, p, 1);
			break;
		}
		
	}
	free(p);
}

void DHhieuchinhMB(DSMayBay& ds_may_bay, MayBay*& ht,PTRChuyenBay &fist, int* x, int* y, int* ii)
{
	int xg = 50, yg = 10;
	char text[4][40]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	///=====================///
	void* p1 = malloc(imagesize(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200));
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
	char nhap;
	int k;
	char shmb[16]{}, lmb[41]{}, soday[3]{}, sodong[3]{};
	shmb[0] = '\0'; lmb[0] = '\0'; soday[0] = '\0'; sodong[0] = '\0';
	int i0 = 0, i1 = 0, i2 = 0, i3 = 0, old1 = -1;
	while (1) {
		nhap = getch();
		old1 = mouseHieuChinhMb(*x, *y, old1);
		if ((int)nhap != 13 && (int)nhap != 27) {
			if (mouseThemMb(*x, *y) == 0) {
				if (i0 < 15) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
				if (i1 < 40) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
		}
		if ((int)nhap == 13) {
			int t1 = ht->so_day, t2 = ht->so_dong;
			if (soday[0] != '\0')t1 = atoi(soday);
			if (sodong[0] != '\0')	t2 = atoi(sodong);
			if (t1 * t2 >= ht->so_day * ht->so_dong) {
				if (shmb[0] != '\0') {
					if (TimSoHieu(shmb, ds_may_bay) == NULL) {
						HieuChinhMB(ht, shmb, lmb, t1, t2);
						bool d = 1;
						if (t1 * t2 == ht->so_day * ht->so_dong) {
							d = 0;
						}
						for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
							p1->capNhapVe(ds_may_bay, shmb, d);							
						}
					}
					else {
						outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
							const_cast<char*>("so hieu may bay trung"));
						Sleep(500);
						bar(1019, 200, 1019 + textwidth(const_cast<char*>("so hieu may bay trung")), 200 + textheight(const_cast<char*>("so hieu may bay trung")));
					}
				}
				else {
					HieuChinhMB(ht, shmb, lmb, t1, t2);
					bool d = 1;
					if (t1 * t2 == ht->so_day * ht->so_dong) {
						d = 0;
					}
					for (PTRChuyenBay p1 = fist; p1 != NULL; p1 = p1->next) {
						p1->capNhapVe(ds_may_bay, shmb, d);
					}
				}
			}
			else {
				outtextxy(xg + textwidth(text[0]) + getmaxx() / 2 + 100, yg + 20 + 130 - textheight(text[1]) / 2 + 50,
					const_cast<char*>("so ve ko duoc giam"));
				Sleep(500);
				bar(1019, 200, 1019 + textwidth(const_cast<char*>("so ve ko duoc giam")), 200 + textheight(const_cast<char*>("so ve ko duoc giam")));
			}
				
		}
		if ((int)nhap == 27) {
			getimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
			putimage(xg + getmaxx() / 2 - 25 - 310, yg + 45, p1, 1);
			free(p1);
			*x = -1; *y = -1;
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
///=================================================================================///
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
///===================================================================///
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
///=====================hieu chinh mb======///
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
///============================================chuyen bay===============================///
void DHThemCB(PTRChuyenBay& dau_chuyen_bay,DSMayBay& ds_may_bay, int* x, int* y)
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
	//outtextxy(xg + 10 + textwidth(text[2])+30, yg + 50 + 10, text[3]);
	outtextxy(xg + 335 + 170, yg + 60, text[4]);
	outtextxy(xg + 10, yg + 120, text[5]);
	/*outtextxy(xg + 10 + 400, yg + 120, text[6]);*/
	///=======================///
	bar(xg + 5 + textwidth(text[0]), yg + 5, xg + 10 + textwidth(text[0]) + 230, yg + 10 + 25);
	bar(xg + 10 + 225 + 50 + textwidth(text[0]) + 95, yg + 5
		, xg + 10 + 225 + 50 + textwidth(text[0]) + 550, yg + 10 + 25);
	bar(xg + 10 + 100, yg + 50 + 5, xg + 10 + 30 + 100, yg + 50 + 10 + 25);///gio
	bar(xg + 50 + 100, yg + 50 + 5, xg + 50 + 30 + 100, yg + 50 + 10 + 25);///phut
	bar(xg + 95 + 100, yg + 50 + 5, xg + 95 + 30 + 100, yg + 50 + 10 + 25);///ngay
	bar(xg + 140 + 100, yg + 50 + 5, xg + 140 + 30 + 100, yg + 50 + 10 + 25);///thang
	bar(xg + 180 + 100, yg + 50 + 5, xg + 180 + 30 + 100, yg + 50 + 10 + 25);///nam
	/*bar(xg + 335 + 105, yg + 55, xg + 335 + 105 + 50, yg + 60 + 25);*/
	bar(xg + 120 + 475, yg + 55, xg + 225 + 120 + 475, yg + 60 + 25);
	///=======================///
	char nhap;
	int i[10]{}, n, tam = 0;
	char mcb[16]{}, sbd[101]{}, gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[3]{}, tt[2]{}, shmb[16]{};
	for (int k = 0; k < 10; k++) {
		i[k] = 0;
	}
	setbkcolor(1);
	while (1) {
		if (((int)(nhap = getch()) != 13) && ((int)nhap != 27)) {
			n = mouseThemCB(*x, *y);
			switch (n)
			{
			case 1: {
				if (i[n] < 15) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
					sbd[i[n]] = nhap; i[n]++;
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
				if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
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
		/*	case 8: {
				if (i[n] < 1)if (('0' <= nhap) && (nhap <= '4')) {
					tt[i[n] + 1] = tt[i[n]];
					tt[i[n]] = nhap; i[n]++;
					outtextxy(xg + 335 + 105, yg + 60, tt);
				}
				if ((int)nhap == 8) {
					xoachu(tt, xg + 335 + 105, yg + 60);
					if (i[n] > 0) {
						tt[i[n] - 1] = tt[i[n]--];
					}
					outtextxy(xg + 335 + 105, yg + 60, tt);
				}
				break;
			}*/
			case 9: {
				if (i[n] < 15) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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
				outtextxy(xg+200, yg+90, const_cast<char*>("khong de thong tin trong"));
				Sleep(500);
				xoachu(const_cast<char*>("khong de thong tin trong"), xg + 200, yg + 90);
				setbkcolor(mt);
			}
			else {
				if (timChuyenBay(dau_chuyen_bay, mcb) == NULL && TimSoHieu(shmb, ds_may_bay) != NULL) {
					ChuyenBay tam1;
					NgayGio tam2;
					tam2.datNgayGio(atoi(gio), atoi(phut), atoi(ngay), atoi(thang), atoi(nam));
					tam1.datChuyenBay(mcb, tam2, sbd, shmb, capNhapTT(tam2), ds_may_bay);
					/*for (PTRChuyenBay p = dau_chuyen_bay; p != NULL; p = p->next) {
						if (strcmp(p->cb.sh_Mb, shmb) == 0) {
							
						}
					}*/
					///SE SUA THEM 
					themChuyenBay(dau_chuyen_bay, tam1);
					getimage(xg, yg, xg + 975, yg + 150, p);
					putimage(xg, yg, p, 1);
					free(p);
					return;
				}
				else {
					int mt = getbkcolor();
					setbkcolor(0);
					outtextxy(xg + 200, yg + 90, const_cast<char*>("ma chuyen bay bi trung hoac ko co so hieu may bay nay"));
					Sleep(700);
					xoachu(const_cast<char*>("ma chuyen bay bi trung hoac ko co so hieu may bay nay"), xg + 200, yg + 90);
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
		else if (xg + 180 + 100 <= x && x <= xg + 180 + 100 + 30) {
			return 7;///nam
		}
		/*else if (xg + 335 + 105 <= x && x <= xg + 335 + 105 + 50) {
			return 8;
		}*/
		else if (xg + 120 + 475 <= x && x <= xg + 225 + 120 + 475) {
			return 9;
		}
	}
	return 0;
}

void DHHuyChuyen(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, int* x, int* y,int *ii)
{
	int xg = 500, yg = 10, kc = 65;
	char text[5][225]{};
	strcpy_s(text[0], 100, "you dang huy chuyen bay: ");
	strcpy_s(text[1], 100, "xac nhan");
	strcpy_s(text[2], 100, "huy bo");
	PTRChuyenBay p; int n;
	void* q = malloc(imagesize(xg, yg, xg + 500, yg + 50));
	while (1) {
		if (mouseHuyCB(*x, *y) >= 0) {
			int i = 0;
			n = mouseHuyCB(*x, *y);
			for (p = dau_chuyen_bay; p != NULL && i < *ii * 10 + n; p = p->next) {
				i++;
			}
			if(p!=NULL){
				bar(xg, yg, xg + 500, yg + 50);
				outtextxy(xg + 10, yg + 5, text[0]);
				outtextxy(xg + 60 + textwidth(text[0]), yg + 5, text[1]);
				outtextxy(xg + 150 + textwidth(text[0]) + textwidth(text[1]), yg + 5, text[2]);
				outtextxy(xg + 10, yg + 25, p->cb.ma_cb);
				///=======================================///
				rectangle(xg + 60 + 170, yg + 5, xg + 60 + 260, yg + 30);
				rectangle(xg + 60 + 330, yg + 5, xg + 60 + 400, yg + 30);
				while (1) {
					if (mouseHuyCB(*x, *y) == -1) {
						p->cb.trang_thai_cb = HUY_CHUYEN;
						getimage(xg, yg, xg + 500, yg + 50, q);
						putimage(xg, yg, q, 1);
						break;
					}
					else if (mouseHuyCB(*x, *y) == -2) {
						getimage(xg, yg, xg + 500, yg + 50, q);
						putimage(xg, yg, q, 1);
						break;
					}
					else if (*x == -1 && *y == -1) {
						getimage(xg, yg, xg + 500, yg + 50, q);
						putimage(xg, yg, q, 1);
						free(q);
						return;
					}
				}
			}
		}
		if (*x == -1 && *y == -1) {
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
	setfillstyle(1, 1);
	setbkcolor(1);
	strcpy_s(text[0], 40, "Ma chuyen bay: ");
	strcpy_s(text[1], 40, "San bay den:");
	strcpy_s(text[2], 220, "Ngay gio KH:        :                /       /     ");
	strcpy_s(text[3], 40, "Trang thai CB: ");
	strcpy_s(text[4], 40, "So hieu MB: ");
	strcpy_s(text[5], 100, "So ve con lai: ");
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	///==================================================================================///
	PTRChuyenBay q; 
	int i1 = 0, k, cd = 0;
	char tam[225], nhap = 0;
	MayBay* tm = nullptr;
	for (PTRChuyenBay p1 = dau_chuyen_bay; p1 != NULL; p1 = p1->next)cd++; 
	while (1) {
		i1 = 0;
		for (q = dau_chuyen_bay; q != NULL && i1 < *ii * 10; q = q->next)i1++;
		bar(xg, yg, xg + getmaxx(), yg + getmaxy());
		for (int i = 0; i < 10; i++) {
			if (q != NULL) {
				outtextxy(xg + 10, yg + 10 + kc * i, text[0]);
				outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10 + kc * i, text[1]);
				outtextxy(xg + 10, yg + 40 + kc * i, text[2]);
				outtextxy(xg + 10 + textwidth(text[2]) + 30, yg + 40 + kc * i, text[3]);
				outtextxy(xg + 320 + 170, yg + 40 + kc * i, text[4]);
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
				outtextxy(xg + 485 + 100, yg + 40 + kc * i, q->cb.sh_Mb);
				tm = TimSoHieu(q->cb.sh_Mb, ds_may_bay);
				_itoa_s(tm->so_day * tm->so_dong - q->cb.so_ve, tam, 100, 10);
				outtextxy(xg + 720 + 100, yg + 40 + kc * i, tam);
				outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("HUY CHUYEN"));
				rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 880 + 100, yg + 60 + kc * i);
				q = q->next;
				line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
			}
		}
		if ((int)(nhap = getch()) == 0 && mouseHuyCB(*x, *y) < 0) {
			nhap = getch();
			if ((int)nhap == 77) {
				if (*ii*10-cd < 0) {
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
			*x = -1; *y = -1;
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
void DHHieuChinhCB(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay &ht, int* x, int* y, int* ii)
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
	strcpy_s(text[6], 100, "trang thai chuyen bay: 0 huy chuyen; 1 con ve; 2 het ve; 3 hoan tat");
	rectangle(xg, yg, xg + 975, yg + 150);
	///=======================///
	outtextxy(xg + 10, yg + 10, text[0]);
	outtextxy(xg + 10 + 225 + 50 + textwidth(text[0]), yg + 10, text[1]);
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
	bar(xg + 180 + 100, yg + 50 + 5, xg + 180 + 30 + 100, yg + 50 + 10 + 25);///nam
	bar(xg + 120 + 475, yg + 55, xg + 225 + 120 + 475, yg + 60 + 25);
	///=======================///
	int cd = 0, k = 0;
	for (PTRChuyenBay p1 = dau_chuyen_bay; p1 != NULL; p1 = p1->next)cd++;
	while (1) {
		char nhap;
		int i[10]{}, n, tam = 0;
		char mcb[16]{}, sbd[101]{}, gio[3]{}, phut[3]{}, ngay[3]{}, thang[3]{}, nam[3]{}, tt[2]{}, shmb[16]{};
		for (int k = 0; k < 10; k++) {
			i[k] = 0;
		}
		setbkcolor(1);
		while (1) {
			if (((int)(nhap = getch()) != 13) && ((int)nhap != 27)) {
				n = mouseThemCB(*x, *y);
				switch (n)
				{
				case 2: {
					if (i[n] < 100) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
						|| (('0' <= nhap) && (nhap <= '9'))) {
						sbd[i[n] + 1] = sbd[i[n]];
						sbd[i[n]] = nhap; i[n]++;
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
					if (i[n] < 2)if (('0' <= nhap) && (nhap <= '9')) {
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
					if (i[n] < 15) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
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

			}else
			if ((int)nhap == 13) {
				NgayGio tam1;
				int gi = -1, ph = -1, ng = -1, th = -1, na = -1;
				if (gio[0] != '\0') {
					 gi= atoi(gio);
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
				tam1.datNgayGio(gi, ph, ng, th, na);
				//tam1.datNgayGio(-1, -1, -1, -1, -1);
				chinhsuaChuyenBay(ht, tam1, sbd, shmb);
				ht->capnhap();
				outtextxy(xg + 100, yg + 100, const_cast<char*>("hieu chinh tc"));
				Sleep(250);
				xoachu(const_cast<char*>("hieu chinh tc"), xg + 100, yg + 100);
			}
			else if ((int)nhap == 27) {
				getimage(xg, yg, xg + 975, yg + 150, p);
				putimage(xg, yg, p, 1);
				*x = -1; *y = -1;
				return;
			}
		}
	}
	getch();
}
void hienDSCB2(int* x, int* y, int* ii, PTRChuyenBay& ht, PTRChuyenBay& dau_chuyen_bay, DSMayBay ds_may_bay)
{
	Sleep(50);
	setbkcolor(1);
	int xg = 500, yg = 220, kc = 65;
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
	PTRChuyenBay q ;
	int i1 = 0, cd = 0, ii1 = 1, old = -1;
	char tam[225], nhap = 0;
	MayBay* tm=NULL;
	for ( q = dau_chuyen_bay; q != NULL; q = q->next)cd++;
	while (1) {
		if (old != mouseHieuChinhCB(old, *x, *y) && *ii * 8 + mouseHieuChinhCB(old, *x, *y) < cd) {
			bar(619, 60, 854, 90);
			old = mouseHieuChinhCB(old, *x, *y);
			i1 = 0;
			for (q = dau_chuyen_bay; q != NULL && i1 < *ii * 8 + old; q = q->next)i1++;
			ht = q;
			if (q != NULL)
			outtextxy(xg + 120, yg - 155, q->cb.ma_cb);
		}
		if (ii1 != *ii) {
			i1 = 0; old = -1; *x = 0; *y = 0;
			for (q = dau_chuyen_bay; q != NULL && i1 < *ii * 8; q = q->next)i1++;
			bar(xg, yg, xg + getmaxx(), yg + getmaxy());
			for (int i = 0; i < 8; i++) {
				if (q != NULL) {
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
					outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("HIEU CHINH"));
					rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 870 + 100, yg + 60 + kc * i);
					line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
					q = q->next;
				}
			}
			ii1 = *ii;
		}
		if (*x == -1 && *y == -1) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			return;
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
///====================khach hang==================================================================///
void DHdatVe(PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay, PTRKhachhang& goc_khach_hang, int* x, int* y)
{
	int xg = 500, yg = 10, kc = 65;
	int ii = 0; 
	PTRChuyenBay ht=NULL;
	thread nhanh(chonChuyenBay, ref(dau_chuyen_bay), ref(ht), x, y, &ii);
	hienDSCB3(x, y, &ii, dau_chuyen_bay, ds_may_bay);
	nhanh.join();
	setbkcolor(0);
	char text[5][100]{};
	strcpy_s(text[0], 25, "Cmnd: ");
	strcpy_s(text[1], 25, "Ho: ");
	strcpy_s(text[2], 25, "Ten: ");
	strcpy_s(text[3], 25, "Phai: ");
	strcpy_s(text[4], 25,"Vi tri dat: ");
	///========///
	char nhap, ho[41]{}, ten[11]{}, cmnd[13]{}, phai[2]{}, vitri[10]{}, vtd[10]{};
	int n[5]{ 0, 0,0,0,0 }, n1 = 0, id = 0, in = 0, ido = -1, ino = -1;
	if (ht != NULL) {
		rectangle(xg, yg, xg + 650, yg + 100);
		outtextxy(xg + 15, yg + 15, text[1]);
		outtextxy(xg + 520, yg + 15, text[3]);
		outtextxy(xg + 15, yg + 55, text[2]);
		outtextxy(xg + 240, yg + 55, text[0]);
		outtextxy(xg + 700, yg + 55, text[4]);
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
		while (1) {
			if (in != ino || id != ido) {
				ino = in; ido = id;
				bar(xg - 170, yg + 120, getmaxx(), getmaxy());
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
						if (vtd[0] != '\0') {
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
							}
							else {
								outtextxy(xg + 500, yg + 55, const_cast<char*>("ko the dat ve o day"));
								Sleep(250);
								xoachu(const_cast<char*>("ko the dat ve o day"), xg + 500, yg + 55);
							}
						}
						///phai sua them
					}
					else {
						outtextxy(xg + 500, yg + 55, const_cast<char*>("ko tim thay"));
						Sleep(250);
						xoachu(const_cast<char*>("ko tim thay"), xg + 500, yg + 55);
					}
				}
				if (cmnd[0] != '\0' && ho[0] != '\0' && ten[0] != '\0' && phai[0] != '\0') {
					kh = timKhachHang(goc_khach_hang, cmnd);
					if (kh != NULL && (strcmp(kh->info.ho, ho) != 0
						|| strcmp(kh->info.ten, ten) != 0 || atoi(phai) != (int)kh->info.phai)) {
						outtextxy(xg + 500, yg + 55, const_cast<char*>("khong khop thong tin"));
						Sleep(250);
						xoachu(const_cast<char*>("khong khop thong tin"), xg + 500, yg + 55);
					}
					else if (kh == NULL) {
						KhachHang tam;
						tam.datKhachHang(cmnd, ho, ten, (bool)atoi(phai));
						if (vtd[0] != '\0') {
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
							}
							else {
								outtextxy(xg + 500, yg + 55, const_cast<char*>("ko the dat ve o day"));
								Sleep(250);
								xoachu(const_cast<char*>("ko the dat ve o day"), xg + 500, yg + 55);
							}
						}
						///phai sua them
						themKhachHang(goc_khach_hang, tam);
					}
					else if (kh != NULL) {
						if (vtd[0] != '\0') {
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
							}
							else {
								outtextxy(xg + 500, yg + 55, const_cast<char*>("ko the dat ve o day"));
								Sleep(250);
								xoachu(const_cast<char*>("ko the dat ve o day"), xg + 500, yg + 55);
							}
						}
						///phai sua them
					}
				}
				if (cmnd[0] == '\0' && ho[0] != '\0' && ten[0] != '\0' && phai[0] != '\0') {

				}
			}
			if ((int)nhap == 27) {
				bar(xg, yg, xg + 850, yg + 101);
				bar(xg - 170, yg + 120, getmaxx(), getmaxy());
				setbkcolor(0);
				return;
			}
		}
	}

}
void chonChuyenBay(PTRChuyenBay& dau_chuyen_bay, PTRChuyenBay& ht, int* x, int* y, int* ii)
{
	int xg = 500, yg = 10, kc = 65;
	char text[5][225]{};
	strcpy_s(text[0], 100, "you con muon dat ve chuyen bay nay: ");
	strcpy_s(text[1], 100, "xac nhan");
	strcpy_s(text[2], 100, "huy bo");
	PTRChuyenBay p; int n, cd = 0;
	for (p = dau_chuyen_bay; p != NULL; p = p->next) {
		cd++;
	}
	void* q = malloc(imagesize(xg, yg, xg + 550, yg + 50));
	while (1) {
		if (*ii * 10 + mouseChonCB(*x, *y) < cd)
		if (mouseChonCB(*x, *y) >= 0 ) {
			int i = 0;
			n = mouseHuyCB(*x, *y);
			for (p = dau_chuyen_bay; p != NULL && i < *ii * 10 + n; p = p->next) {
				i++;
			}
			if (p != NULL) {
				bar(xg, yg, xg + 550, yg + 50);
				outtextxy(xg + 10, yg + 5, text[0]);
				outtextxy(xg + 50 + textwidth(text[0]), yg + 5, text[1]);
				outtextxy(xg + 150 + textwidth(text[0]) + textwidth(text[1]), yg + 5, text[2]);
				outtextxy(xg + 10, yg + 25, p->cb.ma_cb);
				///=======================================///
				rectangle(xg + 60 + 250, yg + 5, xg + 60 + 330, yg + 30);
				rectangle(xg + 60 + 415, yg + 5, xg + 60 + 470, yg + 30);
				while (1) {
					if (mouseChonCB(*x,*y) == -1) {
						getimage(xg, yg, xg + 550, yg + 50, q);
						putimage(xg, yg, q, 1);
						ht = p;
						free(q);
						outtextxy(xg, getmaxy() - 35, const_cast<char*>("nhap phim tuy y de tiep tuc"));
						return;
					}
					else if (mouseChonCB(*x, *y) == -2) {
						getimage(xg, yg, xg + 550, yg + 50, q);
						putimage(xg, yg, q, 1);
						break;
					}
					else if (*x == -1 && *y == -1) {
						getimage(xg, yg, xg + 550, yg + 50, q);
						putimage(xg, yg, q, 1);
						return;
					}
				}
			}
		}
		if (*x == -1 && *y == -1) {
			getimage(xg, yg, xg + 550, yg + 50, q);
			putimage(xg, yg, q, 1);
			free(q);
			return;
		}
	}
}

void hienDSCB3(int* x, int* y, int* ii, PTRChuyenBay& dau_chuyen_bay, DSMayBay& ds_may_bay)
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
	int i1 = 0, k, cd = 0;
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
				outtextxy(xg + 770 + 100, yg + 40 + kc * i, const_cast<char*>("DAT VE"));
				rectangle(xg + 765 + 100, yg + 40 + kc * i, xg + 880 + 100, yg + 60 + kc * i);
				line(xg, yg + 63 + kc * i, getmaxx(), yg + 63 + kc * i);
			}
		}
		nhap = getch();
		if (mouseChonCB(*x, *y) == -1) {
			getimage(xg, yg, xg + getmaxx(), yg + getmaxy(), p);
			putimage(xg, yg, p, 1);
			free(p);
			*x = -1; *y = -1;
			return;
		}
		if ((int)nhap == 0)
			if ( !(*ii * 10 + mouseChonCB(*x, *y) < cd && mouseChonCB(*x, *y) >= 0)) {
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
	}
}
int mouseChonCB(int x, int y)
{
	int xg = 500, yg = 70, kc = 65;
	int n = (y - yg - 40) / kc;
	if (xg + 765 + 100 <= x && x <= xg + 880 + 100) {
		if (yg + 40 + kc * n <= y && y <= yg + 60 + kc * n) {
			return n;
		}
	}
	if (yg - 60 + 5 <= y && y <= yg - 60 + 30) {
		if (xg + 60 + 250 <= x && x <= xg + 60 + 330) {
			return -1;
		}
		if (xg + 60 + 415 <= x && x <= xg + 60 + 470) {
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
	int ii = 0;
	PTRChuyenBay ht = NULL;
	thread nhanh(chonChuyenBay, ref(dau_chuyen_bay), ref(ht), x, y, &ii);
	hienDSCB3(x, y, &ii, dau_chuyen_bay, ds_may_bay);
	nhanh.join();

}
///=====================================================================================///
void KhoiDong()
{
	initwindow(1500, 770, "quan ly chuyen bay");	
	
}

void KetThuc()
{
	//getch();
	closegraph();
}