#include"khai_bao.h"
#include<fstream>
void DSMayBay::napFile(const char file[])
{
	fstream file1(file, ios::binary | ios::in);
	while (!file1.eof()) {
		maybay[so_MB] = new MayBay;
		file1.read(reinterpret_cast<char*>(maybay[so_MB++]), sizeof(MayBay));
	}
	so_MB--;
	delete maybay[so_MB];
	file1.close();
}
/*ghi file may bay*/
void DSMayBay::ghiFile(const char file[]) const
{
	fstream file1(file, ios::binary | ios::out);
	for (int i = 0; i < so_MB; i++) {
		file1.write(reinterpret_cast<char*>(maybay[i]), sizeof(MayBay));
	}
	file1.close();
}
/*giai phong bo nho*/
void DSMayBay::xoa()
{
	for (int i = 0; i < so_MB; i++) {
		delete maybay[i];
	}
	this->so_MB = 0;;
}

/*doc file chuyen bay*/
//==========them may bay vao danh sach=======

void ThemMayBay(MayBay maybay,DSMayBay &DSMayBay)
{	
	if (DSMayBay.so_MB < MAX_MB) {
		MayBay* p = new MayBay;
		strcpy_s(p->sh_Mb, maybay.sh_Mb);
		strcpy_s(p->loai_may_bay,maybay.loai_may_bay);
		p->so_day = maybay.so_day;
		p->so_dong = maybay.so_dong;
		DSMayBay.maybay[DSMayBay.so_MB++] = p;
	}
}
//========xoa may bay khoi danh sach may bay====

void XoaMayBay(DSMayBay &DSMayBay,char sohieu[15])
{
	char x[15];
	strcpy_s(x, sohieu); 
	int so = 0;
	MayBay *temp =TimSoHieu(x, DSMayBay);
	if (temp != NULL) {
		for (int i = 0; i < DSMayBay.so_MB; i++) {
			if (DSMayBay.maybay[i] == temp) {
				so = i;
				delete temp;
				break;
			}
		}
		DSMayBay.so_MB--;
		while (so < DSMayBay.so_MB) {
			DSMayBay.maybay[so] = DSMayBay.maybay[so + 1];
			so++;
		}
	}
}
//==========hieu chinh may bay trong danh sach=======

void HieuChinhMB(MayBay* maybay,char sohieu[15],char loai[40],int soday,int sodong)
{
	char check[1]{}; check[0] = '\0';
	if (strcmp(check, sohieu) != 0) {
		strcpy_s(maybay->sh_Mb,15, sohieu);
	}
	if (strcmp(check, loai) != 0) {
		strcpy_s(maybay->loai_may_bay,40, loai);
	}
	if (soday > 0) {
		maybay->so_day = soday;
	}
	if (sodong > 0) {
		maybay->so_dong = sodong;
	}
}



// ======search theo so hieu may bay=======
MayBay *TimSoHieu (char x[15], DSMayBay DSmaybay) {
	for (int i = 0; i <DSmaybay.so_MB; i++) {
		if (strcmp(x, DSmaybay.maybay[i]->sh_Mb) == 0) {
			return DSmaybay.maybay[i];
		}
	}
	return NULL;
}

void napFileChuyenBay(const char file[], PTRChuyenBay &fist,DSMayBay ds)/*se sua them*/
{
	fstream file1(file, ios::binary | ios::in);
	ChuyenBay doc;
	MayBay *tam;
	int n;
	while (!file1.eof()) {
		file1.read(reinterpret_cast<char*>(&doc), sizeof(ChuyenBay));
		if (doc.trang_thai_cb != HUY_CHUYEN) {
			doc.trang_thai_cb = capNhapTT(doc.ngay_gio_kh);
		}
		tam = TimSoHieu(doc.sh_Mb, ds);
		n = tam->so_day * tam->so_dong;
		doc.ds_ve = new Ve[n];
		for (int i = 0; i < doc.so_ve; i++) {
			file1.read(reinterpret_cast<char*>(&doc.ds_ve[i]), sizeof(Ve));
		}
		themChuyenBay(fist, doc);
	}
}
/*ghi file chuyen bay*/
void ghiFileChuyenBay(const char file[], PTRChuyenBay fist)
{
	fstream file1(file, ios::binary | ios::out);
	PTRChuyenBay p;
	for (p = fist; p != NULL; p = p->next) {
		file1.write(reinterpret_cast<char*>(&p->cb), sizeof(ChuyenBay));
		for (int i = 0; i < p->cb.so_ve; i++) {
			file1.write(reinterpret_cast<char*>(&p->cb.ds_ve[i]), sizeof(Ve));
		}
	}
}
/*them chuyen bay*/
bool themChuyenBay(PTRChuyenBay &fist, ChuyenBay x)/*co sua them*/
{
	if (fist == NULL) {
		ThemDauCB(fist, x);
		return 1;
	}else
	if (strcmp(fist->cb.ma_cb, x.ma_cb) == 1) {
		ThemDauCB(fist, x);
		return 1;
	}
	if (strcmp(fist->cb.ma_cb, x.ma_cb) == 0) {
		return 0;
	}
	else {
		PTRChuyenBay p = fist;
		while (1) {
			if (p->next == NULL) {
				ThemSauCB(p, x);
				return 1;
			}else
			if ((strcmp(p->next->cb.ma_cb, x.ma_cb) == 1) ) {
				ThemSauCB(p, x);
				return 1;
			}else
			if(strcmp(p->next->cb.ma_cb, x.ma_cb) == 0) {
				return 0;
			}
			p = p->next;
		}
	}
}
/*giai phong bo nho*/
void xoahetChuyenBay(PTRChuyenBay& fist)
{
	while (fist != NULL) {
		delete fist->cb.ds_ve;
		xoadauNodeChuyenBay(fist);
	}
}
/*xoa 1 chuyen bay*/
bool xoaChuyenBay(PTRChuyenBay &fist, PTRChuyenBay p)
{
	PTRChuyenBay q = fist;
	if (fist == NULL) {
		return 0;
	}
	if (fist == p) {
		xoadauNodeChuyenBay(fist);
		return 1;
	}
	for (q = fist; q->next != NULL && q->next != p; q = q->next);
	if (q->next != NULL) {
		xoasauNodeChuyenBay(q);
		return 1;
	}
	return 0;
}
bool xoadauNodeChuyenBay(PTRChuyenBay& fist)
{
	PTRChuyenBay p;
	if (fist == NULL) {
		return 0;
	}
	p = fist;
	fist = fist->next;
	delete p;
	return 1;
}
bool xoasauNodeChuyenBay(PTRChuyenBay p)
{	
	PTRChuyenBay q;
	if ((p == NULL) || (p->next == NULL)) {
		return 0;
	}
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
/*tim chuyen bay*/
PTRChuyenBay timChuyenBay(PTRChuyenBay fist, char x[])
{	
	for (PTRChuyenBay i = fist; i != NULL; i = i->next) {
		if (strcmp(i->cb.ma_cb, x) == 0) {
			return i;
		}
	}
	return NULL;
}
int timCBtheoSHMB(PTRChuyenBay fist, char x[], int& m)
{
	int n1 = 0, n2 = 0;
	for (PTRChuyenBay i = fist; i != NULL; i = i->next) {
		if (strcmp(i->cb.sh_Mb, x) == 0) {
			n1++;
			if (i->cb.trang_thai_cb == HOAN_TAT) {
				n2++;
			}
		}
	}
	m = n2++;
	return n1;
}
/*chinh sua chuyen bay*/
void chinhsuaChuyenBay(PTRChuyenBay &p, NgayGio time, char sbd[], char shmb[])
{
	if (p != NULL) {
		if (time.gio_kh.gio >= 0) {
			p->cb.ngay_gio_kh.gio_kh.gio = time.gio_kh.gio;
		}
		if (time.gio_kh.phut >= 0) {
			p->cb.ngay_gio_kh.gio_kh.phut = time.gio_kh.phut;
		}
		if (time.ngay_kh.nam >= 0) {
			p->cb.ngay_gio_kh.ngay_kh.nam = time.ngay_kh.nam;
		}
		if (time.ngay_kh.ngay >= 0) {
			p->cb.ngay_gio_kh.ngay_kh.ngay = time.ngay_kh.ngay;
		}
		if (time.ngay_kh.thang >= 0) {
			p->cb.ngay_gio_kh.ngay_kh.thang = time.ngay_kh.thang;
		}
		if (sbd[0] != '\0') {
			strcpy_s(p->cb.san_bay_den, 100, sbd);
		}
		if (shmb[0] != '\0') {
			strcpy_s(p->cb.sh_Mb, 15, shmb);
		}
	}
}

PTRChuyenBay KhoiTaoCB()
{
	PTRChuyenBay p = new NodeChuyenBay;
	return p;
}

void ThemDauCB(PTRChuyenBay& fist, ChuyenBay x)
{
	PTRChuyenBay p;
	p = new NodeChuyenBay;
	p->cb = x;
	p->next = fist;
	fist = p;
}

void ThemSauCB(PTRChuyenBay p, ChuyenBay x)
{
	PTRChuyenBay q;
	if (p == NULL) {
	}
	else {
		q = new NodeChuyenBay;
		q->cb = x;
		q->next = p->next;
		p->next = q;
	}
}

TrangThai capNhapTT(NgayGio thoigian)
{
	time_t now = time(0);
	tm th;
	localtime_s(&th, &now);
	if (th.tm_year % 100 > thoigian.ngay_kh.nam) {
		return HOAN_TAT;
	}
	else if (th.tm_year % 100 < thoigian.ngay_kh.nam) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.thang > th.tm_mon + 1) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.thang < th.tm_mon + 1) {
		return HOAN_TAT;
	}
	else if (thoigian.ngay_kh.ngay > th.tm_mday) {
		return CON_VE;
	}
	else if (thoigian.ngay_kh.ngay < th.tm_mday) {
		return HOAN_TAT;
	}
	else if (thoigian.gio_kh.gio > th.tm_hour) {
		return CON_VE;
	}
	else if (thoigian.gio_kh.gio < th.tm_hour) {
		return HOAN_TAT;
	}
	else if (thoigian.gio_kh.phut > th.tm_min) {
		return CON_VE;
	}
	else if (thoigian.gio_kh.phut < th.tm_min) {
		return HOAN_TAT;
	}
	return CON_VE;
}
/*dat chuyen bay*/
void ChuyenBay::datChuyenBay(char macb[], NgayGio ngay, char sanbay[], char somb[], TrangThai trangthai,DSMayBay ds)
{
	if (TimSoHieu(somb, ds) != NULL) {	
		strcpy_s(this->ma_cb, 16, macb);
		this->ngay_gio_kh = ngay;
		strcpy_s(this->san_bay_den, 100, sanbay);
		strcpy_s(this->sh_Mb, 15, somb);
		MayBay *tam = TimSoHieu(somb, ds);
		this->ds_ve = new Ve[tam->so_day * tam->so_dong];
		this->trang_thai_cb = trangthai;
	}	
}

//ChuyenBay::ChuyenBay()
//{
//	this->ma_cb[0] = '\0';
//	this->san_bay_den[0] = '\0';
//	this->sh_Mb[0] = '\0';
//}
/*setup ngay gio*/
void NgayGio::datNgayGio(int gio, int phut, int ngay, int thang, int nam)
{
	if (gio >= 0) {
		this->gio_kh.gio = gio;
	}
	if (phut >= 0) {
		this->gio_kh.phut = phut;
	}
	if (ngay > 0) {
		this->ngay_kh.ngay = ngay;
	}
	if (thang > 0) {
		this->ngay_kh.thang = thang;
	}
	if (nam > 0) {
		this->ngay_kh.nam = nam;
	}
}

Ve::Ve()
{
	cmnd[0] = '\0';
	vitri[0] = '\0';
}
//tao cccd ngau nhien
void CCCDNN(char cccd[])
{
	srand(time(NULL));
	cccd[0] = rand() % (90 - 65 + 1) + 65;
	for (int i = 1; i < 10; i++) {
		cccd[i] = rand() % (57 - 48 + 1) + 48;
	}
	cccd[10] = NULL;
}
// sap ve theo so day so dong
void SapVe(char ve[],int ghe_day,int ghe_dong)
{
	ve[0] = ghe_day + (90 - 26);
	if (ghe_dong < 10) {
		ve[1] = ghe_dong + (57 - 9);
	}
	else if (ghe_dong >= 10) {
		ve[1] = ghe_dong + 55;
	}
	ve[2] = NULL;
}
// chuan hoa ngay
void SuaNgay(Ngay& day) {
	if (day.nam % 4 == 0) {
		switch (day.thang) {
		case 1:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 2:
			if (day.ngay > 29) {
				day.ngay = day.ngay - 29;
				day.thang++;
			}
			break;
		case 3:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 4:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 5:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 6:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 7:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 8:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 9:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 10:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 11:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 12:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang = 1;
				day.nam = day.nam + 1;
			}
			break;
		}
	}
	else if (day.nam % 4 != 0) {
		switch (day.thang) {
		case 1:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 2:
			if (day.ngay > 28) {
				day.ngay = day.ngay - 28;
				day.thang++;
			}
			break;
		case 3:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 4:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 5:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 6:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 7:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 8:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 9:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 10:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang++;
			}
			break;
		case 11:
			if (day.ngay > 30) {
				day.ngay = day.ngay - 30;
				day.thang++;
			}
			break;
		case 12:
			if (day.ngay > 31) {
				day.ngay = day.ngay - 31;
				day.thang = 1;
				day.nam = day.nam + 1;
			}
			break;
		}
	}
}


