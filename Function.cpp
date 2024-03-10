#include "Function.h"
void nhapTraiCay(Fruit& t) {
	cout << "\nNhap ma trai cay: ";
	cin >> t.ma;
	cin.ignore();
	cout << "\nNhap Ten Trai Cay: ";
	cin.getline(t.ten, 100);
	cout << "\nNhap so luong trai cay: ";
	cin >> t.soluong;
	cout << "\nNhap gia trai cay: ";
	cin >> t.giatri;
}
void nhapMangTraiCay(Fruit t[], int& n) {
	cout << "\nNhap So phan tu trai cay: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap Loai Trai Cay " << i + 1 << endl;
		nhapTraiCay(t[i]);
	}
}
void xuatTraiCay(Fruit t) {
	cout << t.ma << " " << t.ten << " " << t.soluong << " " << t.giatri << endl;
}
void xuatMangTraiCay(Fruit t[], int n) {
	for (int i = 0; i < n; i++) {
		xuatTraiCay(t[i]);
		cout << "----------------------" << endl;
	}

}
void swap(Fruit& t1, Fruit& t2) {
	Fruit temp = t1;
	t1 = t2;
	t2 = temp;
}
void SapXepTangDan(Fruit t[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i].ten > t[j].ten) {
				swap(t[i], t[j]);
			}
			else if (t[i].ten == t[j].ten) {
				if (t[i].giatri < t[j].giatri) {
					swap(t[i], t[j]);
				}
			}
		}
	}

}
float TraiCayCoGiaTriCaoNhat(Fruit t[], int n) {
	float max = t[0].giatri;
	for (int i = 0; i < n; i++) {
		max = (max > t[i].giatri ? max : t[i].giatri);
	}
	return max;
	
}
float TongGiaTriTraiCay(Fruit t[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		int tien = t[i].giatri*t[i].soluong;
		sum += tien;
	}
	return sum;
}
void GhiFile(char filename[], Fruit t[], int n) {
	ofstream output(filename);
	if (output.is_open() == false) {
		cout << "\nKhong the mo file " << filename << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		output << t[i].ma <<"-"<<t[i].ten<<"<"<< t[i].giatri << ">" << ";;" << t[i].soluong << endl;
	}
	output.close();
}
void DocFile(char filename[]) {
	ifstream input(filename);
	if (input.is_open() == false) {
		cout << "\nKhong the mo file " << filename << endl;
		return;
	}
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}
	input.close();
}
void themTraiCay(Fruit t[], int& n, int vitrithem, Fruit TraiCayThem) {
	for (int i = n-1; i >=vitrithem; i--) {
		t[i + 1] = t[i];
	}
	n++;
	t[vitrithem] = TraiCayThem;
	for (int i = 0; i < n; i++) {
		if (t[i].ten == TraiCayThem.ten && t[i].ma == TraiCayThem.ma && t[i].giatri == TraiCayThem.giatri) {
			t[i].soluong += TraiCayThem.soluong;
		}
	}
}
int GiaTraiCay(Fruit t[], int n, char ten[], float gia) {
	int soluong;
	for (int i = 0; i < n; i++) {
		if (t[i].ten == ten && t[i].giatri == gia) {
			soluong = t[i].soluong;
			return soluong;
		}
	}
	return 0;
	
}





