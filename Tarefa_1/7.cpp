#include <iostream>
#include <vector>

int main()
{
    //A
    int array[5]={10,20,30,40,50};
    int soma=0;
    for(int i=0;i<5;i++)
        soma+=array[i];
    std::cout<<"A soma dos elementos do array e: "<<soma<<std::endl;
    //B

    std::vector<int> v = { 5, 10, 15 };

    v.push_back(20);
    v.push_back(25);

    std::cout << v.size() << std::endl;
    std::cout << "Elementos do vetor: ";
    for (int num : v) {
        std::cout << num << " ";
    }


    return 0;
}
