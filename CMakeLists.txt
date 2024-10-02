cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# C++11 standardını kullan
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Kaynak dosyalarını otomatik olarak bul
file(GLOB SOURCES "src/*.cpp")

# Header dosyalarının bulunduğu dizini ekle
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Çalıştırılabilir dosyayı oluştur
add_executable(game ${SOURCES})

# Çıktı dosyasının adını ayarla
set_target_properties(game PROPERTIES OUTPUT_NAME "game")

# Windows'ta .exe uzantısını ekle
if(WIN32)
    set_target_properties(game PROPERTIES SUFFIX ".exe")
endif()
