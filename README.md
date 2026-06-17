🏢 Hệ thống Quản lý Nhân sự (HRM System)   
📖 Giới thiệu (Overview)   
Hệ thống Quản lý Nhân sự (HRM) là một phần mềm được phát triển bằng ngôn ngữ C++. Dự án nhằm mục đích tối ưu hóa việc quản lý dữ liệu nhân viên trong các công ty phần mềm, hỗ trợ các chức năng cơ bản từ quản lý thông tin cá nhân đến tính toán lương tự động dựa trên vị trí công việc.   
🚀 Tính năng chính (Key Features)  
Quản lý dữ liệu: Thêm, xóa, cập nhật và hiển thị danh sách nhân viên.  
Cấu trúc dữ liệu linh hoạt: Sử dụng lập trình hướng đối tượng (OOP) để quản lý các đối tượng nhân viên khác nhau.  
Tính lương tự động: Cơ chế tính lương linh hoạt tùy thuộc vào chức vụ (Lập trình viên, Kiểm thử, Kế toán, v.v.).  
Giao diện trực quan: Bảng dữ liệu được căn chỉnh khoa học, dễ nhìn ngay trên cửa sổ Terminal.  
🛠 Công nghệ sử dụng (Tech Stack)  
Ngôn ngữ: C++.  
Thư viện: * <iostream>, <string>: Quản lý dữ liệu.  
<iomanip>: Định dạng bảng và xuất dữ liệu.  
<fstream>: Hỗ trợ đọc/ghi dữ liệu từ file.  
Môi trường: IDE (Visual Studio Code, Dev-C++), Git/GitHub.  
💻 Hướng dẫn cài đặt (Installation)  
Clone dự án:  
git clone https://github.com/vanlaihk2k7-afk/PBL1.git  
Bước 1: Biên dịch    
+Mở terminal tại thư mục dự án và sử dụng lệnh:  
  g++ -o HRM_System quanlynhanvien.cpp  
Bước 2: Thực thi    
+Sau khi biên dịch thành công, chạy file thực thi vừa tạo bằng lệnh sau:  
-Trên Windows:  
  ./HRM_System.exe  
-Trên Linux hoặc macOS:  
  ./HRM_System  
📊 Mô hình dữ liệu (Data Structure)  
-Để hiểu rõ cách chương trình vận hành, dưới đây là mô hình phân cấp lớp (Class Hierarchy) của hệ thống:  
+Lớp cơ sở (NhanVien): Lưu trữ thông tin chung (Tên, tuổi, địa chỉ, số điện thoại, email, lương cơ bản...).  
+Lớp dẫn xuất (ChucVu): Thừa kế từ NhanVien, bổ sung thuộc tính riêng và hàm tính lương đặc thù.  
📸 Hình ảnh minh họa (Preview)  
<img width="1037" height="176" alt="image" src="https://github.com/user-attachments/assets/a06544cf-0c5b-4acc-ab0a-745c55818ae7" />  
📝 Liên hệ (Contact)  
Người phát triển: [Lê Văn Lai, Hồ Nguyễn Nhật Huy]  
Email: [vanlaihk2k7@gmail.com]  
GitHub: [https://github.com/vanlaihk2k7-afk/PBL1.git]  
