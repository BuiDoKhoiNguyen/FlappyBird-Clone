**Flappy Bird**

#### Mục lục
1. [Giới thiệu](#introduction)
2. [Tính năng](#features)
3. [Cách chơi](#play)
4. [Cách cài đặt](#installation)

# Introduction <a name="introduction"></a>

* Game được tạo bằng cách sử dụng [SDL2](https://www.libsdl.org/download-2.0.php) và C++.

_*Game đã được tham khảo và chỉnh sửa 

<p align="center">
<img width="640" height="480" src="https://i.pinimg.com/originals/02/98/fa/0298fa4e7f8b0495169b2e964f06d7f2.jpg">
</p>

# Feature <a name="features"></a>

**1. GameWindow**
* Xử lý va chạm giữa nhân vật và đường ống, mặt đất, đường viền trên cửa sổ
* Xử lý thao tác phím/chuột của người chơi
* Hiển thị điểm, biểu tượng trạng thái trận đấu (chơi/tạm dừng).
* Mặt đất, các nhân vật di chuyển làm cho trò chơi chân thực hơn.
* Giới hạn FPS để tương thích với mọi thiết bị (nếu không, khi chạy game trên máy cấu hình cao, hình ảnh sẽ bị render quá nhanh, gây ra hiệu ứng "tua nhanh").

**2. TabPause**
* Bật/Tắt trò chơi.
* Giao diện Sáng/Tối (thay đổi ngay sau khi chọn).
* Xem điểm hiện tại, điểm cao nhất

**3. TabGameOver**
* Hiển thị huy chương tương ứng với số điểm (Vàng > 50, Bạc > 20, Danh dự <= 20).
* Xem điểm hiện tại, điểm cao nhất

# How to play <a name="play"></a>
* Kích chuột hoặc nhấn phím SPACE/UP để chơi.
* Nhấn ESC để tạm dừng

<p align="center">
<img src="https://i.imgur.com/dvni6mF.png">
</p>

# Installation <a name="installation"></a>

>> một số hình ảnh về Game

<img src="https://user-images.githubusercontent.com/123927630/230642952-c093d07c-0b6d-469a-b06b-c89671cbaa9d.png" alt="https://user-images.githubusercontent.com/123927630/230642952-c093d07c-0b6d-469a-b06b-c89671cbaa9d.png" width="260" /> <img src="https://user-images.githubusercontent.com/123927630/230642954-95c2a9aa-c46e-4392-a95e-38f401501f10.png" alt="https://user-images.githubusercontent.com/123927630/230642954-95c2a9aa-c46e-4392-a95e-38f401501f10.png" width="250" /> <img src="https://user-images.githubusercontent.com/123927630/230642959-0788c580-a086-4e67-8ce0-64256c76153f.png" alt="https://user-images.githubusercontent.com/123927630/230642959-0788c580-a086-4e67-8ce0-64256c76153f.png" width="250" />
