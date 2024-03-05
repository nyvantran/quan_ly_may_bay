#include"khai_bao.h"
//#include<fstream>
/*doc file may bay*/
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
void DSMayBay::xoa() const
{
	for (int i = 0; i < so_MB; i++) {
		delete maybay[i];
	}
}
/*doc file chuyen bay*/
void napFileChuyenBay(const char file[], PTRChuyenBay &fist)/*se sua them*/
{
	fstream file1(file, ios::binary | ios::in);
	ChuyenBay doc;
	PTRChuyenBay here = NULL;
}
/*ghi file chuyen bay*/
void ghiFileChuyenBay(const char file[], PTRChuyenBay fist)
{
	fstream file1(file, ios::binary | ios::out);
	PTRChuyenBay p;
	for (p = fist; p->next != NULL; p = p->next) {
		/*file1.write(reinterpret_cast<char*>(p->cb.ma_cb), sizeof(char*));
		file1.write(reinterpret_cast<char*>(&p->cb.ngay_gio_kh), sizeof(NgayGio));
		file1.write(reinterpret_cast<char*>(p->cb.san_bay_den), sizeof(char*));
		file1.write(reinterpret_cast<char*>(p->cb.sh_Mb), sizeof(char*));
		file1.write(reinterpret_cast<char*>(&p->cb.trang_thai_cb), sizeof(TrangThai));*/
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
	PTRChuyenBay p = fist, tam;
	while (p != NULL) {
		tam = p->next;
		delete p;
		p = tam;
	}
	fist = NULL;
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

ChuyenBay::ChuyenBay()
{
	this->ma_cb[0] = '\0';
	this->san_bay_den[0] = '\0';
	this->sh_Mb[0] = '\0';
}
/*setup ngay gio*/
void NgayGio::datNgayGio(int gio, int phut, int ngay, int thang, int nam)
{
	if (gio >= 0) {
		this->gio_kh.gio = gio;
	}
	if (phut > 0) {
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
