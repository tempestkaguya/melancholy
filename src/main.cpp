#include <QApplication>
#include <QtGlobal>
#include "mainwindow.h"
#include "widgets/initializing.h"
#include "widgets/close.h"

#ifndef Q_OS_LINUX
    #error "Melancholy is only supported on Linux."
#endif

/* straight fucking garbage, memory leaks expected
template <typename T>
struct ShmHandle {
    T* data;
    int fd;
    size_t size;
};

template <typename T>
extern ShmHandle<T> create_smipc(const char* os_id, size_t size) {
    int fd = shm_open(os_id, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        throw std::system_error(errno, std::generic_category(), "Failed to shm_open");
    }

    if (ftruncate(fd, size) == -1) {
        close(fd);
        throw std::system_error(errno, std::generic_category(), "Failed to ftruncate");
    }

    void* raw_ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (raw_ptr == MAP_FAILED) {
        close(fd);
        throw std::system_error(errno, std::generic_category(), "Failed to mmap");
    }

    T* typed_ptr = static_cast<T*>(raw_ptr);
    return ShmHandle<T>{ typed_ptr, fd, size };
}*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Initializing window;
    //window.show();

    MainWindow window;
    window.show();
    
    return app.exec();
}   