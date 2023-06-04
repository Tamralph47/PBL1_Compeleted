#include"ChucNang.cpp"
using namespace std ; 
//Menu chon lua  khi dang nhap admin 
string keyAdmin[5] ={"0905373789","0787717471","0906578748","012345678","987654321"};
void menuAdmin(vector<Employee>& listEmployee, vector<Task>& listTask, vector<Customer>& listCustomer){
    char c = '1' ; 
    do{
        c='1';
        string pass ;
        cout<<"\t\tNhap mat khau: " ; cin >> pass ; 
        for(int i=0;i<5;i++){
            if(keyAdmin[i]==pass) c='0' ;
        }
        if(c=='1'){cout<<"nhap sai mat khau bam phim '0' de thoat hoac phim bat ki de tiep tuc"; cin>> c ; if(c=='0') return; }
    } while(c!='0') ; 
    do{ char * time = ctime(&now) ; 
         system("cls") ; 
    gotoxy(52,0);                cout<<time ; 
    gotoxy(45,1);                cout<<"Chao mung den voi phien lam viec cua quan li" ; 
    gotoxy(55,2);                cout << "==MENU QUAN LI==";
    gotoxy(42,3) ;               cout<< "+------------------------------------------+";
    gotoxy(42,4);                cout << "|1.  Xem danh sach nhan vien                |" ; 
    gotoxy(42,5);                cout << "|2.  Xem danh sach khach hang               |" ;
    gotoxy(42,6);                cout << "|3.  Xem danh sach don hang                 |" ;
    gotoxy(42,7);                cout << "|4.  Them 1 nhan vien                       |" ;
    gotoxy(42,8);                cout << "|5.  Sap xep nhan vien theo luong           |" ;
    gotoxy(42,9);                cout << "|6.  Tim nhan vien theo ID                  |" ;
    gotoxy(42,10);               cout << "|7.  Cap nhap thong tin nhan vien           |";
    gotoxy(42,11);               cout << "|8.  Xoa 1 nhan vien theo ID                |" ;
    gotoxy(42,12) ;              cout << "|9.  Them mot khach hang                    |" ; 
    gotoxy(42,13);               cout << "|10. Tim khach hang theo ID                 |" ;
    gotoxy(42,14);               cout << "|11. Tim khach hang theo dia chi thanh pho  |" ;
    gotoxy(42,15);               cout << "|12. Tim khach hang theo so dien thoai      |" ;
    gotoxy(42,16);               cout << "|13. Cap nhap thong tin khach hang          |" ;
    gotoxy(42,17);               cout << "|14. Xoa mot khach hang                     |" ;     
    gotoxy(42,18);               cout << "|15. Thoat phien lam viec cua Admin         |" ; 
    gotoxy(42,19) ;              cout << "+------------------------------------------+";
    gotoxy(42,20) ;              cout <<  "Moi ban nhap vao lua chon cua ban: " ; int n ; cin >> n ; cin.ignore() ;
    switch(n) {
        case 1:{   
                   system("cls") ; 
                    cout << "----------------------------------------------------------------" << endl;
                        // Display Employees
                        if (listEmployee.empty()) {
                            cout << "Khong co nhan vien nao." << endl;
                        } else {
                            cout << "Danh sach nhan vien:" << endl;
                            for (int i=0;i<listEmployee.size();i++) {
                                cout << "Xuat thong tin nhan vien thu " << i+1 << ": " << endl;
                                cout << listEmployee[i] ;
                            }
                        }
                        system("pause") ; 
            break ; 
        }
        case 2:{
            system("cls") ; 
            cout << "-------------------------" << endl;
                if (listCustomer.empty()) {
                    cout << "\t\tKhong co khach hang nao." << endl;
                } else {
                    cout << "\t\tDanh sach khach hang:" << endl;
                    for (int i=0 ;i<listCustomer.size();i++) {
                        cout << "Xuat thong tin khach hang thu " << i+1 << ": " << endl;
                        cout << listCustomer[i];
                    }
                }
            system("pause") ; 
            break;
        }
        case 3: {
            system("cls") ; 
              cout << "--------------------" << endl;
                        // Display Tasks
                        if (listTask.empty()) {
                            cout << "\t\tKhong co nhiem vu nao." << endl;
                        } else {
                            cout << "\t\tDanh sach nhiem vu:" << endl;
                            for (int i =0 ; i< listTask.size();i++) {
                                cout << "Xuat thong tin nhiem vu thu " << i+1 << ": " << endl;
                                cout << listTask[i];
                            }
                        }
            system("pause") ; 
            break ;
        }
        case 4: {
            system("cls") ; 
             cout << "--------------------" << endl;
                        // Add Employee
                        Employee emp;
                        cin >> emp;
                        listEmployee.push_back(emp);
                        cout << "\t\tThem nhan vien thanh cong!" << endl;
            system("pause") ; 
            break; 
        }
        case 5: {
            system("cls") ; 
                            //sap xep nhan vien dung comperator
                        sort(listEmployee.begin(), listEmployee.end(), Employee::compareBySalary);

                        // In ket qua
                        cout << "\t\tDanh sach nhan vien theo thu tu tang luong:" << endl;
                        for (int i=0;i<listEmployee.size();i++) {
                            cout << listEmployee[i];
                        }
                        system("pause") ; 
                        break; 
        }
        case 6:{
            system("cls") ; 
            string searchId;
                        cout << "Nhap ID nhan vien can tim: ";
                        cin >> searchId;
                        Employee* foundEmployee = Employee::findById(listEmployee, searchId);

                        if (foundEmployee != nullptr) {
                            cout << "\t\tNhan vie co ID " << searchId << " duoc tim thay: " << endl;
                            cout << *foundEmployee ; 
                        } else {
                            cout << "\t\tkhong tim thay nhan vien " << searchId << endl;
                        } 
            system("pause") ; 
            break ; 
         } 
        case 7: {
            system("cls") ;
            cout << "--------------------" << endl;
            // Update Employee Information
            string empId;
            cout << "\t\tNhap ID nhan vien muon thay doi: ";
            cin >> empId;
            Employee* emp = Employee::findById(listEmployee, empId);
            if (emp) {
                emp->updateInformation(empId,listEmployee);
                cout << "\t\tThong tin nhan vien da cap nhap thanh cong!" << endl;
            } else {
                cout << "\t\tNhan vien voi ID " << empId << " khong tim thay." << endl;
            } 
            system("pause") ;             
            break ; 
        }
        case 8: {
            system("cls") ;
            cout << "--------------------" << endl;
            // Remove Employee
            string empId;
            cout << "\t\tNhap ID nhan vien de xoa: ";
            cin >> empId;
            removeEmployee(listEmployee, empId);
            system("\t\tpause") ; 
            break ;
        }
        case 10:{
            system("cls") ;
            FindCusById(listCustomer); 
            system("\t\tPause") ; 
            break ; 
        }
        case 11: {
            system("cls") ; 
            FindCusByCity(listCustomer); 
            system("\t\tpause") ; 
            break ; 
        } 
        case 12:{
          system("cls") ; 
          FindCusByPhone(listCustomer) ; 
          system("\t\tpause") ; 
          break;  
        }
        case 13:{
            system("cls") ; 
             if(listCustomer.empty()) {
                cout << "\t\tkhong co khach hang " << endl; 
                break ; 
             }
             Set_Infor_Cus(listCustomer);
             system("\t\tpause") ;
             break ; 
        }
        case 15: return ;
        case 9: {
            system("cls") ; 
            InPut_Cus(listCustomer) ; 
            system("\t\tpause") ; 
            break ; 
        } 
        case 14:{
            system("cls") ; 
            string id ;
            cout<<"\t\tNhap vao id khach hang muon xoa ";cin>>id;  
            removeCustomer(listCustomer,id) ;
            system("\t\tpause") ; 
            break ; 
        }
        default : {
            cout << "\t\tLua chon khong hop le vui long nhap lai \n" ; 
            break; 
        }
      }
     }
    while (1);
 } 
 // MenuEmployee 
 void menuEmpoyee(vector<Employee>& listEmployee, vector<Task>& listTask, vector<Customer>& listCustomer){
    int em;
    int pos;
    char c;    
    while(1) {
    system("cls") ; 
     string id ; string pass ;
    gotoxy(46,2) ;    cout<<"Dang nhap nhan vien " ;
    gotoxy(42,3);    cout<<"+---------------------------+" ;
    gotoxy(42,4);    cout<<"|Ma id:                     |" ;  
    gotoxy(42,5);    cout<<"|Mat khau:                  | " ; 
    gotoxy(42,6);    cout<<"+---------------------------+" ;
    gotoxy(50,4); cin >> id ; cin.ignore() ; pos=PosEmployee(id) ; 
    gotoxy(53,5); cin >> pass ; cin.ignore()  ;
    gotoxy(42,6);    cout<<"+---------------------------+\n" ;
        if(CheckPassEmployee(pos,pass)) {
            cout << "\t\tChao mung dang nhap nhan vien :" <<listEmployee[pos].getName() << endl ;
            system("\t\tpause") ; 
            break ; 
            }
        else {
            cout<<"\t\tTen dang nhap hoac mat khau khong chinh xac \n" ;
            cout<<"\t\tAn phim '0' de ket thuc dang nhap hoac bat ki de tiep tuc \n" ; cin >> c ; cin.ignore() ;
            if(c=='0')return ;   
        } 
    }
    do{system("cls") ;
    char * time = ctime(&now) ; 
    gotoxy(50,0);    cout<<time ;
    gotoxy(45,1);    cout<<"Nhan vien: "<<listEmployee[pos].getName()<<" Ma Id: " << listEmployee[pos].getId() ; 
    gotoxy(55,2);    cout << "==MENU NHAN VIEN==" << endl;
    gotoxy(42,3);    cout <<"+-------------------------------------------+" ;
    gotoxy(42,4);    cout <<"|1. Xem danh sach nhan vien                 |" ;
    gotoxy(42,5);    cout <<"|2. Cap nhap thong tin ca nhan cua nhan vien|" ;
    gotoxy(42,6);    cout <<"|3. Xem danh sach don hang                  |" ;
    gotoxy(42,7);    cout <<"|4. Nhan don hang                           |" ;//con chuc nang chua cap nhap case
    gotoxy(42,8);    cout <<"|5. Cap nhat don hang                       |" ;
    gotoxy(42,9);    cout <<"|6. Xem thong tin ca nhan                   |" ;
    gotoxy(42,10);   cout <<"|7. Ve menu chinh                           |" ;
    gotoxy(42,11);   cout <<"+-------------------------------------------+" ;
    gotoxy(42,12);   cout << "Nhap lua chon cua ban: ";
        cin >>em;

        switch(em){
            case 1:{
                system("cls") ; 
                cout << "--------------------" << endl;
                if (listEmployee.empty()) {
                    cout << "\t\tKhong co nhan vien nao." << endl;
                } else {
                    cout << "\t\t\tDanh sach nhan vien:" << endl;
                    for (const auto& emp : listEmployee) {
                        cout << emp;
                    }
                }
                system("\t\tpause") ; 
                break;
            }
            case 2:{
                system("cls") ;
                cout << "--------------------" << endl;
                string empId=listEmployee[pos].getId();
                Employee* emp = Employee::findById(listEmployee,empId);
                cout << "\t\tCap nhap lai thong tin ca nhan cua ban: \n";
                if (emp) {
                    emp->updateInformation(empId,listEmployee);
                    cout << "\t\tThong tin nhan vien da cap nhap thanh cong!" << endl;
                } else {
                    cout << "\t\tNhan vien voi ID " << empId << " khong tim thay." << endl;
                }
                system("\t\tpause") ; 
                break;
            }
            case 3:{
                system("cls") ; 
                cout << "--------------------" << endl;
                if (listTask.empty()) {
                    cout << "\t\tKhong co nhiem vu nao." << endl;
                } else {
                    cout << "\t\t\tDanh sach nhiem vu:" << endl;
                    for (const auto& task : listTask) {
                        cout << task;
                    }
                }
                system("\t\tpause") ; 
                break;
            }
            case 4:{
                system("cls") ; 
                receiveTask(pos,listEmployee,listTask) ; 
                system("\t\tpause") ; 
                break;
            }
            case 5: {
                system("cls") ; 
                cout << "\t\t--------------------" << endl;
                UpdateTask(pos,listTask,listCustomer) ; 
                system("pause") ; 
                break;
            }
            case 6: {
                system("cls") ; 
                cout<<listEmployee[pos] ;
                system("pause") ; 
                break ; 
            }
            case 7: {
                cout<<"\t\tVe menu chinh" << endl  ;
                system("pause") ; 
                return ; 
            }
            default: {
                system("cls") ; 
                cout << "\t\tLua chon khong hop le! Vui long chon lai." << endl;
                break;
            }
        }
    } while(1);
}
//menuCustomer 
void menuCustomer(vector<Employee>& listEmployee, vector<Task>& listTask, vector<Customer>& listCustomer){
    int cu;
    int pos ;
    char c  ;  
    while(1) {
    system("cls") ; 
     string id ; string pass ;
    gotoxy(46,2) ;    cout<<"Dang nhap khach hang " ;
    gotoxy(42,3);    cout<<"+---------------------------+" ;
    gotoxy(42,4);    cout<<"|Ma id:                     |" ;  
    gotoxy(42,5);    cout<<"|Mat khau:                  | " ; 
    gotoxy(42,6);    cout<<"+---------------------------+" ;
    gotoxy(50,4); cin >> id ; cin.ignore() ; pos=Pos(id) ; 
    gotoxy(53,5); cin >> pass ; cin.ignore()  ;
    gotoxy(42,6);    cout<<"+---------------------------+\n" ;
        if(CheckPass(pos,pass)) {
            cout << "\t\tChao mung dang nhap khach hang :" <<listCustomer[pos].getName() << endl ;
            system("\t\tpause") ; 
            break ; 
            }
        else {
            cout<<"\t\tTen dang nhap hoac mat khau khong chinh xac \n" ;
            cout<<"\t\tAn phim '0' de ket thuc dang nhap hoac bat ki de tiep tuc \n" ; cin >> c ; cin.ignore() ;
            if(c=='0')return ;   
        } 
    }
    do{ system("cls") ;
    char * c = ctime(&now) ; 
    gotoxy(52,0);    cout << c ; 
    gotoxy(48,1);    cout << "Chao mung dang nhap " <<listCustomer[pos].getName() ; 
    gotoxy(58,2);    cout << "MENU KHACH HANG" ;
    gotoxy(42,3);    cout << "+---------------------------------------------+" ;
    gotoxy(42,4);    cout << "|1. xem thong tin ca nhan                     |" ;
    gotoxy(42,5);    cout << "|2. Cap nhap thong tin ca nhan cua khach hang |" ;
    gotoxy(42,6);    cout << "|3. Tao 1 don hang moi                        |" ;
    gotoxy(42,7);    cout << "|4. Xem danh sach don hang                    |" ; 
    gotoxy(42,8);    cout << "|5. Xem lich su don hang cu                   |" ;//con chuc nang chua cap nhap vao case
    gotoxy(42,9);    cout << "|6. Ve menu chinh                             |" ; 
    gotoxy(42,10);   cout << "+---------------------------------------------+" << endl;
    gotoxy(42,11);   cout << "Nhap lua chon cua ban: ";
        cin >>cu;
        switch(cu){
            case 1:{
                system("cls") ; 
                cout << "-------------------------" << endl;
                cout <<"\t\t"<< listCustomer[pos] ;
                system("pause") ; 
                break;
            }

            case 2:{
               system("cls") ; 
               Set_inforCus(pos) ;
                break;
            }

            case 3:{
                system("cls") ; 
                cin.ignore() ; 
                listCustomer[pos].Input_TaskforCus(listTask) ;
                break ;
            }
            case 4:{
                system("cls") ; 
                cout << "--------------------" << endl;
                string id = listCustomer[pos].getId() ; 
                int cnt = 0 ;
                if (listTask.empty()) {
                    cout << "Khong co don hang nao." << endl;
                } else {
                    cout << "Danh sach don hang:" << endl;
                    for (int i=0;i<listTask.size();i++) {
                        if(listTask[i].getCustomerId()==id &&( listTask[i].getStatus()==DangGiao||listTask[i].getStatus()==Doi)) {
                                cout << listTask[i];
                                cnt ++ ; 
                        }
                    }
                }
                if(cnt==0) cout << "Ban khong co don hang\n" ; 
                system("\t\tpause") ; 
                break;
            }
            case 5: {
                system("cls") ;
                 listCustomer[pos].display_Task() ;
                system("\t\tpause") ;
                break;
            }
            case 6: {
                cout << "\t\t--------------------" << endl;
                cout << "\t\tVe menu chinh..." << endl;
                system("pause") ; 
                return ; 
            }
            default: {
                cout << "\t\tLua chon khong hop le! Vui long chon lai." << endl ;
                break;
            }
        }
    } while(1);
}
//menuAll
void menuAll(){
    string fileNameEmp = "employees.txt";
    readFromFileEmp(fileNameEmp, listEmployee);
    string fileNameCus = "customers.txt";
    readFromFileCus(fileNameCus, listCustomer);
    string fileNameTask = "task.txt" ; 
    readFromFileTask(fileNameTask, listTask) ;
    readHisTask(listCustomer) ;
    int choice;
    do{
      char *tm = ctime(&now) ; 
      system("cls") ; 
gotoxy(42,3);                        cout<< tm  ; 
gotoxy(38,4);                        cout<<"chao mung den voi phien lam viec" ; 
gotoxy(40,5);					     cout<<"+---------------------------+\n"  ; 
gotoxy(40,6);					     cout<<"|  1. Dang nhap quan ly     |\n"  ; 
gotoxy(40,7);						 cout<<"|  2. Dang nhap nhan vien   |\n" ; 
gotoxy(40,8);						 cout<<"|  3. Dang nhap khach hang  |\n" ; 
gotoxy(40,9);						 cout<<"|  0. Thoat chuong trinh    |\n" ;   
gotoxy(40,10);						 cout<<"+---------------------------+\n" ; 
gotoxy(40,11); cout << "Moi ban nhap vao lua chon: " ;   
        cin >> choice;

        switch (choice){
            case 1:{
                menuAdmin(listEmployee, listTask, listCustomer);
                break;
            }
            case 2:{
                menuEmpoyee(listEmployee, listTask, listCustomer);
                break;
            }
            case 3:{
                menuCustomer(listEmployee, listTask, listCustomer);
                break;
            }
            case 0: {
                cout << "---------------------------------------------------------" << endl;
                ofstream file1 ("Employees.txt",ios::trunc) ;
                ofstream file2 ("Customers.txt",ios::trunc) ; 
                ofstream file3 ("task.txt",ios::trunc) ; 
                for(int i=0;i<listCustomer.size();i++) {
                    listCustomer[i].saveToFile("Customers.txt") ; 
                    listCustomer[i].saveHisTask();
                } 
                for(int i=0;i<listEmployee.size();i++) {
                    listEmployee[i].saveToFile("Employees.txt") ; 
                }
                for(int i=0;i<listTask.size();i++) {
                    if(listTask[i].getStatus()!=DaGiao)
                    listTask[i].saveToFile("task.txt") ; 
                } 
                file1.close(); file2.close() ; file3.close() ; 
                cout << "\t\tThoat chuong trinh..." << endl;
                break;
            }
            default: {
                cout << "\t\tLua chon khong hop le! Vui long chon lai." << endl;
                break;
            }
        }
    } while (choice != 0);
}
int main() {
    menuAll() ; 
    return  0 ; 
}