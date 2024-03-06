#include"do_hoa.h"
#include<thread>
void* Menu()
{
	void* q = malloc(imagesize(0, 0, getmaxx(), getmaxy()));
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

int checkMouse2(int old, int x, int y)
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
		if ((*x >= getmaxx() - 100) && (*y >= 0) && (*x <= getmaxx()) && (*y <= 100)) {
			break;
		}
	}
}
void chayDoHoa(DSMayBay ds_may_bay, PTRChuyenBay dau_chuyen_bay, PTRKhachhang goc_khach_hang)
{
	int xg = 0, yg = 50;
	void* p1 = Menu();
	void* p2 = nhanhMenu1();
	void* p3 = nhanhMenu2();
	putimage(0, 0, p1, 0);
	int x=0, y=0;
	int n = -1, tam;
	thread nhanh1(mouse, &x, &y);
	while (1) {
		tam = n;
		n = checkMouse1(n, x, y);
		switch (n)
		{
		case 0: {
			if (n != tam) {
				if (getpixel(xg + 425, yg + 88 * 1 + 35) != 0) {
					putimage(xg + 425, yg + 88 * 1, p3, 1);
				}
				putimage(xg + 425, yg + 88 * n, p2, 0);
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



void KhoiDong()
{
	initwindow(1500, 770, "quan ly chuyen bay");
}

void KetThuc()
{
	getch();
	closegraph();
}
