#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#define endl "\n"
#define rows2 "\n\n"
using namespace std;
namespace toLower {
	string toLowerStr(const string& str) {
		string tolowerStr = str;
		transform(tolowerStr.begin(), tolowerStr.end(), tolowerStr.begin(),
			[](char a) {return tolower(a); });
		return tolowerStr;
	}
}

class MayTinh
{
protected:
	unsigned int maMay;
	string nhanHieu;
	string hangSanXuat;
	unsigned short namSanXuat;
	double giaTien;
	unsigned int soLuong;
public:
	MayTinh() : maMay(0), nhanHieu(""), hangSanXuat(""), namSanXuat(0),
		giaTien(0.0), soLuong(0){ }
	MayTinh(unsigned int maMay, string nhanHieu, string hangSanXuat,
		unsigned short namSanXuat, double giaTien, unsigned int soLuong) : 
		maMay(maMay), nhanHieu(nhanHieu), hangSanXuat(hangSanXuat),
		namSanXuat(namSanXuat), giaTien(giaTien), soLuong(soLuong){ }
	~MayTinh() = default;
	// getter setter

	// Mã máy tính
	void setMaMay(unsigned int maMT) { maMay = maMT; }
	unsigned int getMaMay() const { return maMay; }
	// Nhãn hiệu
	void setNhanHieu(const string& nhanHieu) { this->nhanHieu = nhanHieu; }
	string getNhanHieu() const { return nhanHieu; }
	//hãng sản xuất
	void setHangSanXuat(const string& hangSX) { hangSanXuat = hangSX; }
	string getHangSanXuat() const { return hangSanXuat; }
	//Năm sản xuất
	void setNamSanXuat(unsigned short namSX) { namSanXuat = namSX; }
	unsigned short getNamSanXuat() const { return namSanXuat; }
	//giá tiền
	void setGiaTien(double gia) { giaTien = gia; }
	double getGiaTien() const { return giaTien; }
	// số lượng
	void setSoLuong(unsigned int sl) { soLuong = sl; }
	unsigned int getSoLuong() const { return soLuong; }
	// nhập xuất
	virtual void nhap() {
		cout << "\nNhap Ma May tinh: "; cin >> maMay; cin.ignore();
		cout << "\nNhap Nhan hieu: "; getline(cin, nhanHieu);
		cout << "\Nhap Hang san xuat: "; getline(cin, hangSanXuat);
		cout << "\nNhap Nam san xuat: "; cin >> namSanXuat;
		cout << "\nNhap don gia: "; cin >> giaTien;
		cout << "\nNhap so luong: "; cin >> soLuong;
	}
	virtual void xuat() const {
		cout << "\nMa May Tinh: " << maMay << rows2;
		cout << "Nhan Hieu: " << nhanHieu << rows2;
		cout << "Hang san xuat: " << hangSanXuat << rows2;
		cout << "Nam san xuat: " << namSanXuat << rows2;
		cout << "Don Gia: " << giaTien << rows2;
		cout << "So luong: " << soLuong << rows2;
	}
	virtual double thanhTien() const = 0;
	virtual MayTinh* clone() const = 0;

};

