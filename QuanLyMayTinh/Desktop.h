#pragma once
#include "MayTinh.h"
using namespace toLower;

class Desktop : public MayTinh
{
private:
	string loaiCase;
public:
	Desktop() : MayTinh(), loaiCase("") {}
	Desktop(string loaiCase, unsigned int maMay, string nhanHieu, string hangSanXuat,
		unsigned short namSanXuat, double giaTien, unsigned int soLuong) : 
		MayTinh(maMay, nhanHieu, hangSanXuat, namSanXuat, giaTien, soLuong), loaiCase(loaiCase){ }
	~Desktop() = default;
	// getter setter
	void setLoaiCase(const string& loai) { loaiCase = loai; }
	string getLoaiCase() const { return loaiCase; }
	// nhap xuat
	void nhap() {
		MayTinh::nhap();
		cin.ignore();
		cout << "\nNhap loai may tinh (dung / nam): ";
		getline(cin, loaiCase);
	}
	void xuat() const {
		MayTinh::xuat();
		cout << "Loai case Desktop: " << loaiCase << rows2;
		cout << "Thanh tien: " << thanhTien() << " VND" << rows2;
	}
	double thanhTien() const {
		if (toLowerStr(loaiCase) == "dung")
			return soLuong * giaTien;
		else if (toLowerStr(loaiCase) == "nam")
			return (soLuong * giaTien) * 1.05;
		return 0.0;
	}
	Desktop* clone() const override {
		return new Desktop(*this);
	}
};

