#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
int main() {


    std::vector<int> numbers;
    for (int i = 0; i<10; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
    std::cout << "Iterator zwykły: ";
    for (auto i = numbers.begin(); i != numbers.end(); i++) {
        std::cout << *i << " "; 
    }
    std::cout << std::endl;




    std::vector<std::string> names{"Wiktor", "Szymon", "Jakub", "Kacper"};

    std::cout << "reverse_iterator: ";
    for (std::vector<std::string>::reverse_iterator iterator = names.rbegin(); iterator != names.rend(); iterator++) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    



    std::vector<int> source{1,2,3,4,5};
    std::vector<int> dest{};
    std:: cout<<"zawartosc zrodla i docelowego przed copyif: \n";
    for (int x : source) { std::cout << x << " ";};
    std:: cout<<std::endl;
    for (int x : dest) { std::cout << x << " ";};
    std:: cout<<std::endl;


    std::copy_if(source.begin(), source.end(), std::back_inserter(dest), [](int x)
                 { return x % 2 == 0; });
    std:: cout<<"zawartosc zrodla i docelowego po copyif: \n";
    for (int x : source) { std::cout << x << " ";};
    std:: cout<<std::endl;
    for (int x : dest) { std::cout << x << " ";};
    std:: cout<<std::endl;




    std::list<int> numList;
    for (int i = 0; i<20; i++) {
        int num = i + 1;
        numList.push_back(num);
    }
    std::cout << "Lista przed usunięciem nieparzystych: ";
    for (int x : numList) { 
        std::cout << x << " ";
    };

    auto new_end = std::remove_if(numList.begin(), numList.end(),[](int x) { return x % 2 != 0; });
    numList.erase(new_end, numList.end());
    std::cout << "\nLista po usunięciu nieparzystych: ";
    for (int x : numList) { 
        std::cout << x << " ";
    };
    std::cout << std::endl;







    std::map<std::string, int> wordCountMap;
    std::vector<std::pair<std::string, int>> wordCountVector;
    

    return 0;
}