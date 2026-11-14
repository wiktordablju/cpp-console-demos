#include <iostream>
#include <cctype>










class Figura {
public:
    virtual ~Figura() {}
    virtual char symbol() const = 0;
    virtual void mark_attack(bool** attack_map,
                             int x, int y,
                             Figura*** board,
                             int rows, int cols) const = 0;
};



class Wieza : public Figura {
public:
    char symbol() const override {
        return 'W';
    }

    void mark_attack(bool** attack_map,
                     int x, int y,
                     Figura*** board,
                     int rows, int cols) const override {

        // góra
        for (int i = x - 1; i >= 0; --i) {
            attack_map[i][y] = true;
            if (board[i][y] != nullptr) break;
        }
        // dół
        for (int i = x + 1; i < rows; ++i) {
            attack_map[i][y] = true;
            if (board[i][y] != nullptr) break;
        }
        // lewo
        for (int j = y - 1; j >= 0; --j) {
            attack_map[x][j] = true;
            if (board[x][j] != nullptr) break;
        }
        // prawo
        for (int j = y + 1; j < cols; ++j) {
            attack_map[x][j] = true;
            if (board[x][j] != nullptr) break;
        }
    }
};



class Goniec : public Figura {
public:
    char symbol() const override {
        return 'G';
    }

    void mark_attack(bool** attack_map,
                     int x, int y,
                     Figura*** board,
                     int rows, int cols) const override {

        // lewo-góra
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
            attack_map[i][j] = true;
            if (board[i][j] != nullptr) break;
        }
        // prawo-góra
        for (int i = x - 1, j = y + 1; i >= 0 && j < cols; --i, ++j) {
            attack_map[i][j] = true;
            if (board[i][j] != nullptr) break;
        }
        // lewo-dół
        for (int i = x + 1, j = y - 1; i < rows && j >= 0; ++i, --j) {
            attack_map[i][j] = true;
            if (board[i][j] != nullptr) break;
        }
        // prawo-dół
        for (int i = x + 1, j = y + 1; i < rows && j < cols; ++i, ++j) {
            attack_map[i][j] = true;
            if (board[i][j] != nullptr) break;
        }
    }
};


class Szachownica {
private:
    int rows;
    int cols;
    Figura*** board;
    bool** attack_map;


    void allocate_board() {
        board = new Figura**[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new Figura*[cols];
            for (int j = 0; j < cols; ++j)
                board[i][j] = nullptr;
        }
    }

    void allocate_attack_map() {

        attack_map = new bool*[rows];
        for (int i = 0; i < rows; ++i) {
            attack_map[i] = new bool[cols];
            for (int j = 0; j < cols; ++j)
                attack_map[i][j] = false;
        }
    }

public:


    Szachownica(int r, int c) : rows(r), cols(c) {
        allocate_board();
        allocate_attack_map();
    }


    ~Szachownica() {
        clear();

        for (int i = 0; i < rows; ++i)
            delete[] board[i];
        delete[] board;

        for (int i = 0; i < rows; ++i)
            delete[] attack_map[i];
        delete[] attack_map;
    }



    bool place(int x, int y, Figura* fig) {
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return false;
        if (board[x][y] != nullptr)
            return false;
        board[x][y] = fig;
        return true;
    }


    Figura* remove(int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return nullptr;
        Figura* tmp = board[x][y];
        board[x][y] = nullptr;
        return tmp;
    }


    void clear() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
    }


    void compute_attacks() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                attack_map[i][j] = false;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] != nullptr) {
                    board[i][j]->mark_attack(
                        attack_map, i, j, board, rows, cols);
                }
            }
        }
    }


    void print() {
        compute_attacks();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == nullptr) {
                    std::cout << (attack_map[i][j] ? 'x' : '.');
                } else {
                    char s = board[i][j]->symbol();
                    if (attack_map[i][j])
                        std::cout << (char)std::tolower(s);
                    else
                        std::cout << s;
                }
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

/* =====
   main
   ===== */
int main() {
    Szachownica s1(8, 8);
    s1.place(4, 4, new Goniec());
    s1.place(7, 7, new Wieza());
    s1.print();

    Szachownica s2(5, 10);
    s2.place(2, 2, new Goniec());
    s2.place(2, 7, new Wieza());
    s2.print();

    return 0;
}
