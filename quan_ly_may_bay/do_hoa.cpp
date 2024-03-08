#include"do_hoa.h"
#include<thread>
void* Menu()
{
	void* q = malloc(imagesize(0, 0, getmaxx(), getmaxy()));
	line(getmaxx() / 2 - 50, 0, getmaxx() / 2 - 50, getmaxy());
	setfillstyle(1, 4);
	bar(getmaxx() - 50, 0, getmaxx(), 50);
	settextstyle(4, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(1);
	int xg = 20, yg = 50;
	bar(xg, yg, xg + 400, yg + 70);
	rectangle(xg, yg, xg + 400, yg + 70);
	void* p = malloc(imagesize(xg, yg, xg + 400, yg + 70));
	getimage(xg, yg, xg + 400, yg + 70, p);
	for (int i = 0; i <= 7; i++) {
		putimage(xg, yg + 70 * i + 18 * i, p, COPY_PUT);
	}
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
		outtextxy(xg + 200 - textwidth(a[i]) / 2, yg + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	getimage(0, 0, getmaxx(), getmaxy(), q);
	putimage(0, 0, q, XOR_PUT);
	setbkcolor(0);
	return q;
}

void* nhanhMenu1()
{
	settextstyle(4, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(1);
	char a[3][225]{};
	strcpy_s(a[0], 225, "Them MB");
	strcpy_s(a[1], 225, "Xoa MB");
	strcpy_s(a[2], 225, "Hieu Chinh MB");
	int x = 555, y = 50;
	bar(x, y, x + 200, y + 70);
	rectangle(x, y, x + 200, y + 70);
	void* p = malloc(imagesize(x, y, x + 200, y + 70));
	getimage(x, y, x + 200, y + 70, p);
	for (int i = 0; i < 3; i++) {
		line(x - 50, y + 35, x, y + (70 + 18) * i + 35);
		putimage(x, y + (70 + 18) * i, p, COPY_PUT);
		outtextxy(x + 100 - textwidth(a[i]) / 2, y + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	void* q = malloc(imagesize(x - 50, y, x + 200, y + (70 + 18) * 2 + 70));
	getimage(x - 50, y, x + 200, y + (70 + 18) * 2 + 70, q);
	putimage(x - 50, y, q, 1);
	return q;
}

void* nhanhMenu2()
{
	settextstyle(4, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(1);
	char a[3][225]{};
	strcpy_s(a[0], 225, "Them CB");
	strcpy_s(a[1], 225, "Huy CB");
	strcpy_s(a[2], 225, "Hieu Chinh CB");
	int x = 555, y = 50;
	bar(x, y, x + 200, y + 70);
	rectangle(x, y, x + 200, y + 70);
	void* p = malloc(imagesize(x, y, x + 200, y + 70));
	getimage(x, y, x + 200, y + 70, p);
	for (int i = 0; i < 3; i++) {
		line(x - 50, y + 35, x, y + (70 + 18) * i + 35);
		putimage(x, y + (70 + 18) * i, p, COPY_PUT);
		outtextxy(x + 100 - textwidth(a[i]) / 2, y + 70 * i + 18 * i + 35 - textheight(a[0]) / 2, a[i]);
	}
	void* q = malloc(imagesize(x - 50, y, x + 200, y + (70 + 18) * 2 + 70));
	getimage(x - 50, y, x + 200, y + (70 + 18) * 2 + 70, q);
	putimage(x - 50, y, q, 1);
	return q;
}
/*======================mouse=====================*/
int checkMouse1(int old, int x, int y)
{
	int xg = 20, yg = 50;
	if ((x > xg) && (x < xg + 400)) {
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
	if ((xg + 425 + 50 < x) && (x < xg + 425 + 50 + 200)) {
		if ((yg + 88 * n <= y) && (y <= yg + 88 * n + 70)) {
			return n;
		}
	}
	return -1;
}

int checkMouse22(int x, int y)
{
	return 0;
}

void mouse(int* x, int* y)
{
	int xg = 55, yg = 50;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN) == 1) {
			getmouseclick(WM_LBUTTONDOWN, *x, *y);
		}
		if ((*x >= getmaxx() - 50) && (*y >= 0) && (*x <= getmaxx()) && (*y <= 50)) {
			break;
		}
	}
}
///===================================================================================
void chayDoHoa(DSMayBay ds_may_bay, PTRChuyenBay dau_chuyen_bay, PTRKhachhang goc_khach_hang)
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
				if (getpixel(xg + 425, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 425, yg + 88 * 1, p3, 1);
				}
				putimage(xg + 425, yg + 88 * n, p2, 0);
			}
			switch (checkMouse21(x,y))
			{
			case 0: {
				thread nhanh(DHThemMB, ds_may_bay, &x, &y);

				nhanh.join();
				break;
			}

			default:
				break;
			}
			break;
		}
		case 1: {
			if (n != tam) {
				if (getpixel(xg + 425, yg + 88 * 0 + 35) != 0) {
					putimage(xg + 425, yg + 88 * 0, p2, 1);
				}
				putimage(xg + 425, yg + 88 * n, p3, 0);				
			}
			break;
		}
		default:
			break;
		}
	}
	nhanh1.join();
}

void DHThemMB(DSMayBay ds_may_bay, int* x,int* y)
{
	int xg = 0, yg = 10;
	char text[4][40]{};
	settextstyle(3, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	void* p1 = malloc(imagesize(getmaxx() / 2 - 25, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200));
	rectangle(getmaxx() / 2 - 25, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200);
	setbkcolor(0);
	///============================================================================///
	outtextxy(getmaxx() / 2, yg + 45 + 30, text[0]);
	bar(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 30 - textheight(text[0]) / 2,
		textwidth(text[0]) + getmaxx() / 2 + 250, yg + 45 + 30 + 40 - textheight(text[0]) / 2);
	///============================================================================///
	outtextxy(getmaxx() / 2, yg + 45 + 30 + 50, text[1]);
	bar(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 80 - textheight(text[1]) / 2,
		textwidth(text[0]) + getmaxx() / 2 + 500, yg + 45 + 80 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(getmaxx() / 2, yg + 45 + 30 + 100, text[2]);
	bar(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2,
		textwidth(text[0]) + getmaxx() / 2 + 60, yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(textwidth(text[0]) + getmaxx() / 2 + 150, yg + 45 + 30 + 100, text[3]);
	bar(textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]), yg + 45 + 130 - textheight(text[1]) / 2,
		textwidth(text[0]) + getmaxx() / 2 + 150 + 60 + textwidth(text[3]), yg + 45 + 130 + 40 - textheight(text[1]) / 2);
	///============================================================================///
	outtextxy(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 50,
		const_cast<char*>("nhap esc de thoat       nhap enter de xac nhan"));
	getimage(getmaxx() / 2 - 25, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200, p1);
	
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
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
				}
				if ((int)nhap == 8) {
					xoachu(shmb, textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 30 - textheight(text[0]) / 2 + 10);
					if (i0 > 0) {
						shmb[i0 - 1] = shmb[i0--];
					}
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 30 - textheight(text[0]) / 2 + 10, shmb);
				}
			}
			if ( mouseThemMb(*x, *y) == 1) {
				if (i1 < 40) if ((('a' <= nhap) && (nhap <= 'z')) || (('A' <= nhap) && (nhap <= 'Z'))
					|| (('0' <= nhap) && (nhap <= '9'))) {
					nhap = toupper(nhap);
					lmb[i1 + 1] = lmb[i1];
					lmb[i1] = nhap; i1++;
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
				if ((int)nhap == 8) {
					xoachu(lmb, textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 80 - textheight(text[1]) / 2 + 10);
					if (i1 > 0) {
						lmb[i1 - 1] = lmb[i1--];
					}
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 80 - textheight(text[1]) / 2 + 10, lmb);
				}
			}
			if (mouseThemMb(*x, *y) == 2) {
				if (i2 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					soday[i2 + 1] = soday[i2];
					soday[i2] = nhap; i2++;
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
				if ((int)nhap == 8) {
					xoachu(soday, textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i2 > 0) {
						soday[i2 - 1] = soday[i2--];
					}
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10, soday);
				}
			}
			if (mouseThemMb(*x, *y) == 3) {
				if (i3 < 2) if (('0' <= nhap) && (nhap <= '9')) {
					sodong[i3 + 1] = sodong[i3];
					sodong[i3] = nhap; i3++;
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
				if ((int)nhap == 8) {
					xoachu(sodong, textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10);
					if (i3 > 0) {
						sodong[i3 - 1] = sodong[i3--];
					}
					outtextxy(textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) + 5, yg + 45 + 130 - textheight(text[1]) / 2 + 10, sodong);
				}
			}
		}
		if ((int)nhap == 13) {
			if ((shmb[0] == '\0') || (lmb[0] == '\0')
				|| (soday[0] == '\0') || (sodong[0] == '\0') || (atoi(soday) * atoi(sodong) < 20))
			{
				int mt = getbkcolor();
				setbkcolor(0);
				outtextxy(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90,
					const_cast<char*>("khong de thong tin trong"));
				Sleep(500);
				xoachu(const_cast<char*>("khong de thong tin trong"), 
					textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90);
				setbkcolor(mt);
			}
			else {
				if (TimSoHieu(shmb, ds_may_bay) != NULL) {
					MayBay tam;
					strcpy_s(tam.sh_Mb, 15, shmb);
					strcpy_s(tam.loai_may_bay, 40, lmb);
					tam.so_day = atoi(soday);
					tam.so_dong = atoi(sodong);
					ThemMayBay(tam, ds_may_bay);
					putimage(getmaxx() / 2 - 25, yg + 45, p1, 1);
					setfillstyle(1, 0);
					bar(getmaxx() / 2 - 25, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200);
					setbkcolor(1);
					*x = -1; *y = -1;
					break;
				}
				else {
					int mt = getbkcolor();
					setbkcolor(0);
					outtextxy(textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90,
						const_cast<char*>("so hieu may bay da trung"));
					Sleep(500);
					xoachu(const_cast<char*>("so hieu may bay da trung"),
						textwidth(text[0]) + getmaxx() / 2, yg + 45 + 130 - textheight(text[1]) / 2 + 90);
					setbkcolor(mt);
				}
			}
		}
		else if ((int)nhap == 27) {
			putimage(getmaxx() / 2 - 25, yg + 45, p1, 1);
			setfillstyle(1, 0);
			bar(getmaxx() / 2 - 25, yg + 45, getmaxx() / 2 - 25 + 750, yg + 45 + 200);
			setbkcolor(1);
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
void hienDS(int* x, int* y)
{
	int xg = 0, yg = 10;
	int old = -1;
	while (1) {
		old = checkMouse1(old, *x, *y);
		/*if(ismouseclick(WM_LBUTTONDOWN)==1)*/
		if (checkMouse1(old, *x, *y) == 0) {
			outtextxy(getmaxx() / 2 - 25, yg + 45 + 250, const_cast<char*>("hello my friend"));
		}
			
	}
	
}
///=================================================================================///
int mouseThemMb(int x, int y)
{
	int xg = 0, yg = 10;
	char text[4][40]{};
	strcpy_s(text[0], 40, "So hieu may bay:");
	strcpy_s(text[1], 40, "Loai may bay:");
	strcpy_s(text[2], 40, "So day:");
	strcpy_s(text[3], 40, "So dong:");
	///=============///
	if ((textwidth(text[0]) + getmaxx() / 2 <= x) && (x <= textwidth(text[0]) + getmaxx() / 2 + 250)) {
		if ((yg + 45 + 30 - textheight(text[0]) / 2 <= y) && (y <= yg + 45 + 30 + 40 - textheight(text[0]) / 2)) {
			return 0;
		}
	}
	if ((textwidth(text[0]) + getmaxx() / 2 <= x) && (x <= textwidth(text[0]) + getmaxx() / 2 + 500)) {
		if ((yg + 45 + 80 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 80 + 40 - textheight(text[1]) / 2)) {
			return 1;
		}
	}
	if ((textwidth(text[0]) + getmaxx() / 2 <= x) && (x <= textwidth(text[0]) + getmaxx() / 2 + 60)) {
		if ((yg + 45 + 130 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 130 + 40 - textheight(text[1]) / 2)) {
			return 2;
		}
	}
	if ((textwidth(text[0]) + getmaxx() / 2 + 150 + textwidth(text[3]) <= x) && (x <= textwidth(text[0]) + getmaxx() / 2 + 150 + 60 + textwidth(text[3]))) {
		if ((yg + 45 + 130 - textheight(text[1]) / 2 <= y) && (y <= yg + 45 + 130 + 40 - textheight(text[1]) / 2)) {
			return 3;
		}
	}
	return -1;
}

void KhoiDong()
{
	initwindow(1500, 770, "quan ly chuyen bay");
}

void KetThuc()
{
	getch();
	closegraph();
}
