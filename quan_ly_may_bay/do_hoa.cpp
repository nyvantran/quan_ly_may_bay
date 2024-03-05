#include"do_hoa.h"

void* Menu()
{
	void* q = malloc(imagesize(0, 0, getmaxx(), getmaxy()));
	settextstyle(4, HORIZ_DIR, 1);
	setfillstyle(1, 1);
	setbkcolor(1);
	int xg = 55, yg = 50;
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
	//void* p = malloc(imagesize());

	return nullptr;
}

void* nhanhMenu2()
{
	return nullptr;
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
