#pragma once
#include <bits/stdc++.h>
#include"PerCusEmpTask.cpp" 
// tim vi tri cua employee
int PosEmployee(string id) {
    int tmp = -1 ; 
    for(int i=0;i<listEmployee.size();i++) {
        if(listEmployee[i].getId()==id)tmp = i ; 
    }
    return tmp ; 
}
//kiem tra mat khau cua employee 
bool CheckPassEmployee(int const pos, string const pass) {
    if(pos==-1) return false ; 
    if(listEmployee[pos].getPass()==pass) return true ;
    else {
        return false ; 
    }
} 
//tim kiem khach hang theo dia chi id
int Pos(string id) {
    int tmp = -1 ; 
    for(int i=0;i<listCustomer.size();i++) {
        if(listCustomer[i].getId()==id)tmp = i ; 
    }
    return tmp ; 
}
//kiem tra dang nhap cua khach hang 
bool CheckPass(int const pos, string const pass) {
    if(pos==-1) return false ; 
    if(listCustomer[pos].getPass()==pass) return true ;
    else {
        return false ; 
    }
} 
//Cap nhat task lam viec cho nhan vien  
void UpdateTask(int pos, vector<Task>&listTask , vector<Customer>& listCustomer ) {
    string id = listEmployee[pos].getId() ; 
    int cnt = 0;
    char c ; 
    for(int i=0;i<listTask.size();i++) {
        if(listTask[i].getEmployeeId()==id&&listTask[i].getStatus()==DangGiao) {
              cout<<listTask[i] ; 
              cnt ++ ; 
              cout<<"\t\tBan co muon cap nhat don hang [Y/N] " ;
              cin>>c; 
              if(c=='y'||c=='Y') {
                listTask[i].setStatus(DaGiao) ;
                string idCus = listTask[i].getCustomerId() ; 
                int posCus = Pos(idCus) ; 
                if(posCus!=-1) listCustomer[posCus].input_Task(listTask[i]);
                cout<<"\t\tDon hang da duoc cap nhat" ;  
              } 
        }
        if(!cnt) cout<<"\t\tKhong co don hang nao" << endl; 
    } 
}
// ham nhan nhiem vu cu nhan vien
void receiveTask(int pos,vector<Employee>&listEmployee, vector<Task>& listTask) {
    if (listTask.empty()) {
        cout << "Khong co nhiem vu de nhan." << endl;
        return;
     }
    int cnt = 0 ; 
    for(int i=0;i<listTask.size();i++) {
        if(listTask[i].getStatus()==Doi) {
             cout<<listTask[i] ; 
             cout<<"An phim '1' de nhan, phim '2' de bo qua: " ; 
             cin>> cnt ; 
             if(cnt==1) {
                listTask[i].setStatus(DangGiao) ;//hisTask
                listTask[i].setEmployeeId(listEmployee[pos].getId()) ;
                
                listCustomer[pos].upStatusHisTask(listTask[i].getItemId(),listEmployee[pos].getId());
             } 
        }
    } 
    cin.ignore() ; 
    if(!cnt) cout<<"khong con nhiem vu nao de nhan" <<endl;
     }
// ham tang luong cho nhan vien 
    /**/
//doc nhan vien tu mot file 
void readFromFileEmp(const string& filename, vector<Employee>& employees) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        vector<string> lines;
        int employeeCount = 0;
        // doc tung dong tu line va luu vao vector 
        while (getline(file, line)) {
            lines.push_back(line);
        }
        //xoa cac dong cuoi cung neu co 
        while (!lines.empty() && lines.back().empty()) {
            lines.pop_back();
        }
        if (lines.size() < 8) {
            cout << "Khong the doc duoc file" << endl;
            return;
        }
        for (int i = 0; i < lines.size(); i += 8) {
            string id = removeWhitespaceFirstEnd(lines[i].substr(4)); // B? di ph?n "ID: "
            string pass = removeWhitespaceFirstEnd(lines[i + 1].substr(10));//B? di phan "Mat khau: "
            string name = removeWhitespaceFirstEnd(lines[i + 2].substr(5)); // B? di ph?n "Ten: "
            string birth = removeWhitespaceFirstEnd(lines[i + 3].substr(11)); // B? di ph?n "Ngay sinh: "
            string sex = removeWhitespaceFirstEnd(lines[i + 4].substr(11)); // B? di ph?n "Gioi tinh: "
            string emailAddress = removeWhitespaceFirstEnd(lines[i + 5].substr(7)); // B? di ph?n "Email: "
            string phoneNumber = removeWhitespaceFirstEnd(lines[i + 6].substr(5)); // B? di ph?n "SDT: "
            double salary = stod(lines[i + 7].substr(7)); // 
            // 
            Employee employee;
            employee.setId(id);
            employee.setName(name);
            employee.setPass(pass);
            employee.setBirth(birth);
            employee.setSex(sex);
            employee.setEmailAddress(emailAddress);
            employee.setPhone(phoneNumber);
            employee.setSalary(salary);
            // Thêm d?i tu?ng Employee vào vector employees
            employees.push_back(employee);
            employeeCount++;
        }
        file.close();
        cout << "Doc thanh cong " << employeeCount << " nhan vien tu file " << filename << endl;
    } else {
        cout << "Khong the mo file " << filename << " de doc thong tin nhan vien." << endl;
    }
}
// Chuc nang cua khach hang 
// doc khach hang tu file Customers.txt
void readFromFileCus(const std::string& filename, vector<Customer>& listCustomer) {
    std::ifstream file(filename); 

    if (file.is_open()) {
        std::string line;
        std::vector<std::string> lines;
        int customerCount = 0;

        //Doc tung dong luu vao vector 
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        
        while (!lines.empty() && lines.back().empty()) {
            lines.pop_back();
        }
        
        if (lines.size() < 12) {
            cout << "Khong dung dinh dang. Khong the doc thong tin nhan vien." << endl;
            return;
        }
        
        for (int i = 0; i < lines.size(); i += 12) {
            //Trich xuat thong tin trong vector<string>line 
            string id = removeWhitespaceFirstEnd(lines[i].substr(4));
            string pass = removeWhitespaceFirstEnd(lines[i+1].substr(10));
            string name = removeWhitespaceFirstEnd(lines[i+2].substr(8));
            string birth = removeWhitespaceFirstEnd(lines[i+3].substr(11));
            string sex = removeWhitespaceFirstEnd(lines[i+4].substr(11));
            string phone = removeWhitespaceFirstEnd(lines[i+5].substr(5));
            string email = removeWhitespaceFirstEnd(lines[i+6].substr(7));
            string province = removeWhitespaceFirstEnd(lines[i+7].substr(12));
            string district = removeWhitespaceFirstEnd(lines[i+8].substr(12));
            string ward = removeWhitespaceFirstEnd(lines[i+9].substr(10));
            string street = removeWhitespaceFirstEnd(lines[i+10].substr(7));
            string houseNumber = removeWhitespaceFirstEnd(lines[i+11].substr(8));
            //Gan thong tin cho tung Customer 
            Customer customer;
            customer.setId(id);
            customer.setPass(pass);
            customer.setName(name);
            customer.setBirth(birth);
            customer.setSex(sex);
            customer.setPhone(phone);
            customer.setEmailAddress(email);
            Address a; a.province=province; a.district=district; a.ward=ward; a.street=street; a.houseNumber=stoi(houseNumber);
            customer.setAddress(a);
            listCustomer.push_back(customer);
            customerCount++;
        }
        std::cout << "Doc file thanh cong " << customerCount << " khach hang tu file" << filename << std::endl;
        file.close(); // dong file sau khi doc xong
    } else {
        std::cout << "Khong the mo file." << filename << "de doc thong tin khach hang" << std::endl;
    }
}
// thay doi thong tin ca nhan 
void Set_inforCus(int const pos) {
    int n ; 
    while(1) {
        system("cls") ; 
gotoxy(42,3);      cout<<"Chon thong tin muon thay doi "; 
gotoxy(42,4);      cout<<"+------------------------+" ;
gotoxy(42,5);      cout<<"|1.Thay doi so dien thoai|" ;
gotoxy(42,6);      cout<<"|2.Thay doi dia chi      |" ; 
gotoxy(42,7);      cout<<"|3.Thay doi email        |" ;
gotoxy(42,8);      cout<<"|4.Thay doi mat khau     |" ;
gotoxy(42,9);      cout<<"|0.Thoat phien lam viec  |" ;
gotoxy(42,10);     cout<<"+------------------------+" ;
gotoxy(42,11);     cout<<"Moi ban nhap lua chon: " ; 
      cin >> n ; cin.ignore() ; 
      switch (n)
      {
      case 1 : {
        system("cls") ; 
        string phone ; 
        string pass ;
        cout<<"\t\tNhap pass truoc khi thay doi: " ;cin>>pass ; cin.ignore() ;
        while(!CheckPass(pos,pass)) {
            cout<<"\t\tMat khau dang nhap sai " ; 
            cout<<"\t\tAn phim '0' de thoat hoac nhap lai mat khau: " << endl;
            cin>>pass ; cin.ignore() ;
            if(pass=="0") return ; 
        }  
        cout << "\t\tNhap so dien thoai muon thay doi: " ; cin >> phone ;
        listCustomer[pos].setPhone(phone) ; 
        break; 
      }
      case 2: {
        system("cls") ; 
        string pass ;
        cout<<"\t\tNhap pass truoc khi thay doi: " ;cin>>pass ; cin.ignore() ;
        while(!CheckPass(pos,pass)) {
            cout<<"\t\tMat khau dang nhap sai " ; 
            cout<<"\t\tAn phim '0' de thoat hoac nhap lai mat khau: " << endl;
            cin>>pass ; cin.ignore() ;
            if(pass=="0") return ; 
        }  
        Address tmp ;
        cout<<"\t\tNhap dia chi moi \n " ; 
        cout << "\t\tTinh/Thanh: " ;getline(cin, tmp.province) ; 
        toUpperCase(tmp.province) ; 
        cout << "\t\tQuan/Huyen: " ; getline(cin,tmp.district) ;
        toUpperCase(tmp.district) ;  
        cout << "\t\tPhuong/Xa: " ; getline(cin,tmp.ward) ; 
        toUpperCase(tmp.ward) ;   
        cout << "\t\tDuong: " ; getline(cin, tmp.street) ;
        toUpperCase(tmp.street) ;   
        cout << "\t\tSo nha: " ; cin>>tmp.houseNumber ; cin.ignore() ;
        listCustomer[pos].setAddress(tmp) ;  
        break; 
      }
      case 3: {
        system("cls") ; 
            string pass ;
            cout<<"\t\tNhap pass truoc khi thay doi: " ;cin>>pass ; cin.ignore() ;
             while(!CheckPass(pos,pass)) {
            cout<<"\t\tMat khau dang nhap sai " ; 
            cout<<"\t\tAn phim '0' de thoat hoac nhap lai mat khau: " << endl;
            cin>>pass ; cin.ignore() ;
            if(pass=="0") return ; 
        }  
        string tmp ; 
        cout<<"\t\tNhap email moi: " ;cin>>tmp ; cin.ignore() ;
        listCustomer[pos].setEmailAddress(tmp) ; 
        break; 
      }
      case 4: {
            system("cls") ; 
             string pass ;
            cout<<"\t\tNhap pass truoc khi thay doi: " ;cin>>pass ; cin.ignore() ;
             while(!CheckPass(pos,pass)) {
            cout<<"\t\tMat khau dang nhap sai " ; 
            cout<<"\t\tAn phim '0' de thoat hoac nhap lai mat khau: " ; 
            cin>>pass ; cin.ignore() ;
            if(pass=="0") return ; }
            cout << "\t\tNhap mat khau moi: " ; 
            getline(cin,pass) ; 
            listCustomer[pos].setPass(pass) ; 
            break ;
      } 
      case 0: return ; 
      default:
        system("cls") ; 
        cout << "\t\tKhong hop le" ;
        break ; 
      }
    }
}
//doc tu file task.txt
void readFromFileTask (const string filename , vector<Task> &listTask) {
      ifstream file; 
      file.open(filename) ;
      string line ;
      Product tmp ;  
      int n; 
      Task a;  
      if(file.is_open()) {
        while(!file.eof()){ 
            Address deliveryAddress , receivingAddress ; vector<Product> products ; int shippingFee , status ; string date ;
            string itemId , customerId, employeeId ; 
            file>>itemId; a.setItemId(itemId) ;  
            file>>customerId; a.setCustomerId(customerId) ; 
            file>>employeeId; a.setEmployeeId(employeeId) ; 
            file.ignore() ; 
            getline(file,line) ; 
            getline(file,deliveryAddress.province) ; 
            getline(file,deliveryAddress.district) ; 
            getline(file,deliveryAddress.ward) ;
            file>>deliveryAddress.hamlet ; file.ignore() ;
            getline(file,deliveryAddress.street) ;
            file>>deliveryAddress.houseNumber ;
            file.ignore() ;
            a.setDeliveryAddress(deliveryAddress) ; 
            //dia chi nhan
            getline(file,line) ; 
            getline(file,receivingAddress.province) ; 
            getline(file,receivingAddress.district) ; 
            getline(file,receivingAddress.ward) ;
            file>>receivingAddress.hamlet ; file.ignore() ;
            getline(file,receivingAddress.street) ;
            file>>receivingAddress.houseNumber ;
            file.ignore() ;
            a.setReceivingAddress(receivingAddress) ;
            getline(file,line) ;
            file>>n ; 
            for(int i=0;i<n;i++) {
                file.ignore() ;
                getline(file,tmp.itemType) ; 
                file>>tmp.numberOfItems ; 
                products.push_back(tmp) ; 
            } 
            a.setProducts(products) ; 
            file>>shippingFee ; 
            a.setShippingFee(shippingFee) ; 
            file.ignore() ;
            getline(file,date) ; 
            a.setDate(date) ; 
            file>>status ; 
            a.setStatus(status) ; 
            listTask.push_back(a) ; 
        }
        listTask.pop_back() ;
        cout << "Doc thanh cong " << listTask.size() << " don hang tu file." << endl; 
        file.close() ; 
      }else {
        cout<<"can not open the file. " ; 
      }
}
// friend void readHisTask dung de doc nhung lich su don hang cua file MaId.txt
void readHisTask(vector<Customer>&listCustomer) {
      for(int i=0;i<listCustomer.size();i++) {
         string fileName = listCustomer[i].getId()+".txt" ; 
         readFromFileTask(fileName,listCustomer[i].hisTask) ; 
      }
} 
// chuc nang quan li
//tim  kiem khach hang theo dia chi id 
void FindCusById(vector<Customer>&listCustomer) {
	cout<<"\t\tMoi ban nhap vao id cua khach hang muon xem thong tin: " ;
	string id ;
	getline(cin,id) ;
    int pos = Pos(id) ; 
    if (pos==-1) cout << "\t\tKhong tim thay khach hang co ID " << id << endl;
    else {
        cout<<listCustomer[pos] ; 
    }
} 
//cap nhap thong tin khach hang
void Set_Infor_Cus(vector<Customer>&listCustomer) {
	cout<<"\t\tMoi ban nhap vao id cua khach hang muon thay doi :" << endl ;
	string id ;
	cout<<"\t\t"; cin >> id  ;
	int pos = Pos(id) ; 
	while(pos==-1) {
	   cout<<"\t\tDia chi khach hang khong ton tai !!!\n" ;
       cout<<"\t\tNhap lai dia chi id hoac bam '0' de thoat chuong trinh " ;
       cin >> id ;  
       if(id=="0") return ; 
       else pos = Pos(id) ;  
       cin.ignore() ; 
	}  
    while(1) {
    system("cls") ; 
    gotoxy(42,3) ;   cout<<"chon thong tin muon thay doi"  ;
    gotoxy(42,4);	cout<<"+------------------------------------------+" ; 
    gotoxy(42,5);	cout<<"|1. Thay doi mat khau :                    |" ;
    gotoxy(42,6);	cout<<"|2. Thay doi ten :                         |" ;
    gotoxy(42,7);	cout<<"|3. thay doi dia chi:                      |" ; 
    gotoxy(42,8);	cout<<"|4. Thay doi so dien thoai:                |" ; 
    gotoxy(42,9);	cout<<"|5. Thay doi dia chi email:                |" ;
	gotoxy(42,10);	cout<<"|6. Thay doi toan bo thong tin khach hang: |" ;  
    gotoxy(42,11);	cout<<"|0. Thoat trinh lam viec :                 |" ;
    gotoxy(42,12);  cout<<"+------------------------------------------+" ;
    gotoxy(42,13); cout<<"Moi ban nhap vao lua chon " ; 
    	int n ; char c  ; 
		cin >>n  ; 
    	cin.ignore() ; 
    	switch (n) {
    		case 1: {
            system("cls") ; 
    		cout <<"\t\tMoi ban nhap mat khau moi :"  ;
    		string mk ; 
    		getline(cin,mk) ; 
    		listCustomer[pos].setNewPass(mk) ; 
				break;
			}
    		case 2:{
                system("cls") ; 
                cout<<"\t\tAn phim '0' de quay tro lai hoac bat ki de tiep tuc: "; cin>>c ; cin.ignore() ; if(c=='0')break; 
    			cout<<"\t\tMoi ban nhap ho ten moi: " ;
    			string name ;
    			getline(cin,name);
    			listCustomer[pos].setName(name) ; 
				break;
			}	
			case 3:{system("cls") ;
                    cout<<"\t\tAn phim '0' de quay lai hoac bat ki de tiep tuc: "; cin >> c; cin.ignore() ;if(c=='0')break; 
				    cout<<"\t\tmoi ban nhap vao dia chi moi: " << endl ;
				Address address ; 
					cout<<"\t\tTinh/Thanh Pho: " ; getline(cin,address.province) ;
					cout<<"\t\tQuan/Huyen: " ; getline(cin,address.district) ;
					cout<<"\t\tPhuong/xa: " ; getline(cin,address.ward) ;
					cout<<"\t\tTen Duong: " ; getline(cin,address.street) ; 
					cout<<"\t\tso Nha: " ; cin >> address.houseNumber ; 
					cin.ignore() ; 
					listCustomer[pos].setAddress(address) ;
                    cout<<"\t\tBan da cap nhat thanh cong\n" ; 
                    system("pause") ;
				break;
			} 
			case 4: {
                system("cls") ; 
                cout<<"\t\tNhan phim '0' de quay lai hoac bat ki de tiep tuc: "; cin >> c; cin.ignore();if(c=='0')break; 
				string phone ; 
				cout<<"\t\tNhap so dien thoai muon thay doi: " ;
				getline(cin,phone) ; 
				listCustomer[pos].setPhone(phone) ;
                cout<<"\t\tBan da cap nhat thanh cong\n" ; 
                system("pause") ;   
				break;
			} 
			case 5: {
                system("cls") ; 
				cout<<"\t\tNhan phim so '0' de quay lai hoac bat ki de tiep tuc :" ; cin >> c ; cin.ignore() ; if(c=='0') break;   
                cout<<"\t\tMoi ban nhap dia chi Email moi: " ; string tmp ; getline(cin,tmp) ; 
                listCustomer[pos].setEmailAddress(tmp) ; 
                cout<<"\t\tBan da cap nhat thanh cong \n" ;
                system("pause") ;  
				break;
			} 
			case 6: { 
                system("cls") ;
               cout<<"\t\tThay doi toan bo thong tin khach hang: " << listCustomer[pos].getName() <<" ma so id: " << listCustomer[pos].getId() << endl ;
                cout<<"\t\tBam phim '0' de quay lai " ; cin >> c; cin.ignore(); if(c=='0')break;  
			    cin >> listCustomer[pos] ;
                cout<<"\t\tCap nhat thong tin thanh cong \n" ;
                system("pause") ; 
				break  ; 
			} 
			case 0:{
                system("cls") ;
				return ; 
			}  
		}
	} 
}
// chuc nang them 1 khach hang 
void InPut_Cus(vector<Customer>&listCustomer) {
	cout<<"Nhap thong tin cua khach hang ban muon them\n" ; 
	Customer a ; 
	cin >> a;
	listCustomer.push_back(a) ; 
} 
//chuc nang 8 tim kiem mot khach hang khach hang theo ten 
void FindCusByName(const vector<Customer>listCustomer) {
	cout<<"Nhap ten khach hang muon tim: " ; 
	string name ; 
	getline(cin,name) ; toUpperCase(name);
	int cnt = 0 ;
	for(int i=0;i<listCustomer.size();i++) {
		if(name==listCustomer[i].getName()) {
			cnt ++ ; 
			cout << listCustomer[i]; 
		} 
	} 
	if(cnt==0) cout<< "Khong tim thay khach hang co ten nhu tren \n" ;
	else cout<<"Danh sach hien co: " << cnt << " nguoi.\n" ;
} 
// tim kiem khach hang theo so dien thoai  
void FindCusByPhone(const vector<Customer>listCustomer) {
	cout<<"\t\tNhap so dien thoai khach hang muon tim: " ; 
	string phone ; 
	cin>>phone ; cin.ignore() ; 
	int cnt = 0 ;
	for(int i=0;i<listCustomer.size();i++) {
		if(phone==listCustomer[i].getPhone()) {
			cnt ++ ; 
			cout << listCustomer[i]; 
		} 
	} 
	if(cnt==0) cout<< "\t\tKhong tim thay khach hang co so dien thoai nhu tren \n" ;  
	else cout<<"\t\tDanh sach hien co: " << cnt << " nguoi.\n" ; 
}
// tim kiem khach hang theo dia chi thanh pho 
void FindCusByCity(const vector<Customer>listCustomer) {
	  cout<<"\t\tnhap thanh pho ban muon xuat thong tin khach hang: " ; 
	  string city ;
	  getline(cin,city) ; toUpperCase(city);
	  int cnt = 0;  
	  for(int i=0;i<listCustomer.size();i++) {
	  	 if(city==listCustomer[i].getAddress().province) {
	  	 	cout << listCustomer[i]; 
	  	 	cnt++ ; 
		   }
	  } 
	  if(cnt==0) cout<<"\t\tKhong co khach hang tuong ung\n" ; 
	  else cout<<"\t\tDanh sach tren hien co: " << cnt <<" nguoi.\n" ; 
} 
// tim kiem va xoa khach hang theo dia chi id 
void removeCustomer(vector<Customer>& customer, const string& id) {
    bool found = false; 
    for (auto it = customer.begin(); it !=customer.end(); ) {
        if (it->getId() == id) {
            it = customer.erase(it);
            found = true;
            break;  // Thoat khoai vong lap sau khi xoa nhan vien tim thay 
        }
        else {
            ++it;
        }
    }
    // Kiem tra va thong bao ket qua 
    if (found) {
        cout << "\t\tDa xoa khach hang co ID " << id << endl;
    }
    else {
        cout << "\t\tKhong tim thay khach hang co ID " << id << endl;
    }
}
// xoa nhan vien theo dia chi id 
void removeEmployee(vector<Employee>& employees, const string& id) {
    bool found = false;  // kiem tra xem co nhan vien co id can xoa hay khong
    //Duyet qua va xoa thong tin nhan vien co dia chi id trung khop 
    for (auto it = employees.begin(); it != employees.end(); ) {
        if (it->getId() == id) {
            it = employees.erase(it);
            found = true;
            break;}  // thoat khoi vong lap
        else {
            ++it;
        }
    }

    //kiem tra va thong bao ket qua
    if (found) {
        cout << "\t\tDa xoa nhan vien co ID " << id << endl;
    }
    else {
        cout << "\t\tKhong tim thay nhan vien co ID " << id << endl;
    }
}
/*xoa don hang theo dia chi id*/

