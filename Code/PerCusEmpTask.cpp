#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <ctime> 
#include <bits/stdc++.h>
#include"FileDoHoa.cpp"
using namespace std;
time_t now = time(0) ; 
void toUpperCase(std::string& name);
string Tao_Email(string  name , string  birth) ; 
class Person {
private :
	string password ; 
    string name;
    string birth;
    string sex ; 
    string emailAddress;
    string id; 
    string phoneNumber ;
public:
    Person();
    Person(string id, string name , string birth, string sex, string emailAddress, string Pass, string PhoneNumber);
    void setName(string name);
    void setBirth(string birth);
    void setSex(string sex);
    void setEmailAddress(string emailAddress);
	void setPhone(string phoneNumber);
	string getPass() const; 
    string getName()const;
    string getBirth()const;
    string getSex()const;
    string getEmailAddress()const;
    string getId()const;
    string getPhone()const;
	void setNewId(string id);
	void setNewPass(string pass);
    void setId(string id); 
    void setPass(string pass);
    virtual string generatePassword() = 0;
    virtual string generateID() = 0;
    virtual void changePassword() = 0;
	void outPass(); 
    void display() const; 
};

//dinh nghia class Person
Person::Person() : password(""), name(""), birth(""), sex(""), emailAddress(""), id(""), phoneNumber("") {}
Person::Person(string id, string name , string birth, string sex, string emailAddress, string Pass, string PhoneNumber){
    this -> name = name;
    this -> birth = birth;
    this -> sex = sex;
    this -> emailAddress = emailAddress;
    this -> id = id;
    this -> password = Pass ; 
    this -> phoneNumber = PhoneNumber ; 
}

//cac ham setter
void Person::setId(string id){this -> id = id;} 
void Person::setPass(string pass){this->password = pass;}
void Person::setName(string name){this -> name = name;}
void Person::setBirth(string birth){this -> birth = birth;}
void Person::setSex(string sex){this -> sex = sex;}
void Person::setEmailAddress(string emailAddress){this -> emailAddress = emailAddress;}
void Person::setPhone(string phoneNumber) {this->phoneNumber = phoneNumber;}
void Person::setNewId(string id) {setId(id);} 
void Person::setNewPass(string pass) {setPass(pass);}

//cac ham getter
string Person::getPass() const{return password;}
string Person::getName()const{return name;}
string Person::getBirth()const{return birth;}
string Person::getSex()const{return sex;}
string Person::getEmailAddress()const{return emailAddress;}
string Person::getId()const{return id;} 
string Person::getPhone() const{return phoneNumber;}

//ham tinh nang quan li thong tin
void Person::outPass() {
    cout << getPass() ; 
}
void Person::display() const{
    cout << "ID: " << id << endl;
    cout << "Ten: " << name << endl;
    cout << "Ngay sinh: " << birth << endl;
    cout << "Gioi tinh: " << sex << endl;
    cout << "Email address: " << emailAddress << endl;
    cout << "So dien thoai: " << phoneNumber << endl ; 
}

string removeWhitespaceFirstEnd(const std::string& input) {   
    std::string output = input;
    // Xóa khoảng trắng ở đầu chuỗi
    output.erase(0, output.find_first_not_of(' '));
    // Xóa khoảng trắng ở cuối chuỗi
    output.erase(output.find_last_not_of(' ') + 1);
    return output;
}


struct Address {
    string province;
    string district;
    string ward;
    string hamlet;
    string street;
    int houseNumber;
};

struct Product {
    string itemType;
    int numberOfItems;
};

enum Status {
    Doi = 0, DangGiao = 1, DaGiao = 2
};

class Task {
private:
    Address deliveryAddress;
    Address receivingAddress;
    string itemId;
    vector<Product> products;
    int shippingFee;
    string employeeId;
    string customerId;
    string date ; 
    int status;
public:
    Task() : status(Doi) {
        employeeId = "";
    }
    string generateID() ; 
    Task(const Address& deliveryAddress, const Address& receivingAddress, const string& itemId,
        const vector<Product>& products, const int& shippingFee, string date)
        : deliveryAddress(deliveryAddress), receivingAddress(receivingAddress), itemId(itemId),
        products(products), shippingFee(shippingFee) {
       date = new char [10000] ; 
        employeeId = "";
        status = Doi;
    } 
    void setDate(const string c) ;
    string getDate() const;
    void setDeliveryAddress(const Address& address);
    Address getDeliveryAddress() const;
    void setReceivingAddress(const Address& address);
    Address getReceivingAddress() const;
    void setItemId(const string& id);
    string getItemId() const;
    void setProducts(const vector<Product>& products);
    vector<Product> getProducts() const;
    void setShippingFee(const int& fee);
    int getShippingFee() const;
    void setEmployeeId(const string& id);
    string getEmployeeId() const;
    void setCustomerId(const string& id);
    string getCustomerId() const;
    void setStatus(int a);
    int getStatus() const;
    void calculateShippingFee();
    friend istream& operator>>(istream& is, Task& task);
    friend ostream& operator<<(ostream& os, Task task);
    void saveToFile( string filename) const;
};

string Task::generateID() {
    string id;
    const string charset = "0123456789";
    srand(time(nullptr)); // Kh?i t?o seed cho hàm rand()
    for (int i = 0; i < 5; i++) {
        int index = rand() % charset.length();
        id += charset[index];
    }
    id = "0" + id;
    return id;
}
void Task::setDate(const string c) {
    date = c ; 
}
string Task::getDate() const {
    return date;
}

void Task::setDeliveryAddress(const Address& address) {
    deliveryAddress = address;
}

Address Task::getDeliveryAddress() const {
    return deliveryAddress;
}

void Task::setReceivingAddress(const Address& address) {
    receivingAddress = address;
}

Address Task::getReceivingAddress() const {
    return receivingAddress;
}

void Task::setItemId(const string& id) {
    itemId = id;
}

string Task::getItemId() const {
    return itemId;
}

void Task::setProducts(const vector<Product>& p) {
    products = p;
}

vector<Product> Task::getProducts() const {
    return products;
}

void Task::setShippingFee(const int& fee) {
    shippingFee = fee;
}

int Task::getShippingFee() const {
    return shippingFee;
}

void Task::setEmployeeId(const string& id) {
    employeeId = id;
}

string Task::getEmployeeId() const {
    return employeeId;
}

void Task::setCustomerId(const string& id) {
    customerId = id;
}

string Task::getCustomerId() const {
    return customerId;
}

void Task::setStatus(int a) {
    status = a;
}

int Task::getStatus() const {
    return status;
}
void Task::calculateShippingFee() {
    int totalQuantity = 0;
    for (const Product& product : products) {
        totalQuantity += product.numberOfItems;
    }
    shippingFee = totalQuantity * 10;
}
ostream& operator<<(ostream& os, Task task){
    os << "\t\tId Don hang: " << task.getItemId()<<" || "<<"Id Nhan Vien: "<<task.getEmployeeId()<<" || " <<"Id khach hang: "<<task.getCustomerId()<<endl;
    os << "\t\tDia chi giao hang:" << endl;
    os << "\t\tTinh/Thanh: " << task.deliveryAddress.province << endl;
    os << "\t\tQuan/Huyen: " << task.deliveryAddress.district << endl;
    os << "\t\tPhuong/Xa: " << task.deliveryAddress.ward << endl;
    os << "\t\tTo: " << task.deliveryAddress.hamlet << endl;
    os << "\t\tDuong: " << task.deliveryAddress.street << endl;
    os << "\t\tSo nha: " << task.deliveryAddress.houseNumber << endl;
    os << "\t\tDia chi nhan hang:" << endl;
    os << "\t\tTinh/Thanh: " << task.receivingAddress.province << endl;
    os << "\t\tQuan/Huyen: " << task.receivingAddress.district << endl;
    os << "\t\tPhuong/Xa: " << task.receivingAddress.ward << endl;
    os << "\t\tTo: " << task.receivingAddress.hamlet << endl;
    os << "\t\tDuong: " << task.receivingAddress.street << endl;
    os << "\t\tSo nha: " << task.receivingAddress.houseNumber << endl;
    os << "\t\tMa san pham: " << task.itemId << endl;
    os << "\t\tDanh sach san pham:" << endl;
    for (const auto& product : task.products) {
        os << "\t\tLoai san pham: " << product.itemType << endl;
        os << "\t\tSo luong: " << product.numberOfItems << endl;
    }
    os << "\t\tPhi van chuyen: " << task.shippingFee <<endl;  
    os << "\t\tNgay dat don: " << task.date << endl; 
    os << "\t\tTrang thai: ";
    switch (task.status) {
        case Doi:
            os << "Doi" << endl;
            break;
        case DangGiao:
            os << "DangGiao" << endl;
            break;
        case DaGiao:
            os << "DaGiao" << endl;
            break;
    }
    return os;
}
istream& operator>>(istream& is, Task& task) {
    cout << "\t\tNhap dia chi giao hang:" << endl;
    cout << "\t\tTinh/Thanh: ";
    getline(is, task.deliveryAddress.province);
    toUpperCase(task.deliveryAddress.province) ; 
    cout << "\t\tQuan/Huyen: ";
    getline(is, task.deliveryAddress.district);
    toUpperCase(task.receivingAddress.district) ; 
    cout << "\t\tPhuong/Xa: ";
    getline(is, task.deliveryAddress.ward);
    toUpperCase(task.deliveryAddress.ward) ; 
    cout << "\t\tTo: ";
    getline(is, task.deliveryAddress.hamlet);
    cout << "\t\tDuong: ";
    getline(is, task.deliveryAddress.street);
    toUpperCase(task.deliveryAddress.street) ; 
    cout << "\t\tSo nha: ";
    is >> task.deliveryAddress.houseNumber;

    is.ignore(); // doc ki tu cin trc do 
    cout << "\t\tNhap dia chi nhan hang:" << endl;
    cout << "\t\tTinh/Thanh: ";
    getline(is, task.receivingAddress.province);
    toUpperCase(task.receivingAddress.province); 
    cout << "\t\tQuan/Huyen: ";
    getline(is, task.receivingAddress.district);
    toUpperCase(task.receivingAddress.district) ; 
    cout << "\t\tPhuong/Xa: ";
    getline(is, task.receivingAddress.ward);
    toUpperCase(task.receivingAddress.ward) ; 
    cout << "\t\tTo: ";
    getline(is, task.receivingAddress.hamlet);
    cout << "\t\tDuong: ";
    getline(is, task.receivingAddress.street);
    toUpperCase(task.receivingAddress.street) ; 
    cout << "\t\tSo nha: ";
    is >> task.receivingAddress.houseNumber;
    is.ignore(); 
    cout << "\t\tThong tin san pham:" << endl;
    int productCount;
    cout << "\t\tNhap so loai san pham can giao: ";
    is >> productCount;
    for (int i = 0; i < productCount; i++) {
        cout << "\t\tSan pham " << (i + 1) << ":" << endl;
        Product product;
        is.ignore() ; 
        cout << "\t\tTen hang: ";
        getline(is, product.itemType);
        cout << "\t\tSo luong: ";
        is >> product.numberOfItems;
        task.products.push_back(product);
    } 
    task.setEmployeeId("-111") ;
    task.calculateShippingFee() ;
     task.date = ctime(&now) ;
     task.date[task.date.length()-1] = '\0' ; 
    task.itemId = task.generateID() ; 
    is.ignore(); 
    return is;
}
void Task::saveToFile( string filename) const {
    ofstream file(filename,ios::app);
    if (file.is_open()) {
        file<< itemId <<endl; 
        file<< customerId <<endl;
        file<< employeeId <<endl; 
        file << "Dia chi giao hang:\n";
        file << deliveryAddress.province <<endl; 
        file << deliveryAddress.district <<endl;
        file << deliveryAddress.ward <<endl; 
        file << deliveryAddress.hamlet <<endl; 
        file << deliveryAddress.street <<endl; 
        file << deliveryAddress.houseNumber <<endl; 
        file << "Dia chi nhan hang:\n";
        file << receivingAddress.province <<endl; 
        file << receivingAddress.district <<endl; 
        file << receivingAddress.ward  <<endl; 
        file << receivingAddress.hamlet <<endl; 
        file << receivingAddress.street <<endl; 
        file << receivingAddress.houseNumber <<endl; 
        file << "Thong tin san pham:\n"; 
         file<<products.size() <<endl; 
        for (const Product& product : products) {
            file << product.itemType << endl;
            file << product.numberOfItems << endl;
        }
        file << shippingFee << endl;
        file << date <<endl ;
        file << status <<endl; 
        file.close();
        cout << "Thong tin nhiem vu da duoc luu vao file " << filename << endl;
    } else {
        cout << "Khong the mo file " << filename << " de luu thong tin." << endl;
    }
}
// lop Customer 
class Employee : public Person {
private:
    double salary;
    string generatePassword() override;
    string generateID() override ;
    void changePassword()override ;
public:
    Employee();
    Employee(string id, string name, string birth, string sex, string emailAddress, string Pass, string PhoneNumber, double salary);
    void setSalary(double salary);
    double getSalary() const;
    friend istream& operator>>(istream& is, Employee& emp);
    friend ostream& operator<<(ostream& os, const Employee& emp);
    void saveToFile(string fileName) const;
    static bool compareBySalary(const Employee& emp1, const Employee& emp2);
    static Employee* findById(vector<Employee>& employees, const string& id);
    void updateInformation(const string& id, vector<Employee>& employees);
};
void removeEmployee(vector<Employee>& employees, const string& id);
Employee::Employee() : Person(), salary(0.0) {}

Employee::Employee(string id, string name, string birth, string sex, string emailAddress, string Pass, string PhoneNumber, double salary)
    : Person(id, name, birth, sex, emailAddress, Pass, PhoneNumber), salary(salary) {}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

double Employee::getSalary() const {
    return salary;
}

istream& operator>>(istream& is, Employee& emp) {
    string name, birth, sex, emailAddress, phoneNumber;
    double salary;
    cout << "\t\tNhap ten: ";
    getline(is, name);
    toUpperCase(name);
    cout << "\t\tNhap ngay sinh: ";
    getline(is, birth);
    cout << "\t\tNhap gioi tinh: ";
    getline(is, sex);
    toUpperCase(sex);
    cout << "\t\tNhap SDT: ";
    getline(is, phoneNumber);
    cout << "\t\tNhap luong: ";
    cin >> salary;
    cin.ignore();
    emp.setName(name);
    emp.setBirth(birth);
    emp.setSex(sex);
    emp.setEmailAddress(emailAddress);
    emp.setPhone(phoneNumber);
    emp.setSalary(salary);
    emailAddress = Tao_Email(emp.getName(),emp.getBirth()) ; 
    emp.setEmailAddress(emailAddress) ; 
    string id = emp.generateID(); //tao id ngau nhien
    emp.setId(id);
    string password = emp.generatePassword();  //tao mat khau ngau nhien
    emp.setPass(password);
    cout << "\t\t______________________________" << endl;
    cout << "\t\tThong tin nhan vien da nhap:\n";
    emp.display();
    cout << "\t\t______________________________" << endl;
    cout << "\t\tID cua nhan vien: " << id << endl;
    cout << "\t\tMat khau cua nhan vien: " << password << endl;
    cout << "\t\tBan co muon doi mat khau khong (Y/N)? ";  // thay doi mat khau neu muon
    string choice;
    getline(cin, choice);
    if (choice == "Y" || choice == "y") {
        emp.changePassword();
    }
    else {
        cout << "\t\tMat khau khong duoc thay doi." << endl;
    }
    return is;
}
ostream& operator<<(ostream& os, const Employee& emp) {
    os << "\t\tID: " << emp.getId() << endl;
    os << "\t\tTen: " << emp.getName() << endl;
    os << "\t\tNgay sinh: " << emp.getBirth() << endl;
    os << "\t\tGioi tinh: " << emp.getSex() << endl;
    os << "\t\tEmail: " << emp.getEmailAddress() << endl;
    os << "\t\tSDT: " << emp.getPhone() << endl;
    os << "\t\tLuong: " << emp.getSalary()<< endl;
    return os;
}
void Employee::saveToFile(string fileName) const{
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << "ID: " << getId() << endl;
        file << "Mat khau: " << getPass() << endl;
        file << "Ten: " << getName() << endl;
        file << "Ngay sinh: " << getBirth() << endl;
        file << "Gioi tinh: " << getSex() << endl;
        file << "Email: " << getEmailAddress() << endl;
        file << "SDT: " << getPhone() << endl;
        file << "Luong: " << salary << endl;
        file.close();
        cout << "Du lieu da duoc luu vao file." << endl;
    } else {
        cout << "Khong the mo file." << endl;
    }
}
//ham so sanh luong cua 2 nhan vien
bool Employee::compareBySalary(const Employee& emp1, const Employee& emp2) {
    return emp1.salary < emp2.salary;
}
//ham tim nhan vien theo id
Employee* Employee::findById(vector<Employee>& listEmployee, const string& id) {
    for (auto& emp : listEmployee) {
        if (emp.getId() == id) {
            return &emp;
        }
    }
    return nullptr;
}
//ham cap nhap thong tin theo id san co
void Employee::updateInformation(const string& id, vector<Employee>& employees) {
    for (auto& emp : employees) {
        if (emp.getId() == id) {
            string name, birth, sex, emailAddress, phoneNumber;
            double salary;
            cout << "\t\tNhap ten: ";
            cin.ignore();
            getline(cin, name);
            toUpperCase(name);
            cout << "\t\tNhap ngay sinh: ";
            getline(cin, birth);
            cout << "\t\tNhap gioi tinh: ";
            getline(cin, sex);
            cout << "\t\tNhap email: ";
            getline(cin, emailAddress);
            cout << "\t\tNhap SDT: ";
            getline(cin, phoneNumber);
            cout << "\t\tNhap luong: ";
            cin >> salary;
            cin.ignore();
            emp.setName(name);
            emp.setBirth(birth);
            emp.setSex(sex);
            emp.setEmailAddress(emailAddress);
            emp.setPhone(phoneNumber);
            emp.setSalary(salary);
            cout << "\t\tThong tin nhan vien sau khi cap nhat:\n";
            emp.display();
            cout << "\t\tID cua nhan vien: " << emp.getId() << endl;
            cout << "\t\tBan co muon doi mat khau cho tai khoan nhan vien nay khong (Y/N)? ";  // thay doi mat khau neu muon
            string choice;
            getline(cin, choice);
            if (choice == "Y" || choice == "y") {
                emp.changePassword();
            }
            else {
                cout << "\t\tMat khau khong duoc thay doi." << endl;
            }

            return;
        }
    }

    cout << "\t\tKhong tim thay nhan vien co ID " << id << endl;
}
//ham tao id ngau nhien
string Employee::generateID() {
    string id;
    const string charset = "0123456789";

    srand(time(nullptr)); // khoi tao seed cho ham rand 

    for (int i = 0; i < 5; i++) {
        int index = rand() % charset.length();
        id += charset[index];
    }
    id = "0" + id;
    return id;
}
//ham doi mat khau
void Employee::changePassword() {
    string newPassword;
    cout << "Nhap mat khau moi: ";
    getline(cin, newPassword);
    setPass(newPassword);
    cout << "Mat khau da duoc thay doi." << endl;
}
//ham tao mat khau ngau nhien
string Employee::generatePassword() {
    string password;
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(nullptr)); // Kh?i t?o seed cho hàm rand()

    for (int i = 0; i < 8; i++) {
        int index = rand() % charset.length();
        password += charset[index];
    }

    return password;
}
//lop Customer 
class Customer: public Person{
private: 
    Address address ; 	
	vector<Task> hisTask ; 
    static int SumCus;
    string generatePassword() override;
    string generateID() override ;
    void changePassword() override ;
public:
    Customer(){
	  SumCus++ ;  }
    Customer(string const id, string const name , string const birth, string const  sex, string  const emailAddress,string const address,
	 string const Pass, string const PhoneNumber):Person(id,name,birth,sex,emailAddress,Pass,PhoneNumber){
    } 
    void setAddress(Address& address){ 
            this->address.houseNumber =address.houseNumber ;
            toUpperCase(address.province); 
            this->address.province = address.province ;
            toUpperCase(address.street);
            this->address.street = address.street ;
            toUpperCase(address.street); 
            this->address.ward = address.ward ;
            toUpperCase(address.ward); 
            this->address.hamlet = address.hamlet ; 
            this->address.district = address.district ;
            toUpperCase(address.district); 
	}
    Address getAddress() const {return address;}
	static int getSumCus() {return SumCus ;}
	void input_Task(Task const tmp)  ;
	void display_Task() ;   
    friend istream& operator>>(istream& is, Customer& cus);
    friend ostream& operator<<(ostream& os, const Customer& cus);
    void upStatusHisTask(string idTask, string idEmp);
    void saveHisTask();
    void saveToFile(string const filename)const ; 
    void Input_TaskforCus(vector<Task>&listTask) ;
    friend void readHisTask(vector<Customer>&listCustomer) ;
 };
int Customer::SumCus = 0 ;

istream& operator>>(istream& is, Customer& cus){    
    string id,name,sex,birth,emailAddress,phone;
    Address a ; 
    a.houseNumber = -1; 
    cus.setAddress(a); 
    cout<<"\t\tmoi nhap vao ten cua khach hang: " ; 
	getline(is,name) ; 
	cout<<"\t\tmoi nhap vao ngay thang nam sinh: "  ; 
	getline(is,birth) ;
    cout<<"\t\tmoi nhap vao gioi tinh cua khach hang: " ; 
	cin >> sex ; 
	cin.ignore() ;
    cout<<"\t\tmoi nhap vao so dien thoai cua khach hang: " ; 
    is>> phone ; 
    cin.ignore() ; 
	toUpperCase(name) ; 
	toUpperCase(sex) ;
	cus.setName(name) ; 
    cus.setBirth(birth) ; 
	cus.setSex(sex) ;
    emailAddress = Tao_Email(name,birth) ; 
    cus.setEmailAddress(emailAddress);
	cus.setPhone(phone) ;
    id = cus.generateID(); //tao id ngau nhien
    cus.setId(id);
	string password = cus.generatePassword();  //tao mat khau ngau nhien
    cus.setPass(password);
    cout << "\t\t______________________________" << endl;
    cout << "\t\tThong tin khach hang da nhap:\n";
    cus.display();
    cout << "\t\t______________________________" << endl;
    cout << "\t\tID cua khach hang: " << id << endl;
    cout << "\t\tMat khau cua khach hang: " << password << endl;
    cout << "\t\tBan co muon doi mat khau khong (Y/N)? ";  // thay doi mat khau neu muon
    string choice;
    getline(cin, choice);
    if (choice == "Y" || choice == "y") {
        cus.changePassword();
    }
    else {
        cout << "Mat khau khong duoc thay doi." << endl;
    }
    return is;
}

vector<Customer> listCustomer ;
vector<Employee> listEmployee ;
vector<Task> listTask; 

 //ham tao mat khau ngau nhien
string Customer::generatePassword() {
    string password;
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(nullptr)); // Kh?i t?o seed cho hàm rand()

    for (int i = 0; i < 8; i++) {
        int index = rand() % charset.length();
        password += charset[index];
    }

    return password;
}

//ham tao id ngau nhien
string Customer::generateID() {
    string id;
    const string charset = "0123456789";

    srand(time(nullptr)); // Kh?i t?o seed cho hàm rand()

    for (int i = 0; i < 5; i++) {
        int index = rand() % charset.length();
        id += charset[index];
    }
    id = "1" + id;
    return id;
}

//ham doi mat khau
void Customer::changePassword() {
    string newPassword;
    cout << "Nhap mat khau moi: ";
    getline(cin, newPassword);
    setPass(newPassword);
    cout << "Mat khau da duoc thay doi." << endl;
}

ostream& operator<<(ostream& os, const Customer& cus){
        cout << "\t\tID: " << cus.getId() << endl;
        cout << "\t\tTen: " <<cus.getName() << endl;
		cout << "\t\tNgay sinh: " << cus.getBirth() << endl;
		cout << "\t\tGioi tinh: " << cus.getSex() << endl;
		cout << "\t\tso dien thoai: " << cus.getPhone() << endl ; 
		cout << "\t\tEmail address: " << cus.getEmailAddress() << endl; 
		cout << "\t\tDia chi khach hang: " << endl; 
		cout<<"\t\tTinh/Thanh Pho: "<< cus.address.province << endl ;
		cout<<"\t\tQuan/Huyen: " << cus.address.district << endl ;
		cout<<"\t\tPhuong/xa: " << cus.address.ward << endl; 
		cout<<"\t\tTen Duong: " << cus.address.houseNumber <<" "<< cus.address.street << endl ;
        return os;
    }

void Customer::upStatusHisTask(string idTask, string idEmp){
    for (int i=0; i<hisTask.size(); i++){
        if (idTask==hisTask[i].getItemId()) {
            hisTask[i].setCustomerId(idEmp);
            hisTask[i].setStatus(DangGiao);
        }
    }
}
void Customer::input_Task(Task const tmp) {
	hisTask.push_back(tmp) ;  
    }

void Customer::display_Task(){
    // hisTask.clear();
    // readHisTask(listCustomer);
     if(hisTask.size()==0) cout<<"ban chua co don hang nao tung giao dich truoc day !\n" ;
	 else {
		for(int i=0 ; i<hisTask.size();i++) {
			cout << hisTask[i] ; 
		}
	 }
}
void Customer::saveHisTask(){
    string filename = Customer::getId() + ".txt" ;
    ofstream file(filename, ios::trunc);
    for(int i=0;i<hisTask.size();i++) {
        hisTask[i].saveToFile(filename);
    }
    file.close();
}

void Customer::saveToFile(string const filename)const  {
	ofstream outfile (filename, ios::app) ;  
    if (outfile.is_open()) {
        outfile << "ID: " << getId() << std::endl;
        outfile << "Password: " << getPass() << std::endl;
        outfile << "Ho ten: " << getName() << std::endl;
        outfile << "Ngay sinh: " << getBirth() << std::endl;
        outfile << "Gioi tinh: " << getSex() << std::endl;
        outfile << "SDT: " << getPhone() << std::endl;
        outfile << "Email: " << getEmailAddress() << std::endl;
        outfile << "Tinh/Thanh: " << address.province << std::endl;
        outfile << "Quan/Huyen: " << address.district << std::endl;
        outfile << "Phuong/xa: " << address.ward << std::endl;
        outfile << "Duong: " << address.street << std::endl;
        outfile << "So nha: " << address.houseNumber << std::endl;
        outfile.close(); // Ðong file sau khi ghi xong
        std::cout << "Ghi file thanh cong." << std::endl;
    } else {
        std::cout << "Khong the mo file." << std::endl;
    }
}

void Customer::Input_TaskforCus(vector<Task>&listTask) { 
	cout << "Moi ban nhap don hang muon giao \n" ;
	Task tmp ; 
	cin >> tmp ; 
	tmp.setCustomerId(Person::getId()) ; 
	listTask.push_back(tmp) ;
    //input_Task(tmp);
    }

//ham chuan hoa ten
void toUpperCase(std::string& name) {
    for (size_t i = 0; i < name.length(); i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = name[i] - 'a' + 'A';  // Chuyen doi sang chu hoa
        }
    }
}
//Tao email 
string Tao_Email(string  name ,string date) {
	 stringstream ss (name) ;
	 string word ;
	 while (ss>>word) {
	 } 
     string tmp ; 
     for(int i=0;i<date.size();i++) {
     	if(date[i]!='/') tmp += date[i] ; 
	 } 
	 return word + tmp + "@gmail.com" ; 
} 