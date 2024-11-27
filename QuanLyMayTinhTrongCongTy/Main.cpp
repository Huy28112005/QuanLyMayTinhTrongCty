#include<iostream>
#include "CongTy.h"

int main() {
	CongTy cty;
	cty.nhap();
	cty.xuat();
	cout << "\nTong thanh tien Desktop: " << cty.tongThanhTienDesktop() << rows2;
	cout << "\nTong thanh tien Lap Top: " << cty.tongThanhTienLapTop() << rows2;
	cout << "\nTrung Binh cong don gia Desktop: " << cty.trungBinhCongDonGiaDesktop() << rows2;
	unsigned int slNew;
	MayTinh** listLapTop = cty.listLapTopTimThay(slNew);
	if (listLapTop) {
		cout << "\nSo luong lap top tim duoc: " << slNew << rows2;
		for (unsigned int i = 0; i < slNew; ++i) {
			listLapTop[i]->xuat();
			cout << "------------" << rows2;
		}
	}
	else {
		cout << "\nKhong tim thay lap top nao!" << rows2;
	}

	return 0;
}