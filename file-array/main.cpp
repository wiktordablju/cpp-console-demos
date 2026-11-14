#include <iostream>
#include <fstream>
#include <vector>








template <typename T>
class SmartPtr {
private:
    T* ptr;
public:
    SmartPtr(T* p = nullptr) : ptr(p) {}
    ~SmartPtr() {
        delete ptr;
    }
    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
    
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;
    
    SmartPtr(SmartPtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    
    SmartPtr& operator=(SmartPtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

int main() {






    class FileArray {
    private:
        int* data;
        std::string filename;

        
    public:
        int size; // size w public po to, by przetestowac latwo dodawanie na koniec arraya

        FileArray(const std::string& fname) : filename(fname), size(0), data(nullptr) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("brak pliku"); 
            }

            int value;
            while (file >> value) {
                size++;
            }
            file.clear();
            file.seekg(0);
            
            data = new int[size];
            for (int i = 0; i < size; i++) {
                file >> data[i];
            }
            
            file.close();
        }
        int& operator[](int index) {
            if (index < 0 || index >= size) {
                throw std::runtime_error("indeks poza zakresem"); 
            }
            return data[index];
        }
        void append(int value) {
            std::ofstream file(filename, std::ios::app);
            if (!file.is_open()) {
                throw std::runtime_error("brak pliku"); 
            }
            file << value << std::endl;
            file.close();
            
            int* newData = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            newData [size] = value;
            delete[] data;
            data = newData;
            size++;
        };
        ~FileArray() {
            delete[] data;
        }
    };

    FileArray array("test.txt");
    std::cout << array[2] << std::endl;
    array[2] = 100;
    std::cout << array[2] << std::endl;
    array.append(80);
    std::cout << array[array.size - 1] << std::endl;
    
    std::cout << "--------------" << std::endl;

    SmartPtr<int> ptr1(new int(42));
    std::cout << *ptr1 << std::endl;
    *ptr1 = 100;
    std::cout << *ptr1 << std::endl;

    SmartPtr<int> ptr2(std::move(ptr1));
    std::cout << "ptr2 move const: " << *ptr2 << std::endl;

    SmartPtr<std::string> ptr3(new std::string("razdwa"));
    std::cout << "dlugosc stringa: " << ptr3->length() << std::endl;
    
    SmartPtr<int> ptr4(new int(999));
    SmartPtr<int> ptr5(new int(111));
    ptr5 = std::move(ptr4);
    std::cout << "move assin: " << *ptr5 << std::endl;

    // SmartPtr<int> ptr6 = ptr2;







    return 0;
}